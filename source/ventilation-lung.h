#ifndef VENTILATION_LUNG_H__
#define VENTILATION_LUNG_H__

#include "ventilation/ventilation.h"
#include <ventilation/ventilation.hpp>

struct VENTILATION_Lung {
    ventilation::lung::Forward<float> value;

    using Resistance    = ventilation::Resistance<float>;
    using Elastance     = ventilation::Elastance<float>;

    VENTILATION_Lung(const float r, const float e) : VENTILATION_Lung(Resistance(r), Elastance(e))
    {}

    VENTILATION_Lung(const ventilation::Resistance<float>& r, const ventilation::Elastance<float>& e)
        : value(r, e)
    {}
};

#endif // VENTILATION_LUNG_H__
