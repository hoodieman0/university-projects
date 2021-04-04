#include <vector>
#include <string>

#include "ActorType.hpp"
#include "MoveType.hpp"

class Actor {
      private:
          std::string type;
      protected:
          int health;
          std::vector<MoveType> moves;

      public:
          Actor();
          Actor(int, std::string);
          virtual void Hit(int damage);
          virtual void Heal(int amount);
          const std::vector<MoveType>& GetMoves() const {
              return moves;
          }

          bool IsDead() { return health <= 0; }
          friend std::ostream& operator<<(std::ostream& out, const Actor& actor);
      };