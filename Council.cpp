#include <iostream>
#include <string>

#include "MyCouncilVisitor.h"

#include "antlr4/CouncilLexer.h"
#include "antlr4/CouncilVisitor.h"
#include "antlr4/CouncilParser.h"

using namespace std;
using namespace antlr4;

int main(int argc, const char* argv[]){
	string file_path;
	if (argc < 2) {
		cout << "Please enter a file to compile: ";
		cin >> file_path;
	} else {
		file_path = argv[1];
	}
	ifstream stream;
	stream.open(file_path);
	
	string out_path = file_path + ".out";

	ANTLRInputStream input(stream);
	CouncilLexer lexer(&input);
	CommonTokenStream tokens(&lexer);
	CouncilParser parser(&tokens);

	CouncilParser::ParseFileContext* tree = parser.parseFile();

	cout << "-=- Starting Compiling -=-";

	MyCouncilVisitor visitor(out_path);
	visitor.visitParseFile(tree);

	cout << "-=-  Ending Compiling  -=-" << endl;
	return 0;
}
