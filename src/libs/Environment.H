#ifndef ENV_HEADER
#define ENV_HEADER

#include <map>
#include <string>
#include <vector>
#include "Types.H"

using std::map;
using std::pair;
using std::string;
using std::vector;

class Env {
   public:
    bool existsFunction(string name);
    void addFunction(string name, TType retType,
                     vector<pair<string, TType>> args);
    void printFunctions();
    TType getRetType(string name);
    vector<pair<string, TType>> getArgs(string name);
    int getArgsNum(string name);
    void addLocalsCnt(string name, int x);
    int getLocalsCnt(string name);

    void beginBlock();
    void endBlock();
    void addVarToCurScope(string s, TType t, int pos = 0);
    bool lookupVar(string s);
    TType lookupVarType(string s);
    int getPos(string s);
    bool isDeclaredInCurScope(string s);
    bool hasAnyScope();

    void addConstStr(string s);
    string getString(int nr);
    int getStrCnt();
    int getStrNr(string s);
    string getLabStr(int nr);
    string getLabStr(string s);

    void resetLabNr();
    string getNextLabel();

   private:
    map<string, pair<TType, vector<pair<string, TType>>>> functionsMap;
    map<string, int> funcLocalCounts;
    vector<map<string, TType>> varsStack;

    vector<string> constStrings;
    map<string, int> stringsNr;

    int labNr;
};

#endif