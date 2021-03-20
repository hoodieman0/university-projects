#ifndef SlotMachine_hpp
#define SlotMachine_hpp

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

        string Spin(LinkedList<T>* first, LinkedList<T>* second, LinkedList<T>* third)
        {
            T symbolOne; //LinkedList and SlotMachine must be same data type for this to work
            T symbolTwo;
            T symbolThree;

            std::string finalCombo;

            srand((unsigned) time(0)); 
            int spinOne = (rand() % 100) + 1;

            srand((unsigned) time(0) - 393);
            int spinTwo = (rand() % 100) + 1;

            srand((unsigned) time(0) + 255);
            int spinThree = (rand() % 100) + 1;

            std::cout << "|" << spinOne << "|" << spinTwo << "|" << spinThree << "|" << endl;

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

            finalCombo = finalCombo + symbolOne + symbolTwo + symbolThree;
            std::cout << finalCombo << endl;

            return finalCombo;
        }
        
        void Debug()
        {
            std::cerr << "Debug Call:" << endl;
            for (int i =0; i < MAX_SIZE; i++)
            {
                std::cout << reelOne->GetNextItem();
            }
            std::cout << endl;
            for (int i =0; i < MAX_SIZE; i++)
            {
                std::cout << reelTwo->GetNextItem();
            }
            std::cout << endl;
            for (int i =0; i < MAX_SIZE; i++)
            {
                std::cout << reelThree->GetNextItem();
            }
        }
};

#endif