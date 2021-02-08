#include "UnsortedReservationList.hpp"

void UnsortedReservationList::MakeEmpty()
{
    length = 0;
}
        
void UnsortedReservationList::AddReservation(Reservation newReservation)
{
    reservationArray[length] = newReservation;
    length++;
}

Reservation UnsortedReservationList::FindReservation(Reservation comparison)
{
    for(int i = 0; i < length; i++)
    {
        if(reservationArray[i] == comparison)
        {
            return reservationArray[currentPos];
        }
    }
    throw("Reservation Not Found");
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

void UnsortedReservationList::ResetList()
{
    currentPos = 0;
}

Reservation UnsortedReservationList::GetNextReservation()
{
    if(currentPos < length)
    {
        currentPos++;
        return reservationArray[currentPos];
    }
    throw("Out of Range");
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