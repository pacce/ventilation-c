#include "ventilation-flow.h"

#include "ventilation/ventilation.h"
#include "ventilation-utilities.h"

struct VENTILATION_Flow *
VENTILATION_flow_create(const float value, VENTILATION_error * error) {
    *error = VENTILATION_ERROR_OK;

    VENTILATION_Flow * context = new VENTILATION_Flow(value);
    return context;
}

void
VENTILATION_flow_delete(struct VENTILATION_Flow * context, VENTILATION_error * error) {
    if (nullptr == context) {
        *error = VENTILATION_ERROR_NULL;
    } else {
        *error = VENTILATION_ERROR_OK;
        delete context;
    }
}

float
VENTILATION_flow_value(const struct VENTILATION_Flow * context, VENTILATION_error * error) {
    *error = VENTILATION_ERROR_OK;
    return static_cast<float>(context->value);
}

struct VENTILATION_Flow *
VENTILATION_flow_add(
          const struct VENTILATION_Flow *   lhs
        , const struct VENTILATION_Flow *   rhs
        , VENTILATION_error *               error
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
          const struct VENTILATION_Flow *   lhs
        , const struct VENTILATION_Flow *   rhs
        , VENTILATION_error *               error
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
          const struct VENTILATION_Flow *   lhs
        , const struct VENTILATION_Flow *   rhs
        , VENTILATION_error *               error
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
          const struct VENTILATION_Flow *   lhs
        , const struct VENTILATION_Flow *   rhs
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
VENTILATION_flow_neq(
          const struct VENTILATION_Flow *   lhs
        , const struct VENTILATION_Flow *   rhs
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
VENTILATION_flow_gt(
          const struct VENTILATION_Flow *   lhs
        , const struct VENTILATION_Flow *   rhs
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
VENTILATION_flow_ge(
          const struct VENTILATION_Flow *   lhs
        , const struct VENTILATION_Flow *   rhs
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
VENTILATION_flow_lt(
          const struct VENTILATION_Flow *   lhs
        , const struct VENTILATION_Flow *   rhs
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
VENTILATION_flow_le(
          const struct VENTILATION_Flow *   lhs
        , const struct VENTILATION_Flow *   rhs
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
