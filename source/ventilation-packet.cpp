#include "ventilation-packet.h"

#include "ventilation/ventilation.h"

#include "ventilation-flow.h"
#include "ventilation-pressure.h"
#include "ventilation-volume.h"

#include "ventilation-utilities.h"

struct VENTILATION_Packet *
VENTILATION_packet_create(
          const float           flow
        , const float           pressure
        , const float           volume
        , VENTILATION_error*    error
        )
{
    *error = VENTILATION_ERROR_OK;

    VENTILATION_Packet * context = new VENTILATION_Packet(flow, pressure, volume);
    return context;
}

void
VENTILATION_packet_delete(struct VENTILATION_Packet * context, VENTILATION_error * error) {
    if (nullptr == context) {
        *error = VENTILATION_ERROR_NULL;
    } else {
        *error = VENTILATION_ERROR_OK;
        delete context;
    }
}

struct VENTILATION_Pressure *
VENTILATION_packet_pressure(struct VENTILATION_Packet * context, VENTILATION_error * error) {
    VENTILATION_Pressure * p = nullptr;
    if (nullptr == context) {
        *error = VENTILATION_ERROR_NULL;
    } else {
        *error = VENTILATION_ERROR_OK;
        p = new VENTILATION_Pressure(context->value.pressure);
    }
    return p;
}

struct VENTILATION_Flow *
VENTILATION_packet_flow(struct VENTILATION_Packet * context, VENTILATION_error * error) {
    VENTILATION_Flow * f = nullptr;
    if (nullptr == context) {
        *error = VENTILATION_ERROR_NULL;
    } else {
        *error = VENTILATION_ERROR_OK;
        f = new VENTILATION_Flow(context->value.flow);
    }
    return f;
}

struct VENTILATION_Volume *
VENTILATION_packet_volume(struct VENTILATION_Packet * context, VENTILATION_error * error) {
    VENTILATION_Volume * v = nullptr;
    if (nullptr == context) {
        *error = VENTILATION_ERROR_NULL;
    } else {
        *error = VENTILATION_ERROR_OK;
        v = new VENTILATION_Volume(context->value.volume);
    }
    return v;
}


int
VENTILATION_packet_string(
          const struct VENTILATION_Packet * packet
        , char *                            buffer
        , int                               size
        , VENTILATION_error *               error
        )
{
    int buf_size = 0;
    if (nullptr == packet) {
        * error = VENTILATION_ERROR_NULL;
    } else {
        buf_size = std::snprintf(
                buffer
                , size
                , "%f, %f, %f"
                , static_cast<float>(packet->value.pressure)
                , static_cast<float>(packet->value.flow)
                , static_cast<float>(packet->value.volume)
                );
    }
    return buf_size;
}
