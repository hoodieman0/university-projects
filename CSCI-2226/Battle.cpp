#include "Battle.hpp"

Battle::Battle(ActorType actor1, ActorType actor2)
{
    auto player1 = ActorFactory::CreateActor(actor1);
    auto player2 = ActorFactory::CreateActor(actor2);
}

void Battle::Start()
{
    std::cout<< "\nPlayer's Health Is " << player1->GetHealth() << ".\nCPU's Health Is " << player2->GetHealth() << ".\n";
    
    if (player1->IsDead())
    {
        std::cout << "Player Is Dead!";
        isOver = true;   
        return;
    }
    else if (player2->IsDead())
    {
        std::cout << "CPU Is Dead!";
        isOver = true;
        return;
    }
    
    if (isPlayerTurn)
    {
        isPlayerTurn = PlayerTurn();
        std::cout << "\nPlayer Turn is Over!\n";
    }
    else
    {
        NpcTurn();
        std::cout << "\nCPU Turn is Over!\n";
    }
    return;
}

bool Battle::PlayerTurn() //returns boolean to indicate if the player played a valid move or not, then moves on to CPU turn
{
    std::string input;
    
    std::vector<MoveType> allMoves = player1->GetMoves();
    
    std::cout<< "What Will You Do?\n";
    for (auto move : allMoves) //displays all moves player1 has
    {
        for (auto &it : battleHelper.moveDisplayName) //in string form
        {
            std::cout << it.second << "\t";
        }
    }
    std::cout << "\n\"Undo\"";

    std::cin >> input;

    if (input == "Undo") //undoes the last two moves
    {   
        undoManager.Undo(); //undoes cpu move
        undoManager.Undo(); //undoes last player move
        return true;
    }

    for (auto &it : battleHelper.moveDisplayName) //executes the desired move, puts it into the command stack
    {
        if (it.second == input)
        {
            undoManager.Execute(moveFactory->BuildMove(it.first, player1, player2));
            std::cout<< "Player Used " << it.second << "!\n";
            return false;
        }
    }

    std::cout << "\nInvalid Move!\n";
    return true;
}

void Battle::NpcTurn() //CPU chooses a random move from its moveset and executes it then puts it in the command stack
{
    std::vector<MoveType> allMoves = player2->GetMoves();
    int CPUChoice = battleHelper.randInt(0, allMoves.size()-1);
    std::string move = battleHelper.moveDisplayName[allMoves[CPUChoice]]; //helps show the user what the CPU used

    std::cout<< "CPU Used " << move << "!\n";

    undoManager.Execute(moveFactory->BuildMove(allMoves[CPUChoice], player2, player1));

}

bool Battle::GetIsOver()
{
    return isOver;
}