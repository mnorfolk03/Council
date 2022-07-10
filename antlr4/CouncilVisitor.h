
// Generated from Council.g4 by ANTLR 4.10.1

#pragma once


#include "antlr4-runtime.h"
#include "CouncilParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by CouncilParser.
 */
class  CouncilVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by CouncilParser.
   */
    virtual std::any visitParseFile(CouncilParser::ParseFileContext *context) = 0;

    virtual std::any visitImportStmt(CouncilParser::ImportStmtContext *context) = 0;

    virtual std::any visitTypeStr(CouncilParser::TypeStrContext *context) = 0;

    virtual std::any visitTypeInt(CouncilParser::TypeIntContext *context) = 0;

    virtual std::any visitTypeFloat(CouncilParser::TypeFloatContext *context) = 0;

    virtual std::any visitTypeBool(CouncilParser::TypeBoolContext *context) = 0;

    virtual std::any visitDecVar(CouncilParser::DecVarContext *context) = 0;

    virtual std::any visitAssignVar(CouncilParser::AssignVarContext *context) = 0;

    virtual std::any visitDecFunc(CouncilParser::DecFuncContext *context) = 0;

    virtual std::any visitPreMinusExpr(CouncilParser::PreMinusExprContext *context) = 0;

    virtual std::any visitPlusMinusExpr(CouncilParser::PlusMinusExprContext *context) = 0;

    virtual std::any visitObjExpr(CouncilParser::ObjExprContext *context) = 0;

    virtual std::any visitMultiDivExpr(CouncilParser::MultiDivExprContext *context) = 0;

    virtual std::any visitCmpExpr(CouncilParser::CmpExprContext *context) = 0;

    virtual std::any visitFuncCall(CouncilParser::FuncCallContext *context) = 0;

    virtual std::any visitReturnStmt(CouncilParser::ReturnStmtContext *context) = 0;

    virtual std::any visitIfChain(CouncilParser::IfChainContext *context) = 0;

    virtual std::any visitWhileLoop(CouncilParser::WhileLoopContext *context) = 0;

    virtual std::any visitForLoop(CouncilParser::ForLoopContext *context) = 0;

    virtual std::any visitObjId(CouncilParser::ObjIdContext *context) = 0;

    virtual std::any visitObjLiteral(CouncilParser::ObjLiteralContext *context) = 0;

    virtual std::any visitParenExpr(CouncilParser::ParenExprContext *context) = 0;

    virtual std::any visitBarExpr(CouncilParser::BarExprContext *context) = 0;

    virtual std::any visitFuncCallObj(CouncilParser::FuncCallObjContext *context) = 0;

    virtual std::any visitCodeBlock(CouncilParser::CodeBlockContext *context) = 0;

    virtual std::any visitCodeLine(CouncilParser::CodeLineContext *context) = 0;

    virtual std::any visitLiteral(CouncilParser::LiteralContext *context) = 0;


};

