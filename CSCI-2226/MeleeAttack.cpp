#include "MeleeAttack.hpp"

MeleeAttack::MeleeAttack(Actor* attacker, Actor* target)
{
    self = attacker;
    other = target;
}

void MeleeAttack::Execute()
{
    damageAmount = battleMoveHelper.randInt(5, 15);
    other->Hit(damageAmount);
}

void MeleeAttack::Undo()
{
    other->Heal(damageAmount);
}