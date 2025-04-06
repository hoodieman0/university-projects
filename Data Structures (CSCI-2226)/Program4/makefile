CC=g++
CFLAGS=-std=c++11
binaries = main.o

all: program

program: $(binaries)
	$(CC) $(binaries) -o program

main.o: main.cpp RedBlackTreeTemplate.hpp LinkedListTemplate.hpp
	$(CC) -c $(CFLAGS) main.cpp

clean: 
	rm program $(binaries)
	rm -f *.stackdump
