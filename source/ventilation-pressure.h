#ifndef VENTILATION_PRESSURE_H__
#define VENTILATION_PRESSURE_H__

#include "ventilation/ventilation.h"
#include <ventilation/ventilation.hpp>

struct VENTILATION_Pressure {
    ventilation::Pressure<float> value;

    VENTILATION_Pressure(const float v) : value(v) {}
    VENTILATION_Pressure(const ventilation::Pressure<float>& v) : value(v) {}
};

struct VENTILATION_PEEP {
    ventilation::PEEP<float> value;

    VENTILATION_PEEP(const float v) : value(v) {}
    VENTILATION_PEEP(const ventilation::PEEP<float>& v) : value(v) {}
    VENTILATION_PEEP(const ventilation::Pressure<float>& v) : value(v) {}
};

struct VENTILATION_Pressure_Peak {
    ventilation::pressure::Peak<float> value;

    VENTILATION_Pressure_Peak(const float v) : value(v) {}
    VENTILATION_Pressure_Peak(const ventilation::pressure::Peak<float>& v) : value(v) {}
    VENTILATION_Pressure_Peak(const ventilation::Pressure<float>& v) : value(v) {}
};


#endif // VENTILATION_PRESSURE_H__
