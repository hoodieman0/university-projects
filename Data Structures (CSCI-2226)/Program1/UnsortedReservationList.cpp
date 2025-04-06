
/*
XYZ Rental Car Service Program 1

Author:: James Mok

Created:: 3 February 2021
*/

#include "UnsortedReservationList.hpp"

/*
Function:: AddReservation

Author:: James Mok

Type:: Transformer

Input:: Reservation reservationToAdd

Output:: none
*/
        
void UnsortedReservationList::AddReservation(Reservation& newReservation)
{
    reservationArray[length] = newReservation;
    length++;
}

/*
Function:: FindReservation

Author:: James Mok

Type:: Iterator

Input:: string name

Output:: Reservation reservationOfName
*/

Reservation UnsortedReservationList::FindReservation(string comparison)
{
    for(int i = 0; i < length; i++)
    {
        if(reservationArray[i].GetName() == comparison)
        {
            return reservationArray[i];
        }
    }
}

/*
Function:: FindReservationCar

Author:: James Mok

Type:: Observer

Input:: Reservation reservation

Output:: string license plate
*/

string UnsortedReservationList::FindReservationCar(Reservation comparison)
{
    return comparison.GetVehicleRented();
}

/*
Function:: DeleteReservation

Author:: James Mok

Type:: Transformer

Input:: string licnese plate

Output:: none
*/

void UnsortedReservationList::DeleteReservation(string comparison)
{
    for(int i = 0; i < length; i++)
    {
        if (reservationArray[i].GetName() == comparison)
        {
            reservationArray[i] = reservationArray[--length]; //why do I have to decrement first?
        }
    }
}

/*
Function:: PrintList

Author:: James Mok

Type:: Iterator

Input:: none

Output:: prints all reservations in list
*/

void UnsortedReservationList::PrintList()
{
    cout << "\n///////////////////////////////";
    for(int i = 0; i < length; i++)
    {
        cout << "\n-Reservation " << i+1 << "-\n" << reservationArray[i] << endl;
    }
    cout << "///////////////////////////////";
}

//destructor

UnsortedReservationList::~UnsortedReservationList() {}