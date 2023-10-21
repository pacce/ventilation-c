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

struct VENTILATION_Ventilator {
    ventilation::Modes<float> mode;
};

struct VENTILATION_Ventilator *
VENTILATION_ventilator_pcv(
          struct VENTILATION_Cycle *            cycle
        , struct VENTILATION_PEEP *             peep
        , struct VENTILATION_Pressure_Peak *    peak
        , VENTILATION_error *                   error
        ) 
{
    *error = VENTILATION_ERROR_OK;

    ventilation::Modes<float> ventilator = ventilation::modes::PCV<float>(
              peep->value
            , peak->value
            , cycle->value
            );
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

    ventilation::modes::visitor::Control<float> control{lung->value, step};
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
