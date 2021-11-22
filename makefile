main:*.o
	g++ -g -o main *.o
*.o:*.cpp
	g++ -c -g *.cpp
run:
	./main
clean:
	rm *.o main
leakcheck:
	valgrind --leak-check=yes ./main
gdb:
	gdb main
tar:
	tar -cvz *.h *.cpp -f archive.tar