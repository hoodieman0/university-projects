
/*
XYZ Rental Car Service Program 1

Author:: James Mok

Created:: 3 February 2021
*/

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
        void AddCar(Car);
        Car FindCar(string);
        Car& GetCarAtIndex(int);
        void ChangeAvailability(string);
        void DeleteCar(string);
        void PrintList();
        ~UnsortedCarList();

};

#endif