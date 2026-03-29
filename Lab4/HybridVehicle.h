#ifndef HYBRIDVEHICLE_H
#define HYBRIDVEHICLE_H

#include "GasolineVehicle.h"
#include "ElectricVehicle.h"

class HybridVehicle : public GasolineVehicle, public ElectricVehicle {
private:
    double electricMiles;
    double totalKWh;

public:
    HybridVehicle();
    virtual ~HybridVehicle();
    
    void setElectricMiles(double miles);
    double getElectricMiles() const;
    
    void setTotalKWh(double kWh);
    double getTotalKWh() const;
    
    double calcMPG() const;
    double costPerMile(double costOfOneGallon) const;
};

#endif // HYBRIDVEHICLE_H
