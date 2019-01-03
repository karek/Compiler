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

public: 
	vType typ;
	TType() : s_(""), i_(0), b_(false) {
		typ = vType::tNone;
	}
	TType(vType vt) : s_(""), i_(0), b_(false) {
		typ = vt;
	}

	TType(vType vt, string s) : s_(s), i_(0), b_(false) {
		typ = vt;
	}

	TType(vType vt, int i) : s_(""), i_(i), b_(false) {
		typ = vt;
	}

	TType(vType vt, bool b) : s_(""), i_(0), b_(b) {
		typ = vt;
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

	//TODO: Add Classes / arrays?
	bool isAnything() const {
		return typ != vType::tNone;
	}


	string toStr() const {
		switch(typ) {
			// {tVoid, tInt, tBool, tString, tClass, tNone};
			case vType::tVoid : return "tvoid"; break;
			case vType::tInt : return "tint"; break;
			case vType::tBool : return "tbool"; break;
			case vType::tStr : return "tstr"; break;
			case vType::tClass : return "tclass"; break;
			case vType::tNone : return "none"; break;
		}

		return "Err";
	}

	void printType() const {
		cerr << toStr() << "\n";
	}

};


#endif