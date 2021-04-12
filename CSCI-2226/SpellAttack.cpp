#include "SpellAttack.hpp"

SpellAttack::SpellAttack(Actor* attacker, Actor* target)
{
    self = attacker;
    other = target;;
}

void SpellAttack::Execute()
{
    damageAmount = battleMoveHelper.randInt(0, 20);
    other->Hit(damageAmount);
}

void SpellAttack::Undo()
{
    other->Heal(damageAmount);
}