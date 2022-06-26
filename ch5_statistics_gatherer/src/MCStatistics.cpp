//
//  MCStatisitcs.cpp
//  ch5_statistics_gatherer
//
//  Created by cheerzzh on 18/6/14.
//  Copyright (c) 2014年 Jared Zhou. All rights reserved.
//

#include "MCStatistics.h"
using namespace std;

StatisticsMean::StatisticsMean(): RunningSum(0.0),PathsDone(0)
{
    
}

// collect one result from one path
// called every path
void StatisticsMean::DumpOneResult(double result)
{
    PathsDone++;
    RunningSum += result;
}

// called only once per simulation
vector<vector<double>> StatisticsMean::GetResultsSoFar()const
{
    vector<vector<double>> Results(1);
    
    Results[0].resize(1); // first vector length = 1
    Results[0][0]=RunningSum/PathsDone; // store mean
    
    return Results;
}

StatisticsMC* StatisticsMean::clone()const
{
    return new StatisticsMean(*this);
}

StatisticsFirstFourMoments::StatisticsFirstFourMoments()
:PathsDone(0), RunningSum(0), RunningSum2(0), RunningSum3(0), RunningSum4(0)
{

}

void
StatisticsFirstFourMoments::DumpOneResult(double result)
{
    ++PathsDone;
    RunningSum += result;
    RunningSum2 += result * result;
    RunningSum3 += result * result * result;
    RunningSum4 += result * result * result * result;
}

vector<vector<double>> 
StatisticsFirstFourMoments::GetResultsSoFar() const
{
    vector<vector<double>> Results(1,vector<double>(4));

    Results[0][0] = RunningSum / PathsDone;
    Results[0][1] = RunningSum2 / PathsDone;
    Results[0][2] = RunningSum3 / PathsDone;
    Results[0][3] = RunningSum4 / PathsDone;

    return Results;
}

StatisticsFirstFourMoments *
StatisticsFirstFourMoments::clone() const
{
    return new StatisticsFirstFourMoments{*this};
}