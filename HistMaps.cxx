#ifndef HISTMAPS_CXX
#define HISTMAPS_CXX

#include "HistMaps.h"

std::map<TString,TH1D*> HistMaps::GenerateHistos(std::vector<HistInfo> _vHistInfos)
{
    printf("-I- HistMaps: Generate histograms.\n");
    std::map<TString,TH1D*> mapHists;

    for (Int_t i=0; i<_vHistInfos.size(); i++)
    {
        printf("-I- HistMaps: Adding histogram '%s'.\n",_vHistInfos.at(i).Name.Data());
        mapHists[_vHistInfos.at(i).Name] = new TH1D(_vHistInfos.at(i).Name,
                                                       _vHistInfos.at(i).Title,
                                                       _vHistInfos.at(i).NbinsX,
                                                       _vHistInfos.at(i).minX,
                                                       _vHistInfos.at(i).maxX);
    }

    return mapHists;
}

std::map<TString,TH1D*> HistMaps::GetHistograms()
{
    return fMapHists;
}

void HistMaps::FillHistograms(Long_t Nev)
{
    printf("-I- HistMaps: Filling histograms.\n");
    std::map<TString,TH1D*>::iterator it;  
    for (it = fMapHists.begin(); it != fMapHists.end(); it++)
    {
        it->second -> FillRandom("gaus",Nev);
    }
}

void HistMaps::SetHistograms(std::map<TString,TH1D*> _fMapHists)
{
    fMapHists = _fMapHists;
}

void HistMaps::WriteHistograms(TString outName)
{
    printf("-I- HistMaps: Writing histograms.\n");
    outFile = new TFile(outName.Data(),"recreate");
    outFile -> cd();
    std::map<TString,TH1D*>::iterator it;
    for (it = fMapHists.begin(); it != fMapHists.end(); it++)
    {
        it->second -> Write();
    }
    outFile -> Close();
}

#endif