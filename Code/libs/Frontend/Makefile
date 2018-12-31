CC = g++
CCFLAGS = -g 
# -W -Wall

FLEX = flex
FLEX_OPTS = -PLatteCPP

BISON = bison
BISON_OPTS = -t -pLatteCPP

OBJS = Analyzer.o BasicInfoCollector.o
#Compiler.o

.PHONY: clean distclean

all: $(OBJS)

clean:
	rm -f *.o 


BasicInfoCollector.o: BasicInfoCollector.C BasicInfoCollector.H ../Absyn.H
	${CC} ${CCFLAGS} -c BasicInfoCollector.C

Analyzer.o: Analyzer.C Analyzer.H ../Absyn.H
	${CC} ${CCFLAGS} -c Analyzer.C


