#include "Power.h"
#include <cmath>

PayOffPower::PayOffPower(double Strike_, double Power_)
    : Strike(Strike_), Power(Power_){}

double PayOffPower::operator()(double Spot) const {
    return std::max(std::pow(Spot, Power), Strike);
}
