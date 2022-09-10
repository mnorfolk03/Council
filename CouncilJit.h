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
        unique_ptr<ExecutionSession> execution_session;
        RTDyldObjectLinkingLayer object_layer;
        IRCompileLayer compile_layer;

        DataLayout data_layout;
        MangleAndInterner mangle;
        JITDylib &main_dylib;

    public:
        CouncilJit(unique_ptr<ExecutionSession> session, JITTargetMachineBuilder target_machine, DataLayout data_layout)
                : execution_session(std::move(session)),
                  data_layout(data_layout),

                  object_layer(*execution_session,
                               []() { return std::make_unique<SectionMemoryManager>(); }),
                  compile_layer(*execution_session, object_layer,
                                std::make_unique<ConcurrentIRCompiler>(std::move(target_machine))),
                  mangle(*execution_session, data_layout), main_dylib(execution_session->createBareJITDylib("<main>")) {
        }

        CouncilJit create() {
            auto executor_process_control = SelfExecutorProcessControl::Create();
            if (!executor_process_control)
                throw IllegalStateException();
            execution_session = std::make_unique<ExecutionSession>(std::move(*executor_process_control));

            JITTargetMachineBuilder target_machine_builder(
                    execution_session->getExecutorProcessControl().getTargetTriple());
            auto data_layout = target_machine_builder.getDefaultDataLayoutForTarget();
            if (!data_layout)
                throw IllegalStateException();
            return CouncilJit(std::move(execution_session), target_machine_builder, *data_layout);
        }

        const DataLayout &getDataLayout() const { return data_layout; }

        Error addModule(ThreadSafeModule thread_safe_module, ResourceTrackerSP rt = nullptr) {
            if (rt == nullptr)
                rt = main_dylib.getDefaultResourceTracker();
            return compile_layer.add(rt, std::move(thread_safe_module));
        }
    };
}