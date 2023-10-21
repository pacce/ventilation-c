#include "ventilation/ventilation.h"
#include "ventilation-volume.h"
#include "ventilation-utilities.h"

struct VENTILATION_Volume *
VENTILATION_volume_create(const float value, VENTILATION_error * error) {
    *error = VENTILATION_ERROR_OK;

    VENTILATION_Volume * context = new VENTILATION_Volume(value);
    return context;
}

void
VENTILATION_volume_delete(struct VENTILATION_Volume * context, VENTILATION_error * error) {
    if (nullptr == context) {
        *error = VENTILATION_ERROR_NULL;
    } else {
        *error = VENTILATION_ERROR_OK;
        delete context;
    }
}

float
VENTILATION_volume_value(const struct VENTILATION_Volume * context, VENTILATION_error * error) {
    *error = VENTILATION_ERROR_OK;
    return static_cast<float>(context->value);
}

struct VENTILATION_Volume *
VENTILATION_volume_add(
          const struct VENTILATION_Volume * lhs
        , const struct VENTILATION_Volume * rhs
        , VENTILATION_error *               error
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
          const struct VENTILATION_Volume * lhs
        , const struct VENTILATION_Volume * rhs
        , VENTILATION_error *               error
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
          const struct VENTILATION_Volume * lhs
        , const struct VENTILATION_Volume * rhs
        , VENTILATION_error *               error
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
          const struct VENTILATION_Volume * lhs
        , const struct VENTILATION_Volume * rhs
        , VENTILATION_error *               error
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
          const struct VENTILATION_Volume * lhs
        , const struct VENTILATION_Volume * rhs
        , VENTILATION_error *               error
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
          const struct VENTILATION_Volume * lhs
        , const struct VENTILATION_Volume * rhs
        , VENTILATION_error *               error
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
          const struct VENTILATION_Volume * lhs
        , const struct VENTILATION_Volume * rhs
        , VENTILATION_error *               error
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
          const struct VENTILATION_Volume * lhs
        , const struct VENTILATION_Volume * rhs
        , VENTILATION_error *               error
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
          const struct VENTILATION_Volume * lhs
        , const struct VENTILATION_Volume * rhs
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
