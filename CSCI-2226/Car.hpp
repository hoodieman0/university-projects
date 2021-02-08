#ifndef CAR_HPP
#define CAR_HPP

#include <iostream>
#include <string>
using namespace std;

enum VehicleType {SEDAN=1, SUV, EXOTIC};

class Car
{
    private:
        
        string typeArray[4] = {"Error", "Sedan", "SUV", "Exotic"};
        string plateNumber;
        string make;
        string model;
        VehicleType type;
        double pricePerDay;
        bool isAvailable = true;
    
    public:
        void Initialize(string pltKey, string mke, string mdl, VehicleType typ, double ppd);
        void SetAvailable(bool availability); //dont know if this works
        bool GetAvailibility() const;
        string GetPlateNumber() const;
        string GetMake() const;
        string GetModel() const;
        VehicleType GetVehicleTypeEnum() const;
        string GetVehicleType() const;
        double GetPricePerDay() const;
        ~Car();
        bool operator== (const Car&);
        void operator= (const Car&);

};

std::ostream& operator<<(std::ostream& os, const Car& i);

#endif