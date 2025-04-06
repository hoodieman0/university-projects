#include "RBTreeTemplate.hpp"

#include <iostream>
#include <chrono>

int main()
{
    RBTree<int> tree;

    tree.Insert(1);
    tree.Insert(2);
    tree.Insert(4);
    tree.Insert(3);
    tree.Insert(5);
    tree.Insert(10);

    std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
    tree.Find(10);
    std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();

    int duration = std::chrono::duration_cast<std::chrono::microseconds>( end - start ).count();

    std::cout<< "Time to find 10 in 6 items Red-Black Tree : " << duration << " microseconds" << std::endl;


    // srand(time(NULL));
    // tree.Insert(10);
    // for (int i = 0; i < 1000; i++)
    // {
    //     tree.Insert(rand()%(1000));
    // }

    // std::chrono::high_resolution_clock::time_point start2 = std::chrono::high_resolution_clock::now();
    // tree.Find(-1);
    // std::chrono::high_resolution_clock::time_point end2 = std::chrono::high_resolution_clock::now();

    // int duration = std::chrono::duration_cast<std::chrono::microseconds>( end2 - start2 ).count();

    // std::cout<< "Time to find -1 in 1000 items Red-Black Tree : " << duration << " microseconds" << std::endl;
    
    std::cerr << "END OF PROGRAM" << std::endl;
}