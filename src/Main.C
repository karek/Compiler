/* Main file for latte to ASM compiler
 * Author: Krzysztof Kiljan
 */
/****************************************************************************/
#include <stdio.h>
#include <iostream>
#include <sstream>
#include "libs/Absyn.H"
#include "libs/Backend/Compiler.H"
#include "libs/Environment.H"
#include "libs/Frontend/Analyzer.H"
#include "libs/Parser.H"
#include "libs/Printer.H"

using namespace std;
const string CODE_BOLD = "\e[1m";
const string CODE_WRONG = "\e[31m";
const string CODE_END = "\e[0m";

vector<string> split(const string &str, char delim = '/') {
    vector<string> cont;
    size_t current, previous = 0;
    current = str.find(delim);
    while (current != string::npos) {
        cont.push_back(str.substr(previous, current - previous));
        previous = current + 1;
        current = str.find(delim, previous);
    }
    cont.push_back(str.substr(previous, current - previous));

    return cont;
}

int main(int argc, char **argv) {
    FILE *input;
    if (argc > 1) {
        input = fopen(argv[1], "r");
        if (!input) {
            cerr << "ERROR\nError opening input file.\n";
            exit(1);
        }
    } else {
        cerr << "ERROR\n No filename provided.\n";
        exit(1);
    }

    string filename = argv[1];
    vector<string> path = split(filename);

    string dir;
    stringstream ss;
    for (uint i = 0; i < path.size() - 1; i++) {
        ss << path[i] << "/";
    }
    string clName = split(path.back(), '.')[0];

    dir = ss.str();
    if (dir == "")
        dir = "./";

    string noExt = dir + clName;
    string sfile = noExt + ".s";

    /* The default entry point is used. For other options see Parser.H */
    Program *parse_tree = pProgram(input);
    if (parse_tree) {
        Analyzer a;
        Env env;
        try {
            a.analyze(parse_tree, &env);
        } catch (string s) {
            cerr << "ERROR\n";
            cerr << CODE_BOLD << CODE_WRONG << "Error: " << CODE_END << s
                 << "\n";
            return 1;
        }

        Compiler comp;
        cerr << "OK\n";
        try {
            comp.compile(parse_tree, &env);
        } catch (string w) {
            cerr << "Error in compile time: " << w << "\n";
            return 1;
        };


        cerr << "Saving program to file " << sfile << " ...\n";
        comp.printProgramToFile(sfile);

        string call1 = "gcc -c -m32 " + sfile + " -o " + noExt + ".o ";
        cerr << call1 << "\n";
        system(call1.c_str());

        string call2 = "ld -s -o " + noExt + " -melf_i386 " + noExt + ".o " +
         "lib/crti.o lib/crt1.o lib/crtn.o lib/runtime.o " 
         + " -L./lib -l:libc.a ";
        cerr << "Linking... \n" << call2 << "\n";
        system(call2.c_str());
        return 0;
    }
    return 1;
}
