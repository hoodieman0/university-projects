#include "Car.hpp"

void Car::Initialize(string pltKey, string mke, string mdl, VehicleType typ, double ppd)
{
    plateNumber = pltKey;
    make = mke;
    model = mdl;
    type = typ;
    pricePerDay = ppd;
}

void Car::SetAvailable(bool availableControl)
{
    isAvailable = availableControl;
}

bool Car::GetAvailibility() const
{
    return isAvailable;
}

string Car::GetPlateNumber() const
{
    return plateNumber;
}


string Car::GetMake() const
{
    return make;
}
string Car::GetModel() const
{
    return model;
}

VehicleType Car::GetVehicleTypeEnum() const
{
    return type;
}


string Car::GetVehicleType() const
{
    return typeArray[int(type)];
}

double Car::GetPricePerDay() const
{
    return pricePerDay;
}

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