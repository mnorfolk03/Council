#include <iostream>

#include <string>

#include "MyCouncilVisitor.h"
#include "CouncilJit.h"

#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/FileSystem.h"
#include "llvm/Support/Host.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Target/TargetMachine.h"
#include "llvm/Target/TargetOptions.h"

#include "llvm/IR/LegacyPassManager.h"

#include "antlr4/CouncilLexer.h"
#include "antlr4/CouncilParser.h"

using namespace std;
using namespace antlr4;

int main(int argc, const char *argv[]) {
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

    CouncilParser::ParseFileContext *tree = parser.parseFile();

    cout << "-=- Starting Compiling -=-" << endl;

    MyCouncilVisitor visitor(out_path);
    visitor.visitParseFile(tree);

    coun::llvmModule.dump();

    cout << "-=-  Ending Compiling  -=-" << endl;

    // actually generate object file.
    auto target_triple = sys::getDefaultTargetTriple();
    InitializeAllTargetInfos();
    InitializeAllTargets();
    InitializeAllTargetMCs();
    InitializeAllAsmParsers();
    InitializeAllAsmPrinters();

    string error;
    std::error_code ec;

    auto target = TargetRegistry::lookupTarget(target_triple, error);

    auto cpu = "generic";
    auto features = "";

    TargetOptions opt;
    auto RM = Optional<Reloc::Model>();
    auto target_machine = target->createTargetMachine(target_triple, cpu, features, opt, RM);

    coun::llvmModule.setDataLayout(target_machine->createDataLayout());
    coun::llvmModule.setTargetTriple(target_triple);

    raw_fd_ostream out_file_fd(out_path, ec, sys::fs::OF_None);
    if (ec) {
        std::cout << "Could not open: " << ec.message();
        return 1;
    }

    legacy::PassManager pass;
    auto file_type = CGFT_ObjectFile;
    if (target_machine->addPassesToEmitFile(pass, out_file_fd, nullptr, file_type)) {
        std::cout << "TargetMachine cannot emit a file of this type" << std::endl;
        return 1;
    }
    pass.run(coun::llvmModule);
    out_file_fd.flush();
    std::cout << "Wrote Successfully!" << std::endl;


    return 0;
}
