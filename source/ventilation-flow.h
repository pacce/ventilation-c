#ifndef VENTILATION_FLOW_H__
#define VENTILATION_FLOW_H__

#include "ventilation/ventilation.h"
#include <ventilation/ventilation.hpp>

struct VENTILATION_Flow {
    ventilation::Flow<float> value;

    VENTILATION_Flow(const float v) : value(v) {}
    VENTILATION_Flow(const ventilation::Flow<float>& v) : value(v) {}
};

#endif // VENTILATION_FLOW_H__
