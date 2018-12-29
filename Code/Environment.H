#ifndef ENV_HEADER
#define ENV_HEADER

#include <map>
#include <string>
#include <vector>

using std::map;
using std::string;
using std::vector;
using std::pair;  // #include <utility>  ?



class Env {
public:
	bool existsFunction(string name);

	void addFunction(string name); // TODO: ADD PARAMS AND RET TYPE


private:
	map<string, int> functionsMap;


};








#endif