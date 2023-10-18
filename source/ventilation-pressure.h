#ifndef VENTILATION_PRESSURE_H__
#define VENTILATION_PRESSURE_H__

#include "ventilation/ventilation.h"
#include <ventilation/ventilation.hpp>

struct VENTILATION_Pressure {
    ventilation::Pressure<float> value;

    VENTILATION_Pressure(const float v) : value(v) {}
    VENTILATION_Pressure(const ventilation::Pressure<float>& v) : value(v) {}
};

#endif // VENTILATION_PRESSURE_H__
