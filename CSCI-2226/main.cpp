/*
GACHA Slot Machine

Author:: James Mok

Date Created:: 9 March 2021

Objective:: Successfully use templates and circular linked lists.
*/

#include "CircularLinkedListTemp.hpp"

#include <iostream>

int main()
{
    cout << "Gacha Ruins Your Life" << endl;
    
    LinkedList<char> reelOne;
    reelOne.Intitialize();
    reelOne.PutItem('a');
    reelOne.PutItem('a');
    reelOne.PutItem('a');
    reelOne.PutItem('a');
    reelOne.PutItem('b');
    reelOne.PutItem('b');
    reelOne.PutItem('b');
    reelOne.PutItem('c');
    reelOne.PutItem('c');
    reelOne.PutItem('7');

    for (int i = 0; i < 10; i++)
    {
        std::cout << reelOne.GetNextItem();
    }

    cout << "~End of Program~"
}