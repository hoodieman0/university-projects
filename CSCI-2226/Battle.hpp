#pragma once

#include "Actor.hpp"
#include "GhostActor.hpp"
#include "KnightActor.hpp"
#include "ActorFactory.hpp"
#include "BattleMoveFactory.hpp"
#include "CommandManager.hpp"
#include "Utils.hpp"
#include "MoveType.hpp"

#include <iostream>

class Battle
  {
    private:
      CommandManager undoManager; //undo stack
      Actor* player1; 
      Actor* player2; 

      Utils battleHelper; //access utils class
      BattleMoveFactory* moveFactory;

    public:
      Battle(ActorType, ActorType);
      void Start();
      void PlayerTurn();
      void NpcTurn();
  };