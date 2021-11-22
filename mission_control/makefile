main: out/*.o
	g++ -g -o main out/*.o
out/*.o: *.cpp */*.cpp
	g++ -c -g */*.cpp *.cpp; mv -f *.o out/
run:
	make
	./main
clean:
	-@rm out/*.o main 2>/dev/null
leakcheck:
	valgrind --leak-check=yes ./main
gdb:
	gdb main -ex "set disassembly-flavor intel" -ex "break main" -ex "layout reg" -ex "focus cmd"
archive:
	tar -cvz *.h *.cpp -f archive.tar
