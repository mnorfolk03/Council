
// Generated from Council.g4 by ANTLR 4.10.1

#pragma once


#include "antlr4-runtime.h"
#include "CouncilParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by CouncilParser.
 */
class  CouncilListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterParseFile(CouncilParser::ParseFileContext *ctx) = 0;
  virtual void exitParseFile(CouncilParser::ParseFileContext *ctx) = 0;

  virtual void enterImportStmt(CouncilParser::ImportStmtContext *ctx) = 0;
  virtual void exitImportStmt(CouncilParser::ImportStmtContext *ctx) = 0;

  virtual void enterTypeStr(CouncilParser::TypeStrContext *ctx) = 0;
  virtual void exitTypeStr(CouncilParser::TypeStrContext *ctx) = 0;

  virtual void enterTypeInt(CouncilParser::TypeIntContext *ctx) = 0;
  virtual void exitTypeInt(CouncilParser::TypeIntContext *ctx) = 0;

  virtual void enterTypeFloat(CouncilParser::TypeFloatContext *ctx) = 0;
  virtual void exitTypeFloat(CouncilParser::TypeFloatContext *ctx) = 0;

  virtual void enterTypeBool(CouncilParser::TypeBoolContext *ctx) = 0;
  virtual void exitTypeBool(CouncilParser::TypeBoolContext *ctx) = 0;

  virtual void enterDecVar(CouncilParser::DecVarContext *ctx) = 0;
  virtual void exitDecVar(CouncilParser::DecVarContext *ctx) = 0;

  virtual void enterAssignVar(CouncilParser::AssignVarContext *ctx) = 0;
  virtual void exitAssignVar(CouncilParser::AssignVarContext *ctx) = 0;

  virtual void enterDecFunc(CouncilParser::DecFuncContext *ctx) = 0;
  virtual void exitDecFunc(CouncilParser::DecFuncContext *ctx) = 0;

  virtual void enterPreMinusExpr(CouncilParser::PreMinusExprContext *ctx) = 0;
  virtual void exitPreMinusExpr(CouncilParser::PreMinusExprContext *ctx) = 0;

  virtual void enterPlusMinusExpr(CouncilParser::PlusMinusExprContext *ctx) = 0;
  virtual void exitPlusMinusExpr(CouncilParser::PlusMinusExprContext *ctx) = 0;

  virtual void enterObjExpr(CouncilParser::ObjExprContext *ctx) = 0;
  virtual void exitObjExpr(CouncilParser::ObjExprContext *ctx) = 0;

  virtual void enterMultiDivExpr(CouncilParser::MultiDivExprContext *ctx) = 0;
  virtual void exitMultiDivExpr(CouncilParser::MultiDivExprContext *ctx) = 0;

  virtual void enterCmpExpr(CouncilParser::CmpExprContext *ctx) = 0;
  virtual void exitCmpExpr(CouncilParser::CmpExprContext *ctx) = 0;

  virtual void enterFuncCall(CouncilParser::FuncCallContext *ctx) = 0;
  virtual void exitFuncCall(CouncilParser::FuncCallContext *ctx) = 0;

  virtual void enterReturnStmt(CouncilParser::ReturnStmtContext *ctx) = 0;
  virtual void exitReturnStmt(CouncilParser::ReturnStmtContext *ctx) = 0;

  virtual void enterIfChain(CouncilParser::IfChainContext *ctx) = 0;
  virtual void exitIfChain(CouncilParser::IfChainContext *ctx) = 0;

  virtual void enterWhileLoop(CouncilParser::WhileLoopContext *ctx) = 0;
  virtual void exitWhileLoop(CouncilParser::WhileLoopContext *ctx) = 0;

  virtual void enterForLoop(CouncilParser::ForLoopContext *ctx) = 0;
  virtual void exitForLoop(CouncilParser::ForLoopContext *ctx) = 0;

  virtual void enterObjId(CouncilParser::ObjIdContext *ctx) = 0;
  virtual void exitObjId(CouncilParser::ObjIdContext *ctx) = 0;

  virtual void enterObjLiteral(CouncilParser::ObjLiteralContext *ctx) = 0;
  virtual void exitObjLiteral(CouncilParser::ObjLiteralContext *ctx) = 0;

  virtual void enterParenExpr(CouncilParser::ParenExprContext *ctx) = 0;
  virtual void exitParenExpr(CouncilParser::ParenExprContext *ctx) = 0;

  virtual void enterBarExpr(CouncilParser::BarExprContext *ctx) = 0;
  virtual void exitBarExpr(CouncilParser::BarExprContext *ctx) = 0;

  virtual void enterFuncCallObj(CouncilParser::FuncCallObjContext *ctx) = 0;
  virtual void exitFuncCallObj(CouncilParser::FuncCallObjContext *ctx) = 0;

  virtual void enterCodeBlock(CouncilParser::CodeBlockContext *ctx) = 0;
  virtual void exitCodeBlock(CouncilParser::CodeBlockContext *ctx) = 0;

  virtual void enterCodeLine(CouncilParser::CodeLineContext *ctx) = 0;
  virtual void exitCodeLine(CouncilParser::CodeLineContext *ctx) = 0;

  virtual void enterLiteral(CouncilParser::LiteralContext *ctx) = 0;
  virtual void exitLiteral(CouncilParser::LiteralContext *ctx) = 0;


};

