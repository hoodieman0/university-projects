#include "ActorFactory.hpp"
#include "BattleMoveFactory.hpp"
#include "CommandManager.hpp"
#include "Utils.hpp"

#include <iostream>

class Battle
  {
    private:
      CommandManager undoManager;
      Actor* player1; 
      Actor* player2; 

      Utils battleHelper;
      bool isPlayerTurn = true;
      bool isOver = false;
      BattleMoveFactory* moveFactory;

    public:
      Battle(ActorType, ActorType);
      void Start();
      bool PlayerTurn();
      void NpcTurn();
      bool GetIsOver();
  };