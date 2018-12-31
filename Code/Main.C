/* Main file for latte to ASM compiler
 * Author: Krzysztof Kiljan
 */
/****************************************************************************/
#include <stdio.h>
#include <iostream>
#include "libs/Absyn.H"
#include "libs/Parser.H"
#include "libs/Printer.H"
// #include "SemanticAnalyzer.H"
// #include "BasicInfoCollector.H"
#include "libs/Frontend/Analyzer.H"
// #include "Compiler.H"

using namespace std;

int main(int argc, char **argv) {
    FILE *input;
    if (argc > 1) {
        input = fopen(argv[1], "r");
        if (!input) {
            fprintf(stderr, "Error opening input file.\n");
            exit(1);
        }
    } else
        input = stdin;
    /* The default entry point is used. For other options see Parser.H */
    Program *parse_tree = pProgram(input);
    if (parse_tree) {
        Analyzer a;
        try {
            a.analyze(parse_tree);
        } catch (string s) {
            cerr << s << "\n";
            return 1;
        }

        // Compiler comp;
        // comp.compile(parse_tree, sa);
        // comp.debugPrintProgram();
        // comp.printProgramToFile("a.s");

        printf("\nParse Succesful!\n");
        printf("\n[Abstract Syntax]\n");
        ShowAbsyn *s = new ShowAbsyn();
        printf("%s\n\n", s->show(parse_tree));
        printf("[Linearized Tree]\n");
        PrintAbsyn *p = new PrintAbsyn();
        printf("%s\n\n", p->print(parse_tree));
        return 0;
    }
    return 1;
}
