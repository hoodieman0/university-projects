#include "GhostActor.hpp"

GhostActor::GhostActor()
{
    Actor(100, "Ghost");
    moves.push_back(Curse);
    moves.push_back(Spell);
}

void GhostActor::Hit(int damage)
{
    health -= damage;
}

void GhostActor::Heal(int amount)
{
    health += amount;
}