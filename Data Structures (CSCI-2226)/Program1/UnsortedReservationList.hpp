
/*
XYZ Rental Car Service Program 1

Author:: James Mok

Created:: 3 February 2021
*/

#ifndef UNSORTEDRESERVATIONLIST_HPP
#define UNSORTEDRESERVATIONLIST_HPP

#include "Reservation.hpp"

#include <iostream>

#define MAX_POS 100

class UnsortedReservationList
{
    private:
        int length = 0;
        int currentPos = 0;
        Reservation reservationArray[MAX_POS];
    
    public:
        void AddReservation(Reservation&);
        Reservation FindReservation(string);
        string FindReservationCar(Reservation);
        void DeleteReservation(string);
        void PrintList();
        ~UnsortedReservationList();

};

#endif