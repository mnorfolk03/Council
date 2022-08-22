// Abstract Syntax Tree for Council
//
// Author: Max Norfolk
// 7/9/2022

#pragma once

// #include "SymbolTable.h"	// VarType
#include <memory> 	 	// unique_ptr
#include "CouncilExceptions.h" 	// NameAlreadyDeclaredException 
#include <map>

// LLVM stuff
#include "llvm/ADT/APInt.h"
#include "llvm/ADT/APFloat.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/Verifier.h"

#include "llvm/IR/NoFolder.h" // TODO REMOVE THIS

using namespace llvm;

namespace coun {

	static LLVMContext ctx;
	static IRBuilder<NoFolder> builder(ctx);
	static Module llvmModule("Council", ctx);
	enum VarType {
		INT_T,
		FLOAT_T,
		BOOL_T,
		STR_T
	};

	Type* convertType(VarType type){
		switch (type){
			case INT_T:
				return Type::getInt32Ty(ctx);
			case FLOAT_T:
				return Type::getDoubleTy(ctx);
			case BOOL_T:
				return Type::getInt1Ty(ctx);
		}
        logError(ParsingException("Unable to determine and convert type!"));
		return Type::getInt32Ty(ctx);
	}

	class ExprAst {
		public:
			virtual ~ExprAst(){}
			virtual const VarType type() = 0;
			virtual Value* code() = 0;
			ExprAst(){}
	};

	class LitIntAst : public ExprAst {
		public: 

			LitIntAst(int val) : value(val){}
			virtual const VarType type(){return VarType::INT_T;}
			virtual Value* code() {
				return ConstantInt::get(ctx, llvm::APInt(32, value, true));
			}
			const int value;
	};

	class LitFloatAst : public ExprAst {
		public:
			LitFloatAst(double val) : value(val){}
			virtual const VarType type(){return VarType::FLOAT_T;}
			virtual Value* code() {
				return ConstantFP::get(ctx, APFloat(value));
			}
			const double value;
	};

	class LitBoolAst : public ExprAst {
		public:
			LitBoolAst(bool val) : value(val){}
			virtual const VarType type(){return VarType::BOOL_T;}
			virtual Value* code() {
				return ConstantInt::getBool(ctx, value);
			}
			const bool value;
	};

	// the set of binary operations allowed used in the language
	enum BinaryOp {
		PLUS = 0,
		MINUS = 1,
		MULTI = 10,
		FLOAT_DIV = 11,
		INT_DIV = 12,
		MOD = 13,
		CMP_EQ = 20,
		CMP_NEQ = 21,
		CMP_LT = 22,
		CMP_GT = 23,
		CMP_LTEQ = 24,
		CMP_GTEQ = 25
	};

	// returns the type the function should return using the two types
	VarType inferBinaryOpType(VarType left, BinaryOp op, VarType right) {
		if (op >= CMP_EQ) // comparison ops return bools
			return VarType::BOOL_T;

		else if (op <= MULTI) { // float if left or right is float.
			return left == FLOAT_T || right == FLOAT_T ? FLOAT_T : INT_T;

		} else if (op == FLOAT_DIV)
			return FLOAT_T; // floating division always returns float

		else
			return INT_T; // int div or modulus
	}

	// fixes the Value* to be the correct type as necessary based upon the desired op
	Value* fixBinaryOpArgs(VarType desired, VarType current, Value* valuePtr){
		if (desired==current)
			return valuePtr;
		if (current == FLOAT_T) // float -> int
			return builder.CreateFPToSI(valuePtr, Type::getDoubleTy(ctx), "floatToInt");
		else // int -> float
			return builder.CreateSIToFP(valuePtr, Type::getInt32Ty(ctx), "intToFloat");
	}

	class BinaryOpExprAst : public ExprAst {
		public:
			BinaryOpExprAst(ExprAst* left, BinaryOp op, ExprAst* right) : op(op)  {
				this->left = left;
				this->right = right;
				inferred_type = inferBinaryOpType(left->type(), op, right->type());
			}
			const BinaryOp op;
			virtual ~BinaryOpExprAst(){
				delete left;
				delete right;
			}
			virtual const VarType type(){return inferred_type;} 
			virtual Value* code() {
				Value* l_val = left->code();
				Value* r_val = right->code();
				
				// determine what type the arguments should be
				VarType arg_type;
				if (op == INT_DIV || op == MOD)
					arg_type = VarType::INT_T;
				else
					arg_type = (left->type() == FLOAT_T || right->type() == FLOAT_T)
							 ? FLOAT_T : INT_T;
				
				// fix argument types if necessary
				l_val = fixBinaryOpArgs(arg_type, left->type(), l_val);
				r_val = fixBinaryOpArgs(arg_type, right->type(), r_val);


				CmpInst::Predicate pred; // used in CMP operators
				switch (op) {
					case BinaryOp::PLUS:
						// TODO fix with int
						if (arg_type == VarType::INT_T)
							return builder.CreateAdd(l_val, r_val, "iAddTmp");
						return builder.CreateFAdd(l_val, r_val, "fAddTmp");
					case BinaryOp::MINUS:
						if (arg_type == VarType::INT_T)
							return builder.CreateSub(l_val, r_val, "iSubTmp");
						return builder.CreateFSub(l_val, r_val, "fSubTmp");
					case BinaryOp::MULTI:
						if (arg_type == VarType::INT_T)
							return builder.CreateMul(l_val, r_val, "iMulTmp");
						return builder.CreateFMul(l_val, r_val, "fMulTmp");
					case BinaryOp::FLOAT_DIV:
						return builder.CreateFDiv(l_val, r_val, "fDivTmp");
					case BinaryOp::INT_DIV:
						// signed integer division
						return builder.CreateSDiv(l_val, r_val, "iDivTmp");
					case BinaryOp::MOD:
						// signed remainder (not modulus?)
						return builder.CreateSRem(l_val, r_val, "modTmp");
					case BinaryOp::CMP_EQ:
						pred = (arg_type == VarType::INT_T)
							? CmpInst::Predicate::ICMP_EQ
							: CmpInst::Predicate::FCMP_OEQ;
						return builder.CreateCmp(pred, l_val, r_val, "cmpEq");
					case BinaryOp::CMP_NEQ:
						pred = (arg_type == VarType::INT_T)
							? CmpInst::Predicate::ICMP_NE
							: CmpInst::Predicate::FCMP_ONE;
						return builder.CreateCmp(pred, l_val, r_val, "cmpNeq");
					case BinaryOp::CMP_LT:
						pred = (arg_type == VarType::INT_T)
							? CmpInst::Predicate::ICMP_SLT
							: CmpInst::Predicate::FCMP_OLT;
						return builder.CreateCmp(pred, l_val, r_val, "cmpLt");
					case BinaryOp::CMP_GT:
						pred = (arg_type == VarType::INT_T)
							? CmpInst::Predicate::ICMP_SGT
							: CmpInst::Predicate::FCMP_OGT;
						return builder.CreateCmp(pred, l_val, r_val, "cmpGt");
					case BinaryOp::CMP_LTEQ:
						pred = (arg_type == VarType::INT_T)
							? CmpInst::Predicate::ICMP_SLE
							: CmpInst::Predicate::FCMP_OLE;
						return builder.CreateCmp(pred, l_val, r_val, "cmpLtEq");
					case BinaryOp::CMP_GTEQ:
						pred = (arg_type == VarType::INT_T)
							? CmpInst::Predicate::ICMP_SGE
							: CmpInst::Predicate::FCMP_OGE;
						return builder.CreateCmp(pred, l_val, r_val, "cmpGtEq");
				}
				return NULL;
			} // TODO add this
			
		private:
			ExprAst* left;
			ExprAst* right;
			VarType inferred_type;	
	};
	
	typedef struct {
		Value* value;
		VarType type;
	} VariableData;

	std::map<std::string, VariableData> varsMap;

	class DeclareVarAst {
		public:
			DeclareVarAst(VarType type, std::string name){
				VariableData data;
				data.type = type;
				varsMap[name] = data;
			}
	};

	enum CodelineType {
		DECLARE_VAR,
		ASSIGN_VAR,
		FUNC_CALL,
		RETURN_STMT,
		IF_CHAIN,
        ERROR_TYPE
	};

	class CodelineAst {
		public:
		virtual ~CodelineAst(){}
		virtual CodelineType type(){return CodelineType::ERROR_TYPE;};
        
        // generate's a line, but returns nothing.
        virtual void generate_line()=0;
	};

	// the class used for the return line. This is important, because 
	class ReturnAst : public CodelineAst {
		public:
			ReturnAst(ExprAst* ret_val) : ret_val(ret_val) {}
			virtual ~ReturnAst() {
				delete ret_val;
			}
			virtual CodelineType type() {
				return RETURN_STMT;
			}
			
			Value* returnValue(){return ret_val->code();}

            virtual void generate_line(){
                builder.CreateRet(ret_val->code());
            }
		private:
			ExprAst* ret_val;
	};
	
	class CodeBlockAst {
		public:
			CodeBlockAst(std::vector<CodelineAst*> codelines, ReturnAst* return_stmt=nullptr)
			: codelines(codelines), return_stmt(return_stmt)
			{

			}


			BasicBlock* createBlock(Function* parent = nullptr) {
				block = BasicBlock::Create(ctx, "blockEntry", parent);
                std::cout << "creating block" << std::endl;
				// TODO MORE
                for (auto codeline : codelines) {
                    codeline->generate_line();
                }

				return block;
			}
            // returns the basic block if createBlock has been called,
            // otherwise returns nullptr.
			BasicBlock* fetchBlockIfCreated(){
                return block;
            }

			virtual ~CodeBlockAst() {
				delete return_stmt;
			}
			
			bool hasReturn(){return return_stmt != nullptr;}
			
			// returns nullptr if there is no return value (hasReturn()).
			// if it does, then it returns the Value* generated by calling
			// the return_stmt's returnValue method.
			Value* returnValue() {
				return (return_stmt == nullptr) ? nullptr : return_stmt->returnValue();
			}
		private:
			ReturnAst* return_stmt;
			std::vector<CodelineAst*> codelines;
            BasicBlock* block = nullptr;
	};

	class FunctionAst {
		public:
			FunctionAst(std::string name, VarType return_type, CodeBlockAst* body,
				std::vector<std::string> arg_names, std::vector<VarType> arg_types) 
				: name(name), return_type(return_type), body(body),
				  arg_types(arg_types), arg_names(arg_names) {}

			virtual ~FunctionAst(){
				delete body;
			}

			Function* code() {
				std::vector<Type*> args;
				for (auto it = arg_types.begin(); it != arg_types.end(); it++) {
					args.push_back(convertType(*it));
				}
                
                
				// false = not varags
				FunctionType *ft = FunctionType::get(convertType(return_type), args, false);
				
				Function *f = Function::Create(ft, 
					Function::ExternalLinkage, 
					name, 
					llvmModule);
				
				varsMap.clear(); // each function get's its own set of variables
						
				auto arg_types_it = arg_types.begin();	
				auto arg_names_it = arg_names.begin();
                
// TODO fix this
                
                auto llvm_arg_it = f->arg_begin();
				for (; arg_names_it != arg_names.end();) {
                    
    
					llvm_arg_it->setName(*arg_names_it);
					DeclareVarAst(*arg_types_it, *arg_names_it);
					arg_names_it++;
                    arg_types_it++;
                    llvm_arg_it++;
				}				
				
				BasicBlock* bb = body->createBlock(f);
				builder.SetInsertPoint(bb);
				
                

				if (body->hasReturn()) {
					builder.CreateRet(body->returnValue());
				} else { 

					// if no return, then for now just return 0
					// TODO make better?

					Value * ret_val = ConstantInt::get(ctx, llvm::APInt(32, 0, true));
					builder.CreateRet(ret_val);
				}
				verifyFunction(*f);

				return f;
			}
		private:
			std::string name;
			std::vector<std::string> arg_names;
			std::vector<VarType> arg_types;
			VarType return_type;
			CodeBlockAst* body;
	};


    class IfChain : public CodelineAst {
        public:
            IfChain(std::vector<ExprAst*> exprs, std::vector<CodeBlockAst*> blocks) : exprs(exprs), blocks(blocks) {std::cout << "made ifChain" << std::endl;}
            virtual CodelineType type(){return CodelineType::IF_CHAIN;}
            virtual ~IfChain(){
                for (auto expr : exprs){
                    delete expr;
                }
                for (auto block : blocks){
                    delete block;
                }
            }
            virtual void generate_line() {     
                std::cout << "if:generate_line()" << std::endl;

                Function * parent = builder.GetInsertBlock()->getParent();

                std::vector<BasicBlock*> basic_blocks;
                BasicBlock* if_exit = BasicBlock::Create(ctx, "if_exit", parent);
                for (auto block : blocks) {
                    basic_blocks.push_back(block->createBlock(parent));
                }
                basic_blocks.push_back(if_exit);

                std::vector<BasicBlock*> fall_through;

                for (int i = 0; i < exprs.size(); i++) {
                    
                    // Fix type of Expr to become a Bool.
                    Value* expr_value = exprs[i]->code();
                    switch (exprs[i]->type()){
                        case VarType::INT_T:
                        expr_value = builder.CreateICmpNE(expr_value, ConstantInt::get(ctx, llvm::APInt(32, 0, true)), "intToBool");
                        break;
                        case VarType::FLOAT_T:
                        expr_value = builder.CreateFCmpONE(expr_value, ConstantFP::get(ctx, APFloat(0.0)), "floatToBool");
                        break;
                    }
                    
                    // if we are at the last one, we either want the else
                    // clause or to go to if_exit. Either way, the 
                    // basicblocks[i+1] will be this desired value
                    if (i < exprs.size() - 1) {
                        BasicBlock * fall_through = BasicBlock::Create(ctx, "fallThrough", parent);
                        builder.CreateCondBr(expr_value, basic_blocks[i], fall_through);
                        builder.SetInsertPoint(fall_through);
                    } else { // else or if_exit
                        builder.CreateCondBr(expr_value, basic_blocks[i], basic_blocks[i+1]);
                    }
                }
                for (auto block : blocks){
                    builder.SetInsertPoint(block->fetchBlockIfCreated());
                    builder.CreateBr(if_exit);
                }
 
                return;
            } 
            
                        
        private:
            std::vector<ExprAst*> exprs;
            std::vector<CodeBlockAst*> blocks;
    };

	/*
	   class VariableAst : ExprAst {
	   private:
	//VariableAst(VarType type, const std::string& name) : type(type), name(name){}
	const std::string name;
	VarType varType;

	static std::map<const std::string&, std::unique_ptr<VariableAst>> vars;
	public:
	VariableAst(VarType type, const std::string& name) : varType(type), name(name){}
	// looks up a variable and if it exists, then it is returned. Otherwise, NULL is returned
	static std::unique_ptr<VariableAst> lookup(const std::string& name) {
	auto it = vars.find(name);
	if (it != vars.end())
	return it->second;
	return NULL;
	}

	// declares a variable of a given type. It should later be accessed by the lookup method.
	// if this variable is already declared, an Exception will be thrown.
	static std::unique_ptr<VariableAst> declare(VarType type,  const std::string& name){
	auto ret = std::make_unique<VariableAst>(type, name);
	vars[name] = std::move(ret);
	return ret;
	}

	virtual const VarType type(){return varType;}
	};
	 */
	

	
	/*
	   class AssignVarAst : CodelineAst {
	   public:

	   AssignVarAst(const std::string& name, std::unqiue_ptr<ExprAst> expr) : expr(std::move(expr)){}

	   private:
	   std::unique_ptr<ExprAst> expr;
	   };
	 */

} // end of namespace
