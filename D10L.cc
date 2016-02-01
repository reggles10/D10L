#include "D10LDetectorConstruction.hh"

#ifdef G4MULTITHREADED
#include "G4MTRunManager.hh"
#else
#include "G4RunManager.hh"
#endif

#include "G4UImanager.hh"

#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"

#include "Randomize.hh"
#include "DMXPhysicsList.hh"

int main(int argc, char ** argv){

  //Detect interactive mode (if no arguments) and define UI session
  //
  G4UIExecutive * ui = 0;
  if( argc == 1) {
    ui = new G4UIExecutive(argc,argv);
  }

  //Choose the Random engine
  G4Random::setTheEngine(new CLHEP::RanecuEngine);

  //Construcxt the default run manager
  //
  #ifdef G4MULTITHREADED
  G4MTRunManager * runManager = new G4MTRunManager;
  #else
  G4RunManager * runManager = new G4RunManager;
#endif
  //set mandatory initialisation classes
  //
  //Detector construction
  runManager->SetUserInitialization(new D10LDetectorConstruction());
  
  //physics list
  runManager->SetUserInitialization(new DMXPhysicsList);
}

  
