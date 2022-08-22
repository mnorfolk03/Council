
// Generated from Council.g4 by ANTLR 4.10.1

#pragma once

#include<string>
#include<iostream>
#include<cstdlib>

#include "CouncilExceptions.h"
#include "antlr4/CouncilVisitor.h"
// #include "SymbolTable.h"
#include "CouncilAst.h"

using namespace std;
using namespace coun;

/**
 * This class provides an empty implementation of CouncilVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class MyCouncilVisitor : public CouncilVisitor {
	private:
		ofstream file_out;

	public:

		MyCouncilVisitor(string & path){
			file_out.open(path, ios::out);
		}

        VarType typeFromContext(CouncilParser::TypeContext *ctx){
            return any_cast<VarType>(visit(ctx));
        }

		virtual std::any visitParseFile(CouncilParser::ParseFileContext *ctx) override {
			return visitChildren(ctx);
		}

		virtual std::any visitImportStmt(CouncilParser::ImportStmtContext *ctx) override {
			return visitChildren(ctx);
		}

		virtual std::any visitTypeStr(CouncilParser::TypeStrContext *ctx) override {
			return VarType::STR_T;
		}

		virtual std::any visitTypeInt(CouncilParser::TypeIntContext *ctx) override {
			return VarType::INT_T;
		}

		virtual std::any visitTypeFloat(CouncilParser::TypeFloatContext *ctx) override {
			return VarType::FLOAT_T;
		}

		virtual std::any visitTypeBool(CouncilParser::TypeBoolContext *ctx) override {
			return VarType::BOOL_T;
		}

		virtual std::any visitDecVar(CouncilParser::DecVarContext *ctx) override {
			VarType type = std::any_cast<VarType>(visit(ctx->type()));

			visit(ctx->assignVar());
			return NULL;
		}

		virtual std::any visitAssignVar(CouncilParser::AssignVarContext *ctx) override {
			return visitChildren(ctx);
		}

		virtual std::any visitDecFunc(CouncilParser::DecFuncContext *ctx) override {
			
            auto id_vec = ctx->ID();
            auto it_ids = id_vec.begin();
           
			string func_name = (*(it_ids))->getText(); // THIS LINE

            auto types_vec = ctx->type();
            auto it_types = types_vec.begin();
			// TODO finish this
			VarType return_type = typeFromContext(*it_types);
						
			it_ids++;
			it_types++;
			
			vector<string> param_names;
			vector<VarType> param_types;
			for (; it_ids != id_vec.end(); it_ids++, it_types++) {
				param_names.push_back((*it_ids)->getText());
				param_types.push_back(typeFromContext(*it_types));

			}
			
			CodeBlockAst* body = any_cast<CodeBlockAst*>(visitCodeBlock(ctx->codeBlock()));
			if (!body->hasReturn()){
				logError(ParsingException("Funcion '" + func_name + "' may be missing return!"));
			}
			FunctionAst * func = new FunctionAst(func_name, return_type, body, param_names, param_types);
			func->code();
			return func;
		}

		virtual std::any visitPreMinusExpr(CouncilParser::PreMinusExprContext *ctx) override {
			return visitChildren(ctx);
		}

		virtual std::any visitPlusMinusExpr(CouncilParser::PlusMinusExprContext *ctx) override {
			ExprAst* left = any_cast<ExprAst*>(visit(ctx->expr(0)));
			ExprAst* right = any_cast<ExprAst*>(visit(ctx->expr(1)));
			
			BinaryOp op = (ctx->PLUS() == NULL) ? BinaryOp::MINUS : BinaryOp::PLUS;

			return (ExprAst*) new BinaryOpExprAst(left, op, right);
		}

		virtual std::any visitObjExpr(CouncilParser::ObjExprContext *ctx) override {
			return visitChildren(ctx);
		}

		virtual std::any visitMultiDivExpr(CouncilParser::MultiDivExprContext *ctx) override {
			ExprAst* left = std::any_cast<ExprAst*>(visit(ctx->expr(0)));
			ExprAst* right = std::any_cast<ExprAst*>(visit(ctx->expr(1)));

			BinaryOp op;
	
			switch(ctx->op->getType()){
				case CouncilParser::MULTI:
					op = BinaryOp::MULTI;				 
					break;
				case CouncilParser::FLOAT_DIV:
					op = BinaryOp::FLOAT_DIV;
					break;
				case CouncilParser::INT_DIV:
					op = BinaryOp::INT_DIV;
					break;
				case CouncilParser::MOD:
					op = BinaryOp::MOD;
					break;
			}
			return (ExprAst*) new BinaryOpExprAst(left, op, right);
		}

		virtual std::any visitCmpExpr(CouncilParser::CmpExprContext *ctx) override {
			ExprAst* left = std::any_cast<ExprAst*>(visit(ctx->expr(0)));
			ExprAst* right = std::any_cast<ExprAst*>(visit(ctx->expr(1)));

			BinaryOp op;
			
			switch (ctx->op->getType()){
				case CouncilParser::EQ:
					op = BinaryOp::CMP_EQ;
					break;
				case CouncilParser::NEQ:
					op = BinaryOp::CMP_NEQ;
					break;
				case CouncilParser::LT:
					op = BinaryOp::CMP_LT;
					break;
				case CouncilParser::GT:
					op = BinaryOp::CMP_GT;
					break;
				case CouncilParser::GT_EQ:
					op = BinaryOp::CMP_GTEQ;
					break;
				case CouncilParser::LT_EQ:
					op = BinaryOp::CMP_LTEQ;
					break;
			}
			return (ExprAst*) new BinaryOpExprAst(left, op, right);
		}

		virtual std::any visitFuncCall(CouncilParser::FuncCallContext *ctx) override {
			return visitChildren(ctx);
		}

		virtual std::any visitReturnStmt(CouncilParser::ReturnStmtContext *ctx) override {
			return new ReturnAst(any_cast<ExprAst*>(visit(ctx->expr())));
		}

		virtual std::any visitIfChain(CouncilParser::IfChainContext *ctx) override {
	    vector<ExprAst*> exprs;
        vector<CodeBlockAst*> blocks;
        
        auto ctx_exprs = ctx->expr();
        auto ctx_blocks = ctx->codeBlock();
        
        auto expr_it = ctx_exprs.begin();
        auto blocks_it = ctx_blocks.begin();

        for (; expr_it != ctx_exprs.end(); expr_it++, blocks_it++) {
            exprs.push_back(any_cast<ExprAst*>(visit(*expr_it)));
            blocks.push_back(any_cast<CodeBlockAst*>(visit(*blocks_it)));
        }

        // check if there is an "else" clause
	    if (blocks_it != ctx_blocks.end()){
            blocks.push_back(any_cast<CodeBlockAst*>(visit(*blocks_it)));
        }
        
	    return new IfChain(exprs, blocks);
		}

		virtual std::any visitWhileLoop(CouncilParser::WhileLoopContext *ctx) override {
			return visitChildren(ctx);
		}

		virtual std::any visitForLoop(CouncilParser::ForLoopContext *ctx) override {
			return visitChildren(ctx);
		}

		virtual std::any visitObjId(CouncilParser::ObjIdContext *ctx) override {
			return visitChildren(ctx);
		}

		virtual std::any visitObjLiteral(CouncilParser::ObjLiteralContext *ctx) override {
			return visitChildren(ctx);
		}

		virtual std::any visitParenExpr(CouncilParser::ParenExprContext *ctx) override {
			return visitChildren(ctx);
		}

		virtual std::any visitBarExpr(CouncilParser::BarExprContext *ctx) override {
			return visitChildren(ctx);
		}

		virtual std::any visitFuncCallObj(CouncilParser::FuncCallObjContext *ctx) override {
			return visitChildren(ctx);
		}

		virtual std::any visitCodeBlock(CouncilParser::CodeBlockContext *ctx) override {
			auto codelines = ctx->codeLine();
			
			vector<CodelineAst*> codelines_ast;
            
            
			for (auto it = codelines.begin(); it != codelines.end(); it++){
				CodelineAst* line = any_cast<CodelineAst*>(visit(*it));
                if (line == nullptr) // TODO take this out
                    continue;
				if (line->type() == CodelineType::RETURN_STMT) {
					
					// if this return stmt is not the last thing
					// in the function call, throw an error!
					if (next(it) != codelines.end()){
						logError(ParsingException("unreachable code after return."));
					}
					return new CodeBlockAst(codelines_ast, static_cast<ReturnAst*>(line));
				} else {
					codelines_ast.push_back(line);
				}
			}
			return new CodeBlockAst(codelines_ast);
		}

		virtual std::any visitCodeLine(CouncilParser::CodeLineContext *ctx) override {
			if (ctx->decVar() != NULL) {
				// TODO add
			} else if (ctx->assignVar() != NULL) {
				// TODO
			} else if (ctx->funcCall() != NULL) {
				// TODO
			} else if (ctx->returnStmt() != NULL) {
				return (CodelineAst*) any_cast<ReturnAst*>(visit(ctx->returnStmt()));
			} else if (ctx->ifChain() != NULL) {
				// TODO
                return (CodelineAst*) any_cast<IfChain*>(visit(ctx->ifChain()));
			}
			 
			logError(ParsingException("visitCodeLine, unreachable state."));
			return (CodelineAst*) nullptr;
			
		}

		virtual std::any visitLiteral(CouncilParser::LiteralContext *ctx) override {
			
			// NOTE: we need to cast to ExprAst* to be able to use std::any correctly!
			
			if (ctx->INT()!=NULL)
				return (ExprAst*) new LitIntAst(stoi(ctx->INT()->getText()));
			else if (ctx->FLOAT()!=NULL)
				return (ExprAst*) new LitFloatAst(stod(ctx->FLOAT()->getText()));
			else if (ctx->STRING()!=NULL) {
				std::string str = ctx->STRING()->getText(); // kill the "-s
				// return TableEntry(str.substr(1,str.length()-2));
			} else if (ctx->TRUE()!=NULL)
				return (ExprAst*) new LitBoolAst(true);
			else if (ctx->FALSE()!=NULL)
				return (ExprAst*) new LitBoolAst(false);
			
			logError(ParsingException("visitLiteral, unreachable state."));
			return (ExprAst*) nullptr;
		}




};

