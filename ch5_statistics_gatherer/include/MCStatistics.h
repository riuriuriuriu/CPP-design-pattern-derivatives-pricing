//
//  MCStatisitcs.h
//  ch5_statistics_gatherer
//
//  Created by cheerzzh on 18/6/14.
//  Copyright (c) 2014年 Jared Zhou. All rights reserved.
//

/*
 
 -strategy pattern
 - method1: take in data for each path
 - method2: output the desired statistics
 -
 */


#ifndef __ch5_statistics_gatherer__MCStatisitcs__
#define __ch5_statistics_gatherer__MCStatisitcs__

#include <vector>

class StatisticsMC
{
public:
    StatisticsMC(){}
    
    virtual void DumpOneResult(double result)=0; // a pure virtual function
    virtual std::vector<std::vector<double>> GetResultsSoFar()const=0;
    virtual StatisticsMC* clone()const=0;// possibility of virtual copy construction
    virtual ~StatisticsMC(){}//virtual destructor

private:
};


/*
 inherited from StatisticsMC, return mean of simulation
 */
class StatisticsMean:public StatisticsMC
{
public:
    StatisticsMean();
    virtual void DumpOneResult(double result);
    virtual std::vector<std::vector<double>> GetResultsSoFar()const;
    virtual StatisticsMC* clone() const;
    
private:
    double RunningSum;
    unsigned long PathsDone;
};

class StatisticsFirstFourMoments : public StatisticsMC
{
    public:
    StatisticsFirstFourMoments();
    virtual void DumpOneResult(double result);
    virtual std::vector<std::vector<double>> GetResultsSoFar() const;
    virtual StatisticsFirstFourMoments *clone() const;

  private:
    double RunningSum;
    double RunningSum2;
    double RunningSum3;
    double RunningSum4;
    unsigned long PathsDone;
};

class StatisticsVaR : public StatisticsMC {
public:
  StatisticsVaR(double probability);
  virtual void DumpOneResult(double result);
  virtual std::vector<std::vector<double>> GetResultsSoFar() const;
  virtual StatisticsVaR *clone() const;

private:
  std::vector<double> Samples;
  double Probability;
  unsigned long PathsDone;
  double CalcVaR() const;
};

#endif /* defined(__ch5_statistics_gatherer__MCStatisitcs__) */
