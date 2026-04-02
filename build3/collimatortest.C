#define collimatortest_cxx
#include "collimatortest.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <algorithm>
#include <vector>
#include <TPaveText.h>
#include <TLine.h>
#include <TMath.h>

void collimatortest::Loop()
{
    if (fChain == 0) return;

    // Original 4 detectors for old canvases
    const int dets[4] = {1, 8, 9, 14};
    const char* hXYtitles[4] = {
        "hitX vs hitY - Detector 1: Quad 1 Entrance;hitX [cm];hitY [cm]",
        "hitX vs hitY - Detector 8: Quad 4 Exit;hitX [cm];hitY [cm]",
        "hitX vs hitY - Detector 9: Moller Detector;hitX [cm];hitY [cm]",
        "hitX vs hitY - Detector 14: Dipole Entrance;hitX [cm];hitY [cm]"
    };
    const char* hPhcomThcomTitles[4] = {
        "evPhcom vs evThcom - Detector 1: Quad 1 Entrance;evPhcom [deg];evThcom [deg]",
        "evPhcom vs evThcom - Detector 8: Quad 4 Exit;evPhcom [deg];evThcom [deg]",
        "evPhcom vs evThcom - Detector 9: Moller Detector;evPhcom [deg];evThcom [deg]",
        "evPhcom vs evThcom - Detector 14: Dipole Entrance;evPhcom [deg];evThcom [deg]"
    };
    const char* hPh0Th0Titles[4] = {
        "evPh[0] vs evTh[0] (degrees) - Detector 1: Quad 1 Entrance;evPh[0] [deg];evTh[0] [deg]",
        "evPh[0] vs evTh[0] (degrees) - Detector 8: Quad 4 Exit;evPh[0] [deg];evTh[0] [deg]",
        "evPh[0] vs evTh[0] (degrees) - Detector 9: Moller Detector;evPh[0] [deg];evTh[0] [deg]",
        "evPh[0] vs evTh[0] (degrees) - Detector 14: Dipole Entrance;evPh[0] [deg];evTh[0] [deg]"
    };

    // All 15 detectors for new canvas
    const int dets12[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 13, 14, 15, 200, 201, 202};
    const char* hXYtitles12[15] = {
        "hitX vs hitY - Detector 1: VP Quad 1 Entrance;hitX [cm];hitY [cm]",
        "hitX vs hitY - Detector 2: VP Quad 1 Exit;hitX [cm];hitY [cm]",
        "hitX vs hitY - Detector 3: VP Quad 2 Entrance;hitX [cm];hitY [cm]",
        "hitX vs hitY - Detector 4: VP Quad 2 Exit;hitX [cm];hitY [cm]",
        "hitX vs hitY - Detector 5: VP Quad 3 Entrance;hitX [cm];hitY [cm]",
        "hitX vs hitY - Detector 6: VP Quad 3 Exit;hitX [cm];hitY [cm]",
        "hitX vs hitY - Detector 7: VP Quad 4 Entrance;hitX [cm];hitY [cm]",
        "hitX vs hitY - Detector 8: VP Quad 4 Exit;hitX [cm];hitY [cm]",
        "hitX vs hitY - Detector 9: VP Detector (Full Size);hitX [cm];hitY [cm]",
        "hitX vs hitY - Detector 13: VP Detector Box;hitX [cm];hitY [cm]",
        "hitX vs hitY - Detector 14: VP Dipole Entrance;hitX [cm];hitY [cm]",
        "hitX vs hitY - Detector 15: VP Dipole Exit;hitX [cm];hitY [cm]",
        "hitX vs hitY - Detector 200: Upstream GEM tracker (GEM1);hitX [cm];hitY [cm]",
        "hitX vs hitY - Detector 201: Middle GEM tracker (GEM2);hitX [cm];hitY [cm]",
        "hitX vs hitY - Detector 202: Downstream GEM tracker (GEM3);hitX [cm];hitY [cm]"
    };

    // Flux plane detectors (20 detectors in 5x4 grid, left side as columns 0-1, right side as columns 2-3)
    const int detsFlux[20] = {100, 101, 150, 151, 110, 111, 160, 161, 120, 121, 170, 171, 130, 131, 180, 181, 140, 141, 190, 191};
    const char* hXYFluxTitles[20] = {
        "hitX vs hitY - Detector 100: Left Side;hitX [cm];hitY [cm]",
        "hitX vs hitY - Detector 101: Right Side;hitX [cm];hitY [cm]",
        "hitX vs hitY - Detector 150: Left Side;hitX [cm];hitY [cm]",
        "hitX vs hitY - Detector 151: Right Side;hitX [cm];hitY [cm]",
        "hitX vs hitY - Detector 110: Left Side;hitX [cm];hitY [cm]",
        "hitX vs hitY - Detector 111: Right Side;hitX [cm];hitY [cm]",
        "hitX vs hitY - Detector 160: Left Side;hitX [cm];hitY [cm]",
        "hitX vs hitY - Detector 161: Right Side;hitX [cm];hitY [cm]",
        "hitX vs hitY - Detector 120: Left Side;hitX [cm];hitY [cm]",
        "hitX vs hitY - Detector 121: Right Side;hitX [cm];hitY [cm]",
        "hitX vs hitY - Detector 170: Left Side;hitX [cm];hitY [cm]",
        "hitX vs hitY - Detector 171: Right Side;hitX [cm];hitY [cm]",
        "hitX vs hitY - Detector 130: Left Side;hitX [cm];hitY [cm]",
        "hitX vs hitY - Detector 131: Right Side;hitX [cm];hitY [cm]",
        "hitX vs hitY - Detector 180: Left Side;hitX [cm];hitY [cm]",
        "hitX vs hitY - Detector 181: Right Side;hitX [cm];hitY [cm]",
        "hitX vs hitY - Detector 140: Left Side;hitX [cm];hitY [cm]",
        "hitX vs hitY - Detector 141: Right Side;hitX [cm];hitY [cm]",
        "hitX vs hitY - Detector 190: Left Side;hitX [cm];hitY [cm]",
        "hitX vs hitY - Detector 191: Right Side;hitX [cm];hitY [cm]"
    };
    const char* hPhcomThcomFluxTitles[20] = {
        "evPhcom vs evThcom - Detector 100: Left Side;evPhcom [deg];evThcom [deg]",
        "evPhcom vs evThcom - Detector 101: Right Side;evPhcom [deg];evThcom [deg]",
        "evPhcom vs evThcom - Detector 150: Left Side;evPhcom [deg];evThcom [deg]",
        "evPhcom vs evThcom - Detector 151: Right Side;evPhcom [deg];evThcom [deg]",
        "evPhcom vs evThcom - Detector 110: Left Side;evPhcom [deg];evThcom [deg]",
        "evPhcom vs evThcom - Detector 111: Right Side;evPhcom [deg];evThcom [deg]",
        "evPhcom vs evThcom - Detector 160: Left Side;evPhcom [deg];evThcom [deg]",
        "evPhcom vs evThcom - Detector 161: Right Side;evPhcom [deg];evThcom [deg]",
        "evPhcom vs evThcom - Detector 120: Left Side;evPhcom [deg];evThcom [deg]",
        "evPhcom vs evThcom - Detector 121: Right Side;evPhcom [deg];evThcom [deg]",
        "evPhcom vs evThcom - Detector 170: Left Side;evPhcom [deg];evThcom [deg]",
        "evPhcom vs evThcom - Detector 171: Right Side;evPhcom [deg];evThcom [deg]",
        "evPhcom vs evThcom - Detector 130: Left Side;evPhcom [deg];evThcom [deg]",
        "evPhcom vs evThcom - Detector 131: Right Side;evPhcom [deg];evThcom [deg]",
        "evPhcom vs evThcom - Detector 180: Left Side;evPhcom [deg];evThcom [deg]",
        "evPhcom vs evThcom - Detector 181: Right Side;evPhcom [deg];evThcom [deg]",
        "evPhcom vs evThcom - Detector 140: Left Side;evPhcom [deg];evThcom [deg]",
        "evPhcom vs evThcom - Detector 141: Right Side;evPhcom [deg];evThcom [deg]",
        "evPhcom vs evThcom - Detector 190: Left Side;evPhcom [deg];evThcom [deg]",
        "evPhcom vs evThcom - Detector 191: Right Side;evPhcom [deg];evThcom [deg]"
    };
    const char* hPhcomThcomTitles12[15] = {
        "evPhcom vs evThcom - Detector 1: VP Quad 1 Entrance;evPhcom [deg];evThcom [deg]",
        "evPhcom vs evThcom - Detector 2: VP Quad 1 Exit;evPhcom [deg];evThcom [deg]",
        "evPhcom vs evThcom - Detector 3: VP Quad 2 Entrance;evPhcom [deg];evThcom [deg]",
        "evPhcom vs evThcom - Detector 4: VP Quad 2 Exit;evPhcom [deg];evThcom [deg]",
        "evPhcom vs evThcom - Detector 5: VP Quad 3 Entrance;evPhcom [deg];evThcom [deg]",
        "evPhcom vs evThcom - Detector 6: VP Quad 3 Exit;evPhcom [deg];evThcom [deg]",
        "evPhcom vs evThcom - Detector 7: VP Quad 4 Entrance;evPhcom [deg];evThcom [deg]",
        "evPhcom vs evThcom - Detector 8: VP Quad 4 Exit;evPhcom [deg];evThcom [deg]",
        "evPhcom vs evThcom - Detector 9: VP Detector (Full Size);evPhcom [deg];evThcom [deg]",
        "evPhcom vs evThcom - Detector 13: VP Detector Box;evPhcom [deg];evThcom [deg]",
        "evPhcom vs evThcom - Detector 14: VP Dipole Entrance;evPhcom [deg];evThcom [deg]",
        "evPhcom vs evThcom - Detector 15: VP Dipole Exit;evPhcom [deg];evThcom [deg]",
        "evPhcom vs evThcom - Detector 200: Upstream GEM tracker (GEM1);evPhcom [deg];evThcom [deg]",
        "evPhcom vs evThcom - Detector 201: Middle GEM tracker (GEM2);evPhcom [deg];evThcom [deg]",
        "evPhcom vs evThcom - Detector 202: Downstream GEM tracker (GEM3);evPhcom [deg];evThcom [deg]"
    };
    const char* hPh0Th0Titles12[15] = {
        "evPh[0] vs evTh[0] (degrees) - Detector 1: VP Quad 1 Entrance;evPh[0] [deg];evTh[0] [deg]",
        "evPh[0] vs evTh[0] (degrees) - Detector 2: VP Quad 1 Exit;evPh[0] [deg];evTh[0] [deg]",
        "evPh[0] vs evTh[0] (degrees) - Detector 3: VP Quad 2 Entrance;evPh[0] [deg];evTh[0] [deg]",
        "evPh[0] vs evTh[0] (degrees) - Detector 4: VP Quad 2 Exit;evPh[0] [deg];evTh[0] [deg]",
        "evPh[0] vs evTh[0] (degrees) - Detector 5: VP Quad 3 Entrance;evPh[0] [deg];evTh[0] [deg]",
        "evPh[0] vs evTh[0] (degrees) - Detector 6: VP Quad 3 Exit;evPh[0] [deg];evTh[0] [deg]",
        "evPh[0] vs evTh[0] (degrees) - Detector 7: VP Quad 4 Entrance;evPh[0] [deg];evTh[0] [deg]",
        "evPh[0] vs evTh[0] (degrees) - Detector 8: VP Quad 4 Exit;evPh[0] [deg];evTh[0] [deg]",
        "evPh[0] vs evTh[0] (degrees) - Detector 9: VP Detector (Full Size);evPh[0] [deg];evTh[0] [deg]",
        "evPh[0] vs evTh[0] (degrees) - Detector 13: VP Detector Box;evPh[0] [deg];evTh[0] [deg]",
        "evPh[0] vs evTh[0] (degrees) - Detector 14: VP Dipole Entrance;evPh[0] [deg];evTh[0] [deg]",
        "evPh[0] vs evTh[0] (degrees) - Detector 15: VP Dipole Exit;evPh[0] [deg];evTh[0] [deg]",
        "evPh[0] vs evTh[0] (degrees) - Detector 200: Upstream GEM tracker (GEM1);evPh[0] [deg];evTh[0] [deg]",
        "evPh[0] vs evTh[0] (degrees) - Detector 201: Middle GEM tracker (GEM2);evPh[0] [deg];evTh[0] [deg]",
        "evPh[0] vs evTh[0] (degrees) - Detector 202: Downstream GEM tracker (GEM3);evPh[0] [deg];evTh[0] [deg]"
    };
    const char* hETitles12[15] = {
        "Hit Energy - Detector 1: VP Quad 1 Entrance;hitE [GeV];Counts",
        "Hit Energy - Detector 2: VP Quad 1 Exit;hitE [GeV];Counts",
        "Hit Energy - Detector 3: VP Quad 2 Entrance;hitE [GeV];Counts",
        "Hit Energy - Detector 4: VP Quad 2 Exit;hitE [GeV];Counts",
        "Hit Energy - Detector 5: VP Quad 3 Entrance;hitE [GeV];Counts",
        "Hit Energy - Detector 6: VP Quad 3 Exit;hitE [GeV];Counts",
        "Hit Energy - Detector 7: VP Quad 4 Entrance;hitE [GeV];Counts",
        "Hit Energy - Detector 8: VP Quad 4 Exit;hitE [GeV];Counts",
        "Hit Energy - Detector 9: VP Detector (Full Size);hitE [GeV];Counts",
        "Hit Energy - Detector 13: VP Detector Box;hitE [GeV];Counts",
        "Hit Energy - Detector 14: VP Dipole Entrance;hitE [GeV];Counts",
        "Hit Energy - Detector 15: VP Dipole Exit;hitE [GeV];Counts",
        "Hit Energy - Detector 200: Upstream GEM tracker (GEM1);hitE [GeV];Counts",
        "Hit Energy - Detector 201: Middle GEM tracker (GEM2);hitE [GeV];Counts",
        "Hit Energy - Detector 202: Downstream GEM tracker (GEM3);hitE [GeV];Counts"
    };

    // For dynamic axis limits
    std::vector<float> minX(4, 1e9), maxX(4, -1e9), minY(4, 1e9), maxY(4, -1e9);
    std::vector<float> minPhcom(4, 1e9), maxPhcom(4, -1e9), minThcom(4, 1e9), maxThcom(4, -1e9);
    std::vector<float> minPh0(4, 1e9), maxPh0(4, -1e9), minTh0(4, 1e9), maxTh0(4, -1e9);
    
    // For dynamic axis limits - all 15 detectors
    std::vector<float> minX12(15, 1e9), maxX12(15, -1e9), minY12(15, 1e9), maxY12(15, -1e9);
    std::vector<float> minPhcom12(15, 1e9), maxPhcom12(15, -1e9), minThcom12(15, 1e9), maxThcom12(15, -1e9);
    std::vector<float> minPh012(15, 1e9), maxPh012(15, -1e9), minTh012(15, 1e9), maxTh012(15, -1e9);
    std::vector<float> minE12(15, 1e9), maxE12(15, -1e9);

    // For dynamic axis limits - flux plane detectors (20 detectors)
    std::vector<float> minXFlux(20, 1e9), maxXFlux(20, -1e9), minYFlux(20, 1e9), maxYFlux(20, -1e9);
    std::vector<float> minPhcomFlux(20, 1e9), maxPhcomFlux(20, -1e9), minThcomFlux(20, 1e9), maxThcomFlux(20, -1e9);
    std::vector<float> minPh0Flux(20, 1e9), maxPh0Flux(20, -1e9), minTh0Flux(20, 1e9), maxTh0Flux(20, -1e9);

    // First pass: find min/max for each variable per detector
    Long64_t nentries = fChain->GetEntriesFast();
    for (Long64_t jentry = 0; jentry < nentries; ++jentry) {
        Long64_t ientry = LoadTree(jentry);
        if (ientry < 0) break;
        fChain->GetEntry(jentry);

        bool hasHit[4] = {false, false, false, false};
        bool hasHit12[15] = {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false};
        bool hasHitFlux[20] = {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false};

        for (Int_t i = 0; i < hitN; ++i) {
            // Track original 4 detectors
            for (int d = 0; d < 4; ++d) {
                if (hitDet[i] == dets[d]) {
                    float x = hitX[i] * 100.;
                    float y = hitY[i] * 100.;
                    minX[d] = std::min(minX[d], x);
                    maxX[d] = std::max(maxX[d], x);
                    minY[d] = std::min(minY[d], y);
                    maxY[d] = std::max(maxY[d], y);
                    hasHit[d] = true;
                }
            }
            // Track all 15 detectors
            for (int d = 0; d < 15; ++d) {
                if (hitDet[i] == dets12[d]) {
                    float x = hitX[i] * 100.;
                    float y = hitY[i] * 100.;
                    minX12[d] = std::min(minX12[d], x);
                    maxX12[d] = std::max(maxX12[d], x);
                    minY12[d] = std::min(minY12[d], y);
                    maxY12[d] = std::max(maxY12[d], y);
                    minE12[d] = std::min(minE12[d], float(hitE[i]));
                    maxE12[d] = std::max(maxE12[d], float(hitE[i]));
                    hasHit12[d] = true;
                }
            }
            // Track flux plane detectors
            for (int d = 0; d < 20; ++d) {
                if (hitDet[i] == detsFlux[d]) {
                    float x = hitX[i] * 100.;
                    float y = hitY[i] * 100.;
                    minXFlux[d] = std::min(minXFlux[d], x);
                    maxXFlux[d] = std::max(maxXFlux[d], x);
                    minYFlux[d] = std::min(minYFlux[d], y);
                    maxYFlux[d] = std::max(maxYFlux[d], y);
                    hasHitFlux[d] = true;
                }
            }
        }
        for (int d = 0; d < 4; ++d) {
            if (hasHit[d]) {
                minPhcom[d] = std::min(minPhcom[d], float(evPhcom));
                maxPhcom[d] = std::max(maxPhcom[d], float(evPhcom));
                minThcom[d] = std::min(minThcom[d], float(evThcom));
                maxThcom[d] = std::max(maxThcom[d], float(evThcom));
                float ph0deg = evPh[0] * 180.0 / TMath::Pi();
                float th0deg = evTh[0] * 180.0 / TMath::Pi();
                minPh0[d] = std::min(minPh0[d], ph0deg);
                maxPh0[d] = std::max(maxPh0[d], ph0deg);
                minTh0[d] = std::min(minTh0[d], th0deg);
                maxTh0[d] = std::max(maxTh0[d], th0deg);
            }
        }
        for (int d = 0; d < 15; ++d) {
            if (hasHit12[d]) {
                minPhcom12[d] = std::min(minPhcom12[d], float(evPhcom));
                maxPhcom12[d] = std::max(maxPhcom12[d], float(evPhcom));
                minThcom12[d] = std::min(minThcom12[d], float(evThcom));
                maxThcom12[d] = std::max(maxThcom12[d], float(evThcom));
                float ph0deg = evPh[0] * 180.0 / TMath::Pi();
                float th0deg = evTh[0] * 180.0 / TMath::Pi();
                minPh012[d] = std::min(minPh012[d], ph0deg);
                maxPh012[d] = std::max(maxPh012[d], ph0deg);
                minTh012[d] = std::min(minTh012[d], th0deg);
                maxTh012[d] = std::max(maxTh012[d], th0deg);
            }
        }
        for (int d = 0; d < 20; ++d) {
            if (hasHitFlux[d]) {
                minPhcomFlux[d] = std::min(minPhcomFlux[d], float(evPhcom));
                maxPhcomFlux[d] = std::max(maxPhcomFlux[d], float(evPhcom));
                minThcomFlux[d] = std::min(minThcomFlux[d], float(evThcom));
                maxThcomFlux[d] = std::max(maxThcomFlux[d], float(evThcom));
                float ph0deg = evPh[0] * 180.0 / TMath::Pi();
                float th0deg = evTh[0] * 180.0 / TMath::Pi();
                minPh0Flux[d] = std::min(minPh0Flux[d], ph0deg);
                maxPh0Flux[d] = std::max(maxPh0Flux[d], ph0deg);
                minTh0Flux[d] = std::min(minTh0Flux[d], th0deg);
                maxTh0Flux[d] = std::max(maxTh0Flux[d], th0deg);
            }
        }
    }

    // Add a small margin to axis limits
    auto margin = [](float minv, float maxv) {
        float range = maxv - minv;
        if (range == 0) range = 1.0; // avoid zero range
        return std::make_pair(minv - 0.05 * range, maxv + 0.05 * range);
    };

    // Create histograms with dynamic ranges - original 4
    TH2F* hXY[4];
    TH2F* hPhcomThcom[4];
    TH2F* hPh0Th0[4];
    
    // Create histograms with dynamic ranges - all 15
    TH2F* hXY12[15];
    TH2F* hPhcomThcom12[15];
    TH2F* hPh0Th012[15];
    TH1F* hE12[15];
    
    // Create histograms with dynamic ranges - flux plane detectors (20 detectors)
    TH2F* hXYFlux[20];
    TH2F* hPhcomThcomFlux[20];
    TH2F* hPh0Th0Flux[20];
    
    for (int d = 0; d < 4; ++d) {
        auto xlim = margin(minX[d], maxX[d]);
        auto ylim = margin(minY[d], maxY[d]);
        // For detector 9, set lower limit to -36 if needed
        if (dets[d] == 9) {
            xlim.first = std::max(xlim.first, static_cast<double>(-36));
            ylim.first = std::max(ylim.first, static_cast<double>(-36));
        }
        hXY[d] = new TH2F(Form("hXY_%d", dets[d]), hXYtitles[d], 500, xlim.first, xlim.second, 500, ylim.first, ylim.second);

        auto phcomlim = margin(minPhcom[d], maxPhcom[d]);
        auto thcomlim = margin(minThcom[d], maxThcom[d]);
        hPhcomThcom[d] = new TH2F(Form("hPhcomThcom_%d", dets[d]), hPhcomThcomTitles[d], 500, phcomlim.first, phcomlim.second, 500, thcomlim.first, thcomlim.second);

        auto ph0lim = margin(minPh0[d], maxPh0[d]);
        auto th0lim = margin(minTh0[d], maxTh0[d]);
        hPh0Th0[d] = new TH2F(Form("hPh0Th0_%d", dets[d]), hPh0Th0Titles[d], 500, ph0lim.first, ph0lim.second, 500, 0, 1.2);
    }
    
    for (int d = 0; d < 15; ++d) {
        // Fixed X limits: -6 to 6 for all plots
        double xlim_min = -6.0, xlim_max = 6.0;
        // Fixed Y limits: -4 to 4 for detectors 1-8 and 14, keep dynamic for others
        double ylim_min, ylim_max;
        if (dets12[d] == 1 || dets12[d] == 2 || dets12[d] == 3 || dets12[d] == 4 || 
            dets12[d] == 5 || dets12[d] == 6 || dets12[d] == 7 || dets12[d] == 8 || dets12[d] == 14) {
            ylim_min = -4.0;
            ylim_max = 4.0;
        } else {
            auto ylim = margin(minY12[d], maxY12[d]);
            ylim_min = ylim.first;
            ylim_max = ylim.second;
        }
        hXY12[d] = new TH2F(Form("hXY12_%d", dets12[d]), hXYtitles12[d], 500, xlim_min, xlim_max, 500, ylim_min, ylim_max);

        auto phcomlim12 = margin(minPhcom12[d], maxPhcom12[d]);
        auto thcomlim12 = margin(minThcom12[d], maxThcom12[d]);
        hPhcomThcom12[d] = new TH2F(Form("hPhcomThcom12_%d", dets12[d]), hPhcomThcomTitles12[d], 500, phcomlim12.first, phcomlim12.second, 500, thcomlim12.first, thcomlim12.second);

        auto ph0lim12 = margin(minPh012[d], maxPh012[d]);
        hPh0Th012[d] = new TH2F(Form("hPh0Th012_%d", dets12[d]), hPh0Th0Titles12[d], 500, ph0lim12.first, ph0lim12.second, 500, 0.0, 1.5);
        
        auto elim12 = margin(minE12[d], maxE12[d]);
        hE12[d] = new TH1F(Form("hE12_%d", dets12[d]), hETitles12[d], 100, elim12.first, elim12.second);
    }

    // Initialize flux plane histograms
    for (int d = 0; d < 20; ++d) {
        // Set fixed Y limits for all detectors
        double ylim_min = -16.0;
        double ylim_max = 1.0;
        
        // Set X limits based on detector side (left ends with 0, right ends with 1)
        double xlim_min, xlim_max;
        if (detsFlux[d] % 10 == 0) {
            // Left side (detector number ends with 0)
            xlim_min = -6.5;
            xlim_max = -2.5;
        } else {
            // Right side (detector number ends with 1)
            xlim_min = 2.5;
            xlim_max = 6.5;
        }
        
        hXYFlux[d] = new TH2F(Form("hXYFlux_%d", detsFlux[d]), hXYFluxTitles[d], 500, xlim_min, xlim_max, 500, ylim_min, ylim_max);

        auto phcomlim = margin(minPhcomFlux[d], maxPhcomFlux[d]);
        auto thcomlim = margin(minThcomFlux[d], maxThcomFlux[d]);
        hPhcomThcomFlux[d] = new TH2F(Form("hPhcomThcomFlux_%d", detsFlux[d]), hPhcomThcomFluxTitles[d], 500, phcomlim.first, phcomlim.second, 500, thcomlim.first, thcomlim.second);

        auto ph0lim = margin(minPh0Flux[d], maxPh0Flux[d]);
        auto th0lim = margin(minTh0Flux[d], maxTh0Flux[d]);
        hPh0Th0Flux[d] = new TH2F(Form("hPh0Th0Flux_%d", detsFlux[d]), Form("evPh[0] vs evTh[0] - Detector %d;evPh[0] [deg];evTh[0] [deg]", detsFlux[d]), 500, ph0lim.first, ph0lim.second, 500, th0lim.first, th0lim.second);
    }

    // Second pass: fill histograms
    for (Long64_t jentry = 0; jentry < nentries; ++jentry) {
        Long64_t ientry = LoadTree(jentry);
        if (ientry < 0) break;
        fChain->GetEntry(jentry);

        bool hasHit[4] = {false, false, false, false};
        bool hasHit12[15] = {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false};
        bool hasHitFlux[20] = {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false};

        for (Int_t i = 0; i < hitN; ++i) {
            // Fill original 4
            for (int d = 0; d < 4; ++d) {
                if (hitDet[i] == dets[d]) {
                    hXY[d]->Fill(hitX[i] * 100., hitY[i] * 100.);
                    hasHit[d] = true;
                }
            }
            // Fill all 15
            for (int d = 0; d < 15; ++d) {
                if (hitDet[i] == dets12[d]) {
                    hXY12[d]->Fill(hitX[i] * 100., hitY[i] * 100.);
                    hE12[d]->Fill(hitE[i]);
                    hasHit12[d] = true;
                }
            }
            // Fill flux plane detectors
            for (int d = 0; d < 20; ++d) {
                if (hitDet[i] == detsFlux[d]) {
                    hXYFlux[d]->Fill(hitX[i] * 100., hitY[i] * 100.);
                    hasHitFlux[d] = true;
                }
            }
        }
        for (int d = 0; d < 4; ++d) {
            if (hasHit[d]) {
                hPhcomThcom[d]->Fill(evPhcom, evThcom);
                float ph0deg = evPh[0] * 180.0 / TMath::Pi();
                float th0deg = evTh[0] * 180.0 / TMath::Pi();
                hPh0Th0[d]->Fill(ph0deg, th0deg);
            }
        }
        for (int d = 0; d < 15; ++d) {
            if (hasHit12[d]) {
                hPhcomThcom12[d]->Fill(evPhcom, evThcom);
                float ph0deg = evPh[0] * 180.0 / TMath::Pi();
                float th0deg = evTh[0] * 180.0 / TMath::Pi();
                hPh0Th012[d]->Fill(ph0deg, th0deg);
            }
        }
        for (int d = 0; d < 20; ++d) {
            if (hasHitFlux[d]) {
                hPhcomThcomFlux[d]->Fill(evPhcom, evThcom);
                float ph0deg = evPh[0] * 180.0 / TMath::Pi();
                float th0deg = evTh[0] * 180.0 / TMath::Pi();
                hPh0Th0Flux[d]->Fill(ph0deg, th0deg);
            }
        }
    }

    

   // Canvas 0 (NEW): hitX vs hitY for all 15 detectors in 5x3 grid
   TCanvas* c0 = new TCanvas("c0", "Canvas 0: hitX vs hitY (All Detectors)", 1600, 2000);
   c0->SetTopMargin(0.08);
   c0->SetBottomMargin(0.08);
   
   // Create histogram area (leave 5% at top for title)
   TPad *histPad0 = new TPad("histPad0", "histPad0", 0, 0, 1, 0.95);
   histPad0->Draw();
   histPad0->cd();
   histPad0->Divide(3, 5);
   
   // Create title area
   c0->cd();
   TPaveText *pave0 = new TPaveText(0.1, 0.96, 0.9, 0.99, "NDC");
   pave0->AddText("#phi collimator = 0.2cm, -40 < #phi_{cm} < 40");
   pave0->SetFillColor(0);
   pave0->SetBorderSize(0);
   pave0->SetTextSize(0.03);
   pave0->Draw();
   
   // Add separator line
   TLine *line0 = new TLine(0.1, 0.955, 0.9, 0.955);
   line0->SetNDC();
   line0->Draw();
   
   // Draw histograms in the histogram area
   for (int d = 0; d < 15; ++d) {
      histPad0->cd(d + 1);
      gPad->SetRightMargin(0.18);
      gPad->SetLeftMargin(0.13);
      gPad->SetGrid(1, 1);
      hXY12[d]->Draw("COLZ");
   }
   c0->Update();
   //c0->SaveAs("canvas0_hitX_vs_hitY_all_detectors.pdf");
   c0->SaveAs("canvas0_hitX_vs_hitY_all_detectors.png", "PNG");

   // Canvas 4 (NEW): evPhcom vs evThcom for all 15 detectors in 5x3 grid
   TCanvas* c4 = new TCanvas("c4", "Canvas 4: evPhcom vs evThcom (All Detectors)", 1600, 2000);
   c4->SetTopMargin(0.08);
   c4->SetBottomMargin(0.08);
   
   // Create histogram area (leave 5% at top for title)
   TPad *histPad4 = new TPad("histPad4", "histPad4", 0, 0, 1, 0.95);
   histPad4->Draw();
   histPad4->cd();
   histPad4->Divide(3, 5);
   
   // Create title area
   c4->cd();
   TPaveText *pave4 = new TPaveText(0.1, 0.96, 0.9, 0.99, "NDC");
   pave4->AddText("#phi collimator = 0.2cm, -40 < #phi_{cm} < 40");
   pave4->SetFillColor(0);
   pave4->SetBorderSize(0);
   pave4->SetTextSize(0.03);
   pave4->Draw();
   
   // Add separator line
   TLine *line4 = new TLine(0.1, 0.955, 0.9, 0.955);
   line4->SetNDC();
   line4->Draw();
   
   // Draw histograms in the histogram area
   for (int d = 0; d < 15; ++d) {
      histPad4->cd(d + 1);
      gPad->SetRightMargin(0.18);
      gPad->SetLeftMargin(0.13);
      gPad->SetGrid(1, 1);
      hPhcomThcom12[d]->Draw("COLZ");
   }
   c4->Update();
   //c4->SaveAs("canvas4_evPhcom_vs_evThcom_all_detectors.pdf");
   c4->SaveAs("canvas4_evPhcom_vs_evThcom_all_detectors.png", "PNG");

   // Canvas 5 (NEW): evPh[0] vs evTh[0] for all 15 detectors in 5x3 grid
   TCanvas* c5 = new TCanvas("c5", "Canvas 5: evPh[0] vs evTh[0] (All Detectors)", 1600, 2000);
   c5->SetTopMargin(0.08);
   c5->SetBottomMargin(0.08);
   
   // Create histogram area (leave 5% at top for title)
   TPad *histPad5 = new TPad("histPad5", "histPad5", 0, 0, 1, 0.95);
   histPad5->Draw();
   histPad5->cd();
   histPad5->Divide(3, 5);
   
   // Create title area
   c5->cd();
   TPaveText *pave5 = new TPaveText(0.1, 0.96, 0.9, 0.99, "NDC");
   pave5->AddText("#phi collimator = 0.2cm, -40 < #phi_{cm} < 40");
   pave5->SetFillColor(0);
   pave5->SetBorderSize(0);
   pave5->SetTextSize(0.03);
   pave5->Draw();
   
   // Add separator line
   TLine *line5 = new TLine(0.1, 0.955, 0.9, 0.955);
   line5->SetNDC();
   line5->Draw();
   
   // Draw histograms in the histogram area
   for (int d = 0; d < 15; ++d) {
      histPad5->cd(d + 1);
      gPad->SetRightMargin(0.18);
      gPad->SetLeftMargin(0.13);
      gPad->SetGrid(1, 1);
      hPh0Th012[d]->Draw("COLZ");
   }
   c5->Update();
   //c5->SaveAs("canvas5_evPh0_vs_evTh0_all_detectors.pdf");
   c5->SaveAs("canvas5_evPh0_vs_evTh0_all_detectors.png", "PNG");

   // Canvas 6 (NEW): hitE (Hit Energy) for all 15 detectors in 5x3 grid
   TCanvas* c6 = new TCanvas("c6", "Canvas 6: Hit Energy (All Detectors)", 1600, 2000);
   c6->SetTopMargin(0.08);
   c6->SetBottomMargin(0.08);
   
   // Create histogram area (leave 5% at top for title)
   TPad *histPad6 = new TPad("histPad6", "histPad6", 0, 0, 1, 0.95);
   histPad6->Draw();
   histPad6->cd();
   histPad6->Divide(3, 5);
   
   // Create title area
   c6->cd();
   TPaveText *pave6 = new TPaveText(0.1, 0.96, 0.9, 0.99, "NDC");
   pave6->AddText("#phi collimator = 0.2cm, -40 < #phi_{cm} < 40");
   pave6->SetFillColor(0);
   pave6->SetBorderSize(0);
   pave6->SetTextSize(0.03);
   pave6->Draw();
   
   // Add separator line
   TLine *line6 = new TLine(0.1, 0.955, 0.9, 0.955);
   line6->SetNDC();
   line6->Draw();
   
   // Draw histograms in the histogram area
   for (int d = 0; d < 15; ++d) {
      histPad6->cd(d + 1);
      gPad->SetRightMargin(0.15);
      gPad->SetLeftMargin(0.12);
      // gPad->SetLogy();
      gPad->SetGrid(1, 1);
      hE12[d]->Draw();
   }
   c6->Update();
   //c6->SaveAs("canvas6_hitE_all_detectors.pdf");
   c6->SaveAs("canvas6_hitE_all_detectors.png", "PNG");

   // Canvas 7 (NEW): hitX vs hitY for flux plane detectors in 5x4 grid
   TCanvas* c7 = new TCanvas("c7", "Canvas 7: hitX vs hitY (Flux Planes)", 1800, 2000);
   c7->SetTopMargin(0.08);
   c7->SetBottomMargin(0.08);
   
   // Create histogram area (leave 5% at top for title)
   TPad *histPad7 = new TPad("histPad7", "histPad7", 0, 0, 1, 0.95);
   histPad7->Draw();
   histPad7->cd();
   histPad7->Divide(4, 5);
   
   // Create title area
   c7->cd();
   TPaveText *pave7 = new TPaveText(0.1, 0.96, 0.9, 0.99, "NDC");
   pave7->AddText("#phi collimator = 0.2cm, -40 < #phi_{cm} < 40");
   pave7->SetFillColor(0);
   pave7->SetBorderSize(0);
   pave7->SetTextSize(0.03);
   pave7->Draw();
   
   // Add separator line in the middle of canvas
   TLine *line7 = new TLine(0.1, 0.955, 0.9, 0.955);
   line7->SetNDC();
   line7->Draw();
   
   // Add vertical separator line between columns 2 and 3
   TLine *vertLine7 = new TLine(0.5, 0, 0.5, 0.95);
   vertLine7->SetNDC();
   vertLine7->Draw();
   
   // Draw histograms in the histogram area (5x4 grid with separator at column 2)
   for (int d = 0; d < 20; ++d) {
      // Calculate position: row and column within 5x4 grid
      int row = d / 4;      // 0-4
      int col = d % 4;      // 0-3
      int padNum = row * 4 + col + 1;
      
      histPad7->cd(padNum);
      gPad->SetRightMargin(0.18);
      gPad->SetLeftMargin(0.13);
      gPad->SetGrid(1, 1);
      hXYFlux[d]->Draw("COLZ");
   }
   c7->Update();
   c7->SaveAs("canvas7_hitX_vs_hitY_flux_planes.png", "PNG");

   // Canvas 8 (NEW): evPh[0] vs evTh[0] for flux plane detectors in 5x4 grid
   TCanvas* c8 = new TCanvas("c8", "Canvas 8: evPh[0] vs evTh[0] (Flux Planes)", 1800, 2000);
   c8->SetTopMargin(0.08);
   c8->SetBottomMargin(0.08);
   
   // Create histogram area (leave 5% at top for title)
   TPad *histPad8 = new TPad("histPad8", "histPad8", 0, 0, 1, 0.95);
   histPad8->Draw();
   histPad8->cd();
   histPad8->Divide(4, 5);
   
   // Create title area
   c8->cd();
   TPaveText *pave8 = new TPaveText(0.1, 0.96, 0.9, 0.99, "NDC");
   pave8->AddText("#phi collimator = 0.2cm, -40 < #phi_{cm} < 40");
   pave8->SetFillColor(0);
   pave8->SetBorderSize(0);
   pave8->SetTextSize(0.03);
   pave8->Draw();
   
   // Add separator line in the middle of canvas
   TLine *line8 = new TLine(0.1, 0.955, 0.9, 0.955);
   line8->SetNDC();
   line8->Draw();
   
   // Add vertical separator line between columns 2 and 3
   TLine *vertLine8 = new TLine(0.5, 0, 0.5, 0.95);
   vertLine8->SetNDC();
   vertLine8->Draw();
   
   // Draw histograms in the histogram area (5x4 grid with separator at column 2)
   for (int d = 0; d < 20; ++d) {
      // Calculate position: row and column within 5x4 grid
      int row = d / 4;      // 0-4
      int col = d % 4;      // 0-3
      int padNum = row * 4 + col + 1;
      
      histPad8->cd(padNum);
      gPad->SetRightMargin(0.18);
      gPad->SetLeftMargin(0.13);
      gPad->SetGrid(1, 1);
      hPh0Th0Flux[d]->Draw("COLZ");
   }
   c8->Update();
   c8->SaveAs("canvas8_evPh0_vs_evTh0_flux_planes.png", "PNG");

   // COMMENTED OUT - Focus on 15-detector plots
   /*
   TCanvas* c1 = new TCanvas("c1", "Canvas 1: hitX vs hitY", 1200, 1400);
   c1->SetTopMargin(0.08);
   c1->SetBottomMargin(0.08);
   
   // Create histogram area (leave 5% at top for title)
   TPad *histPad1 = new TPad("histPad1", "histPad1", 0, 0, 1, 0.95);
   histPad1->Draw();
   histPad1->cd();
   histPad1->Divide(2, 2);
   
   // Create title area
   c1->cd();
   TPaveText *pave1 = new TPaveText(0.1, 0.96, 0.9, 0.99, "NDC");
   pave1->AddText("#phi collimator = 0.2cm, -40 < #phi_{cm} < 40");
   pave1->SetFillColor(0);
   pave1->SetBorderSize(0);
   pave1->SetTextSize(0.036);
   pave1->Draw();
   
   // Draw histograms in the histogram area
   for (int d = 0; d < 4; ++d) {
      histPad1->cd(d + 1);
      gPad->SetRightMargin(0.18);
      gPad->SetLeftMargin(0.13);
      gPad->SetGrid(1, 1);
      hXY[d]->SetTitle(hXYtitles[d]);
      hXY[d]->Draw("COLZ");
   }
   c1->Update();
   c1->SaveAs("canvas1_hitX_vs_hitY.pdf");
   c1->SaveAs("canvas1_hitX_vs_hitY.png", "PNG");
   */

    // COMMENTED OUT - Focus on 15-detector plots
    /*
    // Canvas 2: evPhcom vs evThcom
    TCanvas* c2 = new TCanvas("c2", "Canvas 2: evPhcom vs evThcom", 1200, 1300);
    c2->SetTopMargin(0.08);
    c2->SetBottomMargin(0.08);
    
    // Create histogram area (leave 5% at top for title)
    TPad *histPad2 = new TPad("histPad2", "histPad2", 0, 0, 1, 0.95);
    histPad2->Draw();
    histPad2->cd();
    histPad2->Divide(2, 2);
    
    // Create title area
    c2->cd();
    TPaveText *pave2 = new TPaveText(0.1, 0.96, 0.9, 0.99, "NDC");
    pave2->AddText("#phi collimator = 0.2cm, -40 < #phi_{cm} < 40");
    pave2->SetFillColor(0);
    pave2->SetBorderSize(0);
    pave2->SetTextSize(0.036);
    pave2->Draw();
    
    // Draw histograms in the histogram area
    for (int d = 0; d < 4; ++d) {
        histPad2->cd(d + 1);
        gPad->SetRightMargin(0.18);
        gPad->SetLeftMargin(0.13);
        gPad->SetGrid(1, 1);
        hPhcomThcom[d]->Draw("COLZ");
    }
    c2->Update();
    c2->SaveAs("canvas2_evPhcom_vs_evThcom.pdf");
    c2->SaveAs("canvas2_evPhcom_vs_evThcom.png", "PNG");
    */

    // COMMENTED OUT - Focus on 15-detector plots
    /*
    // Canvas 3: evPh[0] vs evTh[0] (degrees)
    TCanvas* c3 = new TCanvas("c3", "Canvas 3: evPh[0] vs evTh[0]", 1200, 1300);
    c3->SetTopMargin(0.08);
    c3->SetBottomMargin(0.08);
    
    // Create histogram area (leave 5% at top for title)
    TPad *histPad3 = new TPad("histPad3", "histPad3", 0, 0, 1, 0.95);
    histPad3->Draw();
    histPad3->cd();
    histPad3->Divide(2, 2);
    
    // Create title area
    c3->cd();
    TPaveText *pave3 = new TPaveText(0.1, 0.96, 0.9, 0.99, "NDC");
    pave3->AddText("#phi collimator = 0.2cm, -40 < #phi_{cm} < 40");
    pave3->SetFillColor(0);
    pave3->SetBorderSize(0);
    pave3->SetTextSize(0.036);
    pave3->Draw();
    
    // Draw histograms in the histogram area
    for (int d = 0; d < 4; ++d) {
        histPad3->cd(d + 1);
        gPad->SetRightMargin(0.18);
        gPad->SetLeftMargin(0.13);
        gPad->SetGrid(1, 1);
        hPh0Th0[d]->Draw("COLZ");
    }
    c3->Update();
    c3->SaveAs("canvas3_evPh0_vs_evTh0.pdf");
    c3->SaveAs("canvas3_evPh0_vs_evTh0.png", "PNG");
    */
}