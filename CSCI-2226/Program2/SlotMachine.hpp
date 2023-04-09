#ifndef SlotMachine_hpp
#define SlotMachine_hpp

/*
    Note:: This Slot Machine can only hold three reels.
*/

#include "CircularLinkedListTemp.hpp"

#include <string>
#include <iostream>
#include <ctime>

#define MAX_SIZE 10

template <class T> class SlotMachine
{
    private:
        LinkedList<T>* reelOne = new LinkedList<T>;
        LinkedList<T>* reelTwo = new LinkedList<T>;
        LinkedList<T>* reelThree = new LinkedList<T>;

    public:
        SlotMachine(T (&arrayOne)[MAX_SIZE], T (&arrayTwo)[MAX_SIZE], T (&arrayThree)[MAX_SIZE])
        {
            //puts the symbols in the reels
            for (auto &data : arrayOne)
            {
                reelOne->PutItem(data);
            }
    
            for (auto &data : arrayTwo)
            {
                reelTwo->PutItem(data);
            }
    
            for (auto &data : arrayThree)
            {
                reelThree->PutItem(data);
            }
        }

        LinkedList<T>* GetReelOne()
        {
            return reelOne;
        }

        LinkedList<T>* GetReelTwo()
        {
            return reelTwo;
        }

        LinkedList<T>* GetReelThree()
        {
            return reelThree;
        }

        std::string Spin(LinkedList<T>* first, LinkedList<T>* second, LinkedList<T>* third)
        {
            T symbolOne; //LinkedList and SlotMachine must be same data type for this to work
            T symbolTwo;
            T symbolThree;

            std::string finalCombo;

            //randomizes the spins using the clock time times an offset
            //it can be predicted, but it would not be time efficient to write a solution
            srand((unsigned) time(0)); 
            int spinOne = (rand() % 100) + 1;

            srand((unsigned) time(0) * 393);
            int spinTwo = (rand() % 100) + 1;

            srand((unsigned) time(0) * 255);
            int spinThree = (rand() % 100) + 1;
            
            //the actual spining of the reels
            for (int i = 0; i < spinOne; i++)
            {
                symbolOne = first->GetNextItem();
            }

            for (int i = 0; i < spinTwo; i++)
            {
                symbolTwo = second->GetNextItem();
            }

            for (int i = 0; i < spinThree; i++)
            {
                symbolThree = third->GetNextItem();
            }

            std::cout << "\n ~Your spin~\n---------------\n | " << symbolOne << " | " << symbolTwo << " | " << symbolThree << " |\n---------------" << std::endl;
            
            finalCombo = finalCombo + symbolOne + symbolTwo + symbolThree;
            return finalCombo;
        }
};

#endif