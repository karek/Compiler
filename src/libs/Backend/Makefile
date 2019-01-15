CC = g++
CCFLAGS = -g 
# -W -Wall

FLEX = flex
FLEX_OPTS = -PLatteCPP

BISON = bison
BISON_OPTS = -t -pLatteCPP

OBJS = CodeCreator.o Compiler.o Instructions.o
#Compiler.o

.PHONY: clean distclean

all: $(OBJS)

clean:
	rm -f *.o 


BasicInfoCollector.o: BasicInfoCollector.C BasicInfoCollector.H ../Absyn.H
	${CC} ${CCFLAGS} -c BasicInfoCollector.C
	
CodeCreator.o: CodeCreator.C CodeCreator.H ../Absyn.H
	${CC} ${CCFLAGS} -c CodeCreator.C

Compiler.o: Compiler.C Compiler.H ../Absyn.H
	${CC} ${CCFLAGS} -c Compiler.C

Instructions.o: Instructions.C Instructions.H ../Absyn.H
	${CC} ${CCFLAGS} -c Instructions.C

