#ifndef ENV_HEADER
#define ENV_HEADER

#include <map>
#include <string>
#include <vector>
#include "Types.H"

using std::map;
using std::string;
using std::vector;
using std::pair;


class Env {
public:
	bool existsFunction(string name);

	void addFunction(string name, TType retType, vector<pair<string, TType> > args); 

	void printFunctions();

private:
	map<string, pair<TType, vector<pair<string, TType>>>> functionsMap;


};








#endif