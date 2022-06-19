#ifndef __Option_Class__Power__
#define __Option_Class__Power__

#include "PayOff2.h"

class PayOffPower : public PayOff {
public:
  PayOffPower(double Strike_, double Power_);
  virtual double operator()(double Spot) const;
  virtual ~PayOffPower() {}

private:
  double Power;
  double Strike;
};

#endif /* defined(__Option_Class__Power__) */