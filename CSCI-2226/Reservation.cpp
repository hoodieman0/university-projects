#include "Reservation.hpp"

void Reservation::Initialize(string key, string vehiclePlate)
{
    name = key;
    vehicleRented = vehiclePlate;
}

string Reservation::GetName() const
{
    return name;
}

string Reservation::GetVehicleRented() const
{
    return vehicleRented;
}

Reservation::~Reservation() {}

bool Reservation::operator== (const Reservation& comparison)
{
    return name == comparison.GetName();
}

std::ostream& operator<<(std::ostream& os, const Reservation& res){
	os << "Name: " << res.GetName() << "\nRented Vehicle: " << res.GetVehicleRented();
	return os;
}