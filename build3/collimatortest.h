//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Mar 27 15:44:11 2026 by ROOT version 6.32.10
// from TTree T/Geant4 Moller Polarimetry Simulation
// found on file: sample.root
//////////////////////////////////////////////////////////

#ifndef collimatortest_h
#define collimatortest_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class collimatortest {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Int_t           evNpart;
   Int_t           evPid[2];   //[ev.npart]
   Double_t        evVx[2];   //[ev.npart]
   Double_t        evVy[2];   //[ev.npart]
   Double_t        evVz[2];   //[ev.npart]
   Double_t        evP[2];   //[ev.npart]
   Double_t        evPx[2];   //[ev.npart]
   Double_t        evPy[2];   //[ev.npart]
   Double_t        evPz[2];   //[ev.npart]
   Double_t        evTh[2];   //[ev.npart]
   Double_t        evPh[2];   //[ev.npart]
   Double_t        evPhcom;
   Double_t        evThcom;
   Double_t        evDeltaTh;
   Double_t        evXs;
   Double_t        evAsym;
   Double_t        evUnpolWght;
   Double_t        evPolPlusWghtX;
   Double_t        evPolPlusWghtY;
   Double_t        evPolPlusWghtZ;
   Double_t        evPolMinusWghtX;
   Double_t        evPolMinusWghtY;
   Double_t        evPolMinusWghtZ;
   Double_t        evTargMom;
   Int_t           evCalCoin;
   Int_t           evHodCoin;
   Int_t           hitN;
   Int_t           hitDet[96];   //[hit.n]
   Int_t           hitVid[96];   //[hit.n]
   Int_t           hitPid[96];   //[hit.n]
   Int_t           hitTrid[96];   //[hit.n]
   Int_t           hitMtrid[96];   //[hit.n]
   Int_t           hitGen[96];   //[hit.n]
   Double_t        hitX[96];   //[hit.n]
   Double_t        hitY[96];   //[hit.n]
   Double_t        hitZ[96];   //[hit.n]
   Double_t        hitLx[96];   //[hit.n]
   Double_t        hitLy[96];   //[hit.n]
   Double_t        hitLz[96];   //[hit.n]
   Double_t        hitPx[96];   //[hit.n]
   Double_t        hitPy[96];   //[hit.n]
   Double_t        hitPz[96];   //[hit.n]
   Double_t        hitVx[96];   //[hit.n]
   Double_t        hitVy[96];   //[hit.n]
   Double_t        hitVz[96];   //[hit.n]
   Double_t        hitVdx[96];   //[hit.n]
   Double_t        hitVdy[96];   //[hit.n]
   Double_t        hitVdz[96];   //[hit.n]
   Double_t        hitP[96];   //[hit.n]
   Double_t        hitE[96];   //[hit.n]
   Double_t        hitM[96];   //[hit.n]
   Double_t        hitEdep[96];   //[hit.n]

   // List of branches
   TBranch        *b_ev_npart;   //!
   TBranch        *b_evPid;   //!
   TBranch        *b_evVx;   //!
   TBranch        *b_evVy;   //!
   TBranch        *b_evVz;   //!
   TBranch        *b_evP;   //!
   TBranch        *b_evPx;   //!
   TBranch        *b_evPy;   //!
   TBranch        *b_evPz;   //!
   TBranch        *b_evTh;   //!
   TBranch        *b_evPh;   //!
   TBranch        *b_ev_phcom;   //!
   TBranch        *b_ev_thcom;   //!
   TBranch        *b_ev_deltath;   //!
   TBranch        *b_ev_xs;   //!
   TBranch        *b_ev_asym;   //!
   TBranch        *b_ev_unpolWght;   //!
   TBranch        *b_ev_polPlusWghtX;   //!
   TBranch        *b_ev_polPlusWghtY;   //!
   TBranch        *b_ev_polPlusWghtZ;   //!
   TBranch        *b_ev_polMinusWghtX;   //!
   TBranch        *b_ev_polMinusWghtY;   //!
   TBranch        *b_ev_polMinusWghtZ;   //!
   TBranch        *b_ev_targMom;   //!
   TBranch        *b_ev_calCoin;   //!
   TBranch        *b_ev_hodCoin;   //!
   TBranch        *b_hit_n;   //!
   TBranch        *b_hitDet;   //!
   TBranch        *b_hitVid;   //!
   TBranch        *b_hitPid;   //!
   TBranch        *b_hitTrid;   //!
   TBranch        *b_hitMtrid;   //!
   TBranch        *b_hitGen;   //!
   TBranch        *b_hitX;   //!
   TBranch        *b_hitY;   //!
   TBranch        *b_hitZ;   //!
   TBranch        *b_hitLx;   //!
   TBranch        *b_hitLy;   //!
   TBranch        *b_hitLz;   //!
   TBranch        *b_hitPx;   //!
   TBranch        *b_hitPy;   //!
   TBranch        *b_hitPz;   //!
   TBranch        *b_hitVx;   //!
   TBranch        *b_hitVy;   //!
   TBranch        *b_hitVz;   //!
   TBranch        *b_hitVdx;   //!
   TBranch        *b_hitVdy;   //!
   TBranch        *b_hitVdz;   //!
   TBranch        *b_hitP;   //!
   TBranch        *b_hitE;   //!
   TBranch        *b_hitM;   //!
   TBranch        *b_hitEdep;   //!

   collimatortest(TTree *tree=0);
   virtual ~collimatortest();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual bool     Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef collimatortest_cxx
collimatortest::collimatortest(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("sample.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("sample.root");
      }
      f->GetObject("T",tree);

   }
   Init(tree);
}

collimatortest::~collimatortest()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t collimatortest::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t collimatortest::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void collimatortest::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("evNpart", &evNpart, &b_ev_npart);
   fChain->SetBranchAddress("evPid", evPid, &b_evPid);
   fChain->SetBranchAddress("evVx", evVx, &b_evVx);
   fChain->SetBranchAddress("evVy", evVy, &b_evVy);
   fChain->SetBranchAddress("evVz", evVz, &b_evVz);
   fChain->SetBranchAddress("evP", evP, &b_evP);
   fChain->SetBranchAddress("evPx", evPx, &b_evPx);
   fChain->SetBranchAddress("evPy", evPy, &b_evPy);
   fChain->SetBranchAddress("evPz", evPz, &b_evPz);
   fChain->SetBranchAddress("evTh", evTh, &b_evTh);
   fChain->SetBranchAddress("evPh", evPh, &b_evPh);
   fChain->SetBranchAddress("evPhcom", &evPhcom, &b_ev_phcom);
   fChain->SetBranchAddress("evThcom", &evThcom, &b_ev_thcom);
   fChain->SetBranchAddress("evDeltaTh", &evDeltaTh, &b_ev_deltath);
   fChain->SetBranchAddress("evXs", &evXs, &b_ev_xs);
   fChain->SetBranchAddress("evAsym", &evAsym, &b_ev_asym);
   fChain->SetBranchAddress("evUnpolWght", &evUnpolWght, &b_ev_unpolWght);
   fChain->SetBranchAddress("evPolPlusWghtX", &evPolPlusWghtX, &b_ev_polPlusWghtX);
   fChain->SetBranchAddress("evPolPlusWghtY", &evPolPlusWghtY, &b_ev_polPlusWghtY);
   fChain->SetBranchAddress("evPolPlusWghtZ", &evPolPlusWghtZ, &b_ev_polPlusWghtZ);
   fChain->SetBranchAddress("evPolMinusWghtX", &evPolMinusWghtX, &b_ev_polMinusWghtX);
   fChain->SetBranchAddress("evPolMinusWghtY", &evPolMinusWghtY, &b_ev_polMinusWghtY);
   fChain->SetBranchAddress("evPolMinusWghtZ", &evPolMinusWghtZ, &b_ev_polMinusWghtZ);
   fChain->SetBranchAddress("evTargMom", &evTargMom, &b_ev_targMom);
   fChain->SetBranchAddress("evCalCoin", &evCalCoin, &b_ev_calCoin);
   fChain->SetBranchAddress("evHodCoin", &evHodCoin, &b_ev_hodCoin);
   fChain->SetBranchAddress("hitN", &hitN, &b_hit_n);
   fChain->SetBranchAddress("hitDet", hitDet, &b_hitDet);
   fChain->SetBranchAddress("hitVid", hitVid, &b_hitVid);
   fChain->SetBranchAddress("hitPid", hitPid, &b_hitPid);
   fChain->SetBranchAddress("hitTrid", hitTrid, &b_hitTrid);
   fChain->SetBranchAddress("hitMtrid", hitMtrid, &b_hitMtrid);
   fChain->SetBranchAddress("hitGen", hitGen, &b_hitGen);
   fChain->SetBranchAddress("hitX", hitX, &b_hitX);
   fChain->SetBranchAddress("hitY", hitY, &b_hitY);
   fChain->SetBranchAddress("hitZ", hitZ, &b_hitZ);
   fChain->SetBranchAddress("hitLx", hitLx, &b_hitLx);
   fChain->SetBranchAddress("hitLy", hitLy, &b_hitLy);
   fChain->SetBranchAddress("hitLz", hitLz, &b_hitLz);
   fChain->SetBranchAddress("hitPx", hitPx, &b_hitPx);
   fChain->SetBranchAddress("hitPy", hitPy, &b_hitPy);
   fChain->SetBranchAddress("hitPz", hitPz, &b_hitPz);
   fChain->SetBranchAddress("hitVx", hitVx, &b_hitVx);
   fChain->SetBranchAddress("hitVy", hitVy, &b_hitVy);
   fChain->SetBranchAddress("hitVz", hitVz, &b_hitVz);
   fChain->SetBranchAddress("hitVdx", hitVdx, &b_hitVdx);
   fChain->SetBranchAddress("hitVdy", hitVdy, &b_hitVdy);
   fChain->SetBranchAddress("hitVdz", hitVdz, &b_hitVdz);
   fChain->SetBranchAddress("hitP", hitP, &b_hitP);
   fChain->SetBranchAddress("hitE", hitE, &b_hitE);
   fChain->SetBranchAddress("hitM", hitM, &b_hitM);
   fChain->SetBranchAddress("hitEdep", hitEdep, &b_hitEdep);
   Notify();
}

bool collimatortest::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return true;
}

void collimatortest::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t collimatortest::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef collimatortest_cxx
