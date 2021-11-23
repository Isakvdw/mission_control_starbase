main: out/*.o
	g++ -g -o main.out out/*.o
out/*.o: *.cpp */*.cpp
	g++ -c -g */*.cpp *.cpp; mv -f *.o out/
run:
	make
	./main.out
r:
	./main.out

runonce: run clean

clean:
	-@rm out/*.o main.out 2>/dev/null
leakcheck:
	valgrind --leak-check=yes ./main.out
gdb:
	gdb main.out -ex "set disassembly-flavor intel" -ex "break main" -ex "layout reg" -ex "focus cmd"
archive:
	tar -cvz *.h *.cpp -f archive.tar
