#ifndef ANALYZER_HEADER
#define ANALYZER_HEADER

#include <map>
#include <string>
#include <vector>
#include "BasicInfoCollector.H"
#include "TypeChecker.H"
#include "ReturnChecker.H"
#include "../Environment.H"

using std::map;
using std::string;
using std::vector;
using std::pair;



class Analyzer {
public:
	void analyze(Visitable* v, Env* e);


};








#endif