final: main.o Dependencies/HelperObjects.o Interpreter.o
	g++ -o final final.o Dependencies/HelperObjects.o Interpreter.o

main.o: main.cpp
	g++ -c main.cpp

Dependencies/HelperObjects.o: HelperObjects.o 

clean:
	rm *.o final
