#ifndef _10LDetectorConstruction_h
#define _10LDetectorConstruction_h 1

#include "G4VUserDetectorConstruction.hh"
#include "globals.hh"

#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"

//Detector Class to define materials and geometry

class D10LDetectorConstruction : public G4VUserDetectorConstruction
{
public:
  D10LDetectorConstruction();
  virtual ~D10LDetectorConstruction();

  virtual G4VPhysicalVolume * Construct();
  
  G4LogicalVolume * GetScoringVolume() const {return fScoringVolume;}

protected:
  G4LogicalVolume * fScoringVolume;
};

#endif
