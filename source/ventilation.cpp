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

#include "ventilation-utilities.h"

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

struct VENTILATION_Lung *
VENTILATION_lung_create(
          struct VENTILATION_Resistance *   r
        , struct VENTILATION_Elastance *    e
        , VENTILATION_error *               error
        )
{
    *error = VENTILATION_ERROR_OK;

    struct VENTILATION_Lung * context = new VENTILATION_Lung(r->value, e->value);
    return context;
}

void
VENTILATION_lung_delete(struct VENTILATION_Lung * context, VENTILATION_error * error) {
    if (nullptr == context) {
        *error = VENTILATION_ERROR_NULL;
    } else {
        *error = VENTILATION_ERROR_OK;
        delete context;
    }
}

struct VENTILATION_Resistance *
VENTILATION_lung_resistance(struct VENTILATION_Lung * context, VENTILATION_error * error) {
    VENTILATION_Resistance * r = nullptr;
    if (nullptr == context) {
        *error = VENTILATION_ERROR_NULL;
    } else {
        *error  = VENTILATION_ERROR_OK;
        r       = new VENTILATION_Resistance(context->value.resistance());
    }
    return r;
}

struct VENTILATION_Elastance *
VENTILATION_lung_elastance(struct VENTILATION_Lung * context, VENTILATION_error * error) {
    VENTILATION_Elastance * e = nullptr;
    if (nullptr == context) {
        *error = VENTILATION_ERROR_NULL;
    } else {
        *error  = VENTILATION_ERROR_OK;
        e       = new VENTILATION_Elastance(context->value.elastance());
    }
    return e;
}

struct VENTILATION_Pressure *
VENTILATION_lung_forward(
        struct VENTILATION_Lung *       lung
        , struct VENTILATION_Flow *     flow
        , struct VENTILATION_Volume *   volume
        , VENTILATION_error*            error
        )
{
    struct VENTILATION_Pressure * p = nullptr;
    if ((nullptr == lung) or (nullptr == flow) or (nullptr == volume)) {
        *error = VENTILATION_ERROR_NULL;
    } else {
        p = new VENTILATION_Pressure(lung->value(flow->value, volume->value));
    }
    return p;
}

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
