lexer.o: src/lexer.cpp
	g++ -c -o lexer.o src/lexer.cpp

parser.o: src/parser.cpp
	g++ -c -o parser.o src/parser/.cpp

parser.out: src/parser.o 
	g++ -o parser.out src/parser.o

lexer.out: src/lexer.o 
	g++ -o lexer.out src/lexer.o

clear:
	rm *.o *.out
