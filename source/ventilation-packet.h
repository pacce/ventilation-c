#ifndef VENTILATION_PACKET_H__
#define VENTILATION_PACKET_H__

#include "ventilation/ventilation.h"
#include <ventilation/ventilation.hpp>

struct VENTILATION_Packet {
    ventilation::Packet<float> value;

    VENTILATION_Packet(const float f, const float p, const float v)
    {
        value.flow      = ventilation::Flow<float>(f);
        value.pressure  = ventilation::Pressure<float>(p);
        value.volume    = ventilation::Volume<float>(v);
    }
    VENTILATION_Packet(const ventilation::Packet<float>& v) : value(v) {}
};


#endif // VENTILATION_PACKET_H__
