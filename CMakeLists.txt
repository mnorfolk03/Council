cmake_minimum_required(VERSION 3.13.4)

# set the project name
project(Council)

# set CPP standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_COMPILER "clang++")

find_package(LLVM REQUIRED CONFIG)

# add the generated stuff
set(GEN antlr4/CouncilBaseVisitor.cpp
	antlr4/CouncilLexer.cpp
	antlr4/CouncilVisitor.cpp
	antlr4/CouncilParser.cpp)

# LLVM stuff
include_directories(${LLVM_INCLUDE_DIRS})
separate_arguments(LLVM_DEFINITIONS_LIST NATIVE_COMMAND ${LLVM_DEFINITIONS})
add_definitions(${LLVM_DEFINITIONS_LIST})

# target
add_executable(Council Council.cpp ${GEN})

target_link_libraries(Council antlr4-runtime)
target_include_directories(Council PRIVATE /usr/local/include/antlr4-runtime)

# more LLVM stuff
# llvm_map_components_to_libnames(llvm_libs support core irreader all)

target_link_libraries(Council LLVM-14)

