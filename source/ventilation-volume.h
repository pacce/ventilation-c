#ifndef VENTILATION_VOLUME_H__
#define VENTILATION_VOLUME_H__

#include "ventilation/ventilation.h"
#include <ventilation/ventilation.hpp>

struct VENTILATION_Volume {
    ventilation::Volume<float> value;

    VENTILATION_Volume(const float v) : value(v) {}
    VENTILATION_Volume(const ventilation::Volume<float>& v) : value(v) {}
};

#endif // VENTILATION_VOLUME_H__
