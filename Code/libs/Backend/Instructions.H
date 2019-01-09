#ifndef INSTRUCTIONS_HEADER
#define INSTRUCTIONS_HEADER

#include <string>

using std::string;

class Instruction {
public:
	string op;
	virtual string toStr() = 0;

};

class OneArgInstr : public Instruction {

public: 
	string arg;
	virtual string toStr() = 0;
};

class BinArgInstr : public Instruction {

public: 
	string arg1, arg2;
	virtual string toStr() = 0;
};


class Mov : public BinArgInstr {

public:

	string toStr();
};

class Add : public BinArgInstr {

public:

	string toStr();
};

class Sub : public BinArgInstr {

public:

	string toStr();
};

class IMul : public BinArgInstr {

public:

	string toStr();
};

class IDiv : public BinArgInstr {

public:

	string toStr();
};

class Lea : public BinArgInstr {

public:

	string toStr();
};

class Push : public OneArgInstr {

public:

	string toStr();
};

class Pop : public OneArgInstr {

public:

	string toStr();
};

class Call : public OneArgInstr {

public:

	string toStr();
};


class RetC : public Instruction {

public:

	string toStr();
};

#endif