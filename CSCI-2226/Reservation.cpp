
/*
XYZ Rental Car Service Program 1

Author:: James Mok

Created:: 3 February 2021
*/

#include "Reservation.hpp"

/*
Function:: Initialize

Author:: James Mok

Type:: Constructor

Input:: string name, string license plate

Output:: none
*/

void Reservation::Initialize(string key, string vehiclePlate)
{
    name = key;
    vehicleRented = vehiclePlate;
}

/*
Function:: GetName

Author:: James Mok

Type:: Observer

Input:: none

Output:: string name
*/

string Reservation::GetName() const
{
    return name;
}

/*
Function:: GetVehicleRented

Author:: James Mok

Type:: Observer

Input:: none

Output:: string license plate
*/

string Reservation::GetVehicleRented() const
{
    return vehicleRented;
}

//overloading operators + deconstructor

Reservation::~Reservation() {}

bool Reservation::operator== (const Reservation& comparison)
{
    return name == comparison.GetName();
}

std::ostream& operator<<(std::ostream& os, const Reservation& res){
	os << "Name: " << res.GetName() << "\nRented Vehicle: " << res.GetVehicleRented();
	return os;
}