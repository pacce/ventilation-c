#include "ventilation-resistance.h"

#include "ventilation/ventilation.h"
#include "ventilation-utilities.h"

struct VENTILATION_Resistance *
VENTILATION_resistance_create(const float value, VENTILATION_error * error) {
    *error = VENTILATION_ERROR_OK;

    VENTILATION_Resistance * context = new VENTILATION_Resistance(value);
    return context;
}

void
VENTILATION_resistance_delete(struct VENTILATION_Resistance * context, VENTILATION_error * error) {
    if (nullptr == context) {
        *error = VENTILATION_ERROR_NULL;
    } else {
        *error = VENTILATION_ERROR_OK;
        delete context;
    }
}

float
VENTILATION_resistance_value(const struct VENTILATION_Resistance * context, VENTILATION_error * error) {
    *error = VENTILATION_ERROR_OK;
    return static_cast<float>(context->value);
}

struct VENTILATION_Resistance *
VENTILATION_resistance_add(
          const struct VENTILATION_Resistance * lhs
        , const struct VENTILATION_Resistance * rhs
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
          const struct VENTILATION_Resistance * lhs
        , const struct VENTILATION_Resistance * rhs
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
          const struct VENTILATION_Resistance * lhs
        , const struct VENTILATION_Resistance * rhs
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
          const struct VENTILATION_Resistance * lhs
        , const struct VENTILATION_Resistance * rhs
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
          const struct VENTILATION_Resistance * lhs
        , const struct VENTILATION_Resistance * rhs
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
          const struct VENTILATION_Resistance * lhs
        , const struct VENTILATION_Resistance * rhs
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
          const struct VENTILATION_Resistance * lhs
        , const struct VENTILATION_Resistance * rhs
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
          const struct VENTILATION_Resistance * lhs
        , const struct VENTILATION_Resistance * rhs
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
          const struct VENTILATION_Resistance * lhs
        , const struct VENTILATION_Resistance * rhs
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
