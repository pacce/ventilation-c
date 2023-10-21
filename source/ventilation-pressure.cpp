#include "ventilation-pressure.h"

#include "ventilation/ventilation.h"
#include "ventilation-utilities.h"

struct VENTILATION_Pressure *
VENTILATION_pressure_create(const float value, VENTILATION_error * error) {
    *error = VENTILATION_ERROR_OK;

    VENTILATION_Pressure * context = new VENTILATION_Pressure(value);
    return context;
}

void
VENTILATION_pressure_delete(struct VENTILATION_Pressure * context, VENTILATION_error * error) {
    if (nullptr == context) {
        *error = VENTILATION_ERROR_NULL;
    } else {
        *error = VENTILATION_ERROR_OK;
        delete context;
    }
}

float
VENTILATION_pressure_value(const struct VENTILATION_Pressure * context, VENTILATION_error * error) {
    *error = VENTILATION_ERROR_OK;
    return static_cast<float>(context->value);
}

struct VENTILATION_Pressure *
VENTILATION_pressure_add(
          const struct VENTILATION_Pressure *   lhs
        , const struct VENTILATION_Pressure *   rhs
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
          const struct VENTILATION_Pressure *   lhs
        , const struct VENTILATION_Pressure *   rhs
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
          const struct VENTILATION_Pressure *   lhs
        , const struct VENTILATION_Pressure *   rhs
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
          const struct VENTILATION_Pressure *   lhs
        , const struct VENTILATION_Pressure *   rhs
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
          const struct VENTILATION_Pressure *   lhs
        , const struct VENTILATION_Pressure *   rhs
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
          const struct VENTILATION_Pressure *   lhs
        , const struct VENTILATION_Pressure *   rhs
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
          const struct VENTILATION_Pressure *   lhs
        , const struct VENTILATION_Pressure *   rhs
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
          const struct VENTILATION_Pressure *   lhs
        , const struct VENTILATION_Pressure *   rhs
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
          const struct VENTILATION_Pressure *   lhs
        , const struct VENTILATION_Pressure *   rhs
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

struct VENTILATION_PEEP *
VENTILATION_PEEP_create(const float value, VENTILATION_error * error) {
    *error = VENTILATION_ERROR_OK;

    VENTILATION_PEEP * context = new VENTILATION_PEEP(value);
    return context;
}

void
VENTILATION_PEEP_delete(struct VENTILATION_PEEP * context, VENTILATION_error * error) {
    if (nullptr == context) {
        *error = VENTILATION_ERROR_NULL;
    } else {
        *error = VENTILATION_ERROR_OK;
        delete context;
    }
}

float
VENTILATION_PEEP_value(const struct VENTILATION_PEEP * context, VENTILATION_error * error) {
    *error = VENTILATION_ERROR_OK;
    return static_cast<float>(context->value);
}

struct VENTILATION_PEEP *
VENTILATION_PEEP_add(
          const struct VENTILATION_PEEP *   lhs
        , const struct VENTILATION_PEEP *   rhs
        , VENTILATION_error *               error
        )
{
    if ((nullptr == lhs) or (nullptr == rhs)) {
        *error = VENTILATION_ERROR_NULL;
        return nullptr;
    } else {
        return new VENTILATION_PEEP(lhs->value + rhs->value);
    }
}

struct VENTILATION_PEEP *
VENTILATION_PEEP_sub(
          const struct VENTILATION_PEEP *   lhs
        , const struct VENTILATION_PEEP *   rhs
        , VENTILATION_error *               error
        )
{
    if ((nullptr == lhs) or (nullptr == rhs)) {
        *error = VENTILATION_ERROR_NULL;
        return nullptr;
    } else {
        return new VENTILATION_PEEP(lhs->value - rhs->value);
    }
}

struct VENTILATION_PEEP *
VENTILATION_PEEP_mul(
          const struct VENTILATION_PEEP *   lhs
        , const struct VENTILATION_PEEP *   rhs
        , VENTILATION_error *                   error
        )
{
    if ((nullptr == lhs) or (nullptr == rhs)) {
        *error = VENTILATION_ERROR_NULL;
        return nullptr;
    } else {
        return new VENTILATION_PEEP(lhs->value * rhs->value);
    }
}

VENTILATION_bool
VENTILATION_PEEP_eq(
          const struct VENTILATION_PEEP *   lhs
        , const struct VENTILATION_PEEP *   rhs
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
VENTILATION_PEEP_neq(
          const struct VENTILATION_PEEP *   lhs
        , const struct VENTILATION_PEEP *   rhs
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
VENTILATION_PEEP_gt(
          const struct VENTILATION_PEEP *   lhs
        , const struct VENTILATION_PEEP *   rhs
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
VENTILATION_PEEP_ge(
          const struct VENTILATION_PEEP *   lhs
        , const struct VENTILATION_PEEP *   rhs
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
VENTILATION_PEEP_lt(
          const struct VENTILATION_PEEP *   lhs
        , const struct VENTILATION_PEEP *   rhs
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
VENTILATION_PEEP_le(
          const struct VENTILATION_PEEP *   lhs
        , const struct VENTILATION_PEEP *   rhs
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
