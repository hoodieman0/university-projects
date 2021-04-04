#include "Battle.hpp"

Battle::Battle(ActorType actor1, ActorType actor2)
{
    player1 = ActorFactory::CreateActor(actor1);
    player2 = ActorFactory::CreateActor(actor2);
}

void Battle::Start()
{

}

bool Battle::PlayerTurn()
{

}

void Battle::NpcTurn()
{

}