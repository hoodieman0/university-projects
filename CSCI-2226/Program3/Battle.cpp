#include "Battle.hpp"

Battle::Battle(ActorType actor1, ActorType actor2)
{
    player1 = ActorFactory::CreateActor(actor1);
    player2 = ActorFactory::CreateActor(actor2);
}

void Battle::Start()
{
    while(true)
    {
        
        std::cout<< "\n---------------------------------------------------------------------------\n";
        std::cout << "\nPlayer 1's " << player1->GetType() << "'s Health Is " << player1->GetHealth() << ".\nPlayer 2's " << player2->GetType() << "'s Health Is " << player2->GetHealth() << ".\n";
    
        if (player1->IsDead()) //checks if health is below 0
        {  
            std::cout << "\nPlayer Is Dead!\n";  
            return;
        }
        else if (player2->IsDead())
        {
            std::cout << "\nCPU Is Dead!\n";
            return;
        }
    

        std::cout << "\n\nPlayer's Turn!\n";
        PlayerTurn();
        std::cout << "\nPlayer Turn Is Over!\n";
    
    
        std::cout << "\n\nCPU's Turn!\n";
        NpcTurn();
        std::cout << "\n\nCPU Turn Is Over!\n";
    }
    
}

void Battle::PlayerTurn() //returns boolean to indicate if the player played a valid move or not, then moves on to CPU turn
{
    std::string input;
    bool containsMove;
    int i = 1;
    
    std::vector<MoveType> allMoves = player1->GetMoves();
    
    std::cout<< "\nWhat Will You Do? (Type Name, Case Sensitive)\n";
    for (auto move : allMoves) //displays all moves player1 has
    {
        for (auto &it : battleHelper.moveDisplayName) //in string form
        {
            if (move == it.first)
            {
                std::cout << i << ") " << it.second << "\t";
                i++;
            } 
        }
    }
    std::cout << i << ") Undo\t";
    i++;
    std::cout<< i << ") Exit\n\n";

    getline(std::cin, input);

    if (input == "Undo") //undoes the last two moves
    {   
        undoManager.Undo(); //undoes cpu move
        undoManager.Undo(); //undoes last player move
        PlayerTurn();
        return;
    }

    if (input == "Exit")
    {
        std::cout << "\nPlayer Final Health: " << player1->GetHealth() << ".\nCPU Final Health: " << player2->GetHealth() <<".\n";
        std::cout << "\n~Exiting Program~\n";
        exit(1);
    }

    

    for (auto &move : allMoves) //all moves in player moves vector
        {
            if (battleHelper.moveDisplayName.find(move)->second == input) //checks if move is in vector
            {
                containsMove = true;
                break;
            }
            else
            {
                containsMove = false;
            }
        }
    
    for (auto &it : battleHelper.moveDisplayName) //executes the desired move, puts it into the command stack
    {
        if (containsMove && it.second == input )
        {
            std::cout<< "\nPlayer Used " << it.second << "!\n";
            undoManager.Execute(moveFactory->BuildMove(it.first, player1, player2)); //it.first passes MoveType enum
            return;
        }
    }

    std::cout << "\nInvalid Move!\n";
    return;
}

void Battle::NpcTurn() //CPU chooses a random move from its moveset and executes it then puts it in the command stack
{
    std::vector<MoveType> allMoves = player2->GetMoves();
    int CPUChoice = battleHelper.randInt(0, allMoves.size()-1);
    std::string move = battleHelper.moveDisplayName[allMoves[CPUChoice]]; //helps show the user what the CPU used

    std::cout<< "\nCPU Used " << move << "!\n";

    undoManager.Execute(moveFactory->BuildMove(allMoves[CPUChoice], player2, player1));

}