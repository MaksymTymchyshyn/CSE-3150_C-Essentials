#ifndef GASOLINEVEHICLE_H
#define GASOLINEVEHICLE_H

#include "Vehicle.h"

class GasolineVehicle : virtual public Vehicle {
private:
    double mpg;
    double totalKWh;

public:
    GasolineVehicle();
    virtual ~GasolineVehicle();
    
    void setMPG(double mpg);
    double getMPG() const;
    
    void setTotalKWh(double kWh);
    double getTotalKWh() const;
    
    double costPerMile(double costOfOneGallon) const;
};

#endif // GASOLINEVEHICLE_H
