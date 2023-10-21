#include "ventilation-cycle.h"

#include "ventilation/ventilation.h"
#include "ventilation-utilities.h"

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

