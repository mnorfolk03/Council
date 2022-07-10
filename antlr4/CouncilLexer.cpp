
// Generated from Council.g4 by ANTLR 4.10.1


#include "CouncilLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct CouncilLexerStaticData final {
  CouncilLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  CouncilLexerStaticData(const CouncilLexerStaticData&) = delete;
  CouncilLexerStaticData(CouncilLexerStaticData&&) = delete;
  CouncilLexerStaticData& operator=(const CouncilLexerStaticData&) = delete;
  CouncilLexerStaticData& operator=(CouncilLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

std::once_flag councillexerLexerOnceFlag;
CouncilLexerStaticData *councillexerLexerStaticData = nullptr;

void councillexerLexerInitialize() {
  assert(councillexerLexerStaticData == nullptr);
  auto staticData = std::make_unique<CouncilLexerStaticData>(
    std::vector<std::string>{
      "PERIOD", "COMMA", "SEMICOLON", "STR_T", "INT_T", "FLOAT_T", "BOOL_T", 
      "FUNC", "EXTERN", "RETURN", "IF", "ELIF", "ELSE", "WHILE", "FOR", 
      "BREAK", "ID", "INT", "FLOAT", "TRUE", "FALSE", "STRING", "COMMENT", 
      "BLOCK_COMMENT", "WHITESPACE", "OPEN_BRACE", "CLOSE_BRACE", "OPEN_PAREN", 
      "CLOSE_PAREN", "BAR", "PLUS", "MINUS", "MULTI", "FLOAT_DIV", "INT_DIV", 
      "MOD", "EQUALS", "LT", "LT_EQ", "GT", "GT_EQ", "EQ", "NEQ"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
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
  	4,0,43,287,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,
  	7,28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,
  	7,35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,41,2,42,
  	7,42,1,0,1,0,1,1,1,1,1,2,1,2,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,4,1,4,1,4,
  	1,4,1,5,1,5,1,5,1,5,1,5,1,5,1,6,1,6,1,6,1,6,1,6,1,7,1,7,1,7,1,7,1,7,1,
  	8,1,8,1,8,1,8,1,8,1,8,1,8,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,10,1,10,1,10,
  	1,11,1,11,1,11,1,11,1,11,1,12,1,12,1,12,1,12,1,12,1,13,1,13,1,13,1,13,
  	1,13,1,13,1,14,1,14,1,14,1,14,1,15,1,15,1,15,1,15,1,15,1,15,1,16,1,16,
  	5,16,166,8,16,10,16,12,16,169,9,16,1,17,1,17,5,17,173,8,17,10,17,12,17,
  	176,9,17,1,18,3,18,179,8,18,1,18,1,18,1,18,3,18,184,8,18,1,18,1,18,1,
  	18,3,18,189,8,18,1,18,1,18,1,18,3,18,194,8,18,1,19,1,19,1,19,1,19,1,19,
  	1,20,1,20,1,20,1,20,1,20,1,20,1,21,1,21,1,21,1,21,5,21,211,8,21,10,21,
  	12,21,214,9,21,1,21,1,21,1,22,1,22,5,22,220,8,22,10,22,12,22,223,9,22,
  	1,22,1,22,1,23,1,23,1,23,1,23,1,23,5,23,232,8,23,10,23,12,23,235,9,23,
  	1,23,1,23,1,23,1,23,1,23,1,23,1,24,1,24,1,24,1,24,1,25,1,25,1,26,1,26,
  	1,27,1,27,1,28,1,28,1,29,1,29,1,30,1,30,1,31,1,31,1,32,1,32,1,33,1,33,
  	1,34,1,34,1,34,1,35,1,35,1,36,1,36,1,37,1,37,1,38,1,38,1,38,1,39,1,39,
  	1,40,1,40,1,40,1,41,1,41,1,41,1,42,1,42,1,42,1,233,0,43,1,1,3,2,5,3,7,
  	4,9,5,11,6,13,7,15,8,17,9,19,10,21,11,23,12,25,13,27,14,29,15,31,16,33,
  	17,35,18,37,19,39,20,41,21,43,22,45,23,47,24,49,25,51,26,53,27,55,28,
  	57,29,59,30,61,31,63,32,65,33,67,34,69,35,71,36,73,37,75,38,77,39,79,
  	40,81,41,83,42,85,43,1,0,7,3,0,65,90,95,95,97,122,4,0,48,57,65,90,95,
  	95,97,122,1,0,48,57,2,0,48,57,95,95,3,0,10,10,13,13,34,34,2,0,10,10,13,
  	13,3,0,9,10,13,13,32,32,297,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,
  	0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,
  	0,19,1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,0,0,25,1,0,0,0,0,27,1,0,0,0,0,29,
  	1,0,0,0,0,31,1,0,0,0,0,33,1,0,0,0,0,35,1,0,0,0,0,37,1,0,0,0,0,39,1,0,
  	0,0,0,41,1,0,0,0,0,43,1,0,0,0,0,45,1,0,0,0,0,47,1,0,0,0,0,49,1,0,0,0,
  	0,51,1,0,0,0,0,53,1,0,0,0,0,55,1,0,0,0,0,57,1,0,0,0,0,59,1,0,0,0,0,61,
  	1,0,0,0,0,63,1,0,0,0,0,65,1,0,0,0,0,67,1,0,0,0,0,69,1,0,0,0,0,71,1,0,
  	0,0,0,73,1,0,0,0,0,75,1,0,0,0,0,77,1,0,0,0,0,79,1,0,0,0,0,81,1,0,0,0,
  	0,83,1,0,0,0,0,85,1,0,0,0,1,87,1,0,0,0,3,89,1,0,0,0,5,91,1,0,0,0,7,93,
  	1,0,0,0,9,100,1,0,0,0,11,104,1,0,0,0,13,110,1,0,0,0,15,115,1,0,0,0,17,
  	120,1,0,0,0,19,127,1,0,0,0,21,134,1,0,0,0,23,137,1,0,0,0,25,142,1,0,0,
  	0,27,147,1,0,0,0,29,153,1,0,0,0,31,157,1,0,0,0,33,163,1,0,0,0,35,170,
  	1,0,0,0,37,193,1,0,0,0,39,195,1,0,0,0,41,200,1,0,0,0,43,206,1,0,0,0,45,
  	217,1,0,0,0,47,226,1,0,0,0,49,242,1,0,0,0,51,246,1,0,0,0,53,248,1,0,0,
  	0,55,250,1,0,0,0,57,252,1,0,0,0,59,254,1,0,0,0,61,256,1,0,0,0,63,258,
  	1,0,0,0,65,260,1,0,0,0,67,262,1,0,0,0,69,264,1,0,0,0,71,267,1,0,0,0,73,
  	269,1,0,0,0,75,271,1,0,0,0,77,273,1,0,0,0,79,276,1,0,0,0,81,278,1,0,0,
  	0,83,281,1,0,0,0,85,284,1,0,0,0,87,88,5,46,0,0,88,2,1,0,0,0,89,90,5,44,
  	0,0,90,4,1,0,0,0,91,92,5,59,0,0,92,6,1,0,0,0,93,94,5,83,0,0,94,95,5,116,
  	0,0,95,96,5,114,0,0,96,97,5,105,0,0,97,98,5,110,0,0,98,99,5,103,0,0,99,
  	8,1,0,0,0,100,101,5,73,0,0,101,102,5,110,0,0,102,103,5,116,0,0,103,10,
  	1,0,0,0,104,105,5,70,0,0,105,106,5,108,0,0,106,107,5,111,0,0,107,108,
  	5,97,0,0,108,109,5,116,0,0,109,12,1,0,0,0,110,111,5,66,0,0,111,112,5,
  	111,0,0,112,113,5,111,0,0,113,114,5,108,0,0,114,14,1,0,0,0,115,116,5,
  	70,0,0,116,117,5,117,0,0,117,118,5,110,0,0,118,119,5,99,0,0,119,16,1,
  	0,0,0,120,121,5,105,0,0,121,122,5,109,0,0,122,123,5,112,0,0,123,124,5,
  	111,0,0,124,125,5,114,0,0,125,126,5,116,0,0,126,18,1,0,0,0,127,128,5,
  	114,0,0,128,129,5,101,0,0,129,130,5,116,0,0,130,131,5,117,0,0,131,132,
  	5,114,0,0,132,133,5,110,0,0,133,20,1,0,0,0,134,135,5,105,0,0,135,136,
  	5,102,0,0,136,22,1,0,0,0,137,138,5,101,0,0,138,139,5,108,0,0,139,140,
  	5,105,0,0,140,141,5,102,0,0,141,24,1,0,0,0,142,143,5,101,0,0,143,144,
  	5,108,0,0,144,145,5,115,0,0,145,146,5,101,0,0,146,26,1,0,0,0,147,148,
  	5,119,0,0,148,149,5,104,0,0,149,150,5,105,0,0,150,151,5,108,0,0,151,152,
  	5,101,0,0,152,28,1,0,0,0,153,154,5,102,0,0,154,155,5,111,0,0,155,156,
  	5,114,0,0,156,30,1,0,0,0,157,158,5,98,0,0,158,159,5,114,0,0,159,160,5,
  	101,0,0,160,161,5,97,0,0,161,162,5,107,0,0,162,32,1,0,0,0,163,167,7,0,
  	0,0,164,166,7,1,0,0,165,164,1,0,0,0,166,169,1,0,0,0,167,165,1,0,0,0,167,
  	168,1,0,0,0,168,34,1,0,0,0,169,167,1,0,0,0,170,174,7,2,0,0,171,173,7,
  	3,0,0,172,171,1,0,0,0,173,176,1,0,0,0,174,172,1,0,0,0,174,175,1,0,0,0,
  	175,36,1,0,0,0,176,174,1,0,0,0,177,179,3,35,17,0,178,177,1,0,0,0,178,
  	179,1,0,0,0,179,180,1,0,0,0,180,181,5,46,0,0,181,183,3,35,17,0,182,184,
  	5,102,0,0,183,182,1,0,0,0,183,184,1,0,0,0,184,194,1,0,0,0,185,186,3,35,
  	17,0,186,188,5,46,0,0,187,189,5,102,0,0,188,187,1,0,0,0,188,189,1,0,0,
  	0,189,194,1,0,0,0,190,191,3,35,17,0,191,192,5,102,0,0,192,194,1,0,0,0,
  	193,178,1,0,0,0,193,185,1,0,0,0,193,190,1,0,0,0,194,38,1,0,0,0,195,196,
  	5,84,0,0,196,197,5,82,0,0,197,198,5,85,0,0,198,199,5,69,0,0,199,40,1,
  	0,0,0,200,201,5,70,0,0,201,202,5,65,0,0,202,203,5,76,0,0,203,204,5,83,
  	0,0,204,205,5,69,0,0,205,42,1,0,0,0,206,212,5,34,0,0,207,211,8,4,0,0,
  	208,209,5,92,0,0,209,211,5,34,0,0,210,207,1,0,0,0,210,208,1,0,0,0,211,
  	214,1,0,0,0,212,210,1,0,0,0,212,213,1,0,0,0,213,215,1,0,0,0,214,212,1,
  	0,0,0,215,216,5,34,0,0,216,44,1,0,0,0,217,221,5,35,0,0,218,220,8,5,0,
  	0,219,218,1,0,0,0,220,223,1,0,0,0,221,219,1,0,0,0,221,222,1,0,0,0,222,
  	224,1,0,0,0,223,221,1,0,0,0,224,225,6,22,0,0,225,46,1,0,0,0,226,227,5,
  	35,0,0,227,228,5,45,0,0,228,229,5,45,0,0,229,233,1,0,0,0,230,232,9,0,
  	0,0,231,230,1,0,0,0,232,235,1,0,0,0,233,234,1,0,0,0,233,231,1,0,0,0,234,
  	236,1,0,0,0,235,233,1,0,0,0,236,237,5,45,0,0,237,238,5,45,0,0,238,239,
  	5,35,0,0,239,240,1,0,0,0,240,241,6,23,0,0,241,48,1,0,0,0,242,243,7,6,
  	0,0,243,244,1,0,0,0,244,245,6,24,0,0,245,50,1,0,0,0,246,247,5,123,0,0,
  	247,52,1,0,0,0,248,249,5,125,0,0,249,54,1,0,0,0,250,251,5,40,0,0,251,
  	56,1,0,0,0,252,253,5,41,0,0,253,58,1,0,0,0,254,255,5,124,0,0,255,60,1,
  	0,0,0,256,257,5,43,0,0,257,62,1,0,0,0,258,259,5,45,0,0,259,64,1,0,0,0,
  	260,261,5,42,0,0,261,66,1,0,0,0,262,263,5,47,0,0,263,68,1,0,0,0,264,265,
  	5,47,0,0,265,266,5,47,0,0,266,70,1,0,0,0,267,268,5,37,0,0,268,72,1,0,
  	0,0,269,270,5,61,0,0,270,74,1,0,0,0,271,272,5,60,0,0,272,76,1,0,0,0,273,
  	274,5,60,0,0,274,275,5,61,0,0,275,78,1,0,0,0,276,277,5,62,0,0,277,80,
  	1,0,0,0,278,279,5,62,0,0,279,280,5,61,0,0,280,82,1,0,0,0,281,282,5,61,
  	0,0,282,283,5,61,0,0,283,84,1,0,0,0,284,285,5,33,0,0,285,286,5,61,0,0,
  	286,86,1,0,0,0,11,0,167,174,178,183,188,193,210,212,221,233,1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  councillexerLexerStaticData = staticData.release();
}

}

CouncilLexer::CouncilLexer(CharStream *input) : Lexer(input) {
  CouncilLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *councillexerLexerStaticData->atn, councillexerLexerStaticData->decisionToDFA, councillexerLexerStaticData->sharedContextCache);
}

CouncilLexer::~CouncilLexer() {
  delete _interpreter;
}

std::string CouncilLexer::getGrammarFileName() const {
  return "Council.g4";
}

const std::vector<std::string>& CouncilLexer::getRuleNames() const {
  return councillexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& CouncilLexer::getChannelNames() const {
  return councillexerLexerStaticData->channelNames;
}

const std::vector<std::string>& CouncilLexer::getModeNames() const {
  return councillexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& CouncilLexer::getVocabulary() const {
  return councillexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView CouncilLexer::getSerializedATN() const {
  return councillexerLexerStaticData->serializedATN;
}

const atn::ATN& CouncilLexer::getATN() const {
  return *councillexerLexerStaticData->atn;
}




void CouncilLexer::initialize() {
  std::call_once(councillexerLexerOnceFlag, councillexerLexerInitialize);
}
