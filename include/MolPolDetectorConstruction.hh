#ifndef MolPolDetectorConstruction_h
#define MolPolDetectorConstruction_h 1

#include "globals.hh"
#include "G4VUserDetectorConstruction.hh"

class MolPolEMFieldSetup;
class G4Material;
class G4VPhysicalVolume;
class G4GenericMessenger;
class G4Tubs;
class G4Box;

class MolPolDetectorConstruction : public G4VUserDetectorConstruction
{
  public:
    MolPolDetectorConstruction();
   ~MolPolDetectorConstruction();

   public:
    G4VPhysicalVolume* Construct();
    void ConstructMaterials();

    void SetDipolePbJawsGap(G4double val);
    void SetTargetThickness(G4double val);
    void SetTargetZPosition(G4double val);

    void SetTr1Pos_x(G4double val);
    void SetTr1Pos_y(G4double val);
    void SetTr2Pos_x(G4double val);
    void SetTr2Pos_y(G4double val);
    void SetTr3Pos_x(G4double val);
    void SetTr3Pos_y(G4double val);

    void SetTr1Pos_z(G4double val);
    void SetTr2Pos_z(G4double val);
    void SetTr3Pos_z(G4double val);
    void BuildTracking();    

    void UpdateGeometry();

    G4Material * GetTarget()           {return fTargetMaterial;}
    G4double     GetTargetFullLength() {return fTargetFullLength;}

  private:
    void DefineGeometryCommands();

    MolPolEMFieldSetup*   mEMFieldSetup;

    G4bool                fCheckOverlaps;

    G4Material *          fTargetMaterial;     //Used for Sanghwa's update to PrimaryGenerator

    G4GenericMessenger *  fMessenger;

    // Class members for GEM tracking
    G4double              pTr1Pos_X;
    G4double              pTr1Pos_Y;
    G4double              pTr1Pos_Z;
    G4double              pTr2Pos_X;
    G4double              pTr2Pos_Y;
    G4double              pTr2Pos_Z;
    G4double              pTr3Pos_X;
    G4double              pTr3Pos_Y;
    G4double              pTr3Pos_Z;
    G4Box*                fTrackingSolidUS;
    G4Box*                fTrackingSolidMD;
    G4Box*                fTrackingSolidDS;
    G4LogicalVolume*      fTrackingLogicalUS;
    G4LogicalVolume*      fTrackingLogicalMD;
    G4LogicalVolume*      fTrackingLogicalDS;
    G4VPhysicalVolume *   fTrackingPhysVolUS;
    G4VPhysicalVolume *   fTrackingPhysVolMD;
    G4VPhysicalVolume *   fTrackingPhysVolDS;
    G4double              fLeadJawGapWidth;
    G4double              fLeadJawsHLength;
    G4double              fLeadJawsZOrigin;
    G4double              fLeadJawsYOrigin;
    G4double              fLeadJawsXOrigin;
    G4VPhysicalVolume *   fLeadJawsPhysicalLT;
    G4VPhysicalVolume *   fLeadJawsPhysicalLB;
    G4VPhysicalVolume *   fLeadJawsPhysicalRT;
    G4VPhysicalVolume *   fLeadJawsPhysicalRB;


    //Class members for Pb Jaws
    G4VPhysicalVolume *   fTargetPhysVolume;
    G4double              fTargetFullLength;   //Used for Sanghwa's update to PrimaryGenerator and DetCon's Generic Messenger
    G4double              fTargetFullRadius;
    G4double              fTargetBeamlinePx;
    G4double              fTargetBeamlinePy;
    G4double              fTargetBeamlinePz;
    G4double              fHelmCoilBeamPosZ;   //Position for solenoid center, required for proper placing of the target.
    G4Tubs *              fTargetVSolidTubs;   //Solid volume for target
};

#endif
