CC = g++
CCFLAGS = -g -W -Wall

FLEX = flex
FLEX_OPTS = -PLatteCPP

BISON = bison
BISON_OPTS = -t -pLatteCPP

OBJS = Absyn.o Lexer.o Parser.o Printer.o Environment.o
#Compiler.o

.PHONY: clean distclean

all: $(OBJS)

clean:
	rm -f *.o
	cd Frontend/ && make clean
	cd Backend/ && make clean
# 
# distclean: clean
# 	rm -f Absyn.C Absyn.H Test.C Parser.C Parser.H Lexer.C Skeleton.C Skeleton.H Printer.C Printer.H LatteCPP.l LatteCPP.y LatteCPP.tex 


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

	
# SemanticAnalyzer.o: SemanticAnalyzer.C SemanticAnalyzer.H Absyn.H
# 	${CC} ${CCFLAGS} -c SemanticAnalyzer.C

Environment.o: Environment.C Environment.H Absyn.H Types.H
	${CC} ${CCFLAGS} -c Environment.C

# BasicInfoCollector.o: BasicInfoCollector.C BasicInfoCollector.H Absyn.H
# 	${CC} ${CCFLAGS} -c BasicInfoCollector.C

# Analyzer.o: Analyzer.C Analyzer.H Absyn.H
# 	${CC} ${CCFLAGS} -c Analyzer.C
# 
# Compiler.o: Compiler.C Compiler.H Absyn.H
# 	${CC} ${CCFLAGS} -c Compiler.C


