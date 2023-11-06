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
          const struct VENTILATION_Frequency *  frequency
        , const struct VENTILATION_Ratio *      ratio
        , VENTILATION_error *                   error
        ) 
{
    *error = VENTILATION_ERROR_OK;
    return new VENTILATION_Cycle(frequency->value, ratio->value);
}

struct VENTILATION_Cycle *
VENTILATION_cycle_time(
          VENTILATION_Time      inspiratory_time
        , VENTILATION_Time      inspiratory_pause
        , VENTILATION_Time      expiratory_time
        , VENTILATION_Time      expiratory_pause
        , VENTILATION_error * error
        )
{
    using Time  = ventilation::Time<float>;
    using Pause = std::optional<Time>;

    *error = VENTILATION_ERROR_OK;

    Time i      = Time(inspiratory_time);
    Pause fst   = {};
    Time e      = Time(expiratory_time);
    Pause snd   = {};

    if (inspiratory_pause > 0.0f)   { fst = Pause(inspiratory_pause); }
    if (expiratory_pause > 0.0f)    { snd = Pause(expiratory_pause); }

    return new VENTILATION_Cycle(i, fst, e, snd);
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

