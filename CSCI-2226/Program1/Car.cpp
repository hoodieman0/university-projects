
/*
XYZ Rental Car Service Program 1

Author:: James Mok

Created:: 3 February 2021
*/

#include "Car.hpp"

/*
Function:: Car::Initialize

Author:: James Mok

Type:: Constructor

Input:: string license plate, string make, string model, VehicleType tpye, double price

Output:: none
*/

void Car::Initialize(string pltKey, string mke, string mdl, VehicleType typ, double ppd)
{
    plateNumber = pltKey;
    make = mke;
    model = mdl;
    type = typ;
    pricePerDay = ppd;
}

/*
Function:: Car::SetAvailable

Author:: James Mok

Type :: Transformer

Input:: boolean

Output:: none
*/

void Car::SetAvailable(bool availableControl)
{
    isAvailable = availableControl;
}

/*
Function:: Car::GetAvailability

Author:: James Mok

Type:: Observer

Input:: none

Output:: bool isAvailable
*/

bool Car::GetAvailibility() const
{
    return isAvailable;
}

/*
Function:: Car::GetPlateNumber

Author:: James Mok

Type:: Observer

Input:: none

Output:: string plateNumber
*/

string Car::GetPlateNumber() const
{
    return plateNumber;
}

/*
Function:: Car::GetMake

Author:: James Mok

Type:: Observer

Input:: none

Output:: string make
*/

string Car::GetMake() const
{
    return make;
}

/*
Function:: GetModel

Author:: James Mok

Type:: Observer

Input:: none

Output:: string model
*/

string Car::GetModel() const
{
    return model;
}

/*
Function:: GetVehicleTypeEnum

Author:: James Mok

Type:: Observer

Input:: none

Output:: VehicleType type
*/

VehicleType Car::GetVehicleTypeEnum() const
{
    return type;
}

/*
Function:: GetVehicleType

Author:: James Mok

Type:: Observer

Input:: none

Output:: string type (in plaintext)
*/

string Car::GetVehicleType() const
{
    return typeArray[int(type)];
}

/*
Function:: GetPricePerDay

Author:: James Mok

Type:: Observer

Input:: none

Output:: double pricePerDay
*/

double Car::GetPricePerDay() const
{
    return pricePerDay;
}


//overloading operators + deconstructor

std::ostream& operator<<(std::ostream& os, const Car& i){
	os << "License Plate: " << i.GetPlateNumber() << "\nMake: " << i.GetMake() << "\nModel: " << i.GetModel() << "\nType: " << i.GetVehicleType() << "\nPrice Per Day: $" << i.GetPricePerDay() << "\nReady: " << boolalpha << i.GetAvailibility();
	return os;
}

void Car::operator= (const Car& equivalent)
{
    plateNumber = equivalent.GetPlateNumber();
    make = equivalent.GetMake();
    model = equivalent.GetModel();
    type = equivalent.GetVehicleTypeEnum();
    pricePerDay = equivalent.GetPricePerDay();

}

Car::~Car() {};

bool Car::operator== (const Car& comparison)
{
    return plateNumber == comparison.GetPlateNumber();
}