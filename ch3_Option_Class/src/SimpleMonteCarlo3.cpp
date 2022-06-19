//
//  SimpleMonteCarlo3.cpp
//  Option_Class
//
//  Created by cheerzzh on 10/6/14.
//  Copyright (c) 2014年 Jared Zhou. All rights reserved.
//

#include "SimpleMonteCarlo3.h"
#include "Random1.h"
#include <cmath>


double SimpleMonteCarlo3(const VanillaOption& TheOption, // pass in an option object
                         double Spot,
                         double Vol,
                         double r,
                         unsigned long NumberOfPaths)
{
    double Expiry = TheOption.GetExpiry();
    double variance = Vol*Vol*Expiry;
    double rootVariance = sqrt(variance);
    double itoCorrecton = -0.5 * variance;
    
    double movedSpot = Spot*exp(r*Expiry + itoCorrecton);
    double thisSpot;
    double runningSum = 0;
    
    for (unsigned long i =0; i<NumberOfPaths; i++)
    {
        
        double thisGaussian = GetOneGaussianByBoxMuller();
        thisSpot = movedSpot*exp(rootVariance*thisGaussian);
        double thisPayOff =  TheOption.OptionPayOff(thisSpot);
        runningSum += thisPayOff;
        
    }
    
    double mean = runningSum / NumberOfPaths;
    mean *= exp(-r*Expiry);

    return mean;
}

