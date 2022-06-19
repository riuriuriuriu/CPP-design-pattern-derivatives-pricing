//
//  Parameters.cpp
//  4.3_PayOffBridge
//
//  Created by cheerzzh on 17/6/14.
//  Copyright (c) 2014年 Jared Zhou. All rights reserved.
//

#include "Parameters.h"
#include <iostream>

//==== for Parameters class

Parameters::Parameters(const ParametersInner &InnerObject) {
  InnerObjectPtr = InnerObject.clone();
}

Parameters::Parameters(const Parameters &original) {
  InnerObjectPtr = original.InnerObjectPtr->clone();
}

// return a refernece, not a copy
Parameters &Parameters::operator=(const Parameters &original) {
  if (this != &original) {
    delete InnerObjectPtr;
    InnerObjectPtr = original.InnerObjectPtr->clone();
  }

  return *this;
}

Parameters::~Parameters() { delete InnerObjectPtr; }

/*
 return average value of the parameter between two time
 */
double Parameters::Mean(double time1, double time2) const {
  // calaulate integral over time interval
  double total = Integral(time1, time2);
  return total / (time2 - time1); // get mean
}

/*

 */
double Parameters::RootMeanSquare(double time1, double time2) const {
  double total = IntegralSquare(time1, time2);
  return total / (time1 - time2);
}

//==== for ParametersConstant class
ParametersConstant::ParametersConstant(double constant) {
  this->Constant = constant;
  this->ConstantSquare = Constant * Constant;
}

ParametersInner *ParametersConstant::clone() const {
  return new ParametersConstant(*this);
}

double ParametersConstant::Integral(double time1, double time2) const {
  return (time2 - time1) * Constant;
}

double ParametersConstant::IntegralSquare(double time1, double time2) const {
  return (time2 - time1) * ConstantSquare;
}
//==== for ParametersPieceWiseConstant class
ParametersPieceWiseConstant::ParametersPieceWiseConstant(
    std::vector<double> intervals, std::vector<double> constants) {
  if (intervals.size() - 1 != constants.size()) 
  {
    throw std::runtime_error("Size of `Intervals` is not equivalent to "
                             "size of `Constants` - 1.");
  }
  if (!std::is_sorted(intervals.begin(), intervals.end()))
  {
      throw std::runtime_error("`Intervals` is not sorted.");
  }
  Intervals = std::move(intervals);
  Constants = std::move(constants);
}

ParametersInner *ParametersPieceWiseConstant::clone() const {
  return new ParametersPieceWiseConstant(*this);
}

double ParametersPieceWiseConstant::Integral(double time1, double time2) const 
{
    if(time1 < *Intervals.begin() || time2 > *(--Intervals.end()))
    {
        throw std::runtime_error("Invalid integration interval.");
    }

    double integralValue{0.};
    for(size_t i = 0; i < Intervals.size() - 1; ++i)
    {
        if(time1 > Intervals[i+1] || time2 < Intervals[i])
        {
            continue;
        }

        if(time1 <= Intervals[i] && Intervals[i+1] <= time2)
        {
             integralValue += Constants[i] * (Intervals[i+1] - Intervals[i]);
        } 
        else if (time1 >= Intervals[i] && Intervals[i + 1] <= time2)
        {
            integralValue += Constants[i] * (Intervals[i + 1] - time1);
        } 
        else if (time1 <= Intervals[i] && Intervals[i + 1] >= time2) 
        {
          integralValue += Constants[i] * ( time2 - Intervals[i]);
        } 
        else
        {
          integralValue += Constants[i] * (time2 - time1);
        }
    }
    return integralValue;
}

double ParametersPieceWiseConstant::IntegralSquare(double time1, double time2) const {
  if (time1 < *Intervals.begin() || time2 > *(--Intervals.end())) {
    throw std::runtime_error("Invalid integration interval.");
  }

  double integralValue{0.};
  for (size_t i = 0; i < Intervals.size() - 1; ++i) {
    if (time1 < Intervals[i + 1] || time2 < Intervals[i]) {
      continue;
    }

    if (time1 <= Intervals[i] && Intervals[i + 1] <= time2) {
      integralValue +=
          Constants[i] * Constants[i] * (Intervals[i + 1] - Intervals[i]);
    } else if (time1 >= Intervals[i] && Intervals[i + 1] <= time2) {
      integralValue += Constants[i] * Constants[i] * (Intervals[i + 1] - time1);
    } else if (time1 <= Intervals[i] && Intervals[i + 1] >= time2) {
      integralValue += Constants[i] * Constants[i] * (time2 - Intervals[i]);
    } else {
      integralValue += Constants[i] * Constants[i] * (time2 - time1);
    }
  }
  return integralValue;
}
