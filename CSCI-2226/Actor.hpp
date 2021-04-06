#include "ActorType.hpp"
#include "MoveType.hpp"

#include <vector>
#include <string>
#include <iostream>

class Actor {
      private:
          std::string type;
      protected:
          int health;
          std::vector<MoveType> moves;

      public:
          Actor(int health, std::string type) :
              health{ health },
              type{ type }
          {}
          Actor()=default;
          virtual void Hit(int damage);
          virtual void Heal(int amount);
          int GetHealth()
          {
              return health;
          }
          const std::vector<MoveType>& GetMoves() const {
              return moves;
          }

          bool IsDead() { return health <= 0; }
          friend std::ostream& operator<<(std::ostream& out, const Actor& actor);
      };