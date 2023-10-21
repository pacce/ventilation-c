#include "ventilation-elastance.h"

#include "ventilation/ventilation.h"
#include "ventilation-utilities.h"

struct VENTILATION_Elastance *
VENTILATION_elastance_create(const float value, VENTILATION_error * error) {
    *error = VENTILATION_ERROR_OK;

    VENTILATION_Elastance * context = new VENTILATION_Elastance(value);
    return context;
}

void
VENTILATION_elastance_delete(struct VENTILATION_Elastance * context, VENTILATION_error * error) {
    if (nullptr == context) {
        *error = VENTILATION_ERROR_NULL;
    } else {
        *error = VENTILATION_ERROR_OK;
        delete context;
    }
}

float
VENTILATION_elastance_value(const struct VENTILATION_Elastance * context, VENTILATION_error * error) {
    *error = VENTILATION_ERROR_OK;
    return static_cast<float>(context->value);
}

struct VENTILATION_Elastance *
VENTILATION_elastance_add(
          const struct VENTILATION_Elastance *  lhs
        , const struct VENTILATION_Elastance *  rhs
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
          const struct VENTILATION_Elastance *  lhs
        , const struct VENTILATION_Elastance *  rhs
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
          const struct VENTILATION_Elastance *  lhs
        , const struct VENTILATION_Elastance *  rhs
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
          const struct VENTILATION_Elastance *  lhs
        , const struct VENTILATION_Elastance *  rhs
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
          const struct VENTILATION_Elastance *  lhs
        , const struct VENTILATION_Elastance *  rhs
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
          const struct VENTILATION_Elastance *  lhs
        , const struct VENTILATION_Elastance *  rhs
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
          const struct VENTILATION_Elastance *  lhs
        , const struct VENTILATION_Elastance *  rhs
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
          const struct VENTILATION_Elastance *  lhs
        , const struct VENTILATION_Elastance *  rhs
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
          const struct VENTILATION_Elastance *  lhs
        , const struct VENTILATION_Elastance *  rhs
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
