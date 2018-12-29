CC = g++
CCFLAGS = -g 
# -W -Wall

FLEX = flex
FLEX_OPTS = -PLatteCPP

BISON = bison
BISON_OPTS = -t -pLatteCPP

OBJS = Absyn.o Lexer.o Parser.o Printer.o Analyzer.o BasicInfoCollector.o Environment.o
#Compiler.o

.PHONY: clean distclean

all: Main

clean:
	rm -f *.o TestLatteCPP LatteCPP.aux LatteCPP.log LatteCPP.pdf LatteCPP.dvi LatteCPP.ps LatteCPP

distclean: clean
	rm -f Absyn.C Absyn.H Test.C Parser.C Parser.H Lexer.C Skeleton.C Skeleton.H Printer.C Printer.H Makefile LatteCPP.l LatteCPP.y LatteCPP.tex 

TestLatteCPP: ${OBJS} Test.o
	@echo "Linking TestLatteCPP..."
	${CC} ${CCFLAGS} ${OBJS} Test.o -o TestLatteCPP

Absyn.o: Absyn.C Absyn.H
	${CC} ${CCFLAGS} -c Absyn.C

Lexer.C: LatteCPP.l
	${FLEX} -oLexer.C LatteCPP.l

Parser.C: LatteCPP.y
	${BISON} LatteCPP.y -o Parser.C

Lexer.o: Lexer.C Parser.H
	${CC} ${CCFLAGS} -c Lexer.C

Parser.o: Parser.C Absyn.H
	${CC} ${CCFLAGS} -c Parser.C

Printer.o: Printer.C Printer.H Absyn.H
	${CC} ${CCFLAGS} -c Printer.C

Skeleton.o: Skeleton.C Skeleton.H Absyn.H
	${CC} ${CCFLAGS} -c Skeleton.C

Test.o: Test.C Parser.H Printer.H Absyn.H
	${CC} ${CCFLAGS} -c Test.C
	
	
SemanticAnalyzer.o: SemanticAnalyzer.C SemanticAnalyzer.H Absyn.H
	${CC} ${CCFLAGS} -c SemanticAnalyzer.C


Environment.o: Environment.C Environment.H Absyn.H
	${CC} ${CCFLAGS} -c Environment.C

BasicInfoCollector.o: BasicInfoCollector.C BasicInfoCollector.H Absyn.H
	${CC} ${CCFLAGS} -c BasicInfoCollector.C

Analyzer.o: Analyzer.C Analyzer.H Absyn.H
	${CC} ${CCFLAGS} -c Analyzer.C

Compiler.o: Compiler.C Compiler.H Absyn.H
	${CC} ${CCFLAGS} -c Compiler.C

Main.o: Main.C Parser.H Printer.H Absyn.H Analyzer.H BasicInfoCollector.H
	${CC} ${CCFLAGS} -c Main.C

Main: ${OBJS} Main.o
	@echo "Linking  Main..."
	${CC} ${CCFLAGS} ${OBJS} Main.o -o Main

