#ifndef __ch7_exotics_engine_and_template_pattern__PathDependentUpOutRebate__
#define __ch7_exotics_engine_and_template_pattern__PathDependentUpOutRebate__

#include "PathDependent.h"
#include "PayOffBridge.h"

class PathDependentUpOutRebate : public PathDependent {
public:
  PathDependentUpOutRebate(const MJArray &LookAtTimes_,
                                double DeliveryTime_, double Rebate_,
                                double Barrier_,
                                const PayOffBridge &ThePayOff_);

  virtual unsigned long MaxNumberOfCashFlows() const;
  virtual MJArray PossibleCashFlowTimes() const;
  virtual unsigned long CashFlows(const MJArray &SpotValues,
                                  std::vector<CashFlow> &GeneratedFlows)
      const; // store the cash flow in a vector of CashFlow by pass by reference
  virtual ~PathDependentUpOutRebate() {}
  virtual PathDependent *clone() const;

private:
  double DeliveryTime;
  PayOffBridge ThePayOff;
  unsigned long NumberOfTimes;
  double Rebate;
  double Barrier;
};

#endif