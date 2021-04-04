#include "SwordAttack.hpp"

SwordAttack::SwordAttack(Actor* attacker, Actor* target)
{
    BattleMove(attacker, target);
}

void SwordAttack::Execute()
{
    damageAmount = randInt(0, 20)
    other->Hit(damageAmount);
}

void SwordAttack::Undo()
{
    other->Heal(damageAmount);
}