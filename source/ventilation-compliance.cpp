#include "ventilation-compliance.h"

#include "ventilation/ventilation.h"
#include "ventilation-utilities.h"

struct VENTILATION_Compliance *
VENTILATION_compliance_create(const float value, VENTILATION_error * error) {
    *error = VENTILATION_ERROR_OK;

    VENTILATION_Compliance * context = new VENTILATION_Compliance(value);
    return context;
}

void
VENTILATION_compliance_delete(struct VENTILATION_Compliance * context, VENTILATION_error * error) {
    if (nullptr == context) {
        *error = VENTILATION_ERROR_NULL;
    } else {
        *error = VENTILATION_ERROR_OK;
        delete context;
    }
}

float
VENTILATION_compliance_value(const struct VENTILATION_Compliance * context, VENTILATION_error * error) {
    *error = VENTILATION_ERROR_OK;
    return static_cast<float>(context->value);
}

struct VENTILATION_Compliance *
VENTILATION_compliance_add(
          const struct VENTILATION_Compliance * lhs
        , const struct VENTILATION_Compliance * rhs
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
          const struct VENTILATION_Compliance * lhs
        , const struct VENTILATION_Compliance * rhs
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
          const struct VENTILATION_Compliance * lhs
        , const struct VENTILATION_Compliance * rhs
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
          const struct VENTILATION_Compliance * lhs
        , const struct VENTILATION_Compliance * rhs
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
          const struct VENTILATION_Compliance * lhs
        , const struct VENTILATION_Compliance * rhs
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
          const struct VENTILATION_Compliance * lhs
        , const struct VENTILATION_Compliance * rhs
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
          const struct VENTILATION_Compliance * lhs
        , const struct VENTILATION_Compliance * rhs
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
          const struct VENTILATION_Compliance * lhs
        , const struct VENTILATION_Compliance * rhs
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
          const struct VENTILATION_Compliance * lhs
        , const struct VENTILATION_Compliance * rhs
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

