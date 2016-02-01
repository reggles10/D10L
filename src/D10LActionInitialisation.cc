#include "D10LActionInitialisation.hh"
#include "D10LPrimaryGeneratorAction.hh"
#include "D10LRunAction.hh"
#include "D10LEventAction.hh"
#include "D10LSteppingAction.hh"

D10LActionInitialisation::D10LActionInitialisation()
: G4VUserActionInitialization()
{}

D10LActionInitialisation::~D10LActionInitialisation()
{}

void D10LActionInitialisation::BuildForMaster() const
{
  SetUserAction(new D10LPrimaryGeneratorAction);

  D10LRunAction * runAction = new D10LRunAction;
  SetUserAction(runAction);

  D10LEventAction * eventAction = new D10LEventAction(runAction);
  SetUserAction(eventAction);

  SetUserAction(new D10LSteppingAction(eventAction));
}
