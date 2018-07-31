#ifndef HISTMAPS_H
#define HISTMAPS_H

#include <iostream>
#include <map>
#include <stdio.h>

#include <TROOT.h>
#include <TH1D.h>
#include <TFile.h>
#include <TRandom3.h>

struct HistInfo
{
    TString Name;
    TString Title;
    Int_t NbinsX;
    Double_t minX;
    Double_t maxX;
    Int_t NbinsY;
    Double_t minY;
    Double_t maxY;
};

class HistMaps
{
    public:
        HistMaps() {};
        ~HistMaps() {fMapHists.clear(); outFile->Close();};
        std::map<TString,TH1D*> GenerateHistos(std::vector<HistInfo> _vHistInfos);
        void                    SetHistograms(std::map<TString,TH1D*> _fMapHists);
        void                    WriteHistograms(TString outName);
        std::map<TString,TH1D*> GetHistograms();
        void                    FillHistograms(Long_t Nev);
    private:
        std::map<TString,TH1D*> fMapHists;
        TFile *outFile;
    ClassDef(HistMaps,1);
};

#endif