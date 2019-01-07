CC = g++
CCFLAGS = -g 
# -W -Wall

FLEX = flex
FLEX_OPTS = -PLatteCPP

BISON = bison
BISON_OPTS = -t -pLatteCPP

OBJS = libs/Absyn.o libs/Lexer.o libs/Parser.o libs/Printer.o \
		libs/Frontend/Analyzer.o libs/Frontend/BasicInfoCollector.o libs/Environment.o \
		libs/Frontend/TypeChecker.o libs/Frontend/ReturnChecker.o
#Compiler.o

.PHONY: clean distclean

all: Main

clean:
	rm -f *.o Main
	cd libs/ && make clean

distclean: clean
	rm -f Absyn.C Absyn.H Test.C Parser.C Parser.H Lexer.C Skeleton.C Skeleton.H Printer.C Printer.H LatteCPP.l LatteCPP.y LatteCPP.tex 

Main.o: Main.C libs/Parser.H libs/Printer.H libs/Absyn.H \
	 libs/Frontend/Analyzer.H libs/Frontend/BasicInfoCollector.H libs/Frontend/TypeChecker.H libs/Frontend/ReturnChecker.H \
	 libs/Environment.H
	${CC} ${CCFLAGS} -c Main.C

Main: ${OBJS} Main.o
	@echo "Linking  Main..."
	${CC} ${CCFLAGS} ${OBJS} Main.o -o Main

