/*
XYZ Rental Car Service

Author:: James Mok

Created:: 3 February 2021

Goal:: Create and use unsorted lists using proper classes and ADTs.

Todo::
-Remove functions for Cars
-Remove functions for Reservations (remember bool isAvailable)
-comment code
-write headers (author, purpose, input, output)
*/

#include "Car.hpp"
#include "Reservation.hpp"
#include "UnsortedCarList.hpp"
#include "UnsortedReservationList.hpp"

#include <iostream>
using namespace std;

int main()
{
    bool exitCondition = false;
    int methodController;

    string inputPlate;
    string inputMake;
    string inputModel;
    int inputType;
    double inputPrice;
    
    string inputName;
    string inputRent;

    string deleteCar;
    string deleteReservation;
    
    UnsortedCarList* carList = new UnsortedCarList();
    UnsortedReservationList* reservationList = new UnsortedReservationList();

    cout << "\n----- XYZ Car Rental Serivce -----" << endl;
    
    while(!exitCondition)
    {
        cout << "\n\nType An Option:\n1. List All Cars\n2. Add a Car\n3. Remove a Car\n4. List All Reservations\n5. Add a Reservation\n6. Cancel a Reservation\n7. Exit Program\n" << endl;
        //is there a way to make this on multiple lines?
        cin >> methodController;
        switch (methodController)
        {
            case 1: //list all cars
                {
                    carList->PrintList();
                    break;
                }
            case 2: //add car
                {
                    cout << "\n~Input Car Information~\n" << endl;
                    
                    cout << "License Plate: "; 
                    cin >> inputPlate;
                    cout << "Make: ";
                    cin >> inputMake;
                    cout << "Model: ";
                    cin >> inputModel;
                    cout << "Car Body (1)Sedan (2)SUV (3)Exotic: ";
                    cin >> inputType; //can I type this?
                    cout << "Price Per Day: $";
                    cin >> inputPrice;
                    
                    Car* newCar = new Car;
                    newCar->Initialize(inputPlate, inputMake, inputModel, static_cast<VehicleType>(inputType), inputPrice); //is this okay?
                    
                    carList->AddCar(*newCar);
                    cout << "\n" << inputPlate << " was added to the list and is available.";

                    break;
                }
            case 3: //remove car             
                {
                    cout << "\nEnter License Plate: ";
                    cin >> deleteCar;
                    carList->DeleteCar(deleteCar);
                    cout << "Car Deleted";
                    break;
                }
            case 4: //list reservations
                {
                    reservationList->PrintList();
                    break;
                };
            case 5: //add reservation
                {
                    cout << "\n~Input Reservation Information~\n" << endl;
                    
                    cout << "Name: " << flush; 
                    cin >> noskipws >> inputName; //get or getline work for whole name?
                    cout << inputName;

                    carList->PrintList();
                    cout << "\n\nLicense Plate of Car to Rent: " << endl;
                    cin >> inputRent;
                    
                    Reservation* newReservation = new Reservation;
                    newReservation->Initialize(inputName, inputRent);
                    Car* newCar = new Car;
                    *newCar = carList->FindCar(inputRent);
                    newCar->SetAvailable(false);                    

                    cout << "New reservation under " << inputName << " was created.";

                    break;
                };
            case 6: //remove reservation FIX available status
                {
                    cout << "Enter Name: ";
                    cin >> deleteReservation;

                    reservationList->DeleteReservation(deleteReservation);

                    Car* newCar = new Car;
                    *newCar = carList->FindCar(inputRent);
                    newCar->SetAvailable(true);
                    cout << "Reservation Deleted, Car Made Available";


                    break;
                };
            case 7: //exit
                {
                    cout << "\n~End of Program~\n";
                    exitCondition = true;
                    break;
                }
        }
    }
}