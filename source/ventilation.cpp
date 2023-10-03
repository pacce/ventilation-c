#include "ventilation/ventilation.h"

#include <stddef.h>
#include <ventilation/ventilation.hpp>

#define VENTILATION_BOOL(value) ((value) ? VENTILATION_TRUE : VENTILATION_FALSE)

struct VENTILATION_Compliance {
    ventilation::Compliance<float> value;

    VENTILATION_Compliance(const float v) : value(v) {}
    VENTILATION_Compliance(const ventilation::Compliance<float>& v) : value(v) {}
};

struct VENTILATION_Elastance {
    ventilation::Elastance<float> value;

    VENTILATION_Elastance(const float v) : value(v) {}
    VENTILATION_Elastance(const ventilation::Elastance<float>& v) : value(v) {}
};

struct VENTILATION_Resistance {
    ventilation::Resistance<float> value;

    VENTILATION_Resistance(const float v) : value(v) {}
    VENTILATION_Resistance(const ventilation::Resistance<float>& v) : value(v) {}
};

struct VENTILATION_Flow {
    ventilation::Flow<float> value;

    VENTILATION_Flow(const float v) : value(v) {}
    VENTILATION_Flow(const ventilation::Flow<float>& v) : value(v) {}
};

struct VENTILATION_Pressure {
    ventilation::Pressure<float> value;

    VENTILATION_Pressure(const float v) : value(v) {}
    VENTILATION_Pressure(const ventilation::Pressure<float>& v) : value(v) {}
};

struct VENTILATION_Volume {
    ventilation::Volume<float> value;

    VENTILATION_Volume(const float v) : value(v) {}
    VENTILATION_Volume(const ventilation::Volume<float>& v) : value(v) {}
};

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

struct VENTILATION_Compliance *
VENTILATION_compliance_create(const float value, VENTILATION_error * error) {
    *error = VENTILATION_ERROR_OK;

    VENTILATION_Compliance * context = new VENTILATION_Compliance(value);
    return context;
}

void
VENTILATION_compliance_delete(struct VENTILATION_Compliance* context, VENTILATION_error * error) {
    if (nullptr == context) {
        *error = VENTILATION_ERROR_NULL;
    } else {
        *error = VENTILATION_ERROR_OK;
        delete context;
    }
}

float
VENTILATION_compliance_value(const struct VENTILATION_Compliance* context, VENTILATION_error * error) {
    *error = VENTILATION_ERROR_OK;
    return static_cast<float>(context->value);
}

struct VENTILATION_Compliance *
VENTILATION_compliance_add(
          const struct VENTILATION_Compliance*  lhs
        , const struct VENTILATION_Compliance*  rhs
        , VENTILATION_error *                   error
        )
{
    if ((nullptr == lhs) or (nullptr == rhs)) {
        *error = VENTILATION_ERROR_NULL;
        return nullptr;
    } else {
        return new VENTILATION_Compliance(lhs->value + rhs->value);
    }
}

struct VENTILATION_Compliance *
VENTILATION_compliance_sub(
          const struct VENTILATION_Compliance*  lhs
        , const struct VENTILATION_Compliance*  rhs
        , VENTILATION_error *                   error
        )
{
    if ((nullptr == lhs) or (nullptr == rhs)) {
        *error = VENTILATION_ERROR_NULL;
        return nullptr;
    } else {
        return new VENTILATION_Compliance(lhs->value - rhs->value);
    }
}

struct VENTILATION_Compliance *
VENTILATION_compliance_mul(
          const struct VENTILATION_Compliance*  lhs
        , const struct VENTILATION_Compliance*  rhs
        , VENTILATION_error *                   error
        )
{
    if ((nullptr == lhs) or (nullptr == rhs)) {
        *error = VENTILATION_ERROR_NULL;
        return nullptr;
    } else {
        return new VENTILATION_Compliance(lhs->value * rhs->value);
    }
}

VENTILATION_bool
VENTILATION_compliance_eq(
          const struct VENTILATION_Compliance*  lhs
        , const struct VENTILATION_Compliance*  rhs
        , VENTILATION_error *                   error
        )
{
    if ((nullptr == lhs) or (nullptr == rhs)) {
        *error = VENTILATION_ERROR_NULL;
        return VENTILATION_FALSE;
    } else {
        return VENTILATION_BOOL((lhs->value == rhs->value));
    }
}

VENTILATION_bool
VENTILATION_compliance_neq(
          const struct VENTILATION_Compliance*  lhs
        , const struct VENTILATION_Compliance*  rhs
        , VENTILATION_error *                   error
        )
{
    if ((nullptr == lhs) or (nullptr == rhs)) {
        *error = VENTILATION_ERROR_NULL;
        return VENTILATION_FALSE;
    } else {
        return VENTILATION_BOOL((lhs->value != rhs->value));
    }
}

VENTILATION_bool
VENTILATION_compliance_gt(
          const struct VENTILATION_Compliance*  lhs
        , const struct VENTILATION_Compliance*  rhs
        , VENTILATION_error *                   error
        )
{
    if ((nullptr == lhs) or (nullptr == rhs)) {
        *error = VENTILATION_ERROR_NULL;
        return VENTILATION_FALSE;
    } else {
        return VENTILATION_BOOL((lhs->value > rhs->value));
    }
}

VENTILATION_bool
VENTILATION_compliance_ge(
          const struct VENTILATION_Compliance*  lhs
        , const struct VENTILATION_Compliance*  rhs
        , VENTILATION_error *                   error
        )
{
    if ((nullptr == lhs) or (nullptr == rhs)) {
        *error = VENTILATION_ERROR_NULL;
        return VENTILATION_FALSE;
    } else {
        return VENTILATION_BOOL((lhs->value >= rhs->value));
    }
}

VENTILATION_bool
VENTILATION_compliance_lt(
          const struct VENTILATION_Compliance*  lhs
        , const struct VENTILATION_Compliance*  rhs
        , VENTILATION_error *                   error
        )
{
    if ((nullptr == lhs) or (nullptr == rhs)) {
        *error = VENTILATION_ERROR_NULL;
        return VENTILATION_FALSE;
    } else {
        return VENTILATION_BOOL((lhs->value < rhs->value));
    }
}

VENTILATION_bool
VENTILATION_compliance_le(
          const struct VENTILATION_Compliance*  lhs
        , const struct VENTILATION_Compliance*  rhs
        , VENTILATION_error *                   error
        )
{
    if ((nullptr == lhs) or (nullptr == rhs)) {
        *error = VENTILATION_ERROR_NULL;
        return VENTILATION_FALSE;
    } else {
        return VENTILATION_BOOL((lhs->value <= rhs->value));
    }
}

struct VENTILATION_Elastance *
VENTILATION_elastance_create(const float value, VENTILATION_error * error) {
    *error = VENTILATION_ERROR_OK;

    VENTILATION_Elastance * context = new VENTILATION_Elastance(value);
    return context;
}

void
VENTILATION_elastance_delete(struct VENTILATION_Elastance* context, VENTILATION_error * error) {
    if (nullptr == context) {
        *error = VENTILATION_ERROR_NULL;
    } else {
        *error = VENTILATION_ERROR_OK;
        delete context;
    }
}

float
VENTILATION_elastance_value(const struct VENTILATION_Elastance* context, VENTILATION_error * error) {
    *error = VENTILATION_ERROR_OK;
    return static_cast<float>(context->value);
}

struct VENTILATION_Elastance *
VENTILATION_elastance_add(
          const struct VENTILATION_Elastance*   lhs
        , const struct VENTILATION_Elastance*   rhs
        , VENTILATION_error *                   error
        )
{
    if ((nullptr == lhs) or (nullptr == rhs)) {
        *error = VENTILATION_ERROR_NULL;
        return nullptr;
    } else {
        return new VENTILATION_Elastance(lhs->value + rhs->value);
    }
}

struct VENTILATION_Elastance *
VENTILATION_elastance_sub(
          const struct VENTILATION_Elastance*   lhs
        , const struct VENTILATION_Elastance*   rhs
        , VENTILATION_error *                   error
        )
{
    if ((nullptr == lhs) or (nullptr == rhs)) {
        *error = VENTILATION_ERROR_NULL;
        return nullptr;
    } else {
        return new VENTILATION_Elastance(lhs->value - rhs->value);
    }
}

struct VENTILATION_Elastance *
VENTILATION_elastance_mul(
          const struct VENTILATION_Elastance*   lhs
        , const struct VENTILATION_Elastance*   rhs
        , VENTILATION_error *                   error
        )
{
    if ((nullptr == lhs) or (nullptr == rhs)) {
        *error = VENTILATION_ERROR_NULL;
        return nullptr;
    } else {
        return new VENTILATION_Elastance(lhs->value * rhs->value);
    }
}

VENTILATION_bool
VENTILATION_elastance_eq(
          const struct VENTILATION_Elastance*   lhs
        , const struct VENTILATION_Elastance*   rhs
        , VENTILATION_error *                   error
        )
{
    if ((nullptr == lhs) or (nullptr == rhs)) {
        *error = VENTILATION_ERROR_NULL;
        return VENTILATION_FALSE;
    } else {
        return VENTILATION_BOOL((lhs->value == rhs->value));
    }
}

VENTILATION_bool
VENTILATION_elastance_neq(
          const struct VENTILATION_Elastance*   lhs
        , const struct VENTILATION_Elastance*   rhs
        , VENTILATION_error *                   error
        )
{
    if ((nullptr == lhs) or (nullptr == rhs)) {
        *error = VENTILATION_ERROR_NULL;
        return VENTILATION_FALSE;
    } else {
        return VENTILATION_BOOL((lhs->value != rhs->value));
    }
}

VENTILATION_bool
VENTILATION_elastance_gt(
          const struct VENTILATION_Elastance*   lhs
        , const struct VENTILATION_Elastance*   rhs
        , VENTILATION_error *                   error
        )
{
    if ((nullptr == lhs) or (nullptr == rhs)) {
        *error = VENTILATION_ERROR_NULL;
        return VENTILATION_FALSE;
    } else {
        return VENTILATION_BOOL((lhs->value > rhs->value));
    }
}

VENTILATION_bool
VENTILATION_elastance_ge(
          const struct VENTILATION_Elastance*   lhs
        , const struct VENTILATION_Elastance*   rhs
        , VENTILATION_error *                   error
        )
{
    if ((nullptr == lhs) or (nullptr == rhs)) {
        *error = VENTILATION_ERROR_NULL;
        return VENTILATION_FALSE;
    } else {
        return VENTILATION_BOOL((lhs->value >= rhs->value));
    }
}

VENTILATION_bool
VENTILATION_elastance_lt(
          const struct VENTILATION_Elastance*   lhs
        , const struct VENTILATION_Elastance*   rhs
        , VENTILATION_error *                   error
        )
{
    if ((nullptr == lhs) or (nullptr == rhs)) {
        *error = VENTILATION_ERROR_NULL;
        return VENTILATION_FALSE;
    } else {
        return VENTILATION_BOOL((lhs->value < rhs->value));
    }
}

VENTILATION_bool
VENTILATION_elastance_le(
          const struct VENTILATION_Elastance*   lhs
        , const struct VENTILATION_Elastance*   rhs
        , VENTILATION_error *                   error
        )
{
    if ((nullptr == lhs) or (nullptr == rhs)) {
        *error = VENTILATION_ERROR_NULL;
        return VENTILATION_FALSE;
    } else {
        return VENTILATION_BOOL((lhs->value <= rhs->value));
    }
}

struct VENTILATION_Resistance *
VENTILATION_resistance_create(const float value, VENTILATION_error * error) {
    *error = VENTILATION_ERROR_OK;

    VENTILATION_Resistance * context = new VENTILATION_Resistance(value);
    return context;
}

void
VENTILATION_resistance_delete(struct VENTILATION_Resistance* context, VENTILATION_error * error) {
    if (nullptr == context) {
        *error = VENTILATION_ERROR_NULL;
    } else {
        *error = VENTILATION_ERROR_OK;
        delete context;
    }
}

float
VENTILATION_resistance_value(const struct VENTILATION_Resistance* context, VENTILATION_error * error) {
    *error = VENTILATION_ERROR_OK;
    return static_cast<float>(context->value);
}

struct VENTILATION_Resistance *
VENTILATION_resistance_add(
          const struct VENTILATION_Resistance*   lhs
        , const struct VENTILATION_Resistance*   rhs
        , VENTILATION_error *                   error
        )
{
    if ((nullptr == lhs) or (nullptr == rhs)) {
        *error = VENTILATION_ERROR_NULL;
        return nullptr;
    } else {
        return new VENTILATION_Resistance(lhs->value + rhs->value);
    }
}

struct VENTILATION_Resistance *
VENTILATION_resistance_sub(
          const struct VENTILATION_Resistance*   lhs
        , const struct VENTILATION_Resistance*   rhs
        , VENTILATION_error *                   error
        )
{
    if ((nullptr == lhs) or (nullptr == rhs)) {
        *error = VENTILATION_ERROR_NULL;
        return nullptr;
    } else {
        return new VENTILATION_Resistance(lhs->value - rhs->value);
    }
}

struct VENTILATION_Resistance *
VENTILATION_resistance_mul(
          const struct VENTILATION_Resistance*   lhs
        , const struct VENTILATION_Resistance*   rhs
        , VENTILATION_error *                   error
        )
{
    if ((nullptr == lhs) or (nullptr == rhs)) {
        *error = VENTILATION_ERROR_NULL;
        return nullptr;
    } else {
        return new VENTILATION_Resistance(lhs->value * rhs->value);
    }
}

VENTILATION_bool
VENTILATION_resistance_eq(
          const struct VENTILATION_Resistance*   lhs
        , const struct VENTILATION_Resistance*   rhs
        , VENTILATION_error *                   error
        )
{
    if ((nullptr == lhs) or (nullptr == rhs)) {
        *error = VENTILATION_ERROR_NULL;
        return VENTILATION_FALSE;
    } else {
        return VENTILATION_BOOL((lhs->value == rhs->value));
    }
}

VENTILATION_bool
VENTILATION_resistance_neq(
          const struct VENTILATION_Resistance*   lhs
        , const struct VENTILATION_Resistance*   rhs
        , VENTILATION_error *                   error
        )
{
    if ((nullptr == lhs) or (nullptr == rhs)) {
        *error = VENTILATION_ERROR_NULL;
        return VENTILATION_FALSE;
    } else {
        return VENTILATION_BOOL((lhs->value != rhs->value));
    }
}

VENTILATION_bool
VENTILATION_resistance_gt(
          const struct VENTILATION_Resistance*   lhs
        , const struct VENTILATION_Resistance*   rhs
        , VENTILATION_error *                   error
        )
{
    if ((nullptr == lhs) or (nullptr == rhs)) {
        *error = VENTILATION_ERROR_NULL;
        return VENTILATION_FALSE;
    } else {
        return VENTILATION_BOOL((lhs->value > rhs->value));
    }
}

VENTILATION_bool
VENTILATION_resistance_ge(
          const struct VENTILATION_Resistance*   lhs
        , const struct VENTILATION_Resistance*   rhs
        , VENTILATION_error *                   error
        )
{
    if ((nullptr == lhs) or (nullptr == rhs)) {
        *error = VENTILATION_ERROR_NULL;
        return VENTILATION_FALSE;
    } else {
        return VENTILATION_BOOL((lhs->value >= rhs->value));
    }
}

VENTILATION_bool
VENTILATION_resistance_lt(
          const struct VENTILATION_Resistance*   lhs
        , const struct VENTILATION_Resistance*   rhs
        , VENTILATION_error *                   error
        )
{
    if ((nullptr == lhs) or (nullptr == rhs)) {
        *error = VENTILATION_ERROR_NULL;
        return VENTILATION_FALSE;
    } else {
        return VENTILATION_BOOL((lhs->value < rhs->value));
    }
}

VENTILATION_bool
VENTILATION_resistance_le(
          const struct VENTILATION_Resistance*   lhs
        , const struct VENTILATION_Resistance*   rhs
        , VENTILATION_error *                   error
        )
{
    if ((nullptr == lhs) or (nullptr == rhs)) {
        *error = VENTILATION_ERROR_NULL;
        return VENTILATION_FALSE;
    } else {
        return VENTILATION_BOOL((lhs->value <= rhs->value));
    }
}

struct VENTILATION_Flow *
VENTILATION_flow_create(const float value, VENTILATION_error * error) {
    *error = VENTILATION_ERROR_OK;

    VENTILATION_Flow * context = new VENTILATION_Flow(value);
    return context;
}

void
VENTILATION_flow_delete(struct VENTILATION_Flow* context, VENTILATION_error * error) {
    if (nullptr == context) {
        *error = VENTILATION_ERROR_NULL;
    } else {
        *error = VENTILATION_ERROR_OK;
        delete context;
    }
}

float
VENTILATION_flow_value(const struct VENTILATION_Flow* context, VENTILATION_error * error) {
    *error = VENTILATION_ERROR_OK;
    return static_cast<float>(context->value);
}

struct VENTILATION_Flow *
VENTILATION_flow_add(
          const struct VENTILATION_Flow*   lhs
        , const struct VENTILATION_Flow*   rhs
        , VENTILATION_error *                   error
        )
{
    if ((nullptr == lhs) or (nullptr == rhs)) {
        *error = VENTILATION_ERROR_NULL;
        return nullptr;
    } else {
        return new VENTILATION_Flow(lhs->value + rhs->value);
    }
}

struct VENTILATION_Flow *
VENTILATION_flow_sub(
          const struct VENTILATION_Flow*   lhs
        , const struct VENTILATION_Flow*   rhs
        , VENTILATION_error *                   error
        )
{
    if ((nullptr == lhs) or (nullptr == rhs)) {
        *error = VENTILATION_ERROR_NULL;
        return nullptr;
    } else {
        return new VENTILATION_Flow(lhs->value - rhs->value);
    }
}

struct VENTILATION_Flow *
VENTILATION_flow_mul(
          const struct VENTILATION_Flow*   lhs
        , const struct VENTILATION_Flow*   rhs
        , VENTILATION_error *                   error
        )
{
    if ((nullptr == lhs) or (nullptr == rhs)) {
        *error = VENTILATION_ERROR_NULL;
        return nullptr;
    } else {
        return new VENTILATION_Flow(lhs->value * rhs->value);
    }
}

VENTILATION_bool
VENTILATION_flow_eq(
          const struct VENTILATION_Flow*   lhs
        , const struct VENTILATION_Flow*   rhs
        , VENTILATION_error *                   error
        )
{
    if ((nullptr == lhs) or (nullptr == rhs)) {
        *error = VENTILATION_ERROR_NULL;
        return VENTILATION_FALSE;
    } else {
        return VENTILATION_BOOL((lhs->value == rhs->value));
    }
}

VENTILATION_bool
VENTILATION_flow_neq(
          const struct VENTILATION_Flow*   lhs
        , const struct VENTILATION_Flow*   rhs
        , VENTILATION_error *                   error
        )
{
    if ((nullptr == lhs) or (nullptr == rhs)) {
        *error = VENTILATION_ERROR_NULL;
        return VENTILATION_FALSE;
    } else {
        return VENTILATION_BOOL((lhs->value != rhs->value));
    }
}

VENTILATION_bool
VENTILATION_flow_gt(
          const struct VENTILATION_Flow*   lhs
        , const struct VENTILATION_Flow*   rhs
        , VENTILATION_error *                   error
        )
{
    if ((nullptr == lhs) or (nullptr == rhs)) {
        *error = VENTILATION_ERROR_NULL;
        return VENTILATION_FALSE;
    } else {
        return VENTILATION_BOOL((lhs->value > rhs->value));
    }
}

VENTILATION_bool
VENTILATION_flow_ge(
          const struct VENTILATION_Flow*   lhs
        , const struct VENTILATION_Flow*   rhs
        , VENTILATION_error *                   error
        )
{
    if ((nullptr == lhs) or (nullptr == rhs)) {
        *error = VENTILATION_ERROR_NULL;
        return VENTILATION_FALSE;
    } else {
        return VENTILATION_BOOL((lhs->value >= rhs->value));
    }
}

VENTILATION_bool
VENTILATION_flow_lt(
          const struct VENTILATION_Flow*   lhs
        , const struct VENTILATION_Flow*   rhs
        , VENTILATION_error *                   error
        )
{
    if ((nullptr == lhs) or (nullptr == rhs)) {
        *error = VENTILATION_ERROR_NULL;
        return VENTILATION_FALSE;
    } else {
        return VENTILATION_BOOL((lhs->value < rhs->value));
    }
}

VENTILATION_bool
VENTILATION_flow_le(
          const struct VENTILATION_Flow*   lhs
        , const struct VENTILATION_Flow*   rhs
        , VENTILATION_error *                   error
        )
{
    if ((nullptr == lhs) or (nullptr == rhs)) {
        *error = VENTILATION_ERROR_NULL;
        return VENTILATION_FALSE;
    } else {
        return VENTILATION_BOOL((lhs->value <= rhs->value));
    }
}

struct VENTILATION_Pressure *
VENTILATION_pressure_create(const float value, VENTILATION_error * error) {
    *error = VENTILATION_ERROR_OK;

    VENTILATION_Pressure * context = new VENTILATION_Pressure(value);
    return context;
}

void
VENTILATION_pressure_delete(struct VENTILATION_Pressure* context, VENTILATION_error * error) {
    if (nullptr == context) {
        *error = VENTILATION_ERROR_NULL;
    } else {
        *error = VENTILATION_ERROR_OK;
        delete context;
    }
}

float
VENTILATION_pressure_value(const struct VENTILATION_Pressure* context, VENTILATION_error * error) {
    *error = VENTILATION_ERROR_OK;
    return static_cast<float>(context->value);
}

struct VENTILATION_Pressure *
VENTILATION_pressure_add(
          const struct VENTILATION_Pressure*   lhs
        , const struct VENTILATION_Pressure*   rhs
        , VENTILATION_error *                   error
        )
{
    if ((nullptr == lhs) or (nullptr == rhs)) {
        *error = VENTILATION_ERROR_NULL;
        return nullptr;
    } else {
        return new VENTILATION_Pressure(lhs->value + rhs->value);
    }
}

struct VENTILATION_Pressure *
VENTILATION_pressure_sub(
          const struct VENTILATION_Pressure*   lhs
        , const struct VENTILATION_Pressure*   rhs
        , VENTILATION_error *                   error
        )
{
    if ((nullptr == lhs) or (nullptr == rhs)) {
        *error = VENTILATION_ERROR_NULL;
        return nullptr;
    } else {
        return new VENTILATION_Pressure(lhs->value - rhs->value);
    }
}

struct VENTILATION_Pressure *
VENTILATION_pressure_mul(
          const struct VENTILATION_Pressure*   lhs
        , const struct VENTILATION_Pressure*   rhs
        , VENTILATION_error *                   error
        )
{
    if ((nullptr == lhs) or (nullptr == rhs)) {
        *error = VENTILATION_ERROR_NULL;
        return nullptr;
    } else {
        return new VENTILATION_Pressure(lhs->value * rhs->value);
    }
}

VENTILATION_bool
VENTILATION_pressure_eq(
          const struct VENTILATION_Pressure*   lhs
        , const struct VENTILATION_Pressure*   rhs
        , VENTILATION_error *                   error
        )
{
    if ((nullptr == lhs) or (nullptr == rhs)) {
        *error = VENTILATION_ERROR_NULL;
        return VENTILATION_FALSE;
    } else {
        return VENTILATION_BOOL((lhs->value == rhs->value));
    }
}

VENTILATION_bool
VENTILATION_pressure_neq(
          const struct VENTILATION_Pressure*   lhs
        , const struct VENTILATION_Pressure*   rhs
        , VENTILATION_error *                   error
        )
{
    if ((nullptr == lhs) or (nullptr == rhs)) {
        *error = VENTILATION_ERROR_NULL;
        return VENTILATION_FALSE;
    } else {
        return VENTILATION_BOOL((lhs->value != rhs->value));
    }
}

VENTILATION_bool
VENTILATION_pressure_gt(
          const struct VENTILATION_Pressure*   lhs
        , const struct VENTILATION_Pressure*   rhs
        , VENTILATION_error *                   error
        )
{
    if ((nullptr == lhs) or (nullptr == rhs)) {
        *error = VENTILATION_ERROR_NULL;
        return VENTILATION_FALSE;
    } else {
        return VENTILATION_BOOL((lhs->value > rhs->value));
    }
}

VENTILATION_bool
VENTILATION_pressure_ge(
          const struct VENTILATION_Pressure*   lhs
        , const struct VENTILATION_Pressure*   rhs
        , VENTILATION_error *                   error
        )
{
    if ((nullptr == lhs) or (nullptr == rhs)) {
        *error = VENTILATION_ERROR_NULL;
        return VENTILATION_FALSE;
    } else {
        return VENTILATION_BOOL((lhs->value >= rhs->value));
    }
}

VENTILATION_bool
VENTILATION_pressure_lt(
          const struct VENTILATION_Pressure*   lhs
        , const struct VENTILATION_Pressure*   rhs
        , VENTILATION_error *                   error
        )
{
    if ((nullptr == lhs) or (nullptr == rhs)) {
        *error = VENTILATION_ERROR_NULL;
        return VENTILATION_FALSE;
    } else {
        return VENTILATION_BOOL((lhs->value < rhs->value));
    }
}

VENTILATION_bool
VENTILATION_pressure_le(
          const struct VENTILATION_Pressure*   lhs
        , const struct VENTILATION_Pressure*   rhs
        , VENTILATION_error *                   error
        )
{
    if ((nullptr == lhs) or (nullptr == rhs)) {
        *error = VENTILATION_ERROR_NULL;
        return VENTILATION_FALSE;
    } else {
        return VENTILATION_BOOL((lhs->value <= rhs->value));
    }
}

struct VENTILATION_Volume *
h
VENTILATION_volume_create(const float value, VENTILATION_error * error) {
    *error = VENTILATION_ERROR_OK;

    VENTILATION_Volume * context = new VENTILATION_Volume(value);
    return context;
}

void
VENTILATION_volume_delete(struct VENTILATION_Volume* context, VENTILATION_error * error) {
    if (nullptr == context) {
        *error = VENTILATION_ERROR_NULL;
    } else {
        *error = VENTILATION_ERROR_OK;
        delete context;
    }
}

float
VENTILATION_volume_value(const struct VENTILATION_Volume* context, VENTILATION_error * error) {
    *error = VENTILATION_ERROR_OK;
    return static_cast<float>(context->value);
}

struct VENTILATION_Volume *
VENTILATION_volume_add(
          const struct VENTILATION_Volume*   lhs
        , const struct VENTILATION_Volume*   rhs
        , VENTILATION_error *                   error
        )
{
    if ((nullptr == lhs) or (nullptr == rhs)) {
        *error = VENTILATION_ERROR_NULL;
        return nullptr;
    } else {
        return new VENTILATION_Volume(lhs->value + rhs->value);
    }
}

struct VENTILATION_Volume *
VENTILATION_volume_sub(
          const struct VENTILATION_Volume*   lhs
        , const struct VENTILATION_Volume*   rhs
        , VENTILATION_error *                   error
        )
{
    if ((nullptr == lhs) or (nullptr == rhs)) {
        *error = VENTILATION_ERROR_NULL;
        return nullptr;
    } else {
        return new VENTILATION_Volume(lhs->value - rhs->value);
    }
}

struct VENTILATION_Volume *
VENTILATION_volume_mul(
          const struct VENTILATION_Volume*   lhs
        , const struct VENTILATION_Volume*   rhs
        , VENTILATION_error *                   error
        )
{
    if ((nullptr == lhs) or (nullptr == rhs)) {
        *error = VENTILATION_ERROR_NULL;
        return nullptr;
    } else {
        return new VENTILATION_Volume(lhs->value * rhs->value);
    }
}

VENTILATION_bool
VENTILATION_volume_eq(
          const struct VENTILATION_Volume*   lhs
        , const struct VENTILATION_Volume*   rhs
        , VENTILATION_error *                   error
        )
{
    if ((nullptr == lhs) or (nullptr == rhs)) {
        *error = VENTILATION_ERROR_NULL;
        return VENTILATION_FALSE;
    } else {
        return VENTILATION_BOOL((lhs->value == rhs->value));
    }
}

VENTILATION_bool
VENTILATION_volume_neq(
          const struct VENTILATION_Volume*   lhs
        , const struct VENTILATION_Volume*   rhs
        , VENTILATION_error *                   error
        )
{
    if ((nullptr == lhs) or (nullptr == rhs)) {
        *error = VENTILATION_ERROR_NULL;
        return VENTILATION_FALSE;
    } else {
        return VENTILATION_BOOL((lhs->value != rhs->value));
    }
}

VENTILATION_bool
VENTILATION_volume_gt(
          const struct VENTILATION_Volume*   lhs
        , const struct VENTILATION_Volume*   rhs
        , VENTILATION_error *                   error
        )
{
    if ((nullptr == lhs) or (nullptr == rhs)) {
        *error = VENTILATION_ERROR_NULL;
        return VENTILATION_FALSE;
    } else {
        return VENTILATION_BOOL((lhs->value > rhs->value));
    }
}

VENTILATION_bool
VENTILATION_volume_ge(
          const struct VENTILATION_Volume*   lhs
        , const struct VENTILATION_Volume*   rhs
        , VENTILATION_error *                   error
        )
{
    if ((nullptr == lhs) or (nullptr == rhs)) {
        *error = VENTILATION_ERROR_NULL;
        return VENTILATION_FALSE;
    } else {
        return VENTILATION_BOOL((lhs->value >= rhs->value));
    }
}

VENTILATION_bool
VENTILATION_volume_lt(
          const struct VENTILATION_Volume*   lhs
        , const struct VENTILATION_Volume*   rhs
        , VENTILATION_error *                   error
        )
{
    if ((nullptr == lhs) or (nullptr == rhs)) {
        *error = VENTILATION_ERROR_NULL;
        return VENTILATION_FALSE;
    } else {
        return VENTILATION_BOOL((lhs->value < rhs->value));
    }
}

VENTILATION_bool
VENTILATION_volume_le(
          const struct VENTILATION_Volume*  lhs
        , const struct VENTILATION_Volume*  rhs
        , VENTILATION_error *               error
        )
{
    if ((nullptr == lhs) or (nullptr == rhs)) {
        *error = VENTILATION_ERROR_NULL;
        return VENTILATION_FALSE;
    } else {
        return VENTILATION_BOOL((lhs->value <= rhs->value));
    }
}
