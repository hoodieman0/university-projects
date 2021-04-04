#include "Actor.hpp"

class GhostActor: public Actor
{
  public:
      GhostActor();
      void Hit(int damage);
      void Heal(int amount);
};