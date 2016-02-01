#ifndef _10LRunAction_h
#define _10LRunAction_h 1

#include "G4UserRunActioon.hh"
#include "G4Parameter.hh"
#include "globals.hh"

class G4Run;

//run action class

//in EndOfRunAction(), it calculates the 'dose' in the selected volume from the energy deposit
//accumulated via stepping and event actions.
//the computed dose is then printed on  the screen

class 10LRunAction : public G4UserRunAction
{
public:
  10LRunAction();
  virtual ~10LRunAction();

  virtual void BeginOfRunAction(const G4Run*);
  virtual void EndofRunAction(const G4Run*);

  void AddEdep (G4double edep);

private:
  G4Parameter<G4double> fEdep;
  G4Parameter<G4double> fEdep2;

};

#endif
