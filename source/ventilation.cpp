#include "ventilation/ventilation.h"

#include <stddef.h>
#include <ventilation/ventilation.hpp>

#include "ventilation-compliance.h"
#include "ventilation-elastance.h"
#include "ventilation-resistance.h"

#include "ventilation-flow.h"
#include "ventilation-pressure.h"
#include "ventilation-volume.h"
#include "ventilation-packet.h"

#include "ventilation-lung.h"

#include "ventilation-utilities.h"

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

struct VENTILATION_Ventilator {
    ventilation::Modes<float> mode;
};

struct VENTILATION_Frequency *
VENTILATION_frequency_hertz(float hertz, VENTILATION_error * error) {
    *error = VENTILATION_ERROR_OK;
    return new VENTILATION_Frequency(hertz);
}

struct VENTILATION_Frequency *
VENTILATION_frequency_bpm(float bpm, VENTILATION_error * error) {
    *error = VENTILATION_ERROR_OK;
    return new VENTILATION_Frequency(bpm / 60.0f);
}

void
VENTILATION_frequency_delete(struct VENTILATION_Frequency* context, VENTILATION_error * error) {
    if (nullptr == context) {
        *error = VENTILATION_ERROR_NULL;
    } else {
        *error = VENTILATION_ERROR_OK;
        delete context;
    }
}

struct VENTILATION_Ratio *
VENTILATION_ratio_create(float inspiration, float expiration, VENTILATION_error * error) {
    *error = VENTILATION_ERROR_OK;

    return new VENTILATION_Ratio(inspiration, expiration);
}

void
VENTILATION_ratio_delete(struct VENTILATION_Ratio * context, VENTILATION_error * error) {
    if (nullptr == context) {
        *error = VENTILATION_ERROR_NULL;
    } else {
        *error = VENTILATION_ERROR_OK;
        delete context;
    }
}

struct VENTILATION_Cycle *
VENTILATION_cycle_create(
          struct VENTILATION_Frequency *    frequency
        , struct VENTILATION_Ratio *        ratio
        , VENTILATION_error *               error
        ) 
{
    *error = VENTILATION_ERROR_OK;
    return new VENTILATION_Cycle(frequency->value, ratio->value);
}

void
VENTILATION_cycle_delete(struct VENTILATION_Cycle * context, VENTILATION_error * error) {
    if (nullptr == context) {
        *error = VENTILATION_ERROR_NULL;
    } else {
        *error = VENTILATION_ERROR_OK;
        delete context;
    }
}

struct VENTILATION_Ventilator *
VENTILATION_ventilator_pcv(struct VENTILATION_Cycle * cycle, VENTILATION_error * error) {
    *error = VENTILATION_ERROR_OK;

    ventilation::Modes<float> ventilator = ventilation::modes::PCV<float>(
              ventilation::PEEP<float>(5.0)
            , ventilation::pressure::Peak<float>(20.0)
            , cycle->value
            );
    return new VENTILATION_Ventilator(ventilator);
}

struct VENTILATION_Packet *
VENTILATION_ventilator_control(
          struct VENTILATION_Ventilator *   context
        , struct VENTILATION_Lung *         lung
        , VENTILATION_error *               error
        ) 
{
    using namespace std::chrono_literals;
    std::chrono::duration<float> step = 100us;

    ventilation::modes::visitor::Control<float> control{lung->value, step};
    ventilation::Packet packet = std::visit(control, context->mode);

    return new VENTILATION_Packet(packet);
}

void
VENTILATION_ventilator_delete(struct VENTILATION_Ventilator * context, VENTILATION_error * error) {
    if (nullptr == context) {
        *error = VENTILATION_ERROR_NULL;
    } else {
        *error = VENTILATION_ERROR_OK;
        delete context;
    }
}
