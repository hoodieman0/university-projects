#ifndef UNSORTEDCARLIST_HPP
#define UNSORTEDCARLIST_HPP

#include "Car.hpp"

#include <iostream>

#define MAX_POS 100

class UnsortedCarList
{
    private:
        int length = 0;
        int currentPos = 0;
        Car carArray[MAX_POS];
    
    public:
        void MakeEmpty();
        void AddCar(Car);
        Car FindCar(string);
        Car& GetCarAtIndex(int);
        void ChangeAvailability(string);
        void DeleteCar(string);
        int GetLength();
        void PrintList();
        ~UnsortedCarList();

};

#endif