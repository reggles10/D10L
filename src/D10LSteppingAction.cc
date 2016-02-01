#include "D10LSteppingAction.hh"
#include "D10LEventAction.hh"
#include "D10LDetectorConstruction.hh"

#include "G4Step.hh"
#include "G4Event.hh"
#include "G4RunManager.hh"
#include "G4LogicalVolume.hh"

D10LSteppingAction::D10LSteppingAction(D10LEventAction * eventAction)
: G4UserSteppingAction(), fEventAction(eventAction), fScoringVolume(0)
{}

D10LSteppingAction::~D10LSteppingAction()
{}


void D10LSteppingAction::UserSteppingAction(const G4Step* step)
{
  if(!fScoringVolume) {
    const D10LDetectorConstruction * detectorConstruction = static_cast<const D10LDetectorConstruction*>
      (G4RunManager::GetRunManager()->GetUserDetectorConstruction());
    fScoringVolume = detectorCostruction->GetScoringVolume();
  }

  //get volume of the current step
  G4LogicalVolume * volume = step->GetPreStepPoint()->GetTouchableHandle()->GetVolume()->GetLogicalVolume();

  //check if we are in a scoring volume
  if (volume !- fScoringVolume) return;

  //collect energy deposited in this step
  G4double edepStep = step->GetTotalEnergyDeposit();
  fEventAction->AddEdep(edepStep);
}
