#include "UnsortedReservationList.hpp"

void UnsortedReservationList::MakeEmpty()
{
    length = 0;
}
        
void UnsortedReservationList::AddReservation(Reservation& newReservation)
{
    reservationArray[length] = newReservation;
    length++;
}

Reservation UnsortedReservationList::FindReservation(string comparison)
{
    for(int i = 0; i < length; i++)
    {
        if(reservationArray[i].GetName() == comparison)
        {
            return reservationArray[i];
        }
    }
    // throw "Reservation Not Found";
}

string UnsortedReservationList::FindReservationCar(Reservation comparison)
{
    return comparison.GetVehicleRented();
}

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

int UnsortedReservationList::GetLength()
{
    return length;
}

void UnsortedReservationList::PrintList()
{
    cout << "\n///////////////////////////////";
    for(int i = 0; i < length; i++)
    {
        cout << "\n-Reservation " << i+1 << "-\n" << reservationArray[i] << endl;
    }
    cout << "///////////////////////////////";
}

UnsortedReservationList::~UnsortedReservationList() {}