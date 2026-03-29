#include "GasolineVehicle.h"

GasolineVehicle::GasolineVehicle() : mpg(0.0), totalKWh(0.0) {
}

GasolineVehicle::~GasolineVehicle() {
}

void GasolineVehicle::setMPG(double mpg) {
    this->mpg = mpg;
}

double GasolineVehicle::getMPG() const {
    return mpg;
}

void GasolineVehicle::setTotalKWh(double kWh) {
    this->totalKWh = kWh;
}

double GasolineVehicle::getTotalKWh() const {
    return totalKWh;
}

double GasolineVehicle::costPerMile(double costOfOneGallon) const {
    if (mpg == 0.0) return 0.0;
    return costOfOneGallon / mpg;
}
