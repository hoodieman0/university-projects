CC=g++
CFLAGS=-std=c++11
binaries = main.o GameController.o

all: program

program: $(binaries)
	$(CC) $(binaries) -o program

main.o: main.cpp CircularLinkedListTemp.hpp SlotMachine.hpp
	$(CC) -c $(CFLAGS) main.cpp

GameController.o: GameController.cpp GameController.hpp
	$(CC) -c $(CFLAGS) GameController.cpp

clean: 
	rm program $(binaries)
	rm -f *.stackdump
