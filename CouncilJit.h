//
// Created by Max Norfolk on 9/1/22.
//

#pragma once


#include "llvm/ADT/StringRef.h"
#include "llvm/ExecutionEngine/JITSymbol.h"
#include "llvm/ExecutionEngine/Orc/CompileUtils.h"
#include "llvm/ExecutionEngine/Orc/Core.h"
#include "llvm/ExecutionEngine/Orc/ExecutionUtils.h"
#include "llvm/ExecutionEngine/Orc/IRCompileLayer.h"
#include "llvm/ExecutionEngine/Orc/JITTargetMachineBuilder.h"
#include "llvm/ExecutionEngine/Orc/RTDyldObjectLinkingLayer.h"
#include "llvm/ExecutionEngine/SectionMemoryManager.h"
#include "llvm/IR/DataLayout.h"
#include "llvm/IR/LLVMContext.h"
#include <memory>

namespace llvm::orc {

    class CouncilJit {
    private:
        ExecutionSession execution_session;
        RTDyldObjectLinkingLayer object_layer;
        IRCompileLayer compile_layer;

        DataLayout data_layout;
        MangleAndInterner mangle;
        ThreadSafeContext ctx;

    public:
        CouncilJit(JITTargetMachineBuilder target_machine, DataLayout data_layout)
                : object_layer(execution_session,
                               []() { return std::make_unique<SectionMemoryManager>(); }), {
            unique_ptr<IRCompileLayer::IRCompiler> ptr;
            IRCompileLayer compile_layer(execution_session, object_layer,
                                         std::move(ConcurrentIRCompiler(std::move(target_machine))))
        }
    };
}