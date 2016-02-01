#ifndef _10LPrimaryGeneratorAction_h
#define _10LPrimaryGeneratorAction_h 1

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ParticleGun.hh"
#include "globals.hh"

class G4ParticleGun;
class G4Event;
class G4Box;

//The primary generator action class with particle gun
///
// The default kinematic is a 6 MeV gamma, randomly distributed
// infront of the phantomacross 90% of the (X,Y) phantom size

class 10LPrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
public:
  10LPrimaryGeneratorAction();
  virtual ~10LPrimaryGeneratorAction();

  //method from the base class
  virtual void GeneratePrimaries(G4Event*);

  //method to access particle gun
  const G4ParticleGun * GetParticleGun() const {return fParticleGun; }

private:
  G4ParticleGun * fParticleGun;
  G4Box * fWorld;

};
