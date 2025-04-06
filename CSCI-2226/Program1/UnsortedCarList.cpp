
/*
XYZ Rental Car Service Program 1

Author:: James Mok

Created:: 3 February 2021
*/

#include "UnsortedCarList.hpp"

/*
Function:: AddCar

Author:: James Mok

Type:: Transformer

Input:: Car carToAdd

Output:: none
*/

void UnsortedCarList::AddCar(Car newCar)
{
    carArray[length] = newCar;
    length++;
}

/*
Function:: FindCar

Author:: James Mok

Type:: Iterator

Input:: string license plate

Output:: Car carToFind
*/

Car UnsortedCarList::FindCar(string comparison)
{
    for(int i = 0; i < length; i++)
    {
        if(carArray[i].GetPlateNumber() == comparison)
        {
            return carArray[i];
        }
    }
}

/*
Function:: GetCarAtIndex

Author:: James Mok

Type:: Observer

Input:: int indexOfCar

Output:: Car carToReserve
*/

Car& UnsortedCarList::GetCarAtIndex(int index)
{
    return carArray[index - 1];  
    throw std::out_of_range ("Index Out of Range");
}

/*
Function:: ChangeAvailability

Author:: James Mok

Type:: Transformer

Input:: string license plate

Output:: none
*/

void UnsortedCarList::ChangeAvailability(string comparison)
{
    for(int i = 0; i < length; i++)
    {
        if(carArray[i].GetPlateNumber() == comparison)
        {
            cout << carArray[i].GetAvailibility() <<endl;
            if(carArray[i].GetAvailibility())
            {
                cout << "Im here car is true!";
                carArray[i].SetAvailable(false);
            }
            else
            {
                cout << "Im here  car isfalse!";
                carArray[i].SetAvailable(true);
            }
        }
    }
    // throw("Car Not Found");
}

/*
Function:: DeleteCar

Author:: James Mok

Type:: Transformer

Input:: string license plate

Output:: none
*/

void UnsortedCarList::DeleteCar(string comparison)
{
    for(int i = 0; i < length; i++)
    {
        if (carArray[i].GetPlateNumber() == comparison)
        {
            if(carArray[i].GetAvailibility())
            {
                carArray[i] = carArray[--length];
                cout << "Car Deleted.";
            }
            else
            {
                cout << "Car Is In Use. Action Canceled.";
            }
            break;
        }
    }
}

/*
Function:: PrintList

Author:: James Mok

Type:: Iterator

Input:: none

Output:: prints all cars in the list
*/

void UnsortedCarList::PrintList()
{
    cout << "\n\n///////////////////////////////";
    for(int i = 0; i < length; i++)
    {
        cout << "\n-Car " << i+1 << "-\n" << carArray[i] << endl;
    }
    cout << "///////////////////////////////";
}

//destructor

UnsortedCarList::~UnsortedCarList() {}