CXX=g++
CXXFLAGS=-ll
OBJS = parser.o lex.yy.o nodo.o
CABS = nodo.hpp lexico.h

pinglang: $(OBJS)
	g++ -o pinglang $(OBJS) -ll

lex.yy.c: lexico.l
	flex lexico.l

lex.yy.o: $(CABS) lex.yy.c
	$(CXX) -c -std=c++11 lex.yy.c
parser.o: $(CABS) parser.cpp
	$(CXX) -c -std=c++11 parser.cpp

nodo.o: $(CABS)
	$(CXX) -c -std=c++11 nodo.cpp

check:	pinglang
	./pinglang test.ping && ./test

clean:
	rm -f lex.yy.c *~ *.o pinglang

.PHONY: clean check
