
all: foo

foo: test.o foo.o
	g++ foo.o test.o -o foo

foo.o:
	g++ -c foo.cpp

test.o:
	gcc -c test.c

clean:
	-rm -f foo *.o
