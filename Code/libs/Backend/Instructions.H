#ifndef INSTRUCTIONS_HEADER
#define INSTRUCTIONS_HEADER

#include <string>

using std::string;

// First three don't need to be saved
enum class Reg {EAX, ECX, EDX, ESP, EBP, ESI, EDI, EBX};

string toStr(Reg r);


class Instruction {
   public:
    string op;
    virtual string toStr() = 0;
    virtual bool isLabel() {
    	return false;
    }
};


class Label : public Instruction {
public: 
	Label(string s) : Instruction() {
		op = s;
	}
	
	string toStr() {
		return op + ":\n";
	}
	bool isLabel() {
    	return true;
    }
};


class OneArgInstr : public Instruction {
   public:
    string arg;
    virtual string toStr() {
    	return op + " " + arg + "\n";
    };
};

class BinArgInstr : public Instruction {
   public:
    BinArgInstr() {}
    string arg1, arg2;
    virtual string toStr() {
        return op + " " + arg1 + ", " + arg2 + "\n";
    };
};

class Mov : public BinArgInstr {
   public:
    Mov(string arg1_, string arg2_) : BinArgInstr() {
        op = "movl";
        arg1 = (arg1_);
        arg2 = (arg2_);
    }

    // string toStr()  {return op;}
};

class Add : public BinArgInstr {
   public:
    Add(string arg1_, string arg2_) : BinArgInstr() {
        op = "add";
        arg1 = (arg1_);
        arg2 = (arg2_);
    }
};

class Sub : public BinArgInstr {
   public:
    Sub(string arg1_, string arg2_) : BinArgInstr() {
        op = "sub";
        arg1 = (arg1_);
        arg2 = (arg2_);
    }
};

class IMul : public BinArgInstr {
   public:
   IMul(string arg1_, string arg2_) :
		BinArgInstr() {
			op = "imul";
			arg1 = (arg1_);
			arg2 = (arg2_); 
		}
};

class IDiv : public OneArgInstr {
   public:
   	IDiv(string arg1_) :
		OneArgInstr() {
			op = "idiv";
			arg = (arg1_);
		}
};

class Cdq : public Instruction {
public:
	Cdq() :
		Instruction() {
			op = "cdq";
	}

	string toStr() {
		return op + "\n";
	}
};


class Lea : public BinArgInstr {
   public:
    string toStr();
};

class Push : public OneArgInstr {
   public:
   Push(string arg_) :
		OneArgInstr() {
			op = "push";
			arg = arg_;
	}
};

class Pop : public OneArgInstr {
   public:
   Pop(string arg_) :
		OneArgInstr() {
			op = "pop";
			arg = arg_;
	}
};

class Call : public OneArgInstr {
   public:
   Call(string arg_) :
		OneArgInstr() {
			op = "call";
			arg = arg_;
	}
};

class RetC : public Instruction {
   public:
   RetC() :
		Instruction() {
			op = "ret";
	}

	string toStr() {
		return op + "\n";
	}
};


class Inc : public OneArgInstr {
   public:
   Inc(string arg_) :
		OneArgInstr() {
			op = "inc";
			arg = arg_;
	}
};

class NegI : public OneArgInstr {
   public:
   NegI(string arg_) :
		OneArgInstr() {
			op = "neg";
			arg = arg_;
	}
};



//TODO JUMPs
#endif