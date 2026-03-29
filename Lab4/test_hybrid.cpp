#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "HybridVehicle.h"
#include "GasolineVehicle.h"
#include "ElectricVehicle.h"

TEST_CASE("GasolineVehicle - MPG and cost per mile") {
    GasolineVehicle gas;
    
    SUBCASE("Set and get MPG") {
        gas.setMPG(30.0);
        CHECK(gas.getMPG() == doctest::Approx(30.0));
    }
    
    SUBCASE("Cost per mile calculation") {
        gas.setMPG(30.0);
        double costPerMile = gas.costPerMile(3.00);
        CHECK(costPerMile == doctest::Approx(0.10));
    }
    
    SUBCASE("Zero MPG returns zero cost") {
        gas.setMPG(0.0);
        CHECK(gas.costPerMile(3.00) == doctest::Approx(0.0));
    }
}

TEST_CASE("ElectricVehicle - MPGe and cost per mile") {
    ElectricVehicle electric;
    
    SUBCASE("Set and get MPGe") {
        electric.setMPGe(100.0);
        CHECK(electric.getMPGe() == doctest::Approx(100.0));
    }
    
    SUBCASE("Cost per mile calculation") {
        electric.setMPGe(100.0);
        double costPerMile = electric.costPerMile(3.00);
        CHECK(costPerMile == doctest::Approx(0.03));
    }
    
    SUBCASE("Zero MPGe returns zero cost") {
        electric.setMPGe(0.0);
        CHECK(electric.costPerMile(3.00) == doctest::Approx(0.0));
    }
}

TEST_CASE("HybridVehicle - Multi-inheritance functionality") {
    HybridVehicle hybrid;
    
    SUBCASE("Set and get electric miles") {
        hybrid.setElectricMiles(300.0);
        CHECK(hybrid.getElectricMiles() == doctest::Approx(300.0));
    }
    
    SUBCASE("Set and get total kWh") {
        hybrid.setTotalKWh(70.0);
        CHECK(hybrid.getTotalKWh() == doctest::Approx(70.0));
    }
    
    SUBCASE("Calculate MPGe - 300 miles, 70 kWh") {
        hybrid.setElectricMiles(300.0);
        hybrid.setTotalKWh(70.0);
        double mpge = hybrid.calcMPG();
        // MPGe = (300 / 70) * 33.7 = 144.43
        CHECK(mpge == doctest::Approx(144.429).epsilon(0.01));
    }
    
    SUBCASE("Calculate MPGe - 100 miles, 33.7 kWh (should be 100 MPGe)") {
        hybrid.setElectricMiles(100.0);
        hybrid.setTotalKWh(33.7);
        double mpge = hybrid.calcMPG();
        CHECK(mpge == doctest::Approx(100.0).epsilon(0.01));
    }
    
    SUBCASE("Cost per mile calculation") {
        hybrid.setElectricMiles(300.0);
        hybrid.setTotalKWh(70.0);
        double costPerMile = hybrid.costPerMile(3.10);
        // costOfElectricity = 33.7 * 0.24 = 8.088
        // MPGe = 144.429
        // cost per mile = 8.088 / 144.429 = 0.056
        CHECK(costPerMile == doctest::Approx(0.056).epsilon(0.01));
    }
    
    SUBCASE("Zero kWh returns zero MPGe") {
        hybrid.setElectricMiles(300.0);
        hybrid.setTotalKWh(0.0);
        CHECK(hybrid.calcMPG() == doctest::Approx(0.0));
    }
    
    SUBCASE("Zero MPGe returns zero cost per mile") {
        hybrid.setElectricMiles(0.0);
        hybrid.setTotalKWh(0.0);
        CHECK(hybrid.costPerMile(3.10) == doctest::Approx(0.0));
    }
}

TEST_CASE("HybridVehicle - Energy equivalence formula") {
    HybridVehicle hybrid;
    
    SUBCASE("33.7 kWh equals 1 gallon gasoline energy") {
        // If vehicle uses 33.7 kWh to go 100 miles, it's 100 MPGe
        hybrid.setElectricMiles(100.0);
        hybrid.setTotalKWh(33.7);
        double mpge = hybrid.calcMPG();
        CHECK(mpge == doctest::Approx(100.0).epsilon(0.01));
    }
    
    SUBCASE("Real-world example: Tesla efficiency") {
        // Tesla Model 3 approximately 250 miles on 75 kWh
        hybrid.setElectricMiles(250.0);
        hybrid.setTotalKWh(75.0);
        double mpge = hybrid.calcMPG();
        // MPGe = (250 / 75) * 33.7 = 112.33
        CHECK(mpge == doctest::Approx(112.33).epsilon(0.01));
    }
}
