CC= g++
DEBUG= -g -O0 -pedantic-errors
CFLAGS= -c -Wall -std=c++11 $(DEBUG)
LFLAGS= -Wall $(DEBUG)
COMPILE=$(CC) $(CFLAGS)
LINK= $(CC) $(LFLAGS)

SRC=$(wildcard *.cpp)
OBJ=$(SRC:%.cpp:%.o)
EXE=$(OBJ:%.o:%)

.SUFFIXES: .cpp .o
.PHONY: clean 

all: parser list.o

parser:parser.o list.o
	$(LINK) -o parser parser.o list.o
parser.o:parser.cpp
	$(COMPILE) parser.cpp

list.o:list.cpp
	$(COMPILE) list.cpp

clean: 
	rm -f *.o
	rm -f list