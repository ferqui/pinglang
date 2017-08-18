CXX=g++
CXXFLAGS=-ll
OBJECTS=gramatica.tab.o lex.yy.o

all:	main

main:	$(OBJECTS)
	$(CXX) -o main $(OBJECTS) $(CXXFLAGS)

gramatica.tab.o:	gramatica.tab.c
	$(CXX) -c -std=c++11 gramatica.tab.c

lex.yy.o:	lex.yy.c
	$(CXX) -c lex.yy.c

lex.yy.c:	lexico.l
	flex lexico.l

gramatica.tab.c:	gramatica.y
	bison -d gramatica.y

check:	main
	cat test | ./main

clean:
	rm -f *.o *~ gramatica.tab.c gramatica.tab.h lex.yy.c main
