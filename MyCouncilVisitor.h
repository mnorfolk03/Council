
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
			cout << "declaration!" << endl;
			visit(ctx->assignVar());
			return NULL;
		}

		virtual std::any visitAssignVar(CouncilParser::AssignVarContext *ctx) override {
			return visitChildren(ctx);
		}

		virtual std::any visitDecFunc(CouncilParser::DecFuncContext *ctx) override {
			return visitChildren(ctx);
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
			return visitChildren(ctx);
		}

		virtual std::any visitIfChain(CouncilParser::IfChainContext *ctx) override {
			return visitChildren(ctx);
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
			return visitChildren(ctx);
		}

		virtual std::any visitCodeLine(CouncilParser::CodeLineContext *ctx) override {
			return visitChildren(ctx);
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
			
			throw ParsingException("visitLiteral, unreachable state.");
		}




};

