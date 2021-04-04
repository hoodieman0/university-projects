#include "KnightActor.hpp"

KnightActor::KnightActor()
{
    Actor(100, "Knight");
    moves.push_back(Melee);
    moves.push_back(Sword);
}

void KnightActor::Hit(int damage)
{
    health -= damage;
}

void KnightActor::Heal(int amount)
{
    health += amount;
}