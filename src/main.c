#include "common.h"
#include "source.h"
//mingw32-make
//parse CLI arguments
//load Source
//scan tokens
//if --tokens: print tokens; cleanup; exit
//parse Program into AST
//if --ast: print AST; cleanup; exit
//run semantic analysis
//if --check: cleanup; exit
//generate IR
//if --ir: print IR; cleanup; exit
//run IR Interpreter
//cleanup everything
int main() {
    Source source;
    source_load(&source, "/examples/Main.java");
}