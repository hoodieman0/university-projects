#pragma once

#include "UndoableCommand.hpp"
#include "Actor.hpp"
#include "Utils.hpp"

class BattleMove : public UndoableCommand {
  protected:
    Actor* self;
    Actor* other;
    
    Utils battleMoveHelper;

  public:
    BattleMove(Actor* self, Actor* other)
          :self{ self },
          other{ other }
      {}
    BattleMove()=default;
    virtual void Execute()=0;
    virtual void Undo()=0;
  };