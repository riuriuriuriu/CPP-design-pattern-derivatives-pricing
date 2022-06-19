//
//  main.cpp
//  Option_Class
//
//  Created by cheerzzh on 10/6/14.
//  Copyright (c) 2014年 Jared Zhou. All rights reserved.
//

/*
require DoubleDigital.cpp
        PayOff2.cpp
        Random1.cpp
        SimpleMC3.cpp
        Vanilla1.cpp

 */


#include "SimpleMonteCarlo3.h"
#include "DoubleDigital.h"
#include "Vanilla1.h"
#include <iostream>

using namespace std;

int main()
{
    double Expiry{15};
    double Low{1}, Up{10};
    double Spot{5};
    double Vol{0.2};
    double r{0.01};
    unsigned long NumberOfPath{10000};
    
    PayOffDoubleDigital thePayOff(Low,Up); // prepare payoff object
    VanillaOption theOption(thePayOff,Expiry); // prepare option object
    
    double result = SimpleMonteCarlo3(theOption,
                                      Spot,
                                      Vol,
                                      r,
                                      NumberOfPath);
    
    cout << "\n the price for double digital with low barrier = "<<Low << " and up barrier = "<<Up<<" is "<< result<<"\n" << endl;
    
    return 0;
}




/*

Enter expiry:
1

Enter spot:
100

Enter vol:
0.2

Enter r:
0.05

Enter low barrier
100

Enter up barrier
120

Number of paths:
1000000

the price for double digital with low barrier = 100 and up barrier = 120 is 0.320139
 
 */

