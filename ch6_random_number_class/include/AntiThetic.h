//
//  AntiThetic.h
//  ch6_random_number_class
//
//  Created by cheerzzh on 19/6/14.
//  Copyright (c) 2014年 Jared Zhou. All rights reserved.
//

#ifndef __ch6_random_number_class__AntiThetic__
#define __ch6_random_number_class__AntiThetic__

#include "Random2.h"
#include "Wrapper.h"

class AntiThetic : public RandomBase
{
public:
    AntiThetic(const Wrapper<RandomBase>& innerGenerator);// wrapper object point to a random number generator
    
    virtual RandomBase* clone() const;
    virtual void GetUniforms(MJArray& variates);
    virtual void Skip(unsigned long numberOfPaths);
    virtual void SetSeed(unsigned long Seed);
    virtual void ResetDimensionality(unsigned long NewDimensionality);
    virtual void Reset();
    
private:
    Wrapper<RandomBase> InnerGenerator;
    bool OddEven;// boolean to indicate next draw should from inner generator or anti-thetic of last draw
    MJArray NextVariates; // array as data member to store last vector drawm
};

#endif /* defined(__ch6_random_number_class__AntiThetic__) */
