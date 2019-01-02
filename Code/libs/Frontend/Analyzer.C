#include "Analyzer.H"
#include <iostream>

using namespace std;


void Analyzer::analyze(Visitable* v) {

	cerr << "Analyzing...\n\n";
	Env e;
	BasicInfoCollector b;
	b.collect(v, &e);
	e.printFunctions();
	
}