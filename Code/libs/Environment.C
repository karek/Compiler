#include "Environment.H"
#include <iostream>

using namespace std;


bool Env::existsFunction(string s) {
	return functionsMap.count(s) > 0;
}


void Env::addFunction(string name, TType retType, vector<pair<string, TType> > args) {
	functionsMap[name] = {retType, args};
}


TType Env::getRetType(string name) {
	return functionsMap[name].first;
}

vector<pair<string, TType>> Env::getArgs(string name) {
	return functionsMap[name].second;
}

void Env::printFunctions() {
	cerr << "Functions declared:\n";
	// map<string, pair<TType, vector<pair<string, TType>>>>
	for(auto it = functionsMap.begin(); it != functionsMap.end(); it++) {
		cerr << it->second.first.toStr() << " " << it->first << " (";
		for(auto it2: it->second.second) {
			cerr << it2.second.toStr() << " " << it2.first << ", ";
		}
		cerr << ")\n";
	}

}