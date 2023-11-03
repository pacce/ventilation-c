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
using PCV       = ventilation::modes::PCV<float>;
using VCV       = ventilation::modes::VCV<float>;
using Modes     = ventilation::Modes<float>;
using Control   = ventilation::modes::visitor::Control<float>;

struct VENTILATION_Ventilator {
    Modes mode;
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
    return new VENTILATION_Ventilator(ventilator);
}

struct VENTILATION_Ventilator *
VENTILATION_ventilator_vcv(
          const struct VENTILATION_Cycle *  cycle
        , const struct VENTILATION_PEEP *   peep
        , const struct VENTILATION_Flow *   flow
        , VENTILATION_error *               error
        )
{
    *error = VENTILATION_ERROR_OK;

    Modes ventilator = VCV(peep->value, flow->value, cycle->value);
    return new VENTILATION_Ventilator(ventilator);
}

struct VENTILATION_Packet *
VENTILATION_ventilator_control(
          struct VENTILATION_Ventilator *   context
        , struct VENTILATION_Lung *         lung
        , VENTILATION_error *               error
        )
{
    *error = VENTILATION_ERROR_OK;

    using namespace std::chrono_literals;
    std::chrono::duration<float> step = 100us;

    Control control{lung->value, step};
    ventilation::Packet packet = std::visit(control, context->mode);

    return new VENTILATION_Packet(packet);
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
VENTILATION_ventilator_set_flow(
          struct VENTILATION_Ventilator *   context
        , struct VENTILATION_Flow *         flow
        , VENTILATION_error *               error
        )
{
    if ((nullptr == context) or (nullptr == flow)) {
        *error = VENTILATION_ERROR_NULL;
    } else {
        *error = VENTILATION_ERROR_OK;
        std::visit(ventilation::modes::setter::Flow<float>(flow->value), context->mode);
    }
}
