#ifndef RESERVATION_HPP
#define RESERVATION_HPP

#include <iostream>
#include <string>
using namespace std;

class Reservation
{
    private: 
        string name;
        string vehicleRented;

    public:
        void Initialize(string key, string vehiclePlate);
        string GetName() const;
        string GetVehicleRented() const;
        ~Reservation();
        bool operator== (const Reservation&);
};

std::ostream& operator<<(std::ostream& os, const Reservation& res);

#endif