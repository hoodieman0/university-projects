#include "Utils.hpp"

int Utils::randInt(int min, int max) {
    return rand() % (max - min + 1) + min;
  }

  map<ActorType, string> Utils::actorDisplayName{
    {ActorType::Ghost, "Ghost"},
    {ActorType::Knight, "Knight"},
  };

  map<MoveType, string> Utils::moveDisplayName{
    {MoveType::Curse, "Curse"},
    {MoveType::Melee, "Melee"},
    {MoveType::Spell, "Spell"},
    {MoveType::Sword, "Sword"}
  };