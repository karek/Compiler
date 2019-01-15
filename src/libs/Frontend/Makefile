CC = g++
CCFLAGS = -g 
# -W -Wall

FLEX = flex
FLEX_OPTS = -PLatteCPP

BISON = bison
BISON_OPTS = -t -pLatteCPP

OBJS = Analyzer.o BasicInfoCollector.o TypeChecker.o ReturnChecker.o
#Compiler.o

.PHONY: clean distclean

all: $(OBJS)

clean:
	rm -f *.o 


BasicInfoCollector.o: BasicInfoCollector.C BasicInfoCollector.H ../Absyn.H
	${CC} ${CCFLAGS} -c BasicInfoCollector.C
	
ReturnChecker.o: ReturnChecker.C ReturnChecker.H ../Absyn.H
	${CC} ${CCFLAGS} -c ReturnChecker.C

Analyzer.o: Analyzer.C Analyzer.H ../Absyn.H
	${CC} ${CCFLAGS} -c Analyzer.C

TypeChecker.o: TypeChecker.C TypeChecker.H ../Absyn.H
	${CC} ${CCFLAGS} -c TypeChecker.C

