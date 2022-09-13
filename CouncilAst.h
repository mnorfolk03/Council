// Abstract Syntax Tree for Council
//
// Author: Max Norfolk
// 7/9/2022

#pragma once

// #include "SymbolTable.h"	// VarType
#include <memory>        // unique_ptr
#include "CouncilExceptions.h"    // NameAlreadyDeclaredException
#include <map>
#include <utility>

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

    static auto ctx = std::make_unique<LLVMContext>();
    static IRBuilder<NoFolder> builder(*ctx);
    static auto llvm_module = std::make_unique<Module>("Council", *ctx);
    enum VarType {
        INT_T,
        FLOAT_T,
        BOOL_T,
        STR_T,
        MISSING_T
    };

    Type *convertType(VarType type) {
        switch (type) {
            case INT_T:
                return Type::getInt32Ty(*ctx);
            case FLOAT_T:
                return Type::getDoubleTy(*ctx);
            case BOOL_T:
                return Type::getInt1Ty(*ctx);
        }
        logError(ParsingException("Unable to determine and convert type!"));
        return Type::getInt32Ty(*ctx);
    }

    class ExprAst {
    public:
        virtual ~ExprAst() {}

        virtual const VarType type() = 0;

        virtual Value *code() = 0;

        ExprAst() {}
    };

    class LitIntAst : public ExprAst {
    public:

        LitIntAst(int val) : value(val) {}

        virtual const VarType type() { return VarType::INT_T; }

        virtual Value *code() {
            return ConstantInt::get(*ctx, llvm::APInt(32, value, true));
        }

        const int value;
    };

    class LitFloatAst : public ExprAst {
    public:
        LitFloatAst(double val) : value(val) {}

        virtual const VarType type() { return VarType::FLOAT_T; }

        virtual Value *code() {
            return ConstantFP::get(*ctx, APFloat(value));
        }

        const double value;
    };

    class LitBoolAst : public ExprAst {
    public:
        LitBoolAst(bool val) : value(val) {}

        virtual const VarType type() { return VarType::BOOL_T; }

        virtual Value *code() {
            return ConstantInt::getBool(*ctx, value);
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
    Value *fixBinaryOpArgs(VarType desired, VarType current, Value *valuePtr) {
        if (desired == current)
            return valuePtr;
        if (current == FLOAT_T) // float -> int
            return builder.CreateFPToSI(valuePtr, Type::getDoubleTy(*ctx), "floatToInt");
        else // int -> float
            return builder.CreateSIToFP(valuePtr, Type::getInt32Ty(*ctx), "intToFloat");
    }

    class BinaryOpExprAst : public ExprAst {
    public:
        BinaryOpExprAst(ExprAst *left, BinaryOp op, ExprAst *right) : op(op) {
            this->left = left;
            this->right = right;
        }

        const BinaryOp op;

        virtual ~BinaryOpExprAst() {
            delete left;
            delete right;
        }

        virtual const VarType type() { return inferred_type; }

        virtual Value *code() {
            Value *l_val = left->code();
            Value *r_val = right->code();
            inferred_type = inferBinaryOpType(left->type(), op, right->type());

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
            return nullptr;
        } // TODO add this

    private:
        ExprAst *left;
        ExprAst *right;
        VarType inferred_type;
    };

    class VariableData {
    public:
        VariableData(VarType type) : _type(type) {
            in_memory = false;
        }

        // invalid
        VariableData() {
            _type = VarType::MISSING_T;
        }

        VarType type() {
            return _type;
        }

        Value *value() {
            return (Value *) inst;
        }

        void setAlloca(AllocaInst *inst) {
            this->inst = inst;
        }


    private:
        VarType _type;
        AllocaInst *inst = nullptr;
        bool in_memory;
    };

    class Scope {
    private:
        std::map<std::string, VariableData *> vars;
        Scope *parent;

        static Scope *active_scope;
    public:
        Scope(Scope *parent = nullptr) : parent(parent) {}

        VariableData *find(const std::string &str) {
            if (vars.contains(str)) {
                return vars[str];
            }
            if (parent != nullptr)
                return parent->find(str);
            return nullptr;
        }

        void print() {
            std::cout << "Scope: [";
            for (const auto &pair: vars) {
                std::cout << pair.first;
            }
            std::cout << "]" << std::endl;
        }

        void insert(const std::string &str, VariableData *data) { vars[str] = data; }

        static Scope *&activeScope() { return active_scope; }

        static void newLevel() {
            active_scope = new Scope(active_scope);
            std::cout << "entering new scope" << std::endl;
        }

        static void exitToParent() {
            Scope *parent = active_scope->parent;
            delete active_scope;
            active_scope = parent;

            std::cout << "exiting scope to parent" << std::endl;
        }
    };

    Scope *Scope::active_scope = new Scope();

    class ObjIdAst : public ExprAst {
    public:
        ObjIdAst(std::string id) : id(std::move(id)) {}

        virtual const VarType type() {
            VariableData *data = Scope::activeScope()->find(id);
            std::cout << "DATA: " << data << std::endl;
            return data->type();
        };

        virtual Value *code() {
            VariableData *var = Scope::activeScope()->find(id);
            Type *llvm_type = convertType(var->type());
            Value *ret = builder.CreateLoad(llvm_type, var->value(), id);

            return ret;
        };

    private:
        std::string id;
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
        virtual ~CodelineAst() {}

        virtual CodelineType type() { return CodelineType::ERROR_TYPE; };

        // generates a line, but returns nothing.
        virtual void generate_line() = 0;
    };

    class AssignVarAst : public CodelineAst {
    public:
        AssignVarAst(std::string name, ExprAst *expr) : name(name), expr(expr) {}

        virtual CodelineType type() { return CodelineType::ASSIGN_VAR; }

        virtual void generate_line() {

            VariableData *var = Scope::activeScope()->find(name);
            if (var->type() != expr->type())
                logError(MisMatchTypeException());
            builder.CreateStore(expr->code(), var->value());
        }

        std::string id() {
            return name;
        }

    private:
        ExprAst *expr;
        std::string name;
    };

// This is just used to update the listing of variable's and their
// types, rather than actually editing them in any way.
    class DeclareVarAst : public CodelineAst {
    public:
        DeclareVarAst(VarType type, AssignVarAst *assign) : assign(assign), var_type(type) {};

        DeclareVarAst() {
            assign = nullptr;
            var_type = VarType::MISSING_T;
        }

        virtual CodelineType type() { return CodelineType::DECLARE_VAR; }

        virtual void generate_line() {
            if (assign == nullptr) {
                logError(IllegalStateException());
                return;
            }
            std::string id = assign->id();
            auto *data = new VariableData(var_type);
            Scope::activeScope()->insert(id, data);

            Type *llvm_type = convertType(var_type);

            AllocaInst *alloca = builder.CreateAlloca(llvm_type, nullptr, id);
            data->setAlloca(alloca);

            assign->generate_line();
        };

    private:
        AssignVarAst *assign;
        VarType var_type;
    };

// the class used for the return line. This is important, because
    class ReturnAst : public CodelineAst {
    public:
        ReturnAst(ExprAst *ret_val) : ret_val(ret_val) {}

        virtual ~ReturnAst() {
            delete ret_val;
        }

        virtual CodelineType type() {
            return RETURN_STMT;
        }

        Value *returnValue() { return ret_val->code(); }

        virtual void generate_line() {
            builder.CreateRet(ret_val->code());
        }

    private:
        ExprAst *ret_val;
    };

    class CodeBlockAst {
    public:
        CodeBlockAst(std::vector<CodelineAst *> codelines, ReturnAst *return_stmt = nullptr)
                : codelines(codelines), return_stmt(return_stmt) {
        }


        BasicBlock *createBlock(Function *parent = nullptr) {
            return fillBlock(BasicBlock::Create(*ctx, "blockEntry", parent));
        }

        BasicBlock *fillBlock(BasicBlock *block) {
            builder.SetInsertPoint(block);
            for (auto codeline: codelines) {
                codeline->generate_line();
            }
            if (return_stmt != nullptr)
                builder.CreateRet(return_stmt->returnValue());

            return block;
        }

        virtual ~CodeBlockAst() {
            delete return_stmt;
        }

        bool hasReturn() { return return_stmt != nullptr; }

        // returns nullptr if there is no return value (hasReturn()).
        // if it does, then it returns the Value* generated by calling
        // the return_stmt's returnValue method.
        Value *returnValue() {
            return (return_stmt == nullptr) ? nullptr : return_stmt->returnValue();
        }

    private:
        ReturnAst *return_stmt;
        std::vector<CodelineAst *> codelines;
    };

    class FunctionAst {
    public:
        FunctionAst(std::string name, VarType return_type, CodeBlockAst *body,
                    std::vector<std::string> arg_names, std::vector<VarType> arg_types)
                : name(name), return_type(return_type), body(body),
                  arg_types(arg_types), arg_names(arg_names) {}

        virtual ~FunctionAst() {
            delete body;
        }

        Function *code() {
            std::vector<Type *> args;
            for (auto it = arg_types.begin(); it != arg_types.end(); it++) {
                args.push_back(convertType(*it));
            }


            // false = not varags
            FunctionType *ft = FunctionType::get(convertType(return_type), args, false);

            Function *f = Function::Create(ft,
                                           Function::ExternalLinkage,
                                           name,
                                           *llvm_module);

            Scope::newLevel();

            auto arg_types_it = arg_types.begin();
            auto arg_names_it = arg_names.begin();

            BasicBlock *bb = BasicBlock::Create(*ctx, "blockEntry", f);
            builder.SetInsertPoint(bb);

            auto llvm_arg_it = f->arg_begin();
            for (; arg_names_it != arg_names.end();) {


                llvm_arg_it->setName(*arg_names_it);
                auto *var = new VariableData(*arg_types_it);
                Scope::activeScope()->insert(*arg_names_it, var);

                Type *llvm_type = convertType(*arg_types_it);

                AllocaInst *alloca = builder.CreateAlloca(llvm_type, nullptr, *arg_names_it);
                var->setAlloca(alloca);
                builder.CreateStore(&*llvm_arg_it, alloca);

                arg_names_it++;
                arg_types_it++;
                llvm_arg_it++;
            }


            body->fillBlock(bb);

            Scope::exitToParent();

            /*
               if (body->hasReturn()) {
               builder.CreateRet(body->returnValue());
               } else {

            // if no return, then for now just return 0
            // TODO make better?

            Value * ret_val = ConstantInt::get(ctx, llvm::APInt(32, 0, true));
            builder.CreateRet(ret_val);
            }
             */
            verifyFunction(*f);

            return f;
        }

    private:
        std::string name;
        std::vector<std::string> arg_names;
        std::vector<VarType> arg_types;
        VarType return_type;
        CodeBlockAst *body;
    };

// if statement
    class IfChainAst : public CodelineAst {
    public:
        IfChainAst(std::vector<ExprAst *> exprs, std::vector<CodeBlockAst *> blocks) : exprs(exprs),
                                                                                       blocks(blocks) {
        }

        virtual CodelineType type() { return CodelineType::IF_CHAIN; }

        virtual ~IfChainAst() {
            for (auto expr: exprs) {
                delete expr;
            }
            for (auto block: blocks) {
                delete block;
            }
        }

        virtual void generate_line() {

            Function *parent = builder.GetInsertBlock()->getParent();
            BasicBlock *enter_if = builder.GetInsertBlock();

            std::vector<BasicBlock *> basic_blocks;
            BasicBlock *if_exit = BasicBlock::Create(*ctx, "if_exit", parent);

            for (auto block: blocks) {
                basic_blocks.push_back(block->createBlock(parent));
                if (!block->hasReturn())
                    builder.CreateBr(if_exit);
            }

            builder.SetInsertPoint(enter_if);

            basic_blocks.push_back(if_exit);

            std::vector<BasicBlock *> fall_through;

            for (int i = 0; i < exprs.size(); i++) {

                // Fix type of Expr to become a Bool.
                Value *expr_value = exprs[i]->code();
                switch (exprs[i]->type()) {
                    case VarType::INT_T:
                        expr_value = builder.CreateICmpNE(expr_value,
                                                          ConstantInt::get(*ctx, llvm::APInt(32, 0, true)),
                                                          "intToBool");
                        break;
                    case VarType::FLOAT_T:
                        expr_value = builder.CreateFCmpONE(expr_value, ConstantFP::get(*ctx, APFloat(0.0)),
                                                           "floatToBool");
                        break;
                }

                // if we are at the last one, we either want the else
                // clause or to go to if_exit. Either way, the
                // basicblocks[i+1] will be this desired value
                if (i < exprs.size() - 1) {
                    BasicBlock *fall_through = BasicBlock::Create(*ctx, "fallThrough", parent);
                    builder.CreateCondBr(expr_value, basic_blocks[i], fall_through);
                    builder.SetInsertPoint(fall_through);
                } else { // else or if_exit
                    builder.CreateCondBr(expr_value, basic_blocks[i], basic_blocks[i + 1]);
                    builder.SetInsertPoint(basic_blocks[i + 1]);
                }
            }
            builder.SetInsertPoint(if_exit);
        }


    private:
        std::vector<ExprAst *> exprs;
        std::vector<CodeBlockAst *> blocks;
    };

    class MainMethodAst {
    private:
        CodeBlockAst *body;

    public:
        MainMethodAst(CodeBlockAst *body) : body(body) {}

        void generate() {
            FunctionType *ft = FunctionType::get(convertType(VarType::INT_T), false);
            Function *f = Function::Create(ft, Function::ExternalLinkage, "main", *llvm_module);
            BasicBlock *basic_block = body->createBlock(f);
            verifyFunction(*f);
        }
    };

} // end of namespace
