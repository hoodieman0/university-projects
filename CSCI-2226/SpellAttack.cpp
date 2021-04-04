#include "SpellAttack.hpp"

SpellAttack::SpellAttack(Actor* attacker, Actor* target)
{
    BattleMove(attacker, target);
}

void SpellAttack::Execute()
{
    damageAmount = randInt(0, 20)
    other->Hit(damageAmount);
}

void SpellAttack::Undo()
{
    other->Heal(damageAmount);
}