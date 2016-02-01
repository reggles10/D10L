#ifndef _10LActionInitialisation_h
#define _10LActionInitialisation_h 1

#include "G4VUserActionInitialization.hh"

//Action initialisation class

class 10LActionInitialisation : public G4VUserActionInitialization
{
public:
  10LActionInitialisation();
  virtual ~10LActionInitialisation();

  virtual void BuildForMaster() const;
  virtual void Build() const;

};

#endif
