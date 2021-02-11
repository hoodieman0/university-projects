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
}

Car& UnsortedCarList::GetCarAtIndex(int index)
{
    return carArray[index - 1];  
    throw std::out_of_range ("Index Out of Range");
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