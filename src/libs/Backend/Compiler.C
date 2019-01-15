#include <iostream>
#include <fstream>
#include "Compiler.H"

using namespace std;

void Compiler::compile(Visitable* v, Env* e) {
    // TODO: COmment this out
    cerr << "Compiling...\n\n";

    CodeCreator cc;
    cc.create(v, e);
    // cc.printAllInstrs();
    compiled = cc.generateSections() + cc.generateProgram();
    // cerr << compiled << "\n";
    cc.deleteInstr(); //free the memory
}


void Compiler::printProgramToFile(string filename) {
    ofstream file;
    file.open(filename); 

    file << compiled;
    file.close();
}