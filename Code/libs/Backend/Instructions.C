#include "Instructions.H"
#include <string>

using namespace std;

string toStr(Reg r){
	switch(r) {
			// {EAX, ECX, EDX, ESP, EBP, ESI, EDI, EBX};
			case Reg::EAX : return "\%eax"; break;
			case Reg::ECX : return "\%ecx"; break;
			case Reg::EDX : return "\%edx"; break;
			case Reg::ESP : return "\%esp"; break;
			case Reg::EBP : return "\%ebp"; break;
			case Reg::ESI : return "\%esi"; break;
			case Reg::EDI : return "\%edi"; break;
			case Reg::EBX : return "\%ebx"; break;
		}
	return "";
}