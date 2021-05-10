#ifndef YOUREVENTACTION_HH
#define YOUREVENTACTION_HH
#include "G4UserEventAction.hh"
#include "globals.hh"
class YourEventAction : public G4UserEventAction {
  // Method declaration:
  public:
    YourEventAction();
    virtual ~YourEventAction();
    virtual void BeginOfEventAction(const G4Event* anEvent);
    virtual void EndOfEventAction(const G4Event* anEvent);
    void Add(G4double edep, G4double trackL) {
      fEdepPerEvt += edep;
      fChTrackLengthPerEvt += trackL;
    }
  // Data member declarations:
  private:
    G4double   fEdepPerEvt;
    G4double   fChTrackLengthPerEvt;
};
#endif
