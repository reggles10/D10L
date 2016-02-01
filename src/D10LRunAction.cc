#include "D10LRunAction.hh"
#include "D10LPrimaryGeneratorAction.hh"
#include "D10LDetectorConstruction.hh"

#include "G4RunManager.hh"
#include "G4Run.hh"
#include "G4ParameterManager.hh"
#include "G4LogicalVolumeStore.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"

D10LRunAction::D10LRunAction()
//: G4UserRunAction(), fEdep("Edep",0.), fEdep2("Edep2",0.)
{

  G4ParameterManager * parameterManager = G4ParameterManager::Instance();
  parameterManager->RegisterParameter(fEdep);
  parameterManager->RegisterParameter(fEdep2);
  savehistFile = "D10L";

}

D10LRunAction::~D10LRunAction()
{}

void D10LRunAction::BeginOfRunAction(const G4Run*)
{
  //inform the runManager to save random number seed
  G4RunManager::GetRunManager()->SetRandomNumberStore(false);

  //reset parameters to their initial values
  G4ParameterManager * man = G4ParameterManager::Instance();
  man->Reset();

  //using advanced/underground_physics
  man->OpenFile(saveHistFile);
  
  //---primary ntuple----
  man->CreateNtuple("tree1","Particle Source Energy");
  man->CreateNtupleDColumn("energy");
  man->FinishNtuple();

  //create 1-d histograms
  man->CreateH1("h1","Source Energy /keV", 1000,0.,10000.);

  return;

}

void D10LRunAction::EndOfRunAction(const G4Run * run)
{
  G4int nofEvents = run->GetNumberOfEvent();
  if (nofEvents == 0) return;

  //Merge parameters
  //  G4ParameterManager * man = G4ParameterManager::Instance();
  //  man->Merge();

  //com

}
