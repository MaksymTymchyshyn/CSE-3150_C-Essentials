#include "ElectricVehicle.h"

ElectricVehicle::ElectricVehicle() : mpge(0.0) {
}

ElectricVehicle::~ElectricVehicle() {
}

void ElectricVehicle::setMPGe(double mpge) {
    this->mpge = mpge;
}

double ElectricVehicle::getMPGe() const {
    return mpge;
}

double ElectricVehicle::costPerMile(double costOfOneGallon) const {
    if (mpge == 0.0) return 0.0;
    return costOfOneGallon / mpge;
}
