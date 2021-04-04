#include "Actor.hpp"
#include "BattleMove.hpp"

class Utils
{
  public:
    int randInt(int, int);
    map<ActorType, string> actorDisplayName();
    map<MoveType, string> moveDisplayName();
}