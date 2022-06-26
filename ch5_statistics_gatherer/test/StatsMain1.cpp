//
//  StatsMain1.cpp
//  ch5_statistics_gatherer
//
//  Created by cheerzzh on 18/6/14.
//  Copyright (c) 2014年 Jared Zhou. All rights reserved.
//

/*
 uses source files
 MCStatistics.cpp,
 Parameters.cpp,
 PayOff3.cpp,
 PayOffBridge.cpp,
 Random1.cpp,
 SimpleMC7.cpp,
 Vanilla3.cpp,
 */

#include "SimpleMC7.h"
#include <iostream>
#include "Vanilla3.h"
#include "MCStatistics.h"
#include "ConvergenceTable.h"

using namespace std;

int main()
{
    double Expiry{10};
    double Strike{100};
    double Spot{110};
    double Vol{1};
    double r{0.01};
    unsigned long NumberOfPaths{10000000};
    
    PayOffCall thePayOff(Strike);
    VanillaOption theOption(thePayOff, Expiry);
    ParametersConstant VolParam(Vol);
    ParametersConstant rParam(r);
    StatisticsFirstFourMoments gatherer;
    ConvergenceTable gathererTwo(gatherer);
    
    SimpleMonteCarlo5(theOption, Spot, VolParam, rParam, NumberOfPaths, gathererTwo);
    
    vector<vector<double> > results = gathererTwo.GetResultsSoFar();
    
    cout <<"\nFor the call price the results are \n\n";
    
    // loop over the vectors of vectors to display results
    for (unsigned long i=0; i < results.size(); i++)
    {
        for (unsigned long j=0; j < results[i].size(); j++)
            cout << results[i][j] << " ";
        cout << "\n";
    }
    
    double tmp;
    cin >> tmp;


    return 0;
}