#include "GhostActor.hpp"

GhostActor::GhostActor() : Actor(100, "Ghost")
      {
        moves.push_back(MoveType::Curse);
        moves.push_back(MoveType::Spell);
      };

void GhostActor::Hit(int damage)
{
    health -= damage;
    std::cout << "\nDid " << damage << " Damage! Ghost's Health Is Now " << health << ".\n";
}

void GhostActor::Heal(int amount)
{
    health += amount;
    std::cout << "\nGhost Healed " << amount << "! Health Is Now " << health << ".\n";
}