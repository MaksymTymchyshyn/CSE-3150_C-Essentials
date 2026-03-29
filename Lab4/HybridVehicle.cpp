#include "HybridVehicle.h"

HybridVehicle::HybridVehicle() : electricMiles(0.0), totalKWh(0.0) {
}

HybridVehicle::~HybridVehicle() {
}

void HybridVehicle::setElectricMiles(double miles) {
    this->electricMiles = miles;
}

double HybridVehicle::getElectricMiles() const {
    return electricMiles;
}

void HybridVehicle::setTotalKWh(double kWh) {
    this->totalKWh = kWh;
}

double HybridVehicle::getTotalKWh() const {
    return totalKWh;
}

double HybridVehicle::calcMPG() const {
    // Electric vehicles efficiency is measured in MPGe (miles per gallon equivalent)
    // 1 gallon of gasoline = 33.7 kWh
    // If electric vehicle goes 100 miles per 33.7 kWh, then vehicle is going 100 mpg equivalent
    
    if (totalKWh == 0.0) return 0.0;
    
    // MPGe = (electricMiles / totalKWh) * 33.7
    double mpge = (electricMiles / totalKWh) * 33.7;
    return mpge;
}

double HybridVehicle::costPerMile(double costOfOneGallon) const {
    // Cost in Connecticut is under 24 cents per kWh
    // So, 33.7 times 24 cents per kWh gives a cost of $8
    double costOfElectricity = 33.7 * 0.24;  // $8.088
    
    double mpge = calcMPG();
    if (mpge == 0.0) return 0.0;
    
    double averageCostPerMile = costOfElectricity / mpge;
    return averageCostPerMile;
}
