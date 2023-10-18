#ifndef VENTILATION_COMPLIANCE_H__
#define VENTILATION_COMPLIANCE_H__

#include "ventilation/ventilation.h"
#include <ventilation/ventilation.hpp>

struct VENTILATION_Compliance {
    ventilation::Compliance<float> value;

    VENTILATION_Compliance(const float v) : value(v) {}
    VENTILATION_Compliance(const ventilation::Compliance<float>& v) : value(v) {}
};

#endif // VENTILATION_COMPLIANCE_H__
