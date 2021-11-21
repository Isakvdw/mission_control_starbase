main: main.o
		g++ -static main.o -o main

main.o: *.cpp *.h
		g++ main.cpp -c

run:
		./main