#ifndef ELECTRICVEHICLE_H
#define ELECTRICVEHICLE_H

#include "Vehicle.h"

class ElectricVehicle : virtual public Vehicle {
private:
    double mpge;

public:
    ElectricVehicle();
    virtual ~ElectricVehicle();
    
    void setMPGe(double mpge);
    double getMPGe() const;
    
    double costPerMile(double costOfOneGallon) const;
};

#endif // ELECTRICVEHICLE_H
