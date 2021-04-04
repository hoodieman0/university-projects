#include "BattleMove.hpp"

class SwordAttack : public BattleMove
{
    private:
        int damageAmount;
    public:
        SwordAttack(Actor*, Actor*);
        void Execute();
        void Undo();
}