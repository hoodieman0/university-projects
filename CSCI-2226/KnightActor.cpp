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
    std::cout << "\nDid " << damage << "Damage! Knight's Health Is Now " << health << ".\n";
}

void KnightActor::Heal(int amount)
{
    health += amount;
    std::cout << "\nKnight Healed " << amount << "! Health Is Now " << health << ".\n";
}