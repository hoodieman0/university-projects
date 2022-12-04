CC=g++
CFLAGS=-std=c++11
binaries=SudokuMain-KorideMok.o State-KorideMok.o Board-KorideMok.o Cluster-KorideMok.o Diagboard-KorideMok.o Exceptions-KorideMok.o Game-KorideMok.o Square-KorideMok.o Frame-KorideMok.o UnitTests-KorideMok.o tools.o Canvas.o GridChar.o MixedChar.o Viewer.o

all: program

program: $(binaries)
	$(CC) $(binaries) -o program

SudokuMain-KorideMok.o: SudokuMain-KorideMok.cpp
	$(CC) -c $(CFLAGS) SudokuMain-KorideMok.cpp

State-KorideMok.o: State-KorideMok.cpp State-KorideMok.hpp
	$(CC) -c $(CFLAGS) State-KorideMok.cpp State-KorideMok.hpp

Board-KorideMok.o: Board-KorideMok.cpp Board-KorideMok.hpp
	$(CC) -c $(CFLAGS) Board-KorideMok.cpp Board-KorideMok.hpp

Cluster-KorideMok.o: Cluster-KorideMok.cpp Cluster-KorideMok.hpp
	$(CC) -c $(CFLAGS) Cluster-KorideMok.cpp Cluster-KorideMok.hpp

Diagboard-KorideMok.o: Diagboard-KorideMok.cpp Diagboard-KorideMok.hpp
	$(CC) -c $(CFLAGS) Diagboard-KorideMok.cpp Diagboard-KorideMok.hpp

Exceptions.o: Exceptions.cpp Exceptions.hpp
	$(CC) -c $(CFLAGS) Exceptions.cpp Exceptions.hpp

Game-KorideMok.o: Game-KorideMok.cpp Game-KorideMok.hpp
	$(CC) -c $(CFLAGS) Game-KorideMok.cpp Game-KorideMok.hpp

Square-KorideMok.o: Square-KorideMok.cpp Square-KorideMok.hpp
	$(CC) -c $(CFLAGS) Square-KorideMok.cpp Square-KorideMok.hpp

Frame-KorideMok.o: Frame-KorideMok.cpp Frame-KorideMok.hpp
	$(CC) -c $(CFLAGS) Frame-KorideMok.cpp Frame-KorideMok.hpp

UnitTests-KorideMok.o: UnitTests-KorideMok.cpp UnitTests-KorideMok.hpp
	$(CC) -c $(CFLAGS) UnitTests-KorideMok.cpp UnitTests-KorideMok.hpp

tools.o: tools.hpp tools.cpp
	$(CC) -c $(CFLAGS) tools.hpp tools.cpp

Canvas.o: Canvas.cpp Canvas.hpp
	$(CC) -c $(CFLAGS) Canvas.cpp Canvas.hpp

GridChar.o: GridChar.cpp GridChar.hpp
	$(CC) -c $(CFLAGS) GridChar.cpp GridChar.hpp

MixedChar.o: MixedChar.cpp MixedChar.hpp
	$(CC) -c $(CFLAGS) MixedChar.cpp MixedChar.hpp

Viewer.o: Viewer.cpp Viewer.hpp
	$(CC) -c $(CFLAGS) Viewer.cpp Viewer.hpp

clean:
	rm program *.o *.gch