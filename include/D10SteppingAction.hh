#ifndef D10LSteppingAction_h
#define D10LSteppingAction_h 1

#include "G4UserSteppingAction.hh"
#include "globals.hh"

class D10LEventAction;

class G4LogicalVolume;

//stepping action class

class D10LSteppingAction : public G4UserSteppingAction
{
public:
  D10LSteppingAction(D10LEventAction* eventAction);
  virtual ~D10LSteppingAction();

  //method from the base class
  virtual void UserSteppingAction(const G4Step*);

private:
  D10LEventAction * fEventAction;
  G4LogicalVolume * fScoringVolume;

};
#endif
