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

using namespace llvm;

namespace coun {

	static LLVMContext ctx;
	static IRBuilder<> builder(ctx);
	enum VarType {
		INT_T,
		FLOAT_T,
		BOOL_T,
		STR_T
	};

	class ExprAst {
		public:
			virtual ~ExprAst(){}
			virtual const VarType type() = 0;
			virtual Value* code() = 0;
			ExprAst(){}
	};

	class LitIntAst : ExprAst {
		public: 

			LitIntAst(int val) : value(val){}
			virtual const VarType type(){return VarType::INT_T;}
			virtual Value* code() {
				return ConstantInt::get(ctx, llvm::APInt(32, value, true));
			}
			const int value;
	};

	class LitFloatAst : ExprAst {
		public:
			LitFloatAst(double val) : value(val){}
			virtual const VarType type(){return VarType::FLOAT_T;}
			virtual Value* code() {
				return ConstantFP::get(ctx, APFloat(value));
			}
			const double value;
	};

	class LitBoolAst : ExprAst {
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

	class BinaryOpExprAst : ExprAst {
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
	class CodelineAst {

	};
	/*
	   class AssignVarAst : CodelineAst {
	   public:

	   AssignVarAst(const std::string& name, std::unqiue_ptr<ExprAst> expr) : expr(std::move(expr)){}

	   private:
	   std::unique_ptr<ExprAst> expr;
	   };
	 */

} // end of namespace
