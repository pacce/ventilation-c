#include <ventilation/ventilation.h>

#include <cassert>
#include <cstddef>
#include <cstdio>

const float ELASTANCE   = 1000.0f / 30.0f;
const float RESISTANCE  = 50.0f;

int
main(int, char**) {
    VENTILATION_error error = VENTILATION_ERROR_OK;

    VENTILATION_Elastance * elastance   = VENTILATION_elastance_create(ELASTANCE, &error);
    VENTILATION_Resistance * resistance = VENTILATION_resistance_create(RESISTANCE, &error);
    struct VENTILATION_Lung * lung      = VENTILATION_lung_create(resistance, elastance, &error);
    assert((error == VENTILATION_ERROR_OK));

    struct VENTILATION_Frequency * frequency    = VENTILATION_frequency_bpm(30.0f, &error);
    struct VENTILATION_Ratio * ratio            = VENTILATION_ratio_create(0.5f, 1.0f, &error);
    struct VENTILATION_Cycle * cycle            = VENTILATION_cycle_create(frequency, ratio, &error);
    assert((error == VENTILATION_ERROR_OK));

    struct VENTILATION_PEEP * peep              = VENTILATION_peep_create(5.0f, &error);
    struct VENTILATION_Pressure_Peak * peak     = VENTILATION_pressure_peak_create(20.0f, &error);
    struct VENTILATION_Ventilator * ventilator  = VENTILATION_ventilator_pcv(cycle, peep, peak, &error);
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

    VENTILATION_peep_delete(peep, &error);
    VENTILATION_pressure_peak_delete(peak, &error);
    VENTILATION_ventilator_delete(ventilator, &error);

    VENTILATION_frequency_delete(frequency, &error);
    VENTILATION_ratio_delete(ratio, &error);
    VENTILATION_cycle_delete(cycle, &error);

    VENTILATION_lung_delete(lung, &error);

    VENTILATION_elastance_delete(elastance, &error);
    VENTILATION_resistance_delete(resistance, &error);
    return 0;
}
