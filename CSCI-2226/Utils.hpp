#include "ActorType.hpp"
#include "MoveType.hpp"

#include <string>
#include <map>

using namespace std;

class Utils
{
  public:
    int randInt(int min, int max)
    {
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
};