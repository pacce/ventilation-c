#ifndef VENTILATION_CYCLE_H__
#define VENTILATION_CYCLE_H__

#include <optional>

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
    VENTILATION_Cycle(
              const ventilation::Inspiration<float>&        x
            , const ventilation::inspiratory::Pause<float>& y
            , const ventilation::Expiration<float>&         w
            , const ventilation::expiratory::Pause<float>&  z
            )
        : value(x, y, w, z)
    {}
};

#endif // VENTILATION_CYCLE_H__
