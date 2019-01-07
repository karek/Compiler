#include "Compiler.H"
#include <iostream>

using namespace std;


void Compiler::compile(Visitable* v, Env* e) {
//TODO: COmment this out
	cerr << "Compiling...\n\n";
	
	CodeCreator cc;
	cc.create(v);
// 	BasicInfoCollector b;
// 	b.collect(v, e);
// //TODO: COmment this out
// 	e->printFunctions();

// 	TypeChecker tc;
// 	tc.checkTypes(v, e);

// 	ReturnChecker rc;
// 	rc.checkReturns(v, e);

}