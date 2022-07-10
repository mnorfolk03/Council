
// Generated from Council.g4 by ANTLR 4.10.1


#include "CouncilListener.h"
#include "CouncilVisitor.h"

#include "CouncilParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct CouncilParserStaticData final {
  CouncilParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  CouncilParserStaticData(const CouncilParserStaticData&) = delete;
  CouncilParserStaticData(CouncilParserStaticData&&) = delete;
  CouncilParserStaticData& operator=(const CouncilParserStaticData&) = delete;
  CouncilParserStaticData& operator=(CouncilParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

std::once_flag councilParserOnceFlag;
CouncilParserStaticData *councilParserStaticData = nullptr;

void councilParserInitialize() {
  assert(councilParserStaticData == nullptr);
  auto staticData = std::make_unique<CouncilParserStaticData>(
    std::vector<std::string>{
      "parseFile", "importStmt", "type", "decVar", "assignVar", "decFunc", 
      "expr", "funcCall", "returnStmt", "ifChain", "whileLoop", "forLoop", 
      "obj", "codeBlock", "codeLine", "literal"
    },
    std::vector<std::string>{
      "", "'.'", "','", "';'", "'String'", "'Int'", "'Float'", "'Bool'", 
      "'Func'", "'import'", "'return'", "'if'", "'elif'", "'else'", "'while'", 
      "'for'", "'break'", "", "", "", "'TRUE'", "'FALSE'", "", "", "", "", 
      "'{'", "'}'", "'('", "')'", "'|'", "'+'", "'-'", "'*'", "'/'", "'//'", 
      "'%'", "'='", "'<'", "'<='", "'>'", "'>='", "'=='", "'!='"
    },
    std::vector<std::string>{
      "", "PERIOD", "COMMA", "SEMICOLON", "STR_T", "INT_T", "FLOAT_T", "BOOL_T", 
      "FUNC", "EXTERN", "RETURN", "IF", "ELIF", "ELSE", "WHILE", "FOR", 
      "BREAK", "ID", "INT", "FLOAT", "TRUE", "FALSE", "STRING", "COMMENT", 
      "BLOCK_COMMENT", "WHITESPACE", "OPEN_BRACE", "CLOSE_BRACE", "OPEN_PAREN", 
      "CLOSE_PAREN", "BAR", "PLUS", "MINUS", "MULTI", "FLOAT_DIV", "INT_DIV", 
      "MOD", "EQUALS", "LT", "LT_EQ", "GT", "GT_EQ", "EQ", "NEQ"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,43,212,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,1,0,1,0,5,0,35,8,0,10,0,12,0,38,9,0,1,0,5,0,41,8,0,10,0,
  	12,0,44,9,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,5,1,55,8,1,10,1,12,1,
  	58,9,1,3,1,60,8,1,1,1,1,1,1,1,1,2,1,2,1,2,1,2,3,2,69,8,2,1,3,1,3,1,3,
  	1,4,1,4,1,4,1,4,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,5,5,86,8,5,10,5,12,5,
  	89,9,5,1,5,1,5,1,5,1,6,1,6,1,6,1,6,3,6,98,8,6,1,6,1,6,1,6,1,6,1,6,1,6,
  	1,6,1,6,1,6,5,6,109,8,6,10,6,12,6,112,9,6,1,7,1,7,1,7,1,7,1,7,5,7,119,
  	8,7,10,7,12,7,122,9,7,3,7,124,8,7,1,7,1,7,1,8,1,8,1,8,1,9,1,9,1,9,1,9,
  	1,9,1,9,1,9,1,9,1,9,1,9,1,9,5,9,142,8,9,10,9,12,9,145,9,9,1,9,1,9,3,9,
  	149,8,9,1,10,1,10,1,10,1,10,1,10,1,10,1,10,3,10,158,8,10,1,11,1,11,1,
  	11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,3,11,171,8,11,1,12,1,12,1,
  	12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,3,12,184,8,12,1,13,1,13,5,
  	13,188,8,13,10,13,12,13,191,9,13,1,13,1,13,1,14,1,14,1,14,1,14,1,14,1,
  	14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,3,14,208,8,14,1,15,1,15,1,15,0,
  	1,12,16,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,0,4,1,0,33,36,1,0,
  	31,32,1,0,38,43,1,0,18,22,222,0,32,1,0,0,0,2,48,1,0,0,0,4,68,1,0,0,0,
  	6,70,1,0,0,0,8,73,1,0,0,0,10,77,1,0,0,0,12,97,1,0,0,0,14,113,1,0,0,0,
  	16,127,1,0,0,0,18,130,1,0,0,0,20,150,1,0,0,0,22,159,1,0,0,0,24,183,1,
  	0,0,0,26,185,1,0,0,0,28,207,1,0,0,0,30,209,1,0,0,0,32,36,5,26,0,0,33,
  	35,3,2,1,0,34,33,1,0,0,0,35,38,1,0,0,0,36,34,1,0,0,0,36,37,1,0,0,0,37,
  	42,1,0,0,0,38,36,1,0,0,0,39,41,3,10,5,0,40,39,1,0,0,0,41,44,1,0,0,0,42,
  	40,1,0,0,0,42,43,1,0,0,0,43,45,1,0,0,0,44,42,1,0,0,0,45,46,5,27,0,0,46,
  	47,3,26,13,0,47,1,1,0,0,0,48,49,5,9,0,0,49,50,5,17,0,0,50,59,5,28,0,0,
  	51,56,3,4,2,0,52,53,5,2,0,0,53,55,3,4,2,0,54,52,1,0,0,0,55,58,1,0,0,0,
  	56,54,1,0,0,0,56,57,1,0,0,0,57,60,1,0,0,0,58,56,1,0,0,0,59,51,1,0,0,0,
  	59,60,1,0,0,0,60,61,1,0,0,0,61,62,5,29,0,0,62,63,5,3,0,0,63,3,1,0,0,0,
  	64,69,5,4,0,0,65,69,5,5,0,0,66,69,5,6,0,0,67,69,5,7,0,0,68,64,1,0,0,0,
  	68,65,1,0,0,0,68,66,1,0,0,0,68,67,1,0,0,0,69,5,1,0,0,0,70,71,3,4,2,0,
  	71,72,3,8,4,0,72,7,1,0,0,0,73,74,5,17,0,0,74,75,5,37,0,0,75,76,3,12,6,
  	0,76,9,1,0,0,0,77,78,5,8,0,0,78,79,5,17,0,0,79,80,5,28,0,0,80,87,3,4,
  	2,0,81,82,5,2,0,0,82,83,3,4,2,0,83,84,5,17,0,0,84,86,1,0,0,0,85,81,1,
  	0,0,0,86,89,1,0,0,0,87,85,1,0,0,0,87,88,1,0,0,0,88,90,1,0,0,0,89,87,1,
  	0,0,0,90,91,5,29,0,0,91,92,3,26,13,0,92,11,1,0,0,0,93,94,6,6,-1,0,94,
  	98,3,24,12,0,95,96,5,32,0,0,96,98,3,12,6,4,97,93,1,0,0,0,97,95,1,0,0,
  	0,98,110,1,0,0,0,99,100,10,3,0,0,100,101,7,0,0,0,101,109,3,12,6,4,102,
  	103,10,2,0,0,103,104,7,1,0,0,104,109,3,12,6,3,105,106,10,1,0,0,106,107,
  	7,2,0,0,107,109,3,12,6,2,108,99,1,0,0,0,108,102,1,0,0,0,108,105,1,0,0,
  	0,109,112,1,0,0,0,110,108,1,0,0,0,110,111,1,0,0,0,111,13,1,0,0,0,112,
  	110,1,0,0,0,113,114,5,17,0,0,114,123,5,28,0,0,115,120,3,12,6,0,116,117,
  	5,2,0,0,117,119,3,12,6,0,118,116,1,0,0,0,119,122,1,0,0,0,120,118,1,0,
  	0,0,120,121,1,0,0,0,121,124,1,0,0,0,122,120,1,0,0,0,123,115,1,0,0,0,123,
  	124,1,0,0,0,124,125,1,0,0,0,125,126,5,29,0,0,126,15,1,0,0,0,127,128,5,
  	10,0,0,128,129,3,12,6,0,129,17,1,0,0,0,130,131,5,11,0,0,131,132,5,28,
  	0,0,132,133,3,12,6,0,133,134,5,29,0,0,134,143,3,26,13,0,135,136,5,12,
  	0,0,136,137,5,28,0,0,137,138,3,12,6,0,138,139,5,29,0,0,139,140,3,26,13,
  	0,140,142,1,0,0,0,141,135,1,0,0,0,142,145,1,0,0,0,143,141,1,0,0,0,143,
  	144,1,0,0,0,144,148,1,0,0,0,145,143,1,0,0,0,146,147,5,13,0,0,147,149,
  	3,26,13,0,148,146,1,0,0,0,148,149,1,0,0,0,149,19,1,0,0,0,150,151,5,14,
  	0,0,151,152,5,28,0,0,152,153,3,12,6,0,153,154,5,29,0,0,154,157,3,26,13,
  	0,155,156,5,13,0,0,156,158,3,26,13,0,157,155,1,0,0,0,157,158,1,0,0,0,
  	158,21,1,0,0,0,159,160,5,15,0,0,160,161,5,28,0,0,161,162,3,12,6,0,162,
  	163,5,3,0,0,163,164,3,12,6,0,164,165,5,3,0,0,165,166,3,12,6,0,166,167,
  	5,29,0,0,167,170,3,26,13,0,168,169,5,13,0,0,169,171,3,26,13,0,170,168,
  	1,0,0,0,170,171,1,0,0,0,171,23,1,0,0,0,172,184,5,17,0,0,173,184,3,30,
  	15,0,174,175,5,28,0,0,175,176,3,12,6,0,176,177,5,29,0,0,177,184,1,0,0,
  	0,178,179,5,30,0,0,179,180,3,12,6,0,180,181,5,30,0,0,181,184,1,0,0,0,
  	182,184,3,14,7,0,183,172,1,0,0,0,183,173,1,0,0,0,183,174,1,0,0,0,183,
  	178,1,0,0,0,183,182,1,0,0,0,184,25,1,0,0,0,185,189,5,26,0,0,186,188,3,
  	28,14,0,187,186,1,0,0,0,188,191,1,0,0,0,189,187,1,0,0,0,189,190,1,0,0,
  	0,190,192,1,0,0,0,191,189,1,0,0,0,192,193,5,27,0,0,193,27,1,0,0,0,194,
  	195,3,6,3,0,195,196,5,3,0,0,196,208,1,0,0,0,197,198,3,8,4,0,198,199,5,
  	3,0,0,199,208,1,0,0,0,200,201,3,14,7,0,201,202,5,3,0,0,202,208,1,0,0,
  	0,203,204,3,16,8,0,204,205,5,3,0,0,205,208,1,0,0,0,206,208,3,18,9,0,207,
  	194,1,0,0,0,207,197,1,0,0,0,207,200,1,0,0,0,207,203,1,0,0,0,207,206,1,
  	0,0,0,208,29,1,0,0,0,209,210,7,3,0,0,210,31,1,0,0,0,18,36,42,56,59,68,
  	87,97,108,110,120,123,143,148,157,170,183,189,207
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  councilParserStaticData = staticData.release();
}

}

CouncilParser::CouncilParser(TokenStream *input) : CouncilParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

CouncilParser::CouncilParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  CouncilParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *councilParserStaticData->atn, councilParserStaticData->decisionToDFA, councilParserStaticData->sharedContextCache, options);
}

CouncilParser::~CouncilParser() {
  delete _interpreter;
}

const atn::ATN& CouncilParser::getATN() const {
  return *councilParserStaticData->atn;
}

std::string CouncilParser::getGrammarFileName() const {
  return "Council.g4";
}

const std::vector<std::string>& CouncilParser::getRuleNames() const {
  return councilParserStaticData->ruleNames;
}

const dfa::Vocabulary& CouncilParser::getVocabulary() const {
  return councilParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView CouncilParser::getSerializedATN() const {
  return councilParserStaticData->serializedATN;
}


//----------------- ParseFileContext ------------------------------------------------------------------

CouncilParser::ParseFileContext::ParseFileContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CouncilParser::ParseFileContext::OPEN_BRACE() {
  return getToken(CouncilParser::OPEN_BRACE, 0);
}

tree::TerminalNode* CouncilParser::ParseFileContext::CLOSE_BRACE() {
  return getToken(CouncilParser::CLOSE_BRACE, 0);
}

CouncilParser::CodeBlockContext* CouncilParser::ParseFileContext::codeBlock() {
  return getRuleContext<CouncilParser::CodeBlockContext>(0);
}

std::vector<CouncilParser::ImportStmtContext *> CouncilParser::ParseFileContext::importStmt() {
  return getRuleContexts<CouncilParser::ImportStmtContext>();
}

CouncilParser::ImportStmtContext* CouncilParser::ParseFileContext::importStmt(size_t i) {
  return getRuleContext<CouncilParser::ImportStmtContext>(i);
}

std::vector<CouncilParser::DecFuncContext *> CouncilParser::ParseFileContext::decFunc() {
  return getRuleContexts<CouncilParser::DecFuncContext>();
}

CouncilParser::DecFuncContext* CouncilParser::ParseFileContext::decFunc(size_t i) {
  return getRuleContext<CouncilParser::DecFuncContext>(i);
}


size_t CouncilParser::ParseFileContext::getRuleIndex() const {
  return CouncilParser::RuleParseFile;
}

void CouncilParser::ParseFileContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CouncilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParseFile(this);
}

void CouncilParser::ParseFileContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CouncilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParseFile(this);
}


std::any CouncilParser::ParseFileContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CouncilVisitor*>(visitor))
    return parserVisitor->visitParseFile(this);
  else
    return visitor->visitChildren(this);
}

CouncilParser::ParseFileContext* CouncilParser::parseFile() {
  ParseFileContext *_localctx = _tracker.createInstance<ParseFileContext>(_ctx, getState());
  enterRule(_localctx, 0, CouncilParser::RuleParseFile);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(32);
    match(CouncilParser::OPEN_BRACE);
    setState(36);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CouncilParser::EXTERN) {
      setState(33);
      importStmt();
      setState(38);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(42);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CouncilParser::FUNC) {
      setState(39);
      decFunc();
      setState(44);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(45);
    match(CouncilParser::CLOSE_BRACE);
    setState(46);
    codeBlock();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ImportStmtContext ------------------------------------------------------------------

CouncilParser::ImportStmtContext::ImportStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CouncilParser::ImportStmtContext::EXTERN() {
  return getToken(CouncilParser::EXTERN, 0);
}

tree::TerminalNode* CouncilParser::ImportStmtContext::ID() {
  return getToken(CouncilParser::ID, 0);
}

tree::TerminalNode* CouncilParser::ImportStmtContext::OPEN_PAREN() {
  return getToken(CouncilParser::OPEN_PAREN, 0);
}

tree::TerminalNode* CouncilParser::ImportStmtContext::CLOSE_PAREN() {
  return getToken(CouncilParser::CLOSE_PAREN, 0);
}

tree::TerminalNode* CouncilParser::ImportStmtContext::SEMICOLON() {
  return getToken(CouncilParser::SEMICOLON, 0);
}

std::vector<CouncilParser::TypeContext *> CouncilParser::ImportStmtContext::type() {
  return getRuleContexts<CouncilParser::TypeContext>();
}

CouncilParser::TypeContext* CouncilParser::ImportStmtContext::type(size_t i) {
  return getRuleContext<CouncilParser::TypeContext>(i);
}

std::vector<tree::TerminalNode *> CouncilParser::ImportStmtContext::COMMA() {
  return getTokens(CouncilParser::COMMA);
}

tree::TerminalNode* CouncilParser::ImportStmtContext::COMMA(size_t i) {
  return getToken(CouncilParser::COMMA, i);
}


size_t CouncilParser::ImportStmtContext::getRuleIndex() const {
  return CouncilParser::RuleImportStmt;
}

void CouncilParser::ImportStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CouncilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImportStmt(this);
}

void CouncilParser::ImportStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CouncilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImportStmt(this);
}


std::any CouncilParser::ImportStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CouncilVisitor*>(visitor))
    return parserVisitor->visitImportStmt(this);
  else
    return visitor->visitChildren(this);
}

CouncilParser::ImportStmtContext* CouncilParser::importStmt() {
  ImportStmtContext *_localctx = _tracker.createInstance<ImportStmtContext>(_ctx, getState());
  enterRule(_localctx, 2, CouncilParser::RuleImportStmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(48);
    match(CouncilParser::EXTERN);
    setState(49);
    match(CouncilParser::ID);
    setState(50);
    match(CouncilParser::OPEN_PAREN);
    setState(59);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CouncilParser::STR_T)
      | (1ULL << CouncilParser::INT_T)
      | (1ULL << CouncilParser::FLOAT_T)
      | (1ULL << CouncilParser::BOOL_T))) != 0)) {
      setState(51);
      type();
      setState(56);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == CouncilParser::COMMA) {
        setState(52);
        match(CouncilParser::COMMA);
        setState(53);
        type();
        setState(58);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(61);
    match(CouncilParser::CLOSE_PAREN);
    setState(62);
    match(CouncilParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

CouncilParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CouncilParser::TypeContext::getRuleIndex() const {
  return CouncilParser::RuleType;
}

void CouncilParser::TypeContext::copyFrom(TypeContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- TypeStrContext ------------------------------------------------------------------

tree::TerminalNode* CouncilParser::TypeStrContext::STR_T() {
  return getToken(CouncilParser::STR_T, 0);
}

CouncilParser::TypeStrContext::TypeStrContext(TypeContext *ctx) { copyFrom(ctx); }

void CouncilParser::TypeStrContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CouncilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeStr(this);
}
void CouncilParser::TypeStrContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CouncilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeStr(this);
}

std::any CouncilParser::TypeStrContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CouncilVisitor*>(visitor))
    return parserVisitor->visitTypeStr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- TypeIntContext ------------------------------------------------------------------

tree::TerminalNode* CouncilParser::TypeIntContext::INT_T() {
  return getToken(CouncilParser::INT_T, 0);
}

CouncilParser::TypeIntContext::TypeIntContext(TypeContext *ctx) { copyFrom(ctx); }

void CouncilParser::TypeIntContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CouncilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeInt(this);
}
void CouncilParser::TypeIntContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CouncilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeInt(this);
}

std::any CouncilParser::TypeIntContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CouncilVisitor*>(visitor))
    return parserVisitor->visitTypeInt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- TypeFloatContext ------------------------------------------------------------------

tree::TerminalNode* CouncilParser::TypeFloatContext::FLOAT_T() {
  return getToken(CouncilParser::FLOAT_T, 0);
}

CouncilParser::TypeFloatContext::TypeFloatContext(TypeContext *ctx) { copyFrom(ctx); }

void CouncilParser::TypeFloatContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CouncilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeFloat(this);
}
void CouncilParser::TypeFloatContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CouncilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeFloat(this);
}

std::any CouncilParser::TypeFloatContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CouncilVisitor*>(visitor))
    return parserVisitor->visitTypeFloat(this);
  else
    return visitor->visitChildren(this);
}
//----------------- TypeBoolContext ------------------------------------------------------------------

tree::TerminalNode* CouncilParser::TypeBoolContext::BOOL_T() {
  return getToken(CouncilParser::BOOL_T, 0);
}

CouncilParser::TypeBoolContext::TypeBoolContext(TypeContext *ctx) { copyFrom(ctx); }

void CouncilParser::TypeBoolContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CouncilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeBool(this);
}
void CouncilParser::TypeBoolContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CouncilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeBool(this);
}

std::any CouncilParser::TypeBoolContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CouncilVisitor*>(visitor))
    return parserVisitor->visitTypeBool(this);
  else
    return visitor->visitChildren(this);
}
CouncilParser::TypeContext* CouncilParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 4, CouncilParser::RuleType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(68);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CouncilParser::STR_T: {
        _localctx = _tracker.createInstance<CouncilParser::TypeStrContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(64);
        match(CouncilParser::STR_T);
        break;
      }

      case CouncilParser::INT_T: {
        _localctx = _tracker.createInstance<CouncilParser::TypeIntContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(65);
        match(CouncilParser::INT_T);
        break;
      }

      case CouncilParser::FLOAT_T: {
        _localctx = _tracker.createInstance<CouncilParser::TypeFloatContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(66);
        match(CouncilParser::FLOAT_T);
        break;
      }

      case CouncilParser::BOOL_T: {
        _localctx = _tracker.createInstance<CouncilParser::TypeBoolContext>(_localctx);
        enterOuterAlt(_localctx, 4);
        setState(67);
        match(CouncilParser::BOOL_T);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DecVarContext ------------------------------------------------------------------

CouncilParser::DecVarContext::DecVarContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CouncilParser::TypeContext* CouncilParser::DecVarContext::type() {
  return getRuleContext<CouncilParser::TypeContext>(0);
}

CouncilParser::AssignVarContext* CouncilParser::DecVarContext::assignVar() {
  return getRuleContext<CouncilParser::AssignVarContext>(0);
}


size_t CouncilParser::DecVarContext::getRuleIndex() const {
  return CouncilParser::RuleDecVar;
}

void CouncilParser::DecVarContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CouncilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDecVar(this);
}

void CouncilParser::DecVarContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CouncilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDecVar(this);
}


std::any CouncilParser::DecVarContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CouncilVisitor*>(visitor))
    return parserVisitor->visitDecVar(this);
  else
    return visitor->visitChildren(this);
}

CouncilParser::DecVarContext* CouncilParser::decVar() {
  DecVarContext *_localctx = _tracker.createInstance<DecVarContext>(_ctx, getState());
  enterRule(_localctx, 6, CouncilParser::RuleDecVar);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(70);
    type();
    setState(71);
    assignVar();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignVarContext ------------------------------------------------------------------

CouncilParser::AssignVarContext::AssignVarContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CouncilParser::AssignVarContext::ID() {
  return getToken(CouncilParser::ID, 0);
}

tree::TerminalNode* CouncilParser::AssignVarContext::EQUALS() {
  return getToken(CouncilParser::EQUALS, 0);
}

CouncilParser::ExprContext* CouncilParser::AssignVarContext::expr() {
  return getRuleContext<CouncilParser::ExprContext>(0);
}


size_t CouncilParser::AssignVarContext::getRuleIndex() const {
  return CouncilParser::RuleAssignVar;
}

void CouncilParser::AssignVarContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CouncilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignVar(this);
}

void CouncilParser::AssignVarContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CouncilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignVar(this);
}


std::any CouncilParser::AssignVarContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CouncilVisitor*>(visitor))
    return parserVisitor->visitAssignVar(this);
  else
    return visitor->visitChildren(this);
}

CouncilParser::AssignVarContext* CouncilParser::assignVar() {
  AssignVarContext *_localctx = _tracker.createInstance<AssignVarContext>(_ctx, getState());
  enterRule(_localctx, 8, CouncilParser::RuleAssignVar);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(73);
    match(CouncilParser::ID);
    setState(74);
    match(CouncilParser::EQUALS);
    setState(75);
    expr(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DecFuncContext ------------------------------------------------------------------

CouncilParser::DecFuncContext::DecFuncContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CouncilParser::DecFuncContext::FUNC() {
  return getToken(CouncilParser::FUNC, 0);
}

std::vector<tree::TerminalNode *> CouncilParser::DecFuncContext::ID() {
  return getTokens(CouncilParser::ID);
}

tree::TerminalNode* CouncilParser::DecFuncContext::ID(size_t i) {
  return getToken(CouncilParser::ID, i);
}

tree::TerminalNode* CouncilParser::DecFuncContext::OPEN_PAREN() {
  return getToken(CouncilParser::OPEN_PAREN, 0);
}

std::vector<CouncilParser::TypeContext *> CouncilParser::DecFuncContext::type() {
  return getRuleContexts<CouncilParser::TypeContext>();
}

CouncilParser::TypeContext* CouncilParser::DecFuncContext::type(size_t i) {
  return getRuleContext<CouncilParser::TypeContext>(i);
}

tree::TerminalNode* CouncilParser::DecFuncContext::CLOSE_PAREN() {
  return getToken(CouncilParser::CLOSE_PAREN, 0);
}

CouncilParser::CodeBlockContext* CouncilParser::DecFuncContext::codeBlock() {
  return getRuleContext<CouncilParser::CodeBlockContext>(0);
}

std::vector<tree::TerminalNode *> CouncilParser::DecFuncContext::COMMA() {
  return getTokens(CouncilParser::COMMA);
}

tree::TerminalNode* CouncilParser::DecFuncContext::COMMA(size_t i) {
  return getToken(CouncilParser::COMMA, i);
}


size_t CouncilParser::DecFuncContext::getRuleIndex() const {
  return CouncilParser::RuleDecFunc;
}

void CouncilParser::DecFuncContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CouncilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDecFunc(this);
}

void CouncilParser::DecFuncContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CouncilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDecFunc(this);
}


std::any CouncilParser::DecFuncContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CouncilVisitor*>(visitor))
    return parserVisitor->visitDecFunc(this);
  else
    return visitor->visitChildren(this);
}

CouncilParser::DecFuncContext* CouncilParser::decFunc() {
  DecFuncContext *_localctx = _tracker.createInstance<DecFuncContext>(_ctx, getState());
  enterRule(_localctx, 10, CouncilParser::RuleDecFunc);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(77);
    match(CouncilParser::FUNC);
    setState(78);
    match(CouncilParser::ID);
    setState(79);
    match(CouncilParser::OPEN_PAREN);
    setState(80);
    type();
    setState(87);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CouncilParser::COMMA) {
      setState(81);
      match(CouncilParser::COMMA);
      setState(82);
      type();
      setState(83);
      match(CouncilParser::ID);
      setState(89);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(90);
    match(CouncilParser::CLOSE_PAREN);
    setState(91);
    codeBlock();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

CouncilParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CouncilParser::ExprContext::getRuleIndex() const {
  return CouncilParser::RuleExpr;
}

void CouncilParser::ExprContext::copyFrom(ExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- PreMinusExprContext ------------------------------------------------------------------

tree::TerminalNode* CouncilParser::PreMinusExprContext::MINUS() {
  return getToken(CouncilParser::MINUS, 0);
}

CouncilParser::ExprContext* CouncilParser::PreMinusExprContext::expr() {
  return getRuleContext<CouncilParser::ExprContext>(0);
}

CouncilParser::PreMinusExprContext::PreMinusExprContext(ExprContext *ctx) { copyFrom(ctx); }

void CouncilParser::PreMinusExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CouncilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPreMinusExpr(this);
}
void CouncilParser::PreMinusExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CouncilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPreMinusExpr(this);
}

std::any CouncilParser::PreMinusExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CouncilVisitor*>(visitor))
    return parserVisitor->visitPreMinusExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PlusMinusExprContext ------------------------------------------------------------------

std::vector<CouncilParser::ExprContext *> CouncilParser::PlusMinusExprContext::expr() {
  return getRuleContexts<CouncilParser::ExprContext>();
}

CouncilParser::ExprContext* CouncilParser::PlusMinusExprContext::expr(size_t i) {
  return getRuleContext<CouncilParser::ExprContext>(i);
}

tree::TerminalNode* CouncilParser::PlusMinusExprContext::PLUS() {
  return getToken(CouncilParser::PLUS, 0);
}

tree::TerminalNode* CouncilParser::PlusMinusExprContext::MINUS() {
  return getToken(CouncilParser::MINUS, 0);
}

CouncilParser::PlusMinusExprContext::PlusMinusExprContext(ExprContext *ctx) { copyFrom(ctx); }

void CouncilParser::PlusMinusExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CouncilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPlusMinusExpr(this);
}
void CouncilParser::PlusMinusExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CouncilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPlusMinusExpr(this);
}

std::any CouncilParser::PlusMinusExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CouncilVisitor*>(visitor))
    return parserVisitor->visitPlusMinusExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ObjExprContext ------------------------------------------------------------------

CouncilParser::ObjContext* CouncilParser::ObjExprContext::obj() {
  return getRuleContext<CouncilParser::ObjContext>(0);
}

CouncilParser::ObjExprContext::ObjExprContext(ExprContext *ctx) { copyFrom(ctx); }

void CouncilParser::ObjExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CouncilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterObjExpr(this);
}
void CouncilParser::ObjExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CouncilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitObjExpr(this);
}

std::any CouncilParser::ObjExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CouncilVisitor*>(visitor))
    return parserVisitor->visitObjExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MultiDivExprContext ------------------------------------------------------------------

std::vector<CouncilParser::ExprContext *> CouncilParser::MultiDivExprContext::expr() {
  return getRuleContexts<CouncilParser::ExprContext>();
}

CouncilParser::ExprContext* CouncilParser::MultiDivExprContext::expr(size_t i) {
  return getRuleContext<CouncilParser::ExprContext>(i);
}

tree::TerminalNode* CouncilParser::MultiDivExprContext::MULTI() {
  return getToken(CouncilParser::MULTI, 0);
}

tree::TerminalNode* CouncilParser::MultiDivExprContext::FLOAT_DIV() {
  return getToken(CouncilParser::FLOAT_DIV, 0);
}

tree::TerminalNode* CouncilParser::MultiDivExprContext::INT_DIV() {
  return getToken(CouncilParser::INT_DIV, 0);
}

tree::TerminalNode* CouncilParser::MultiDivExprContext::MOD() {
  return getToken(CouncilParser::MOD, 0);
}

CouncilParser::MultiDivExprContext::MultiDivExprContext(ExprContext *ctx) { copyFrom(ctx); }

void CouncilParser::MultiDivExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CouncilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMultiDivExpr(this);
}
void CouncilParser::MultiDivExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CouncilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMultiDivExpr(this);
}

std::any CouncilParser::MultiDivExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CouncilVisitor*>(visitor))
    return parserVisitor->visitMultiDivExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CmpExprContext ------------------------------------------------------------------

std::vector<CouncilParser::ExprContext *> CouncilParser::CmpExprContext::expr() {
  return getRuleContexts<CouncilParser::ExprContext>();
}

CouncilParser::ExprContext* CouncilParser::CmpExprContext::expr(size_t i) {
  return getRuleContext<CouncilParser::ExprContext>(i);
}

tree::TerminalNode* CouncilParser::CmpExprContext::EQ() {
  return getToken(CouncilParser::EQ, 0);
}

tree::TerminalNode* CouncilParser::CmpExprContext::NEQ() {
  return getToken(CouncilParser::NEQ, 0);
}

tree::TerminalNode* CouncilParser::CmpExprContext::LT() {
  return getToken(CouncilParser::LT, 0);
}

tree::TerminalNode* CouncilParser::CmpExprContext::GT() {
  return getToken(CouncilParser::GT, 0);
}

tree::TerminalNode* CouncilParser::CmpExprContext::LT_EQ() {
  return getToken(CouncilParser::LT_EQ, 0);
}

tree::TerminalNode* CouncilParser::CmpExprContext::GT_EQ() {
  return getToken(CouncilParser::GT_EQ, 0);
}

CouncilParser::CmpExprContext::CmpExprContext(ExprContext *ctx) { copyFrom(ctx); }

void CouncilParser::CmpExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CouncilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCmpExpr(this);
}
void CouncilParser::CmpExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CouncilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCmpExpr(this);
}

std::any CouncilParser::CmpExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CouncilVisitor*>(visitor))
    return parserVisitor->visitCmpExpr(this);
  else
    return visitor->visitChildren(this);
}

CouncilParser::ExprContext* CouncilParser::expr() {
   return expr(0);
}

CouncilParser::ExprContext* CouncilParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CouncilParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  CouncilParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 12;
  enterRecursionRule(_localctx, 12, CouncilParser::RuleExpr, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(97);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CouncilParser::ID:
      case CouncilParser::INT:
      case CouncilParser::FLOAT:
      case CouncilParser::TRUE:
      case CouncilParser::FALSE:
      case CouncilParser::STRING:
      case CouncilParser::OPEN_PAREN:
      case CouncilParser::BAR: {
        _localctx = _tracker.createInstance<ObjExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(94);
        obj();
        break;
      }

      case CouncilParser::MINUS: {
        _localctx = _tracker.createInstance<PreMinusExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(95);
        match(CouncilParser::MINUS);
        setState(96);
        expr(4);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(110);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(108);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<MultiDivExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(99);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(100);
          antlrcpp::downCast<MultiDivExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << CouncilParser::MULTI)
            | (1ULL << CouncilParser::FLOAT_DIV)
            | (1ULL << CouncilParser::INT_DIV)
            | (1ULL << CouncilParser::MOD))) != 0))) {
            antlrcpp::downCast<MultiDivExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(101);
          expr(4);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<PlusMinusExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(102);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(103);
          antlrcpp::downCast<PlusMinusExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == CouncilParser::PLUS

          || _la == CouncilParser::MINUS)) {
            antlrcpp::downCast<PlusMinusExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(104);
          expr(3);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<CmpExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(105);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(106);
          antlrcpp::downCast<CmpExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << CouncilParser::LT)
            | (1ULL << CouncilParser::LT_EQ)
            | (1ULL << CouncilParser::GT)
            | (1ULL << CouncilParser::GT_EQ)
            | (1ULL << CouncilParser::EQ)
            | (1ULL << CouncilParser::NEQ))) != 0))) {
            antlrcpp::downCast<CmpExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(107);
          expr(2);
          break;
        }

        default:
          break;
        } 
      }
      setState(112);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- FuncCallContext ------------------------------------------------------------------

CouncilParser::FuncCallContext::FuncCallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CouncilParser::FuncCallContext::ID() {
  return getToken(CouncilParser::ID, 0);
}

tree::TerminalNode* CouncilParser::FuncCallContext::OPEN_PAREN() {
  return getToken(CouncilParser::OPEN_PAREN, 0);
}

tree::TerminalNode* CouncilParser::FuncCallContext::CLOSE_PAREN() {
  return getToken(CouncilParser::CLOSE_PAREN, 0);
}

std::vector<CouncilParser::ExprContext *> CouncilParser::FuncCallContext::expr() {
  return getRuleContexts<CouncilParser::ExprContext>();
}

CouncilParser::ExprContext* CouncilParser::FuncCallContext::expr(size_t i) {
  return getRuleContext<CouncilParser::ExprContext>(i);
}

std::vector<tree::TerminalNode *> CouncilParser::FuncCallContext::COMMA() {
  return getTokens(CouncilParser::COMMA);
}

tree::TerminalNode* CouncilParser::FuncCallContext::COMMA(size_t i) {
  return getToken(CouncilParser::COMMA, i);
}


size_t CouncilParser::FuncCallContext::getRuleIndex() const {
  return CouncilParser::RuleFuncCall;
}

void CouncilParser::FuncCallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CouncilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncCall(this);
}

void CouncilParser::FuncCallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CouncilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncCall(this);
}


std::any CouncilParser::FuncCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CouncilVisitor*>(visitor))
    return parserVisitor->visitFuncCall(this);
  else
    return visitor->visitChildren(this);
}

CouncilParser::FuncCallContext* CouncilParser::funcCall() {
  FuncCallContext *_localctx = _tracker.createInstance<FuncCallContext>(_ctx, getState());
  enterRule(_localctx, 14, CouncilParser::RuleFuncCall);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(113);
    match(CouncilParser::ID);
    setState(114);
    match(CouncilParser::OPEN_PAREN);
    setState(123);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CouncilParser::ID)
      | (1ULL << CouncilParser::INT)
      | (1ULL << CouncilParser::FLOAT)
      | (1ULL << CouncilParser::TRUE)
      | (1ULL << CouncilParser::FALSE)
      | (1ULL << CouncilParser::STRING)
      | (1ULL << CouncilParser::OPEN_PAREN)
      | (1ULL << CouncilParser::BAR)
      | (1ULL << CouncilParser::MINUS))) != 0)) {
      setState(115);
      expr(0);
      setState(120);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == CouncilParser::COMMA) {
        setState(116);
        match(CouncilParser::COMMA);
        setState(117);
        expr(0);
        setState(122);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(125);
    match(CouncilParser::CLOSE_PAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnStmtContext ------------------------------------------------------------------

CouncilParser::ReturnStmtContext::ReturnStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CouncilParser::ReturnStmtContext::RETURN() {
  return getToken(CouncilParser::RETURN, 0);
}

CouncilParser::ExprContext* CouncilParser::ReturnStmtContext::expr() {
  return getRuleContext<CouncilParser::ExprContext>(0);
}


size_t CouncilParser::ReturnStmtContext::getRuleIndex() const {
  return CouncilParser::RuleReturnStmt;
}

void CouncilParser::ReturnStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CouncilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturnStmt(this);
}

void CouncilParser::ReturnStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CouncilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturnStmt(this);
}


std::any CouncilParser::ReturnStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CouncilVisitor*>(visitor))
    return parserVisitor->visitReturnStmt(this);
  else
    return visitor->visitChildren(this);
}

CouncilParser::ReturnStmtContext* CouncilParser::returnStmt() {
  ReturnStmtContext *_localctx = _tracker.createInstance<ReturnStmtContext>(_ctx, getState());
  enterRule(_localctx, 16, CouncilParser::RuleReturnStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(127);
    match(CouncilParser::RETURN);
    setState(128);
    expr(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfChainContext ------------------------------------------------------------------

CouncilParser::IfChainContext::IfChainContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CouncilParser::IfChainContext::IF() {
  return getToken(CouncilParser::IF, 0);
}

std::vector<tree::TerminalNode *> CouncilParser::IfChainContext::OPEN_PAREN() {
  return getTokens(CouncilParser::OPEN_PAREN);
}

tree::TerminalNode* CouncilParser::IfChainContext::OPEN_PAREN(size_t i) {
  return getToken(CouncilParser::OPEN_PAREN, i);
}

std::vector<CouncilParser::ExprContext *> CouncilParser::IfChainContext::expr() {
  return getRuleContexts<CouncilParser::ExprContext>();
}

CouncilParser::ExprContext* CouncilParser::IfChainContext::expr(size_t i) {
  return getRuleContext<CouncilParser::ExprContext>(i);
}

std::vector<tree::TerminalNode *> CouncilParser::IfChainContext::CLOSE_PAREN() {
  return getTokens(CouncilParser::CLOSE_PAREN);
}

tree::TerminalNode* CouncilParser::IfChainContext::CLOSE_PAREN(size_t i) {
  return getToken(CouncilParser::CLOSE_PAREN, i);
}

std::vector<CouncilParser::CodeBlockContext *> CouncilParser::IfChainContext::codeBlock() {
  return getRuleContexts<CouncilParser::CodeBlockContext>();
}

CouncilParser::CodeBlockContext* CouncilParser::IfChainContext::codeBlock(size_t i) {
  return getRuleContext<CouncilParser::CodeBlockContext>(i);
}

std::vector<tree::TerminalNode *> CouncilParser::IfChainContext::ELIF() {
  return getTokens(CouncilParser::ELIF);
}

tree::TerminalNode* CouncilParser::IfChainContext::ELIF(size_t i) {
  return getToken(CouncilParser::ELIF, i);
}

tree::TerminalNode* CouncilParser::IfChainContext::ELSE() {
  return getToken(CouncilParser::ELSE, 0);
}


size_t CouncilParser::IfChainContext::getRuleIndex() const {
  return CouncilParser::RuleIfChain;
}

void CouncilParser::IfChainContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CouncilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfChain(this);
}

void CouncilParser::IfChainContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CouncilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfChain(this);
}


std::any CouncilParser::IfChainContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CouncilVisitor*>(visitor))
    return parserVisitor->visitIfChain(this);
  else
    return visitor->visitChildren(this);
}

CouncilParser::IfChainContext* CouncilParser::ifChain() {
  IfChainContext *_localctx = _tracker.createInstance<IfChainContext>(_ctx, getState());
  enterRule(_localctx, 18, CouncilParser::RuleIfChain);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(130);
    match(CouncilParser::IF);
    setState(131);
    match(CouncilParser::OPEN_PAREN);
    setState(132);
    expr(0);
    setState(133);
    match(CouncilParser::CLOSE_PAREN);
    setState(134);
    codeBlock();
    setState(143);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CouncilParser::ELIF) {
      setState(135);
      match(CouncilParser::ELIF);
      setState(136);
      match(CouncilParser::OPEN_PAREN);
      setState(137);
      expr(0);
      setState(138);
      match(CouncilParser::CLOSE_PAREN);
      setState(139);
      codeBlock();
      setState(145);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(148);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CouncilParser::ELSE) {
      setState(146);
      match(CouncilParser::ELSE);
      setState(147);
      codeBlock();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WhileLoopContext ------------------------------------------------------------------

CouncilParser::WhileLoopContext::WhileLoopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CouncilParser::WhileLoopContext::WHILE() {
  return getToken(CouncilParser::WHILE, 0);
}

tree::TerminalNode* CouncilParser::WhileLoopContext::OPEN_PAREN() {
  return getToken(CouncilParser::OPEN_PAREN, 0);
}

CouncilParser::ExprContext* CouncilParser::WhileLoopContext::expr() {
  return getRuleContext<CouncilParser::ExprContext>(0);
}

tree::TerminalNode* CouncilParser::WhileLoopContext::CLOSE_PAREN() {
  return getToken(CouncilParser::CLOSE_PAREN, 0);
}

std::vector<CouncilParser::CodeBlockContext *> CouncilParser::WhileLoopContext::codeBlock() {
  return getRuleContexts<CouncilParser::CodeBlockContext>();
}

CouncilParser::CodeBlockContext* CouncilParser::WhileLoopContext::codeBlock(size_t i) {
  return getRuleContext<CouncilParser::CodeBlockContext>(i);
}

tree::TerminalNode* CouncilParser::WhileLoopContext::ELSE() {
  return getToken(CouncilParser::ELSE, 0);
}


size_t CouncilParser::WhileLoopContext::getRuleIndex() const {
  return CouncilParser::RuleWhileLoop;
}

void CouncilParser::WhileLoopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CouncilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhileLoop(this);
}

void CouncilParser::WhileLoopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CouncilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhileLoop(this);
}


std::any CouncilParser::WhileLoopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CouncilVisitor*>(visitor))
    return parserVisitor->visitWhileLoop(this);
  else
    return visitor->visitChildren(this);
}

CouncilParser::WhileLoopContext* CouncilParser::whileLoop() {
  WhileLoopContext *_localctx = _tracker.createInstance<WhileLoopContext>(_ctx, getState());
  enterRule(_localctx, 20, CouncilParser::RuleWhileLoop);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(150);
    match(CouncilParser::WHILE);
    setState(151);
    match(CouncilParser::OPEN_PAREN);
    setState(152);
    expr(0);
    setState(153);
    match(CouncilParser::CLOSE_PAREN);
    setState(154);
    codeBlock();
    setState(157);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CouncilParser::ELSE) {
      setState(155);
      match(CouncilParser::ELSE);
      setState(156);
      codeBlock();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForLoopContext ------------------------------------------------------------------

CouncilParser::ForLoopContext::ForLoopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CouncilParser::ForLoopContext::FOR() {
  return getToken(CouncilParser::FOR, 0);
}

tree::TerminalNode* CouncilParser::ForLoopContext::OPEN_PAREN() {
  return getToken(CouncilParser::OPEN_PAREN, 0);
}

std::vector<CouncilParser::ExprContext *> CouncilParser::ForLoopContext::expr() {
  return getRuleContexts<CouncilParser::ExprContext>();
}

CouncilParser::ExprContext* CouncilParser::ForLoopContext::expr(size_t i) {
  return getRuleContext<CouncilParser::ExprContext>(i);
}

std::vector<tree::TerminalNode *> CouncilParser::ForLoopContext::SEMICOLON() {
  return getTokens(CouncilParser::SEMICOLON);
}

tree::TerminalNode* CouncilParser::ForLoopContext::SEMICOLON(size_t i) {
  return getToken(CouncilParser::SEMICOLON, i);
}

tree::TerminalNode* CouncilParser::ForLoopContext::CLOSE_PAREN() {
  return getToken(CouncilParser::CLOSE_PAREN, 0);
}

std::vector<CouncilParser::CodeBlockContext *> CouncilParser::ForLoopContext::codeBlock() {
  return getRuleContexts<CouncilParser::CodeBlockContext>();
}

CouncilParser::CodeBlockContext* CouncilParser::ForLoopContext::codeBlock(size_t i) {
  return getRuleContext<CouncilParser::CodeBlockContext>(i);
}

tree::TerminalNode* CouncilParser::ForLoopContext::ELSE() {
  return getToken(CouncilParser::ELSE, 0);
}


size_t CouncilParser::ForLoopContext::getRuleIndex() const {
  return CouncilParser::RuleForLoop;
}

void CouncilParser::ForLoopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CouncilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForLoop(this);
}

void CouncilParser::ForLoopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CouncilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForLoop(this);
}


std::any CouncilParser::ForLoopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CouncilVisitor*>(visitor))
    return parserVisitor->visitForLoop(this);
  else
    return visitor->visitChildren(this);
}

CouncilParser::ForLoopContext* CouncilParser::forLoop() {
  ForLoopContext *_localctx = _tracker.createInstance<ForLoopContext>(_ctx, getState());
  enterRule(_localctx, 22, CouncilParser::RuleForLoop);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(159);
    match(CouncilParser::FOR);
    setState(160);
    match(CouncilParser::OPEN_PAREN);
    setState(161);
    expr(0);
    setState(162);
    match(CouncilParser::SEMICOLON);
    setState(163);
    expr(0);
    setState(164);
    match(CouncilParser::SEMICOLON);
    setState(165);
    expr(0);
    setState(166);
    match(CouncilParser::CLOSE_PAREN);
    setState(167);
    codeBlock();
    setState(170);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CouncilParser::ELSE) {
      setState(168);
      match(CouncilParser::ELSE);
      setState(169);
      codeBlock();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ObjContext ------------------------------------------------------------------

CouncilParser::ObjContext::ObjContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CouncilParser::ObjContext::getRuleIndex() const {
  return CouncilParser::RuleObj;
}

void CouncilParser::ObjContext::copyFrom(ObjContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- FuncCallObjContext ------------------------------------------------------------------

CouncilParser::FuncCallContext* CouncilParser::FuncCallObjContext::funcCall() {
  return getRuleContext<CouncilParser::FuncCallContext>(0);
}

CouncilParser::FuncCallObjContext::FuncCallObjContext(ObjContext *ctx) { copyFrom(ctx); }

void CouncilParser::FuncCallObjContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CouncilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncCallObj(this);
}
void CouncilParser::FuncCallObjContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CouncilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncCallObj(this);
}

std::any CouncilParser::FuncCallObjContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CouncilVisitor*>(visitor))
    return parserVisitor->visitFuncCallObj(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ObjLiteralContext ------------------------------------------------------------------

CouncilParser::LiteralContext* CouncilParser::ObjLiteralContext::literal() {
  return getRuleContext<CouncilParser::LiteralContext>(0);
}

CouncilParser::ObjLiteralContext::ObjLiteralContext(ObjContext *ctx) { copyFrom(ctx); }

void CouncilParser::ObjLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CouncilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterObjLiteral(this);
}
void CouncilParser::ObjLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CouncilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitObjLiteral(this);
}

std::any CouncilParser::ObjLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CouncilVisitor*>(visitor))
    return parserVisitor->visitObjLiteral(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ObjIdContext ------------------------------------------------------------------

tree::TerminalNode* CouncilParser::ObjIdContext::ID() {
  return getToken(CouncilParser::ID, 0);
}

CouncilParser::ObjIdContext::ObjIdContext(ObjContext *ctx) { copyFrom(ctx); }

void CouncilParser::ObjIdContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CouncilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterObjId(this);
}
void CouncilParser::ObjIdContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CouncilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitObjId(this);
}

std::any CouncilParser::ObjIdContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CouncilVisitor*>(visitor))
    return parserVisitor->visitObjId(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BarExprContext ------------------------------------------------------------------

std::vector<tree::TerminalNode *> CouncilParser::BarExprContext::BAR() {
  return getTokens(CouncilParser::BAR);
}

tree::TerminalNode* CouncilParser::BarExprContext::BAR(size_t i) {
  return getToken(CouncilParser::BAR, i);
}

CouncilParser::ExprContext* CouncilParser::BarExprContext::expr() {
  return getRuleContext<CouncilParser::ExprContext>(0);
}

CouncilParser::BarExprContext::BarExprContext(ObjContext *ctx) { copyFrom(ctx); }

void CouncilParser::BarExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CouncilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBarExpr(this);
}
void CouncilParser::BarExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CouncilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBarExpr(this);
}

std::any CouncilParser::BarExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CouncilVisitor*>(visitor))
    return parserVisitor->visitBarExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParenExprContext ------------------------------------------------------------------

tree::TerminalNode* CouncilParser::ParenExprContext::OPEN_PAREN() {
  return getToken(CouncilParser::OPEN_PAREN, 0);
}

CouncilParser::ExprContext* CouncilParser::ParenExprContext::expr() {
  return getRuleContext<CouncilParser::ExprContext>(0);
}

tree::TerminalNode* CouncilParser::ParenExprContext::CLOSE_PAREN() {
  return getToken(CouncilParser::CLOSE_PAREN, 0);
}

CouncilParser::ParenExprContext::ParenExprContext(ObjContext *ctx) { copyFrom(ctx); }

void CouncilParser::ParenExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CouncilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParenExpr(this);
}
void CouncilParser::ParenExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CouncilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParenExpr(this);
}

std::any CouncilParser::ParenExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CouncilVisitor*>(visitor))
    return parserVisitor->visitParenExpr(this);
  else
    return visitor->visitChildren(this);
}
CouncilParser::ObjContext* CouncilParser::obj() {
  ObjContext *_localctx = _tracker.createInstance<ObjContext>(_ctx, getState());
  enterRule(_localctx, 24, CouncilParser::RuleObj);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(183);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<CouncilParser::ObjIdContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(172);
      match(CouncilParser::ID);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<CouncilParser::ObjLiteralContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(173);
      literal();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<CouncilParser::ParenExprContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(174);
      match(CouncilParser::OPEN_PAREN);
      setState(175);
      expr(0);
      setState(176);
      match(CouncilParser::CLOSE_PAREN);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<CouncilParser::BarExprContext>(_localctx);
      enterOuterAlt(_localctx, 4);
      setState(178);
      match(CouncilParser::BAR);
      setState(179);
      expr(0);
      setState(180);
      match(CouncilParser::BAR);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<CouncilParser::FuncCallObjContext>(_localctx);
      enterOuterAlt(_localctx, 5);
      setState(182);
      funcCall();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CodeBlockContext ------------------------------------------------------------------

CouncilParser::CodeBlockContext::CodeBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CouncilParser::CodeBlockContext::OPEN_BRACE() {
  return getToken(CouncilParser::OPEN_BRACE, 0);
}

tree::TerminalNode* CouncilParser::CodeBlockContext::CLOSE_BRACE() {
  return getToken(CouncilParser::CLOSE_BRACE, 0);
}

std::vector<CouncilParser::CodeLineContext *> CouncilParser::CodeBlockContext::codeLine() {
  return getRuleContexts<CouncilParser::CodeLineContext>();
}

CouncilParser::CodeLineContext* CouncilParser::CodeBlockContext::codeLine(size_t i) {
  return getRuleContext<CouncilParser::CodeLineContext>(i);
}


size_t CouncilParser::CodeBlockContext::getRuleIndex() const {
  return CouncilParser::RuleCodeBlock;
}

void CouncilParser::CodeBlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CouncilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCodeBlock(this);
}

void CouncilParser::CodeBlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CouncilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCodeBlock(this);
}


std::any CouncilParser::CodeBlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CouncilVisitor*>(visitor))
    return parserVisitor->visitCodeBlock(this);
  else
    return visitor->visitChildren(this);
}

CouncilParser::CodeBlockContext* CouncilParser::codeBlock() {
  CodeBlockContext *_localctx = _tracker.createInstance<CodeBlockContext>(_ctx, getState());
  enterRule(_localctx, 26, CouncilParser::RuleCodeBlock);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(185);
    match(CouncilParser::OPEN_BRACE);
    setState(189);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CouncilParser::STR_T)
      | (1ULL << CouncilParser::INT_T)
      | (1ULL << CouncilParser::FLOAT_T)
      | (1ULL << CouncilParser::BOOL_T)
      | (1ULL << CouncilParser::RETURN)
      | (1ULL << CouncilParser::IF)
      | (1ULL << CouncilParser::ID))) != 0)) {
      setState(186);
      codeLine();
      setState(191);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(192);
    match(CouncilParser::CLOSE_BRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CodeLineContext ------------------------------------------------------------------

CouncilParser::CodeLineContext::CodeLineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CouncilParser::DecVarContext* CouncilParser::CodeLineContext::decVar() {
  return getRuleContext<CouncilParser::DecVarContext>(0);
}

tree::TerminalNode* CouncilParser::CodeLineContext::SEMICOLON() {
  return getToken(CouncilParser::SEMICOLON, 0);
}

CouncilParser::AssignVarContext* CouncilParser::CodeLineContext::assignVar() {
  return getRuleContext<CouncilParser::AssignVarContext>(0);
}

CouncilParser::FuncCallContext* CouncilParser::CodeLineContext::funcCall() {
  return getRuleContext<CouncilParser::FuncCallContext>(0);
}

CouncilParser::ReturnStmtContext* CouncilParser::CodeLineContext::returnStmt() {
  return getRuleContext<CouncilParser::ReturnStmtContext>(0);
}

CouncilParser::IfChainContext* CouncilParser::CodeLineContext::ifChain() {
  return getRuleContext<CouncilParser::IfChainContext>(0);
}


size_t CouncilParser::CodeLineContext::getRuleIndex() const {
  return CouncilParser::RuleCodeLine;
}

void CouncilParser::CodeLineContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CouncilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCodeLine(this);
}

void CouncilParser::CodeLineContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CouncilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCodeLine(this);
}


std::any CouncilParser::CodeLineContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CouncilVisitor*>(visitor))
    return parserVisitor->visitCodeLine(this);
  else
    return visitor->visitChildren(this);
}

CouncilParser::CodeLineContext* CouncilParser::codeLine() {
  CodeLineContext *_localctx = _tracker.createInstance<CodeLineContext>(_ctx, getState());
  enterRule(_localctx, 28, CouncilParser::RuleCodeLine);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(207);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(194);
      decVar();
      setState(195);
      match(CouncilParser::SEMICOLON);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(197);
      assignVar();
      setState(198);
      match(CouncilParser::SEMICOLON);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(200);
      funcCall();
      setState(201);
      match(CouncilParser::SEMICOLON);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(203);
      returnStmt();
      setState(204);
      match(CouncilParser::SEMICOLON);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(206);
      ifChain();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LiteralContext ------------------------------------------------------------------

CouncilParser::LiteralContext::LiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CouncilParser::LiteralContext::INT() {
  return getToken(CouncilParser::INT, 0);
}

tree::TerminalNode* CouncilParser::LiteralContext::FLOAT() {
  return getToken(CouncilParser::FLOAT, 0);
}

tree::TerminalNode* CouncilParser::LiteralContext::STRING() {
  return getToken(CouncilParser::STRING, 0);
}

tree::TerminalNode* CouncilParser::LiteralContext::TRUE() {
  return getToken(CouncilParser::TRUE, 0);
}

tree::TerminalNode* CouncilParser::LiteralContext::FALSE() {
  return getToken(CouncilParser::FALSE, 0);
}


size_t CouncilParser::LiteralContext::getRuleIndex() const {
  return CouncilParser::RuleLiteral;
}

void CouncilParser::LiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CouncilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLiteral(this);
}

void CouncilParser::LiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CouncilListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLiteral(this);
}


std::any CouncilParser::LiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CouncilVisitor*>(visitor))
    return parserVisitor->visitLiteral(this);
  else
    return visitor->visitChildren(this);
}

CouncilParser::LiteralContext* CouncilParser::literal() {
  LiteralContext *_localctx = _tracker.createInstance<LiteralContext>(_ctx, getState());
  enterRule(_localctx, 30, CouncilParser::RuleLiteral);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(209);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CouncilParser::INT)
      | (1ULL << CouncilParser::FLOAT)
      | (1ULL << CouncilParser::TRUE)
      | (1ULL << CouncilParser::FALSE)
      | (1ULL << CouncilParser::STRING))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool CouncilParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 6: return exprSempred(antlrcpp::downCast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool CouncilParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 3);
    case 1: return precpred(_ctx, 2);
    case 2: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

void CouncilParser::initialize() {
  std::call_once(councilParserOnceFlag, councilParserInitialize);
}
