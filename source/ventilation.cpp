#include "ventilation/ventilation.h"

#include <stddef.h>
#include <ventilation/ventilation.hpp>

#include "ventilation-compliance.h"
#include "ventilation-elastance.h"
#include "ventilation-resistance.h"

#include "ventilation-flow.h"
#include "ventilation-pressure.h"
#include "ventilation-volume.h"
#include "ventilation-packet.h"

#include "ventilation-lung.h"
#include "ventilation-cycle.h"

#include "ventilation-utilities.h"

/*
 * Sets ventilation templates types to float precision
 */
using Packet    = ventilation::Packet<float>;
using PCV       = ventilation::modes::PCV<float>;
using VCV       = ventilation::modes::VCV<float>;
using Modes     = ventilation::Modes<float>;
using Time      = ventilation::Time<float>;
using Control   = ventilation::modes::visitor::Control<float>;

using namespace std::chrono_literals;
const Time RESOLUTION = 100us;

struct VENTILATION_Ventilator {
    Modes   mode;
    Time    resolution;
};

struct VENTILATION_Ventilator *
VENTILATION_ventilator_pcv(
          const struct VENTILATION_Cycle *          cycle
        , const struct VENTILATION_PEEP *           peep
        , const struct VENTILATION_Pressure_Peak *  peak
        , VENTILATION_error *                       error
        )
{
    *error = VENTILATION_ERROR_OK;

    Modes ventilator = PCV(peep->value, peak->value, cycle->value);
    return new VENTILATION_Ventilator(ventilator, RESOLUTION);
}

struct VENTILATION_Ventilator *
VENTILATION_ventilator_vcv(
          const struct VENTILATION_Cycle *          cycle
        , const struct VENTILATION_PEEP *           peep
        , const struct VENTILATION_Tidal_Volume *   tidal
        , VENTILATION_error *                       error
        )
{
    *error = VENTILATION_ERROR_OK;

    Modes ventilator = VCV(peep->value, tidal->value, cycle->value);
    return new VENTILATION_Ventilator(ventilator, RESOLUTION);
}

void
VENTILATION_ventilator_set_resolution(
          struct VENTILATION_Ventilator *   context
        , VENTILATION_Time                  resolution
        , VENTILATION_error *               error
        )
{
    if (nullptr == context) {
        *error = VENTILATION_ERROR_NULL;
    } else {
        *error = VENTILATION_ERROR_OK;
        context->resolution = Time(resolution);
    }
}

struct VENTILATION_Packet *
VENTILATION_ventilator_control(
          struct VENTILATION_Ventilator *   context
        , const struct VENTILATION_Lung *   lung
        , VENTILATION_Time                  step
        , VENTILATION_error *               error
        )
{
    *error = VENTILATION_ERROR_OK;

    if (nullptr == context) {
        *error = VENTILATION_ERROR_NULL;
        return nullptr;
    } else {
        Time current            = 0s;
        const Time total        = Time(step);
        const Time& resolution  = context->resolution;

        Control control{lung->value, resolution};
        std::vector<Packet> ps;
        while (current <= total) {
            current += resolution;
            ps.push_back(std::visit(control, context->mode));
        }
        return new VENTILATION_Packet(ventilation::mean(ps));
    }
}

void
VENTILATION_ventilator_delete(struct VENTILATION_Ventilator * context, VENTILATION_error * error) {
    if (nullptr == context) {
        *error = VENTILATION_ERROR_NULL;
    } else {
        *error = VENTILATION_ERROR_OK;
        delete context;
    }
}

void
VENTILATION_ventilator_set_peep(
          struct VENTILATION_Ventilator *   context
        , const struct VENTILATION_PEEP *   peep
        , VENTILATION_error *               error
        )
{

    if ((nullptr == context) or (nullptr == peep)) {
        *error = VENTILATION_ERROR_NULL;
    } else {
        *error = VENTILATION_ERROR_OK;
        std::visit(ventilation::modes::setter::PEEP<float>(peep->value), context->mode);
    }
}

void
VENTILATION_ventilator_set_pressure_peak(
          struct VENTILATION_Ventilator *       context
        , struct VENTILATION_Pressure_Peak *    peak
        , VENTILATION_error *                   error
        )
{
    if ((nullptr == context) or (nullptr == peak)) {
        *error = VENTILATION_ERROR_NULL;
    } else {
        *error = VENTILATION_ERROR_OK;
        std::visit(ventilation::modes::setter::Peak<float>(peak->value), context->mode);
    }
}

void
VENTILATION_ventilator_set_tidal_volume(
          struct VENTILATION_Ventilator *   context
        , struct VENTILATION_Tidal_Volume * tidal
        , VENTILATION_error *               error
        )
{
    if ((nullptr == context) or (nullptr == tidal)) {
        *error = VENTILATION_ERROR_NULL;
    } else {
        *error = VENTILATION_ERROR_OK;
        std::visit(ventilation::modes::setter::Tidal<float>(tidal->value), context->mode);
    }
}


void
VENTILATION_ventilator_set_cycle(
          struct VENTILATION_Ventilator *   context
        , struct VENTILATION_Cycle *        cycle
        , VENTILATION_error *               error
        )
{
    if ((nullptr == context) or (nullptr == cycle)) {
        *error = VENTILATION_ERROR_NULL;
    } else {
        *error = VENTILATION_ERROR_OK;
        std::visit(ventilation::modes::setter::Cycle<float>(cycle->value), context->mode);
    }
}
