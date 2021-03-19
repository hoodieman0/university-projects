#ifndef SlotMachine_hpp
#define SlotMachine_hpp

#include "CircularLinkedListTemp.hpp"
#include <string>
#include <iostream>
#include <ctime>

template <class T> class SlotMachine
{
    private:
        LinkedList<T>* reelOne;
        LinkedList<T>* reelTwo;
        LinkedList<T>* reelThree;

    public:
        void Initialize(T [], T[], T[]);
        LinkedList<T>* GetReelOne();
        LinkedList<T>* GetReelTwo();
        LinkedList<T>* GetReelThree();
        std::string Spin(LinkedList<T>*, LinkedList<T>*, LinkedList<T>*);
        
        void Debug();
};

template <class T> void SlotMachine<T>::Initialize(T arrayOne[], T arrayTwo[], T arrayThree[]) //make range based for loop?
{
    
    for (int i = 0; i < 10; i++)
    {
        reelOne->PutItem(arrayOne[i]);
    }

    // for (int i = 0; i < (sizeof(arrayTwo)/sizeof(arrayTwo[0]); i++)
    // {
    //     reelTwo->PutItem(arrayTwo[i]);
    // }

    // for (int i = 0; i < (sizeof(arrayThree)/sizeof(arrayThree[0])); i++)
    // {
    //     reelThree->PutItem(arrayThree[i]);
    // }
    
    // for (auto i : arrayTwo)
    // {
    //     reelTwo->PutItem(arrayTwo[i]);
    // }
    
    // for (auto i : arrayThree)
    // {
    //     reelThree->PutItem(arrayThree[i]);
    // }
}

template <class T> LinkedList<T>* SlotMachine<T>::GetReelOne()
{
    return reelOne;
}

template <class T> LinkedList<T>* SlotMachine<T>::GetReelTwo()
{
    return reelTwo;
}

template <class T> LinkedList<T>* SlotMachine<T>::GetReelThree()
{
    return reelThree;
}

template <class T> std::string SlotMachine<T>::Spin(LinkedList<T>* first, LinkedList<T>* second, LinkedList<T>* third)
{
    T symbolOne; //LinkedList and SlotMachine must be same data type for this to work
    T symbolTwo;
    T symbolThree;

    string finalCombo;
    

    srand(time(0)); 
    int spinOne = (rand() % 100) + 1;

    srand(time(0));
    int spinTwo = (rand() % 100) + 1;

    srand(time(0));
    int spinThree = (rand() % 100) + 1;

    // std::cout << "|" << spinOne << "|" << spinTwo << "|" << spinThree << "|" << endl;

    for (int i = 0; i < spinOne; i++)
    {
        symbolOne = first->GetNextItem();
    }

    // for (int i = 0; i < spinTwo; i++)
    // {
    //     symbolTwo = second->GetNextItem();
    // }

    // for (int i = 0; i < spinThree; i++)
    // {
    //     symbolThree = third->GetNextItem();
    // }

    finalCombo = symbolOne + symbolTwo + symbolThree;
    std::cout << finalCombo << endl;

    return finalCombo;
}

template <class T> void SlotMachine<T>::Debug()
{
    std::cerr << "Debug Call:" << endl;
    for (int i =0; i < 10; i++)
    {
        std::cout << reelOne->GetNextItem();
    }
}


#endif