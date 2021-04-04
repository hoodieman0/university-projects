#include "UndoableCommand.hpp"
#include "Actor.hpp"
#include "MoveType.hpp"

#include "Utils.hpp"

class BattleMove : public UndoableCommand {
  protected:
    Actor* self;
    Actor* other;

  public:
    BattleMove(Actor*, Actor*);
  };