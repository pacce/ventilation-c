#ifndef VENTILATION_ELASTANCE_H_
#define VENTILATION_ELASTANCE_H_

#include "ventilation/ventilation.h"
#include <ventilation/ventilation.hpp>

struct VENTILATION_Elastance {
    ventilation::Elastance<float> value;

    VENTILATION_Elastance(const float v) : value(v) {}
    VENTILATION_Elastance(const ventilation::Elastance<float>& v) : value(v) {}
};

#endif // VENTILATION_ELASTANCE_H_
