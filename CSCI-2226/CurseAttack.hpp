#include "BattleMove.hpp"

class CurseAttack : public BattleMove
{
    private:
        int damageAmount;
    public:
        CurseAttack(Actor*, Actor*);
        void Execute();
        void Undo();
}