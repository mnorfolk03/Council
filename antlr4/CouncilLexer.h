
// Generated from Council.g4 by ANTLR 4.10.1

#pragma once


#include "antlr4-runtime.h"




class  CouncilLexer : public antlr4::Lexer {
public:
  enum {
    PERIOD = 1, COMMA = 2, SEMICOLON = 3, STR_T = 4, INT_T = 5, FLOAT_T = 6, 
    BOOL_T = 7, FUNC = 8, EXTERN = 9, RETURN = 10, IF = 11, ELIF = 12, ELSE = 13, 
    WHILE = 14, FOR = 15, BREAK = 16, ID = 17, INT = 18, FLOAT = 19, TRUE = 20, 
    FALSE = 21, STRING = 22, COMMENT = 23, BLOCK_COMMENT = 24, WHITESPACE = 25, 
    OPEN_BRACE = 26, CLOSE_BRACE = 27, OPEN_PAREN = 28, CLOSE_PAREN = 29, 
    BAR = 30, PLUS = 31, MINUS = 32, MULTI = 33, FLOAT_DIV = 34, INT_DIV = 35, 
    MOD = 36, EQUALS = 37, LT = 38, LT_EQ = 39, GT = 40, GT_EQ = 41, EQ = 42, 
    NEQ = 43
  };

  explicit CouncilLexer(antlr4::CharStream *input);

  ~CouncilLexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};

