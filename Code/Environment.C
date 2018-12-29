#include "Environment.H"



bool Env::existsFunction(string s) {
	return functionsMap.count(s) > 0;
}


void Env::addFunction(string name) {

	functionsMap[name] = 1;


}