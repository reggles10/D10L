#include "D10LEventAction.hh"
#include "D10LRunAction.hh"

#include "G4Event.hh"
#include "G4RunManager.hh"

D10LEventAction::D10LEventAction(D10LRunAction * runAction)
: G4UserEventAction(), fRunAction(runAction), fEdep(0.)
{}

D10LEventAction::~D10LEventAction()
{}

void D10LEventAction::BeginOfEventAction(const G4Event*)
{
  fEdep = 0.;
  
  //thread-local run action
  if (!runAct)
    runAct = dynamic_cast<const D10LRunAction*>
      (G4RunManager::GetRunManager()->GetUserRunAction());

  if (!genAction)
    genAction = dynamic_cast<const D10LPrimaryGeneratorAction*>
      (G4RunManager::GetRunManager()->GetUserPrimaryGeneratorAction());

  //grab seeds
  seeds = genAction->GetEventSeeds();

  //grab energy of primary
  energy_pri = genAction->GetEnergyPrimary();

  event_id = evt->GetEventID();

}

void D10LEventAction::EndOfEventAction(const G4Event*)
{
  fRunAction->AddEdep(fEdep);

  G4AnalysisManager * man = G4AnalysisManager::Instance();

  //event summary
  totEnergy = 0.;
  totEnergyGammas = 0.;
  totEnergyNeutrons = 0.;
  firstParticleE = 0.;
  particleEnergy = 0.;
  
  firstParticleName = "";
  particleName = "";


}
