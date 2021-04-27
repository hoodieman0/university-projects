#include "RBTreeTemplate.hpp"
#include "LinkedListTemplate.hpp"

#include <iostream>
#include <chrono>

#define BT int; //I didn't know how to use define for data types


void TreeInserter(RBTree<int>, int, int, int);
void LinkedListInserter(LinkedList<int>, int, int, int);
void TimeToFindLinkedList(LinkedList<int>, int, int);
void TimeToFindRBTree(RBTree<int>, int, int);

int main()
{
    RBTree<int> yggdrasil;
    LinkedList<int> roadToRome;

    std::cout << "\n\nWelcome To Lookup!\n\n";
    
    TimeToFindLinkedList(roadToRome, -1, 100);
    std::cout << std::endl;

    TimeToFindLinkedList(roadToRome, -1, 1000);
    std::cout << std::endl;

    TimeToFindLinkedList(roadToRome, -1, 10000);
    std::cout << std::endl;

    TimeToFindLinkedList(roadToRome, -1, 100000);
    std::cout << std::endl;

    TimeToFindLinkedList(roadToRome, -1, 1000000);
    std::cout << std::endl;
    
    // TimeToFindRBTree(yggdrasil, 256, 100);
    // std::cout << std::endl;

    // TimeToFindRBTree(yggdrasil, 256, 1000);
    // std::cout << std::endl;

    // TimeToFindRBTree(yggdrasil, 256, 10000);
    // std::cout << std::endl;

    // TimeToFindRBTree(yggdrasil, 256, 100000);
    // std::cout << std::endl;

    // TimeToFindRBTree(yggdrasil, 256, 1000000);
    // std::cout << std::endl;

    std::cout << "\n\n~End Of Program~\n\n";
}

void TreeInserter(RBTree<int> tree, int length, int max, int min)
{
    srand(time(NULL));
    for (int i = 0; i < length; i++)
    {
        tree.Insert(rand()%(max-min + 1) + min);
    }
}

void TimeToFindLinkedList(LinkedList<int> list, int data, int length)
{
    srand(time(NULL));
    list.Insert(-1);
    for (int i = 0; i < length-1; i++)
    {
        list.Insert(rand()%(1000));
    }
    
    std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
    try
    {
        list.Find(data);
    }
    catch(const char* e)
    {
        std::cerr << e << std::endl;
    }
    std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();

    int duration = std::chrono::duration_cast<std::chrono::microseconds>( end - start ).count();

    std::cout<< "Time to find " << data << " in " << length << " items Linked List : " << duration << " microseconds" << std::endl;
    list.MakeEmpty();
}

void TimeToFindRBTree(RBTree<int> tree, int data, int length)
{
    srand(time(NULL));
    tree.Insert(-1);
    for (int i = 0; i < length; i++)
    {
        tree.Insert(rand()%1000);
    }
    
    std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
    tree.Find(data);
    std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();

    int duration = std::chrono::duration_cast<std::chrono::microseconds>( end - start ).count();

    std::cout<< "Time to find " << data << " in " << length << " items Red-Black Tree : " << duration << " microseconds" << std::endl;
    tree.DestroyTree();
}