//
//  RandomMain3
//  ch6_random_number_class
//
//  Created by cheerzzh on 19/6/14.
//  Copyright (c) 2014年 Jared Zhou. All rights reserved.
//

/*
 uses source files
 
 AntiThetic.cpp
 Arrays.cpp,
 ConvergenceTable.cpp,
 MCStatistics.cpp
 Normals.cpp
 Parameters.cpp,
 ParkMiller.cpp
 PayOff3.cpp,
 PayOffBridge.cpp,
 Random2.cpp,
 SimpleMC8.cpp
 Vanilla3.cpp,
 */

#include "SimpleMC8.h"
#include "ParkMiller.h"
#include "iostream"
#include "Vanilla3.h"
#include "MCStatistics.h"
#include "ConvergenceTable.h"
#include "AntiThetic.h"

using namespace std;

int main()
{
    double Expiry{10};
    double Strike{100};
    double Spot{100};
    double Vol{0.1};
    double r{0.02};
    unsigned long NumberOfPaths{10000000};

    // for call option
    PayOffCall thePayOff(Strike);
    VanillaOption theOption(thePayOff,Expiry);
    
    PayOffPut thePayOff1(Strike);
    VanillaOption theOption1(thePayOff1,Expiry);
    
    ParametersConstant VolParam(Vol);
    ParametersConstant rParam(r);
    
    StatisticsMean gatherer;
    ConvergenceTable gathererTwo(gatherer);
    
    RandomParkMiller generator(1);
    
    AntiThetic GenTwo(generator);
    
    // for call option
    SimpleMonteCarlo6(theOption,
                      Spot,
                      VolParam,
                      rParam,
                      NumberOfPaths,
                      gathererTwo,
                      GenTwo);
    vector<vector<double> > results = gathererTwo.GetResultsSoFar();
    
    cout <<"\nFor the call price the results are \n";
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