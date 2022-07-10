
// Generated from Council.g4 by ANTLR 4.10.1

#pragma once


#include "antlr4-runtime.h"
#include "CouncilListener.h"


/**
 * This class provides an empty implementation of CouncilListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  CouncilBaseListener : public CouncilListener {
public:

  virtual void enterParseFile(CouncilParser::ParseFileContext * /*ctx*/) override { }
  virtual void exitParseFile(CouncilParser::ParseFileContext * /*ctx*/) override { }

  virtual void enterImportStmt(CouncilParser::ImportStmtContext * /*ctx*/) override { }
  virtual void exitImportStmt(CouncilParser::ImportStmtContext * /*ctx*/) override { }

  virtual void enterTypeStr(CouncilParser::TypeStrContext * /*ctx*/) override { }
  virtual void exitTypeStr(CouncilParser::TypeStrContext * /*ctx*/) override { }

  virtual void enterTypeInt(CouncilParser::TypeIntContext * /*ctx*/) override { }
  virtual void exitTypeInt(CouncilParser::TypeIntContext * /*ctx*/) override { }

  virtual void enterTypeFloat(CouncilParser::TypeFloatContext * /*ctx*/) override { }
  virtual void exitTypeFloat(CouncilParser::TypeFloatContext * /*ctx*/) override { }

  virtual void enterTypeBool(CouncilParser::TypeBoolContext * /*ctx*/) override { }
  virtual void exitTypeBool(CouncilParser::TypeBoolContext * /*ctx*/) override { }

  virtual void enterDecVar(CouncilParser::DecVarContext * /*ctx*/) override { }
  virtual void exitDecVar(CouncilParser::DecVarContext * /*ctx*/) override { }

  virtual void enterAssignVar(CouncilParser::AssignVarContext * /*ctx*/) override { }
  virtual void exitAssignVar(CouncilParser::AssignVarContext * /*ctx*/) override { }

  virtual void enterDecFunc(CouncilParser::DecFuncContext * /*ctx*/) override { }
  virtual void exitDecFunc(CouncilParser::DecFuncContext * /*ctx*/) override { }

  virtual void enterPreMinusExpr(CouncilParser::PreMinusExprContext * /*ctx*/) override { }
  virtual void exitPreMinusExpr(CouncilParser::PreMinusExprContext * /*ctx*/) override { }

  virtual void enterPlusMinusExpr(CouncilParser::PlusMinusExprContext * /*ctx*/) override { }
  virtual void exitPlusMinusExpr(CouncilParser::PlusMinusExprContext * /*ctx*/) override { }

  virtual void enterObjExpr(CouncilParser::ObjExprContext * /*ctx*/) override { }
  virtual void exitObjExpr(CouncilParser::ObjExprContext * /*ctx*/) override { }

  virtual void enterMultiDivExpr(CouncilParser::MultiDivExprContext * /*ctx*/) override { }
  virtual void exitMultiDivExpr(CouncilParser::MultiDivExprContext * /*ctx*/) override { }

  virtual void enterCmpExpr(CouncilParser::CmpExprContext * /*ctx*/) override { }
  virtual void exitCmpExpr(CouncilParser::CmpExprContext * /*ctx*/) override { }

  virtual void enterFuncCall(CouncilParser::FuncCallContext * /*ctx*/) override { }
  virtual void exitFuncCall(CouncilParser::FuncCallContext * /*ctx*/) override { }

  virtual void enterReturnStmt(CouncilParser::ReturnStmtContext * /*ctx*/) override { }
  virtual void exitReturnStmt(CouncilParser::ReturnStmtContext * /*ctx*/) override { }

  virtual void enterIfChain(CouncilParser::IfChainContext * /*ctx*/) override { }
  virtual void exitIfChain(CouncilParser::IfChainContext * /*ctx*/) override { }

  virtual void enterWhileLoop(CouncilParser::WhileLoopContext * /*ctx*/) override { }
  virtual void exitWhileLoop(CouncilParser::WhileLoopContext * /*ctx*/) override { }

  virtual void enterForLoop(CouncilParser::ForLoopContext * /*ctx*/) override { }
  virtual void exitForLoop(CouncilParser::ForLoopContext * /*ctx*/) override { }

  virtual void enterObjId(CouncilParser::ObjIdContext * /*ctx*/) override { }
  virtual void exitObjId(CouncilParser::ObjIdContext * /*ctx*/) override { }

  virtual void enterObjLiteral(CouncilParser::ObjLiteralContext * /*ctx*/) override { }
  virtual void exitObjLiteral(CouncilParser::ObjLiteralContext * /*ctx*/) override { }

  virtual void enterParenExpr(CouncilParser::ParenExprContext * /*ctx*/) override { }
  virtual void exitParenExpr(CouncilParser::ParenExprContext * /*ctx*/) override { }

  virtual void enterBarExpr(CouncilParser::BarExprContext * /*ctx*/) override { }
  virtual void exitBarExpr(CouncilParser::BarExprContext * /*ctx*/) override { }

  virtual void enterFuncCallObj(CouncilParser::FuncCallObjContext * /*ctx*/) override { }
  virtual void exitFuncCallObj(CouncilParser::FuncCallObjContext * /*ctx*/) override { }

  virtual void enterCodeBlock(CouncilParser::CodeBlockContext * /*ctx*/) override { }
  virtual void exitCodeBlock(CouncilParser::CodeBlockContext * /*ctx*/) override { }

  virtual void enterCodeLine(CouncilParser::CodeLineContext * /*ctx*/) override { }
  virtual void exitCodeLine(CouncilParser::CodeLineContext * /*ctx*/) override { }

  virtual void enterLiteral(CouncilParser::LiteralContext * /*ctx*/) override { }
  virtual void exitLiteral(CouncilParser::LiteralContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

