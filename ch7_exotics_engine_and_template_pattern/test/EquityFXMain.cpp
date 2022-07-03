//
//  EquityFXMain.cpp
//  ch7_exotics_engine_and_template_pattern
//
//  Created by cheerzzh on 21/6/14.
//  Copyright (c) 2014年 Jared Zhou. All rights reserved.
//

/*
 uses source files
 AntiThetic.cpp
 Arrays.cpp,
 ConvergenceTable.cpp,
 ExoticBSEngine.cpp
 ExoticEngine.cpp
 MCStatistics.cpp
 Normals.cpp
 Parameters.cpp,
 ParkMiller.cpp,
 PathDependent.cpp
 PathDependentAsian.cpp
 PayOff3.cpp,
 PayOffBridge.cpp,
 Random2.cpp,
 */

#include "AntiThetic.h"
#include "ConvergenceTable.h"
#include "ExoticBSEngine.h"
#include "MCStatistics.h"
#include "Parameters.h"
#include "ParkMiller.h"
#include "PathDependentAsian.h"
#include "PathDependentGeometricAsian.h"
#include "PathDependentUpOutRebate.h"
#include "PayOff3.h"
#include <iostream>
using namespace std;

int main()
{
    
    double Expiry{10};
    double Strike{100};
    double Spot{100};
    double Barrier{150};
    double Rebate{500};
    double Vol{1};
    double r{0.1};
    double d{0.01};
    unsigned long NumberOfPaths{1000000};
    unsigned NumberOfDates{50}; // averaging frequency in Asian option
    
    PayOffCall thePayOff(Strike);
    
    // compute time point 0~expiry, evenly splited
    MJArray times(NumberOfDates);
    for (unsigned long i=0; i < NumberOfDates; i++)
        times[i] = (i+1.0)*Expiry/NumberOfDates;
    
    ParametersConstant VolParam(Vol);
    ParametersConstant rParam(r);
    ParametersConstant dParam(d);
    
    PathDependentUpOutRebate theOption(times, Expiry, Rebate, Barrier, thePayOff);
    
    StatisticsMean gatherer;
    ConvergenceTable gathererTwo(gatherer);
    
    RandomParkMiller generator(NumberOfDates);
    
    AntiThetic GenTwo(generator);
    
    ExoticBSEngine theEngine(theOption, rParam, dParam,
                             VolParam, GenTwo, Spot);
    
    theEngine.DoSimulation(gathererTwo, NumberOfPaths);
    
    vector<vector<double> > results =
    gathererTwo.GetResultsSoFar();
    
    cout <<"\nFor the Asian call price the results are \n";
    
    {
        for (unsigned long i=0; i < results.size(); i++)
        {
            for (unsigned long j=0; j < results[i].size(); j++)
                cout << results[i][j] << " ";
            cout << "\n";
        }
    }
    
    double tmp;
    cin >> tmp;
    
    
    
    return 0;
}





