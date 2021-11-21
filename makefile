test: test.o
		g++ -static test.o -o test

test.o: *.cpp *.h
		g++ test.cpp -c

run:
		./test