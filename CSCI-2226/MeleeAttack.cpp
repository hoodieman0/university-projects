#include "MeleeAttack.hpp"

MeleeAttack::MeleeAttack(Actor* attacker, Actor* target)
{
    BattleMove(attacker, target);
}

void MeleeAttack::Execute()
{
    damageAmount = randInt(5, 15)
    other->Hit(damageAmount);
}

void MeleeAttack::Undo()
{
    other->Heal(damageAmount);
}