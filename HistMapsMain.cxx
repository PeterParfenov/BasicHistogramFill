#include "HistMaps.h"

void GenerateHistos();

const Int_t     NumberOfHists = 3;

const HistInfo  ListOfHists [] = {{.Name = "histGaus1", .Title = "Title for histGaus 1", .NbinsX = 100, .minX = -5., .maxX = 5., .NbinsY = 0, .minY = 0.,  .maxY = 0.},
                                  {.Name = "histGaus2", .Title = "Title for histGaus 2", .NbinsX = 200, .minX = -10., .maxX = 10., .NbinsY = 0, .minY = 0.,  .maxY = 0.},
                                  {.Name = "histGaus3", .Title = "Title for histGaus 3", .NbinsX = 300, .minX = -15., .maxX = 15., .NbinsY = 0, .minY = 0.,  .maxY = 0.}};

int main()
{
    std::vector<HistInfo> vHistInfos;

    for (Int_t i=0; i<NumberOfHists; i++){
        vHistInfos.push_back(ListOfHists[i]);
    }

    HistMaps *mHists = new HistMaps();
    std::map<TString,TH1D*> TotalMap = mHists -> GenerateHistos(vHistInfos);
    mHists -> SetHistograms(TotalMap);
    mHists -> FillHistograms(100000);
    mHists -> WriteHistograms("./output.root");

    return 0;
}