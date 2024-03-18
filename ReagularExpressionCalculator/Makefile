lexer.o: src/lexer.cpp
	g++ -c src/lexer.cpp

main.o: src/main.cpp
	g++ -c src/main.cpp

final: lexer.o main.o
	g++ -o final lexer.o main.o

all: final

clear:
	rm *.o final
