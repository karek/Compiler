#include <iostream>
#include "Compiler.H"

using namespace std;

void Compiler::compile(Visitable* v, Env* e) {
    // TODO: COmment this out
    cerr << "Compiling...\n\n";

    CodeCreator cc;
    cc.create(v, e);
    cc.printAllInstrs();
    // 	BasicInfoCollector b;
    // 	b.collect(v, e);
    // //TODO: COmment this out
    // 	e->printFunctions();

    // 	TypeChecker tc;
    // 	tc.checkTypes(v, e);

    // 	ReturnChecker rc;
    // 	rc.checkReturns(v, e);
}