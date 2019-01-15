#include <cassert>
#include <iostream>
#include <sstream>
#include "Environment.H"

using namespace std;

bool Env::existsFunction(string s) {
    return functionsMap.count(s) > 0;
}

void Env::addFunction(string name, TType retType,
                      vector<pair<string, TType>> args) {
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

void Env::addLocalsCnt(string name, int x) {
    if (!funcLocalCounts.count(name))
        funcLocalCounts[name] = x;
    else
        funcLocalCounts[name] += x;
}

int Env::getLocalsCnt(string name) {
    return funcLocalCounts[name];
}

void Env::addVarToCurScope(string s, TType t, int pos) {
    assert(varsStack.size() > 0);
    assert(varsStack.back().count(s) == 0);
    varsStack.back()[s] = t;
    if (pos)
        varsStack.back()[s].setPos(pos);
}

bool Env::isDeclaredInCurScope(string s) {
    assert(varsStack.size() > 0);
    return varsStack.back().count(s);
}

bool Env::hasAnyScope() {
    return !varsStack.empty();
}

bool Env::lookupVar(string s) {
    for (int i = varsStack.size() - 1; i >= 0; i--) {
        if (varsStack[i].count(s))
            return true;
    }
    return false;
}

TType Env::lookupVarType(string s) {
    for (int i = varsStack.size() - 1; i >= 0; i--) {
        if (varsStack[i].count(s))
            return varsStack[i][s];
    }

    throw("Lookup of a variable that doesn't exist\n"s);
    return vType::tNone;
}

int Env::getPos(string s) {
    TType x = lookupVarType(s);
    return x.getPos();
}

void Env::printFunctions() {
    cerr << "Functions declared:\n";
    // map<string, pair<TType, vector<pair<string, TType>>>>
    for (auto it = functionsMap.begin(); it != functionsMap.end(); it++) {
        cerr << it->second.first.toStr() << " " << it->first << " (";
        for (auto it2 : it->second.second) {
            cerr << it2.second.toStr() << " " << it2.first << ", ";
        }
        cerr << ")  -> locals cnt = " << getLocalsCnt(it->first) << "\n";
    }
}

void Env::addConstStr(string s) {
    if (stringsNr.count(s) != 0)
        return;
    stringsNr[s] = constStrings.size();
    constStrings.push_back(s);
}

string Env::getString(int nr) {
    return constStrings[nr];
}

int Env::getStrCnt() {
    return stringsNr.size();
}

int Env::getStrNr(string s) {
    return stringsNr[s];
}

string Env::getLabStr(int nr) {
    stringstream ss;
    // int nr = getStrNr(s);
    ss << "_CSL" << nr;
    return ss.str();
}

string Env::getLabStr(string s) {
    stringstream ss;
    int nr = getStrNr(s);
    ss << "_CSL" << nr;
    return ss.str();
}


void Env::resetLabNr() {
	labNr = 0;
}

string Env::getNextLabel() {
	labNr++;
	stringstream ss;
	ss << "_lab" << labNr;
	return ss.str();
}