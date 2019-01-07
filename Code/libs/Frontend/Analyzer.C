#include "Analyzer.H"
#include <iostream>

using namespace std;


void Analyzer::analyze(Visitable* v, Env* e) {
//TODO: COmment this out
	cerr << "Analyzing...\n\n";
	
	BasicInfoCollector b;
	b.collect(v, e);
//TODO: COmment this out
	e->printFunctions();

	TypeChecker tc;
	tc.checkTypes(v, e);

	ReturnChecker rc;
	rc.checkReturns(v, e);

}