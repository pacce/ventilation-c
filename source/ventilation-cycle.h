#ifndef VENTILATION_CYCLE_H__
#define VENTILATION_CYCLE_H__

#include "ventilation/ventilation.h"
#include <ventilation/ventilation.hpp>

struct VENTILATION_Frequency {
    ventilation::frequency::Frequency<float> value;

    VENTILATION_Frequency(float frequency) : value(frequency) {}
};

struct VENTILATION_Ratio {
    ventilation::ratio::Ratio<float> value;

    VENTILATION_Ratio(float inspiration, float expiration) : value(inspiration, expiration) {}
};

struct VENTILATION_Cycle {
    ventilation::cycle::Cycle<float> value;

    VENTILATION_Cycle(
              const ventilation::frequency::Frequency<float>&   frequency
            , const ventilation::ratio::Ratio<float>&           ratio
            )
        : value(frequency, ratio)
    {}
};

#endif // VENTILATION_CYCLE_H__
