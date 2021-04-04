#include "ActorFactory.hpp"
#include "BattleMoveFactory.hpp"
#include "CommandManager.hpp"

class Battle
  {
    private:
      CommandManager undoManager;
      Actor* player1; 
      Actor* player2; 

    public:
      Battle(ActorType, ActorType);
      void Start();
      bool PlayerTurn();
      void NpcTurn();
  };