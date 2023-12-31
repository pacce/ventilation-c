#include "ventilation-lung.h"

#include "ventilation/ventilation.h"

#include "ventilation-elastance.h"
#include "ventilation-resistance.h"

#include "ventilation-flow.h"
#include "ventilation-pressure.h"
#include "ventilation-volume.h"

#include "ventilation-utilities.h"

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

struct VENTILATION_Elastance *
VENTILATION_lung_elastance(const struct VENTILATION_Lung * context, VENTILATION_error * error) {
    VENTILATION_Elastance * e = nullptr;
    if (nullptr == context) {
        *error = VENTILATION_ERROR_NULL;
    } else {
        *error  = VENTILATION_ERROR_OK;
        e       = new VENTILATION_Elastance(context->value.elastance());
    }
    return e;
}

struct VENTILATION_Resistance *
VENTILATION_lung_resistance(const struct VENTILATION_Lung * context, VENTILATION_error * error) {
    VENTILATION_Resistance * r = nullptr;
    if (nullptr == context) {
        *error = VENTILATION_ERROR_NULL;
    } else {
        *error  = VENTILATION_ERROR_OK;
        r       = new VENTILATION_Resistance(context->value.resistance());
    }
    return r;
}

void
VENTILATION_lung_set_elastance(
          struct VENTILATION_Lung *     lung
        , const VENTILATION_Elastance * elastance
        , VENTILATION_error *           error
        )
{
    if ((nullptr == error)) {
        *error = VENTILATION_ERROR_NULL;
    } else {
        *error = VENTILATION_ERROR_OK;
        const ventilation::Elastance<float>& e  = elastance->value;
        const ventilation::Resistance<float>& r = lung->value.resistance();

        lung->value = ventilation::lung::Forward<float>(r, e);
    }
}

void
VENTILATION_lung_set_resistance(
          struct VENTILATION_Lung *         lung
        , const VENTILATION_Resistance *    resistance
        , VENTILATION_error *               error
        )
{
    if ((nullptr == error)) {
        *error = VENTILATION_ERROR_NULL;
    } else {
        *error = VENTILATION_ERROR_OK;
        const ventilation::Elastance<float>& e  = lung->value.elastance();
        const ventilation::Resistance<float>& r = resistance->value;

        lung->value = ventilation::lung::Forward<float>(r, e);
    }
}

struct VENTILATION_Pressure *
VENTILATION_lung_forward(
          const struct VENTILATION_Lung *   lung
        , const struct VENTILATION_Flow *   flow
        , const struct VENTILATION_Volume * volume
        , VENTILATION_error*                error
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
