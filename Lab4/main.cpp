#include <iostream>
#include "HybridVehicle.h"

using namespace std;

int main() {
    HybridVehicle hybrid;
    
    double miles = 300;
    hybrid.setElectricMiles(miles);
    
    double totalKWh = 70.0;
    hybrid.setTotalKWh(totalKWh);
    
    double mpge = hybrid.calcMPG();
    cout << "MPGe: " << mpge << endl;
    
    double costOfOneGallon = 3.10;
    double averageCostPerMile = hybrid.costPerMile(costOfOneGallon);
    cout << "Average Cost Per Mile: $" << averageCostPerMile << endl;
    
    return 0;
}
