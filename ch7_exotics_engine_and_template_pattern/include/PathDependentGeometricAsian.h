#ifndef __ch7_exotics_engine_and_template_pattern__PathDependentGeometricAsian__
#define __ch7_exotics_engine_and_template_pattern__PathDependentGeometricAsian__

#include "PathDependent.h"
#include "PayOffBridge.h"

class PathDependentGeometricAsian : public PathDependent {
public:
  PathDependentGeometricAsian(const MJArray &LookAtTimes_, double DeliveryTime_,
                              const PayOffBridge &ThePayOff_);

  virtual unsigned long MaxNumberOfCashFlows() const;
  virtual MJArray PossibleCashFlowTimes() const;
  virtual unsigned long CashFlows(const MJArray &SpotValues,
                                  std::vector<CashFlow> &GeneratedFlows)
      const; // store the cash flow in a vector of CashFlow by pass by reference
  virtual ~PathDependentGeometricAsian() {}
  virtual PathDependent *clone() const;

private:
  double DeliveryTime;
  PayOffBridge ThePayOff;
  unsigned long NumberOfTimes;
};

#endif