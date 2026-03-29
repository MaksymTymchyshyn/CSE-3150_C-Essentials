# Lab Week 4: Hybrid Vehicles - Multi-Inheritance

Name: Maksym Tymchyshyn  
Lab: Lab Week 4: Hybrid Vehicles - Multi-Inheritance

## Solution Description

1. **Vehicle Base Class**: Abstract base class providing common interface for all vehicle types. Uses virtual inheritance to avoid diamond problem in multi-inheritance hierarchy.

2. **GasolineVehicle Class**: Inherits virtually from Vehicle. Tracks fuel efficiency in MPG (miles per gallon) and provides cost per mile calculation based on gasoline prices. Stores MPG and total kWh for hybrid calculations.

3. **ElectricVehicle Class**: Inherits virtually from Vehicle. Measures efficiency in MPGe (miles per gallon equivalent) where 1 gallon of gasoline equals 33.7 kWh. Calculates cost per mile based on electricity prices.

4. **HybridVehicle Class**: Multi-inheritance from both GasolineVehicle and ElectricVehicle. Combines both propulsion systems to measure fuel efficiency of hybrid vehicles. Calculates MPGe based on electric miles and total kWh consumed.

5. **MPGe Calculation**: Implements formula where MPGe = (electricMiles / totalKWh) × 33.7. This converts electric efficiency to gasoline equivalent for comparison. If electric vehicle goes 100 miles per 33.7 kWh, it achieves 100 MPGe.

6. **Cost Per Mile**: Uses Connecticut electricity rate of $0.24 per kWh. Calculates equivalent gasoline cost as 33.7 kWh × $0.24 = $8.088. Divides by MPGe to get average cost per mile for hybrid operation.

## System Architecture

```
┌─────────────────────────────────────────────┐
│             Vehicle (Base Class)            │
│             (Virtual Base)                  │
├─────────────────────────────────────────────┤
│ Public:                                     │
│  + Vehicle()                                │
│  + virtual ~Vehicle()                       │
└──────────────┬──────────────────────────────┘
               │
               │ virtual inheritance
               │
       ┌───────┴───────┐
       │               │
       ▼               ▼
┌─────────────┐ ┌─────────────┐
│ Gasoline    │ │ Electric    │
│ Vehicle     │ │ Vehicle     │
├─────────────┤ ├─────────────┤
│ Private:    │ │ Private:    │
│ - mpg       │ │ - mpge      │
│ - totalKWh  │ │             │
├─────────────┤ ├─────────────┤
│ Public:     │ │ Public:     │
│ + setMPG()  │ │ + setMPGe() │
│ + getMPG()  │ │ + getMPGe() │
│ + costPer   │ │ + costPer   │
│   Mile()    │ │   Mile()    │
└──────┬──────┘ └──────┬──────┘
       │               │
       └───────┬───────┘
               │
               │ multiple inheritance
               ▼
    ┌─────────────────────────┐
    │   HybridVehicle         │
    ├─────────────────────────┤
    │ Private:                │
    │  - electricMiles        │
    │  - totalKWh             │
    ├─────────────────────────┤
    │ Public:                 │
    │  + setElectricMiles()   │
    │  + getElectricMiles()   │
    │  + setTotalKWh()        │
    │  + getTotalKWh()        │
    │  + calcMPG()            │  ← Calculates MPGe
    │  + costPerMile()        │  ← Uses electricity cost
    └─────────────────────────┘
```

## Use Flow Diagram

```
Start
  │
  ▼
[Create HybridVehicle instance]
  │
  ├──────────────────┬──────────────────┐
  │                  │                  │
  ▼                  ▼                  ▼
[Set Electric    [Set Total       [Calculate MPGe]
 Miles = 300]     kWh = 70.0]          │
  │                  │                  │
  └──────────────────┴──────────────────┘
                     │
                     ▼
            [calcMPG() method]
                     │
                     ▼
        [MPGe = (electricMiles / totalKWh) × 33.7]
                     │
                     ▼
        [MPGe = (300 / 70.0) × 33.7]
                     │
                     ▼
        [MPGe = 4.2857 × 33.7 ≈ 144.43]
                     │
                     ▼
        [Display MPGe value]
                     │
                     ▼
        [Calculate cost per mile]
                     │
                     ▼
        [costPerMile(costOfOneGallon)]
                     │
                     ▼
        [costOfElectricity = 33.7 × 0.24 = $8.088]
                     │
                     ▼
        [averageCostPerMile = $8.088 / MPGe]
                     │
                     ▼
        [averageCostPerMile = $8.088 / 144.43]
                     │
                     ▼
        [averageCostPerMile ≈ $0.056]
                     │
                     ▼
        [Display cost per mile]
                     │
                     ▼
                   End

