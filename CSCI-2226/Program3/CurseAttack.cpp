#include "CurseAttack.hpp"

CurseAttack::CurseAttack(Actor* attacker, Actor* target)
{
    self = attacker;
    other = target;
}

void CurseAttack::Execute()
{
    damageAmount = battleMoveHelper.randInt(5,15);
    other->Hit(damageAmount);
}

void CurseAttack::Undo()
{
    other->Heal(damageAmount);
}