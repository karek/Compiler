#ifndef INSTRUCTIONS_HEADER
#define INSTRUCTIONS_HEADER

#include <string>

using std::string;

const int MULTIPLIER = 4;

// First three don't need to be saved
enum class Reg { EAX, ECX, EDX, ESP, EBP, ESI, EDI, EBX };

string rtoStr(Reg r);

class Addr {
   public:
    Reg r;
    int modifier;
    Addr(Reg r_, int m = 0) : r(r_), modifier(m) {}

    string toStr(bool isAddr = false);
};

class Instruction {
   public:
    string op;
    virtual string toStr() = 0;
    virtual bool isLabel() {
        return false;
    }
};

// class Comment : public Instruction {
//    public:
// 	Comment(string s) : Instruction() {
//         op = s;
//     }

//     string toStr() {
//         return op ;
//     }
//     bool isLabel() {
//         return true;
//     }
// }

class Label : public Instruction {
   public:
    string comment;
    Label(string s, string com ="") : Instruction() {
        op = s;
        comment = com;
    }

    string toStr() {
        return op + ":" + comment + "\n";
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
    IMul(string arg1_, string arg2_) : BinArgInstr() {
        op = "imul";
        arg1 = (arg1_);
        arg2 = (arg2_);
    }
};

class IDiv : public OneArgInstr {
   public:
    IDiv(string arg1_) : OneArgInstr() {
        op = "idiv";
        arg = (arg1_);
    }
};

class Cdq : public Instruction {
   public:
    Cdq() : Instruction() {
        op = "cdq";
    }

    string toStr() {
        return op + "\n";
    }
};

class Lea : public BinArgInstr {
   public:
    Lea(string arg1_, string arg2_) : BinArgInstr() {
        op = "lea";
        arg1 = (arg1_);
        arg2 = (arg2_);
    }
};

class Push : public OneArgInstr {
   public:
    Push(string arg_) : OneArgInstr() {
        op = "push";
        arg = arg_;
    }
};

class Pop : public OneArgInstr {
   public:
    Pop(string arg_) : OneArgInstr() {
        op = "pop";
        arg = arg_;
    }
};

class Call : public OneArgInstr {
   public:
    Call(string arg_) : OneArgInstr() {
        op = "call";
        arg = arg_;
    }
};

class RetC : public Instruction {
   public:
    RetC() : Instruction() {
        op = "ret";
    }

    string toStr() {
        return op + "\n";
    }
};

class Inc : public OneArgInstr {
   public:
    Inc(string arg_) : OneArgInstr() {
        op = "incl";
        arg = arg_;
    }
};

class Dec : public OneArgInstr {
   public:
    Dec(string arg_) : OneArgInstr() {
        op = "decl";
        arg = arg_;
    }
};

class NegI : public OneArgInstr {
   public:
    NegI(string arg_) : OneArgInstr() {
        op = "neg";
        arg = arg_;
    }
};


class Jmp : public OneArgInstr {
	public:
    Jmp(string arg_) : OneArgInstr() {
        op = "jmp";
        arg = arg_;
    }
};

class Jz : public OneArgInstr {
    public:
    Jz(string arg_) : OneArgInstr() {
        op = "jz";
        arg = arg_;
    }
};

class Jnz : public OneArgInstr {
    public:
    Jnz(string arg_) : OneArgInstr() {
        op = "jnz";
        arg = arg_;
    }
};

class Jeq : public OneArgInstr {
	public:
    Jeq(string arg_) : OneArgInstr() {
        op = "je";
        arg = arg_;
    }
};

class Jneq : public OneArgInstr {
	public:
    Jneq(string arg_) : OneArgInstr() {
        op = "jne";
        arg = arg_;
    }
};

class Jgt : public OneArgInstr {
	public:
    Jgt(string arg_) : OneArgInstr() {
        op = "jg";
        arg = arg_;
    }
};

class Jge : public OneArgInstr {
	public:
    Jge(string arg_) : OneArgInstr() {
        op = "jge";
        arg = arg_;
    }
};

class Jlt : public OneArgInstr {
	public:
    Jlt(string arg_) : OneArgInstr() {
        op = "jl";
        arg = arg_;
    }
};


class Jle : public OneArgInstr {
	public:
    Jle(string arg_) : OneArgInstr() {
        op = "jle";
        arg = arg_;
    }
};


class Cmp : public BinArgInstr {
	public:
    Cmp(string arg1_, string arg2_) : BinArgInstr() {
        op = "cmpl";
        arg1 = (arg1_);
        arg2 = (arg2_);
    }

};

class Testz : public BinArgInstr {
    public:
    Testz(string arg1_, string arg2_) : BinArgInstr() {
        op = "test";
        arg1 = (arg1_);
        arg2 = (arg2_);
    }

};

#endif