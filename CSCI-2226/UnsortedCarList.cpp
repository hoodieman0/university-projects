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
            return carArray[i];
        }
    }
    // throw("Car Not Found");
}

int UnsortedCarList::FindCarInt(string comparison)
{
    for(int i = 0; i < length; i++)
    {
        if(carArray[i].GetPlateNumber() == comparison)
        {
            return i;
        }
    }
    // throw("Car Not Found");
}

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