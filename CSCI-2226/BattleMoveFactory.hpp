#include "BattleMove.hpp"
#include "CurseAttack.hpp"
#include "MeleeAttack.hpp"
#include "SpellAttack.hpp"
#include "SwordAttack.hpp"

class BattleMoveFactory
  {
  public:
    static Attack* BuildMove(MoveType moveType, Actor* attacker, Actor* target) {
      Attack* battleMove = nullptr;
      switch (moveType) {
      case MoveType::Curse:
        battleMove = new CurseAttack(attacker, target);
        break;
      case MoveType::Sword:
        battleMove = new SwordAttack(attacker, target);
        break;
      case MoveType::Spell:
        battleMove = new SpellAttack(attacker, target);
        break;
      case MoveType::Melee:
        battleMove = new MeleeAttack(attacker, target);
        break;
      }
      return battleMove;
    }
  };