
// Generated from Council.g4 by ANTLR 4.10.1

#pragma once


#include "antlr4-runtime.h"
#include "CouncilVisitor.h"


/**
 * This class provides an empty implementation of CouncilVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  CouncilBaseVisitor : public CouncilVisitor {
public:

  virtual std::any visitParseFile(CouncilParser::ParseFileContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitImportStmt(CouncilParser::ImportStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypeStr(CouncilParser::TypeStrContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypeInt(CouncilParser::TypeIntContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypeFloat(CouncilParser::TypeFloatContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypeBool(CouncilParser::TypeBoolContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDecVar(CouncilParser::DecVarContext *ctx) override {
    return visitChildren(ctx);
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
    return visitChildren(ctx);
  }

  virtual std::any visitObjExpr(CouncilParser::ObjExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMultiDivExpr(CouncilParser::MultiDivExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCmpExpr(CouncilParser::CmpExprContext *ctx) override {
    return visitChildren(ctx);
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
    return visitChildren(ctx);
  }


};

