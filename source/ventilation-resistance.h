#ifndef VENTILATION_RESISTANCE_H_
#define VENTILATION_RESISTANCE_H_

#include "ventilation/ventilation.h"
#include <ventilation/ventilation.hpp>

struct VENTILATION_Resistance {
    ventilation::Resistance<float> value;

    VENTILATION_Resistance(const float v) : value(v) {}
    VENTILATION_Resistance(const ventilation::Resistance<float>& v) : value(v) {}
};

#endif // VENTILATION_RESISTANCE_H_
