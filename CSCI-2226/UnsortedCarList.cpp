#include "UnsortedCarList.hpp"

void UnsortedCarList::MakeEmpty()
{
    length = 0;
}
        
void UnsortedCarList::AddCar(Car newCar)
{
    carArray[length] = newCar;
    length++;
}

Car UnsortedCarList::FindCar(string comparison)
{
    for(int i = 0; i < length; i++)
    {
        if(carArray[i].GetPlateNumber() == comparison)
        {
            return carArray[currentPos];
        }
    }
    throw("Car Not Found");
}

void UnsortedCarList::DeleteCar(string comparison)
{
    for(int i = 0; i < length; i++)
    {
        if (carArray[i].GetPlateNumber() == comparison)
        {
            if(carArray[i].GetAvailibility())
            {
                carArray[i] = carArray[--length];
            }
            else throw("Car is currently rented");
            break;
        }
    }
}

void UnsortedCarList::ResetList()
{
    currentPos = 0;
}

Car UnsortedCarList::GetNextCar()
{
    if(currentPos < length)
    {
        currentPos++;
        return carArray[currentPos];
    }
    throw("Out of Range");
}

int UnsortedCarList::GetLength()
{
    return length+1;
}

void UnsortedCarList::PrintList()
{
    cout << "\n\n///////////////////////////////";
    for(int i = 0; i < length; i++)
    {
        cout << "\n-Car " << i+1 << "-\n" << carArray[i] << endl;
    }
    cout << "///////////////////////////////";
}

UnsortedCarList::~UnsortedCarList() {}