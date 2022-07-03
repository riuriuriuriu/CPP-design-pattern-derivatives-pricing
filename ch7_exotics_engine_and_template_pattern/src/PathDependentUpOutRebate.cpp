#include "PathDependentUpOutRebate.h"

PathDependentUpOutRebate::PathDependentUpOutRebate(
    const MJArray &LookAtTimes_, 
    double DeliveryTime_,
    double Rebate_,
    double Barrier_,
    const PayOffBridge &ThePayOff_
    )
    : 
    PathDependent(LookAtTimes_), 
    DeliveryTime(DeliveryTime_),
    ThePayOff(ThePayOff_),
    NumberOfTimes(LookAtTimes_.size()),
    Rebate(Rebate_), 
    Barrier(Barrier_){};

unsigned long 
PathDependentUpOutRebate::MaxNumberOfCashFlows() const 
{
  return 1UL;
}

MJArray PathDependentUpOutRebate::PossibleCashFlowTimes() const 
{
  MJArray tmp(1UL);
  tmp[0] = DeliveryTime;
  return tmp;
}

unsigned long PathDependentUpOutRebate::CashFlows(
    const MJArray &SpotValues, std::vector<CashFlow> &GeneratedFlows) const 
{
  double maxSpot = SpotValues.max();
  double expirySpot = SpotValues[NumberOfTimes-1];

  GeneratedFlows[0].TimeIndex = 0UL;
  GeneratedFlows[0].Amount = maxSpot > Barrier ? Rebate : ThePayOff(expirySpot);

  return 1UL;
}

PathDependent *PathDependentUpOutRebate::clone() const 
{
  return new PathDependentUpOutRebate(*this);
}
