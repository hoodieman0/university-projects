#include <vector>
#include <string>
using namespace std;

enum ActorType {
      Ghost,
      Knight
    };

class Actor {
      private:
          string type;
      protected:
          int health;
          vector<MoveType> moves;

      public:
          Actor(int health, string type) :
              health{ health },
              type{ type }
          {}
          virtual void Hit(int damage);
          virtual void Heal(int amount);
          const vector<MoveType>& GetMoves() const {
              return moves;
          }

          bool IsDead() { return health <= 0; }
          friend ostream& operator<<(ostream& out, const Actor& actor);
      };