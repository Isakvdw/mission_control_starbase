test:*.o
	g++ -g -o test *.o
*.o:*.cpp
	g++ -c -g *.cpp
run:
	./test
clean:
	rm *.o test
leakcheck:
	valgrind --leak-check=yes ./test
gdb:
	gdb test
tar:
	tar -cvz *.h *.cpp -f archive.tar