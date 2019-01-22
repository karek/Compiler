#ifndef TYPES_HEADER
#define TYPES_HEADER

#include <iostream>
#include <string>

using std::string;
using std::cerr;
using std::ostream;

enum class vType {tVoid, tInt, tBool, tStr, tClass, tNone};

class TType {
private: 
	//vals
	string s_;
	int i_;
	bool b_;
	vType typ;
	int _posModifier;
	bool isArr_;

public: 
	
	TType() : s_(""), i_(0), b_(false) {
		typ = vType::tNone;
		isArr_ = false;
	}
	TType(vType vt) : s_(""), i_(0), b_(false) {
		typ = vt;
		isArr_ = false;
	}

	TType(vType vt, string s) : s_(s), i_(0), b_(false) {
		typ = vt;
		isArr_ = false;
	}

	TType(vType vt, int i) : s_(""), i_(i), b_(false) {
		typ = vt;
		isArr_ = false;
	}

	TType(vType vt, bool b) : s_(""), i_(0), b_(b) {
		typ = vt;
		isArr_ = false;
	}


	void setPos(int p) {
		_posModifier = p;
	}

	void setIsArr(bool b) {
		isArr_ = b;
	}

	int getPos() {
		return _posModifier;
	}

	bool isInt() const {
		return typ == vType::tInt;
	}

	bool isVoid() const {
		return typ == vType::tVoid;
	}

	bool isString() const {
		return typ == vType::tStr;
	}
	
	bool isBool() const {
		return typ == vType::tBool;
	}

	bool isArray() const {
		return isArr_ == true;
	}

	//TODO: Add Classes / arrays?
	bool isAnything() const {
		return typ != vType::tNone;
	}


	vType getTyp() const {
		return typ;
	}

	string toStr() const {
		string arr;
		if (isArray())
			arr = "[]";
		switch(typ) {
			// {tVoid, tInt, tBool, tString, tClass, tNone};
			case vType::tVoid : return "tvoid" + arr; break;
			case vType::tInt : return "tint" + arr; break;
			case vType::tBool : return "tbool" + arr; break;
			case vType::tStr : return "tstr" + arr; break;
			case vType::tClass : return "tclass" + arr; break;
			case vType::tNone : return "none" + arr; break;
		}

		return "Err";
	}

	void printType() const {
		cerr << toStr() << "\n";
	}

	friend bool operator==(const TType& lhs, const TType& rhs){
    	return lhs.getTyp() == rhs.getTyp() && lhs.isArray() == rhs.isArray();
	}

};



enum class vOp {oPlus, oMinus, oMul, oDiv, oMod, oNone};

class TOp {
private: 
	vOp operator_;

public: 
	
	TOp() {
		operator_ = vOp::oNone;
	}
	
	TOp(vOp o) : operator_(o) {

	}

	bool isPlus() const {
		return operator_ == vOp::oPlus;
	}

	//TODO: Add Classes / arrays?
	bool isAnything() const {
		return operator_ != vOp::oNone;
	}


	vOp getOp() const {
		return operator_;
	}

	string toStr() const {
		switch(operator_) {
			// {oPlus, oMinus, oMul, oDiv, oMod, oNone};
			case vOp::oPlus : return "add"; break;
			case vOp::oMinus : return "sub"; break;
			case vOp::oMul : return "mul"; break;
			case vOp::oDiv : return "div"; break;
			case vOp::oMod : return "mod"; break;
			case vOp::oNone : return "none"; break;
		}

		return "Err";
	}

	void printType() const {
		cerr << toStr() << "\n";
	}

	friend bool operator==(const TOp& lhs, const TOp& rhs){
    	return lhs.getOp() == rhs.getOp();
	}

};


enum class vRelop {oLt, oLe, oGt, oGe, oEq, oNeq, oNone};

class TRelop {
private: 
	vRelop operator_;

public: 
	
	TRelop() {
		operator_ = vRelop::oNone;
	}
	
	TRelop(vRelop o) : operator_(o) {

	}

	bool isEq() const {
		return operator_ == vRelop::oEq;
	}

	bool isNeq() const {
		return operator_ == vRelop::oNeq;
	}

	bool isAnything() const {
		return operator_ != vRelop::oNone;
	}


	vRelop getOp() const {
		return operator_;
	}

	string toStr() const {
		switch(operator_) {
			// {oLt, oLe, oGt, oGe, oEq, oNeq, oNone};
			case vRelop::oLt : return "lt"; break;
			case vRelop::oLe : return "le"; break;
			case vRelop::oGt : return "gt"; break;
			case vRelop::oGe : return "ge"; break;
			case vRelop::oEq : return "eq"; break;
			case vRelop::oNeq : return "neq"; break;
			case vRelop::oNone : return "none"; break;
		}

		return "Err";
	}

	void printType() const {
		cerr << toStr() << "\n";
	}

	friend bool operator==(const TRelop& lhs, const TRelop& rhs){
    	return lhs.getOp() == rhs.getOp();
	}

};


#endif