grammar Council;

parseFile
	: OPEN_BRACE importStmt* decFunc* CLOSE_BRACE codeBlock
	;

importStmt
	: EXTERN ID OPEN_PAREN (type (COMMA type)* )? CLOSE_PAREN SEMICOLON
	;

type
	: STR_T		# typeStr
	| INT_T		# typeInt
	| FLOAT_T	# typeFloat
	| BOOL_T	# typeBool
	;

decVar
	: type assignVar
	;

assignVar
	: ID EQUALS expr
	;

decFunc
	: FUNC ID OPEN_PAREN type (COMMA type ID)* CLOSE_PAREN codeBlock
	;

expr
	: obj							# objExpr
	| MINUS expr						# preMinusExpr
	| expr op=(MULTI | FLOAT_DIV | INT_DIV | MOD) expr	# multiDivExpr
	| expr op=(PLUS | MINUS) expr				# plusMinusExpr
	| expr op=(EQ | NEQ | LT | GT | LT_EQ | GT_EQ) expr	# cmpExpr
	;

funcCall
	: ID OPEN_PAREN (expr (COMMA expr)* )? CLOSE_PAREN	
	;

returnStmt
	: RETURN expr
	;

ifChain
	: IF OPEN_PAREN expr CLOSE_PAREN codeBlock 
		(ELIF OPEN_PAREN expr CLOSE_PAREN codeBlock)* 
		(ELSE codeBlock)?
	;

whileLoop
	: WHILE OPEN_PAREN expr CLOSE_PAREN codeBlock 
		(ELSE codeBlock)?
	;

forLoop
	: FOR OPEN_PAREN expr SEMICOLON expr SEMICOLON expr CLOSE_PAREN codeBlock
		(ELSE codeBlock)?
	;

obj
	: ID							# objId
	| literal						# objLiteral
	| OPEN_PAREN expr CLOSE_PAREN				# parenExpr
	| BAR expr BAR						# barExpr
	| funcCall 						# funcCallObj
	;

codeBlock
	: OPEN_BRACE codeLine* CLOSE_BRACE
	;

codeLine
	: decVar SEMICOLON
	| assignVar SEMICOLON
	| funcCall SEMICOLON
	| returnStmt SEMICOLON
	| ifChain
	;

literal
	: INT
	| FLOAT
	| STRING
	| TRUE
	| FALSE
	;



// Tokens
PERIOD		: '.';
COMMA		: ',';
SEMICOLON	: ';';

// keyword

STR_T		: 'String';
INT_T		: 'Int';
FLOAT_T		: 'Float';
BOOL_T		: 'Bool';

FUNC		: 'Func';
EXTERN		: 'import';

RETURN		: 'return';
IF		: 'if';
ELIF		: 'elif';
ELSE		: 'else';
WHILE		: 'while';
FOR		: 'for';
BREAK		: 'break';

ID		: [a-zA-Z_][a-zA-Z0-9_]*;

// literals
INT		: [0-9][0-9_]*;
FLOAT		: INT? '.' INT 'f'?
		| INT '.' 'f'?
		| INT 'f'
		;

TRUE		: 'TRUE';
FALSE		: 'FALSE';

STRING		: '"' (~["\r\n] | '\\"')* '"'
		;

COMMENT		: '#' ~ [\r\n]* -> skip;
BLOCK_COMMENT	: '#--' .*? '--#' -> skip;
WHITESPACE	: [ \t\r\n] -> skip;

OPEN_BRACE	: '{';
CLOSE_BRACE	: '}';

OPEN_PAREN	: '(';
CLOSE_PAREN	: ')';

BAR		: '|';

PLUS		: '+';
MINUS		: '-';
MULTI		: '*';
FLOAT_DIV	: '/';
INT_DIV		: '//';
MOD		: '%';
EQUALS		: '=';

LT		: '<';
LT_EQ		: '<=';
GT		: '>';
GT_EQ		: '>=';
EQ		: '==';
NEQ		: '!=';
