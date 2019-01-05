#include "Environment.H"
#include <iostream>
#include <cassert>

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

int Env::getArgsNum(string name) {
	return functionsMap[name].second.size();
}

void Env::beginBlock() {
	varsStack.push_back({});
}

void Env::endBlock() {
	varsStack.pop_back();
}

void Env::addVarToCurScope(string s, TType t) {
	assert(varsStack.size() > 0);
	assert(varsStack.back().count(s) == 0);
	varsStack.back()[s] = t;
}

bool Env::isDeclaredInCurScope(string s) {
	assert(varsStack.size() > 0);
	return varsStack.back().count(s);
}

bool Env::hasAnyScope() {
	return !varsStack.empty();
}

bool Env::lookupVar(string s) {
	for(int i = varsStack.size() - 1; i >= 0; i--) {
		if (varsStack[i].count(s))
			return true;
	}
	return false;
}


TType Env::lookupVarType(string s) {
	for(int i = varsStack.size() - 1; i >= 0; i--) {
		if (varsStack[i].count(s))
			return varsStack[i][s];
	}

	return vType::tNone;
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