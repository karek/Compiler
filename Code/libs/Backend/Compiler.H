#ifndef COMPILER_HEADER
#define COMPILER_HEADER

#include <map>
#include <string>
#include <vector>
#include "CodeCreator.H"
#include "../Environment.H"

using std::map;
using std::string;
using std::vector;
using std::pair;



class Compiler {
private:
	string compiled;
public:
	void compile(Visitable* v, Env* e);
	void printProgramToFile(string filename);

};








#endif