#ifndef YOURDETECTORCONTRUCTION_HH
#define YOURDETECTORCONTRUCTION_HH
#include "G4VUserDetectorConstruction.hh"
// forward declaration
class YourDetectorMessenger;
class G4Material;
class G4String;
class G4LogicalVolume;
class YourDetectorConstruction : public G4VUserDetectorConstruction {
  // Method declaration:
  public:
    YourDetectorConstruction();
    virtual ~YourDetectorConstruction();
    virtual G4VPhysicalVolume* Construct();
    void     SetTargetThickness(const G4double thick) { fTargetThickness = thick; }
    G4double GetTargetThickness() const               { return fTargetThickness;  }
    void              SetTargetMaterial(const G4String& matName);
    const G4Material* GetTargetMaterial() const  { return fTargetMaterial; }

    G4double GetGunXPosition() { return fGunXPosition; }


    const G4VPhysicalVolume* GetTargetPhysicalVolume() const { 
        return fTargetPhysicalVolume; 
    } 
  // Data member declaration
  private:
    // The detector messenger pointer: to set the target thickness
    YourDetectorMessenger* fDetMessenger;
    // Target material 
    G4Material*            fTargetMaterial;
    // Target logical volume pointer
    G4VPhysicalVolume*     fTargetPhysicalVolume;
    // The target thickness i.e. its (full) x-size (YZ size will be set 10x this)
    G4double               fTargetThickness;
    // The midpoint between the target and the world on the negative x-side
    G4double               fGunXPosition;
};
#endif 
