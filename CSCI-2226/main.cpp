#include "ActorFactory.hpp"
#include "BattleMoveFactory.hpp"

#include "BattleMove.hpp"
#include "CommandManager.hpp"

int main()
{
    auto actorKnight = ActorFactory::CreateActor(ActorType::Knight);
    auto actorGhost = ActorFactory::CreateActor(ActorType::Ghost); //actors

    auto move = BattleMoveFactory::CreateBattleMove(MoveType::Melee); //battle moves

    CommandManager lol = new CommandManager();

    BattleMove abc = new BattleMove(actorKnight, actorGhost);

}