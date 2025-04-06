CC=g++
CFLAGS=-std=c++11
binaries = main.o Actor.o Battle.o CommandManager.o CurseAttack.o Game.o GhostActor.o KnightActor.o MeleeAttack.o SpellAttack.o SwordAttack.o

all: program

program: $(binaries)
	$(CC) $(binaries) -o program

main.o: main.cpp Game.cpp Game.hpp ActorType.hpp MoveType.hpp
	$(CC) -c $(CFLAGS) main.cpp

Actor.o: Actor.cpp Actor.hpp ActorType.hpp MoveType.hpp
	$(CC) -c $(CFLAGS) Actor.cpp

Battle.o: Battle.cpp Battle.hpp ActorFactory.hpp BattleMoveFactory.hpp CommandManager.hpp Utils.hpp
	$(CC) -c $(CFLAGS) Battle.cpp

CommandManager.o: CommandManager.cpp CommandManager.hpp UndoableCommand.hpp
	$(CC) -c $(CFLAGS) CommandManager.cpp

CurseAttack.o: CurseAttack.cpp CurseAttack.hpp BattleMove.hpp
	$(CC) -c $(CFLAGS) CurseAttack.cpp

Game.o: Game.cpp Game.hpp Battle.cpp Battle.hpp
	$(CC) -c $(CFLAGS) Game.cpp

GhostActor.o: GhostActor.cpp GhostActor.hpp Actor.cpp Actor.hpp
	$(CC) -c $(CFLAGS) GhostActor.cpp

KnightActor.o: KnightActor.cpp KnightActor.hpp Actor.cpp Actor.hpp
	$(CC) -c $(CFLAGS) KnightActor.cpp

MeleeAttack.o: MeleeAttack.cpp MeleeAttack.hpp BattleMove.hpp
	$(CC) -c $(CFLAGS) MeleeAttack.cpp

SpellAttack.o: SpellAttack.cpp SpellAttack.hpp BattleMove.hpp
	$(CC) -c $(CFLAGS) SpellAttack.cpp

SwordAttack.o: SwordAttack.cpp SwordAttack.hpp BattleMove.hpp
	$(CC) -c $(CFLAGS) SwordAttack.cpp

clean: 
	rm program $(binaries)
	rm -f *.stackdump
