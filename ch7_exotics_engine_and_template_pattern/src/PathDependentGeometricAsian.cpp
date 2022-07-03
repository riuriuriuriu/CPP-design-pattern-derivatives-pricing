#include <cmath>
#include "PathDependentGeometricAsian.h"

PathDependentGeometricAsian::PathDependentGeometricAsian(
    const MJArray &LookAtTimes_, 
    double DeliveryTime_,
    const PayOffBridge &ThePayOff_
    )
    : PathDependent(LookAtTimes_), DeliveryTime(DeliveryTime_),
      ThePayOff(ThePayOff_), NumberOfTimes(LookAtTimes_.size()) {}

unsigned long 
PathDependentGeometricAsian::MaxNumberOfCashFlows() const 
{
  return 1UL; 
}

MJArray PathDependentGeometricAsian::PossibleCashFlowTimes() const 
{
  MJArray tmp(1UL);
  tmp[0] = DeliveryTime;
  return tmp;
}

unsigned long PathDependentGeometricAsian::CashFlows(
    const MJArray &SpotValues, std::vector<CashFlow> &GeneratedFlows) const 
{
  MJArray LogSpotValues{SpotValues.size()};
  for(int i = 0; i < SpotValues.size(); ++i)
  {
      LogSpotValues[i] = log(SpotValues[i]);
  }
  double LogSum = LogSpotValues.sum();
  double Logmean = LogSum / NumberOfTimes;

  GeneratedFlows[0].TimeIndex = 0UL;
  GeneratedFlows[0].Amount = ThePayOff(exp(Logmean));

  return 1UL;
}

PathDependent *PathDependentGeometricAsian::clone() const 
{
  return new PathDependentGeometricAsian(*this);
}
