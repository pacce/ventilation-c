#include <ventilation/ventilation.h>

#include <cassert>
#include <cstddef>
#include <cstdio>

const float ELASTANCE   = 1000.0f / 30.0f;
const float RESISTANCE  = 50.0f;

int
main(int, char**) {
    VENTILATION_error error = VENTILATION_ERROR_OK;
    struct VENTILATION_Lung * lung              = VENTILATION_lung_create(ELASTANCE, RESISTANCE, &error);
    assert((error == VENTILATION_ERROR_OK));

    struct VENTILATION_Cycle * cycle = VENTILATION_cycle_create(0.5f, 0.5f, 1.0f, &error);
    assert((error == VENTILATION_ERROR_OK));

    struct VENTILATION_Ventilator * ventilator = VENTILATION_ventilator_pcv(cycle, &error);
    assert((error == VENTILATION_ERROR_OK));

    for (std::size_t i = 0; i < 200000; i++) {
        struct VENTILATION_Packet * packet = VENTILATION_ventilator_control(ventilator, lung, &error);
        assert((error == VENTILATION_ERROR_OK));

        VENTILATION_Pressure * pressure = VENTILATION_packet_pressure(packet, &error);
        VENTILATION_Flow * flow         = VENTILATION_packet_flow(packet, &error);
        VENTILATION_Volume * volume     = VENTILATION_packet_volume(packet, &error);

        std::printf("%f, %f, %f\n"
                , VENTILATION_pressure_value(pressure, &error)
                , VENTILATION_flow_value(flow, &error)
                , VENTILATION_volume_value(volume, &error)
                );

        VENTILATION_pressure_delete(pressure, &error);
        VENTILATION_flow_delete(flow, &error);
        VENTILATION_volume_delete(volume, &error);

        VENTILATION_packet_delete(packet, &error);
        assert((error == VENTILATION_ERROR_OK));
    }

    VENTILATION_cycle_delete(cycle, &error);
    assert((error == VENTILATION_ERROR_OK));

    VENTILATION_ventilator_delete(ventilator, &error);
    assert((error == VENTILATION_ERROR_OK));

    return 0;
}
