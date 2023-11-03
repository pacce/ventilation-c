#ifndef VENTILATION_H__
#define VENTILATION_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef uint8_t VENTILATION_bool;
#define VENTILATION_FALSE   0
#define VENTILATION_TRUE    1
#define VENTILATION_BOOL(value) ((value) ? VENTILATION_TRUE : VENTILATION_FALSE)

typedef int32_t VENTILATION_error;
#define VENTILATION_ERROR_OK        0
#define VENTILATION_ERROR_GENERIC  -1
#define VENTILATION_ERROR_NULL     -2

/*
 * VENTILATION_Compliance is an opaque structure that handles Compliance values.
 * VENTILATION_Elastance is an opaque structure that handles Elastance values.
 * VENTILATION_Resistance is an opaque structure that handles Resistance values.
 *
 * Compliance values are expressed in L.(cmH2O^-1)
 * Elastance values are expressed in cmH2O.L^-1
 * Resistance values are expressed in cmH2O.s.L^-1
 */
struct VENTILATION_Compliance;
struct VENTILATION_Elastance;
struct VENTILATION_Resistance;

/*
 * VENTILATION_Flow is an opaque structure that handles Flow values.
 * VENTILATION_Volume is an opaque structure that handles Volume values.
 * VENTILATION_Pressure is an opaque structure that handles Pressure values.
 *
 * Flow values are expressed in L/s
 * Volume values are expressed in L
 * Pressure values are expressed in cmH2O
 *
 * Ventilation_PEEP is an opaque structure that handles Positive End Expiratory Pressure
 * VENTILATION_Pressure_Peak is an opaque that handles the Peak Pressure
 *
 * Both parameters are expressed in cmH2O
 */
struct VENTILATION_Flow;
struct VENTILATION_Volume;
struct VENTILATION_Pressure;
struct VENTILATION_PEEP;
struct VENTILATION_Pressure_Peak;

/*
 * VENTILATION_Packet is an opaque structure that handles ventilation::Packet
 * Packets store Pressure, Flow and Volume
 */
struct VENTILATION_Packet;
/*
 * VENTILATION_Lung is an opaque structure that handles ventilation::forward::Lung
 * Lung is a linear forward model of the lung mechanics, under the hood it implements the
 * movement equation, as follows:
 *
 * P = E * V + R * F + PEEP
 *
 * Where:
 *  - E     : Single compartment lung elastance
 *  - R     : Single compartment lung resistance
 *  - P     : Airway pressure
 *  - F     : Flow
 *  - V     : Volume (obtained via integration)
 *  - PEEP  : Positive End Expiratory Pressure
 */
struct VENTILATION_Lung;

/*
 * VENTILATION_Frequency is an opaque structure that handles the ventilator excitation frequency
 * VENTILATION_Ratio is an opaque structure that stores the inspiratory and expiratory ratio
 * VENTILATION_Cycle is an opaque structure that stores the ventilation setup in cycle-wise fashion
 *
 * Frequency is stored in hertz, that is, the number of respiratory cycles over one second
 * Ratio is the i:e ratio, that is, a 1:3 ratio, for instance, designates that 25% of the cycle
 * is inspiration while the remaining 75% is expiration.
 */
struct VENTILATION_Frequency;
struct VENTILATION_Ratio;
struct VENTILATION_Cycle;
/*
 * VENTILATION_Ventilator is an opaque structure that stores the ventilation mode and control.
 * It stores two types of ventilation modes:
 *  - Volume Controlled Ventilation (VCV)
 *  - Pressure Controlled Ventilation (PCV)
 */
struct VENTILATION_Ventilator;

/*
 * Given a float, converts it to the internal opaque struct representation
 */
struct VENTILATION_Compliance *
VENTILATION_compliance_create(const float, VENTILATION_error*);
/*
 * Deallocates the opaque struct allocated using VENTILATION_compliance_create
 * Notice that if a null pointer is passed, error will be set to VENTILATION_ERROR_NULL
 */
void
VENTILATION_compliance_delete(struct VENTILATION_Compliance*, VENTILATION_error*);
/*
 * Retrives the float stored in the opaque struct
 * Notice that if a null pointer is passed, error will be set to VENTILATION_ERROR_NULL
 */
float
VENTILATION_compliance_value(const struct VENTILATION_Compliance*, VENTILATION_error*);
/*
 * Adds two compliance values: lhs and rhs
 * Notice that if either lhs or rhs are null, error will be set to VENTILATION_ERROR_NULL
 * and the return will be a null pointer
 */
struct VENTILATION_Compliance *
VENTILATION_compliance_add(
          const struct VENTILATION_Compliance*
        , const struct VENTILATION_Compliance*
        , VENTILATION_error*
        );
/*
 * Subtract two compliance values: lhs and rhs
 * Notice that if either lhs or rhs are null, error will be set to VENTILATION_ERROR_NULL
 * and the return will be a null pointer
 */
struct VENTILATION_Compliance *
VENTILATION_compliance_sub(
          const struct VENTILATION_Compliance*
        , const struct VENTILATION_Compliance*
        , VENTILATION_error*
        );
/*
 * Multiplies two compliance values: lhs and rhs
 * Notice that if either lhs or rhs are null, error will be set to VENTILATION_ERROR_NULL
 * and the return will be a null pointer
 */
struct VENTILATION_Compliance *
VENTILATION_compliance_mul(
          const struct VENTILATION_Compliance*
        , const struct VENTILATION_Compliance*
        , VENTILATION_error*
        );
/*
 * Checks whether two compliance values, lhs and rhs, are equal
 * Notice that if either lhs or rhs are null, error will be set to VENTILATION_ERROR_NULL
 * and the return will be false
 *
 * The precision is 0.1, that is:
 * 10.00 and 10.09 are considered equal
 * 10.00 and 10.10 are considered unequal
 */
VENTILATION_bool
VENTILATION_compliance_eq(
          const struct VENTILATION_Compliance*
        , const struct VENTILATION_Compliance*
        , VENTILATION_error*
        );

VENTILATION_bool
VENTILATION_compliance_neq(
          const struct VENTILATION_Compliance*
        , const struct VENTILATION_Compliance*
        , VENTILATION_error*
        );
/*
 * The precision is 0.1, that is:
 * 10.10 is considered greater than 10.00,
 * while 10.00 and 10.09 are considered equal
 */
VENTILATION_bool
VENTILATION_compliance_gt(
          const struct VENTILATION_Compliance*
        , const struct VENTILATION_Compliance*
        , VENTILATION_error*
        );
/*
 * The precision is 0.1, that is:
 * 10.10 is considered greater than 10.00,
 * while 10.00 and 10.09 are considered equal
 */
VENTILATION_bool
VENTILATION_compliance_ge(
          const struct VENTILATION_Compliance*
        , const struct VENTILATION_Compliance*
        , VENTILATION_error*
        );
/*
 * The precision is 0.1, that is:
 * 10.00 is considered smaller than 10.10,
 * while 10.00 and 10.09 are considered equal
 */
VENTILATION_bool
VENTILATION_compliance_lt(
          const struct VENTILATION_Compliance*
        , const struct VENTILATION_Compliance*
        , VENTILATION_error*
        );
/*
 * The precision is 0.1, that is:
 * 10.00 is considered smaller than 10.10,
 * while 10.00 and 10.09 are considered equal
 */
VENTILATION_bool
VENTILATION_compliance_le(
          const struct VENTILATION_Compliance*
        , const struct VENTILATION_Compliance*
        , VENTILATION_error*
        );

struct VENTILATION_Elastance *
VENTILATION_elastance_create(const float, VENTILATION_error*);

void
VENTILATION_elastance_delete(struct VENTILATION_Elastance*, VENTILATION_error*);

float
VENTILATION_elastance_value(const struct VENTILATION_Elastance*, VENTILATION_error*);

struct VENTILATION_Elastance *
VENTILATION_elastance_add(
          const struct VENTILATION_Elastance*
        , const struct VENTILATION_Elastance*
        , VENTILATION_error*
        );

struct VENTILATION_Elastance *
VENTILATION_elastance_sub(
          const struct VENTILATION_Elastance*
        , const struct VENTILATION_Elastance*
        , VENTILATION_error*
        );

struct VENTILATION_Elastance *
VENTILATION_elastance_mul(
          const struct VENTILATION_Elastance*
        , const struct VENTILATION_Elastance*
        , VENTILATION_error*
        );


VENTILATION_bool
VENTILATION_elastance_eq(
          const struct VENTILATION_Elastance*
        , const struct VENTILATION_Elastance*
        , VENTILATION_error*
        );

VENTILATION_bool
VENTILATION_elastance_neq(
          const struct VENTILATION_Elastance*
        , const struct VENTILATION_Elastance*
        , VENTILATION_error*
        );

VENTILATION_bool
VENTILATION_elastance_gt(
          const struct VENTILATION_Elastance*
        , const struct VENTILATION_Elastance*
        , VENTILATION_error*
        );

VENTILATION_bool
VENTILATION_elastance_ge(
          const struct VENTILATION_Elastance*
        , const struct VENTILATION_Elastance*
        , VENTILATION_error*
        );

VENTILATION_bool
VENTILATION_elastance_lt(
          const struct VENTILATION_Elastance*
        , const struct VENTILATION_Elastance*
        , VENTILATION_error*
        );

VENTILATION_bool
VENTILATION_elastance_le(
          const struct VENTILATION_Elastance*
        , const struct VENTILATION_Elastance*
        , VENTILATION_error*
        );

struct VENTILATION_Resistance *
VENTILATION_resistance_create(const float, VENTILATION_error*);

void
VENTILATION_resistance_delete(struct VENTILATION_Resistance*, VENTILATION_error*);

float
VENTILATION_resistance_value(const struct VENTILATION_Resistance*, VENTILATION_error*);

struct VENTILATION_Resistance *
VENTILATION_resistance_add(
          const struct VENTILATION_Resistance*
        , const struct VENTILATION_Resistance*
        , VENTILATION_error*
        );

struct VENTILATION_Resistance *
VENTILATION_resistance_sub(
          const struct VENTILATION_Resistance*
        , const struct VENTILATION_Resistance*
        , VENTILATION_error*
        );

struct VENTILATION_Resistance *
VENTILATION_resistance_mul(
          const struct VENTILATION_Resistance*
        , const struct VENTILATION_Resistance*
        , VENTILATION_error*
        );


VENTILATION_bool
VENTILATION_resistance_eq(
          const struct VENTILATION_Resistance*
        , const struct VENTILATION_Resistance*
        , VENTILATION_error*
        );

VENTILATION_bool
VENTILATION_resistance_neq(
          const struct VENTILATION_Resistance*
        , const struct VENTILATION_Resistance*
        , VENTILATION_error*
        );

VENTILATION_bool
VENTILATION_resistance_gt(
          const struct VENTILATION_Resistance*
        , const struct VENTILATION_Resistance*
        , VENTILATION_error*
        );

VENTILATION_bool
VENTILATION_resistance_ge(
          const struct VENTILATION_Resistance*
        , const struct VENTILATION_Resistance*
        , VENTILATION_error*
        );

VENTILATION_bool
VENTILATION_resistance_lt(
          const struct VENTILATION_Resistance*
        , const struct VENTILATION_Resistance*
        , VENTILATION_error*
        );

VENTILATION_bool
VENTILATION_resistance_le(
          const struct VENTILATION_Resistance*
        , const struct VENTILATION_Resistance*
        , VENTILATION_error*
        );

struct VENTILATION_Flow *
VENTILATION_flow_create(const float, VENTILATION_error*);

void
VENTILATION_flow_delete(struct VENTILATION_Flow*, VENTILATION_error*);

float
VENTILATION_flow_value(const struct VENTILATION_Flow*, VENTILATION_error*);

struct VENTILATION_Flow *
VENTILATION_flow_add(
          const struct VENTILATION_Flow*
        , const struct VENTILATION_Flow*
        , VENTILATION_error*
        );

struct VENTILATION_Flow *
VENTILATION_flow_sub(
          const struct VENTILATION_Flow*
        , const struct VENTILATION_Flow*
        , VENTILATION_error*
        );

struct VENTILATION_Flow *
VENTILATION_flow_mul(
          const struct VENTILATION_Flow*
        , const struct VENTILATION_Flow*
        , VENTILATION_error*
        );


VENTILATION_bool
VENTILATION_flow_eq(
          const struct VENTILATION_Flow*
        , const struct VENTILATION_Flow*
        , VENTILATION_error*
        );

VENTILATION_bool
VENTILATION_flow_neq(
          const struct VENTILATION_Flow*
        , const struct VENTILATION_Flow*
        , VENTILATION_error*
        );

VENTILATION_bool
VENTILATION_flow_gt(
          const struct VENTILATION_Flow*
        , const struct VENTILATION_Flow*
        , VENTILATION_error*
        );

VENTILATION_bool
VENTILATION_flow_ge(
          const struct VENTILATION_Flow*
        , const struct VENTILATION_Flow*
        , VENTILATION_error*
        );

VENTILATION_bool
VENTILATION_flow_lt(
          const struct VENTILATION_Flow*
        , const struct VENTILATION_Flow*
        , VENTILATION_error*
        );

VENTILATION_bool
VENTILATION_flow_le(
          const struct VENTILATION_Flow*
        , const struct VENTILATION_Flow*
        , VENTILATION_error*
        );

struct VENTILATION_Pressure *
VENTILATION_pressure_create(const float, VENTILATION_error*);

void
VENTILATION_pressure_delete(struct VENTILATION_Pressure*, VENTILATION_error*);

float
VENTILATION_pressure_value(const struct VENTILATION_Pressure*, VENTILATION_error*);

struct VENTILATION_Pressure *
VENTILATION_pressure_add(
          const struct VENTILATION_Pressure*
        , const struct VENTILATION_Pressure*
        , VENTILATION_error*
        );

struct VENTILATION_Pressure *
VENTILATION_pressure_sub(
          const struct VENTILATION_Pressure*
        , const struct VENTILATION_Pressure*
        , VENTILATION_error*
        );

struct VENTILATION_Pressure *
VENTILATION_pressure_mul(
          const struct VENTILATION_Pressure*
        , const struct VENTILATION_Pressure*
        , VENTILATION_error*
        );


VENTILATION_bool
VENTILATION_pressure_eq(
          const struct VENTILATION_Pressure*
        , const struct VENTILATION_Pressure*
        , VENTILATION_error*
        );

VENTILATION_bool
VENTILATION_pressure_neq(
          const struct VENTILATION_Pressure*
        , const struct VENTILATION_Pressure*
        , VENTILATION_error*
        );

VENTILATION_bool
VENTILATION_pressure_gt(
          const struct VENTILATION_Pressure*
        , const struct VENTILATION_Pressure*
        , VENTILATION_error*
        );

VENTILATION_bool
VENTILATION_pressure_ge(
          const struct VENTILATION_Pressure*
        , const struct VENTILATION_Pressure*
        , VENTILATION_error*
        );

VENTILATION_bool
VENTILATION_pressure_lt(
          const struct VENTILATION_Pressure*
        , const struct VENTILATION_Pressure*
        , VENTILATION_error*
        );

VENTILATION_bool
VENTILATION_pressure_le(
          const struct VENTILATION_Pressure*
        , const struct VENTILATION_Pressure*
        , VENTILATION_error*
        );

struct VENTILATION_PEEP *
VENTILATION_peep_create(const float, VENTILATION_error*);

void
VENTILATION_peep_delete(struct VENTILATION_PEEP*, VENTILATION_error*);

float
VENTILATION_peep_value(const struct VENTILATION_PEEP*, VENTILATION_error*);

struct VENTILATION_PEEP *
VENTILATION_peep_add(
          const struct VENTILATION_PEEP*
        , const struct VENTILATION_PEEP*
        , VENTILATION_error*
        );

struct VENTILATION_PEEP *
VENTILATION_peep_sub(
          const struct VENTILATION_PEEP*
        , const struct VENTILATION_PEEP*
        , VENTILATION_error*
        );

struct VENTILATION_PEEP *
VENTILATION_peep_mul(
          const struct VENTILATION_PEEP*
        , const struct VENTILATION_PEEP*
        , VENTILATION_error*
        );


VENTILATION_bool
VENTILATION_peep_eq(
          const struct VENTILATION_PEEP*
        , const struct VENTILATION_PEEP*
        , VENTILATION_error*
        );

VENTILATION_bool
VENTILATION_peep_neq(
          const struct VENTILATION_PEEP*
        , const struct VENTILATION_PEEP*
        , VENTILATION_error*
        );

VENTILATION_bool
VENTILATION_peep_gt(
          const struct VENTILATION_PEEP*
        , const struct VENTILATION_PEEP*
        , VENTILATION_error*
        );

VENTILATION_bool
VENTILATION_peep_ge(
          const struct VENTILATION_PEEP*
        , const struct VENTILATION_PEEP*
        , VENTILATION_error*
        );

VENTILATION_bool
VENTILATION_peep_lt(
          const struct VENTILATION_PEEP*
        , const struct VENTILATION_PEEP*
        , VENTILATION_error*
        );

VENTILATION_bool
VENTILATION_peep_le(
          const struct VENTILATION_PEEP*
        , const struct VENTILATION_PEEP*
        , VENTILATION_error*
        );

struct VENTILATION_Pressure_Peak *
VENTILATION_pressure_peak_create(const float, VENTILATION_error*);

void
VENTILATION_pressure_peak_delete(struct VENTILATION_Pressure_Peak*, VENTILATION_error*);

float
VENTILATION_pressure_peak_value(const struct VENTILATION_Pressure_Peak*, VENTILATION_error*);

struct VENTILATION_Pressure_Peak *
VENTILATION_pressure_peak_add(
          const struct VENTILATION_Pressure_Peak*
        , const struct VENTILATION_Pressure_Peak*
        , VENTILATION_error*
        );

struct VENTILATION_Pressure_Peak *
VENTILATION_pressure_peak_sub(
          const struct VENTILATION_Pressure_Peak*
        , const struct VENTILATION_Pressure_Peak*
        , VENTILATION_error*
        );

struct VENTILATION_Pressure_Peak *
VENTILATION_pressure_peak_mul(
          const struct VENTILATION_Pressure_Peak*
        , const struct VENTILATION_Pressure_Peak*
        , VENTILATION_error*
        );


VENTILATION_bool
VENTILATION_pressure_peak_eq(
          const struct VENTILATION_Pressure_Peak*
        , const struct VENTILATION_Pressure_Peak*
        , VENTILATION_error*
        );

VENTILATION_bool
VENTILATION_pressure_peak_neq(
          const struct VENTILATION_Pressure_Peak*
        , const struct VENTILATION_Pressure_Peak*
        , VENTILATION_error*
        );

VENTILATION_bool
VENTILATION_pressure_peak_gt(
          const struct VENTILATION_Pressure_Peak*
        , const struct VENTILATION_Pressure_Peak*
        , VENTILATION_error*
        );

VENTILATION_bool
VENTILATION_pressure_peak_ge(
          const struct VENTILATION_Pressure_Peak*
        , const struct VENTILATION_Pressure_Peak*
        , VENTILATION_error*
        );

VENTILATION_bool
VENTILATION_pressure_peak_lt(
          const struct VENTILATION_Pressure_Peak*
        , const struct VENTILATION_Pressure_Peak*
        , VENTILATION_error*
        );

VENTILATION_bool
VENTILATION_pressure_peak_le(
          const struct VENTILATION_Pressure_Peak*
        , const struct VENTILATION_Pressure_Peak*
        , VENTILATION_error*
        );

struct VENTILATION_Volume *
VENTILATION_volume_create(const float, VENTILATION_error*);

void
VENTILATION_volume_delete(struct VENTILATION_Volume*, VENTILATION_error*);

float
VENTILATION_volume_value(const struct VENTILATION_Volume*, VENTILATION_error*);

struct VENTILATION_Volume *
VENTILATION_volume_add(
          const struct VENTILATION_Volume*
        , const struct VENTILATION_Volume*
        , VENTILATION_error*
        );

struct VENTILATION_Volume *
VENTILATION_volume_sub(
          const struct VENTILATION_Volume*
        , const struct VENTILATION_Volume*
        , VENTILATION_error*
        );

struct VENTILATION_Volume *
VENTILATION_volume_mul(
          const struct VENTILATION_Volume*
        , const struct VENTILATION_Volume*
        , VENTILATION_error*
        );


VENTILATION_bool
VENTILATION_volume_eq(
          const struct VENTILATION_Volume*
        , const struct VENTILATION_Volume*
        , VENTILATION_error*
        );

VENTILATION_bool
VENTILATION_volume_neq(
          const struct VENTILATION_Volume*
        , const struct VENTILATION_Volume*
        , VENTILATION_error*
        );

VENTILATION_bool
VENTILATION_volume_gt(
          const struct VENTILATION_Volume*
        , const struct VENTILATION_Volume*
        , VENTILATION_error*
        );

VENTILATION_bool
VENTILATION_volume_ge(
          const struct VENTILATION_Volume*
        , const struct VENTILATION_Volume*
        , VENTILATION_error*
        );

VENTILATION_bool
VENTILATION_volume_lt(
          const struct VENTILATION_Volume*
        , const struct VENTILATION_Volume*
        , VENTILATION_error*
        );

VENTILATION_bool
VENTILATION_volume_le(
          const struct VENTILATION_Volume*
        , const struct VENTILATION_Volume*
        , VENTILATION_error*
        );

struct VENTILATION_Packet *
VENTILATION_packet_create(const float, const float, const float, VENTILATION_error*);

void
VENTILATION_packet_delete(struct VENTILATION_Packet*, VENTILATION_error*);

struct VENTILATION_Pressure *
VENTILATION_packet_pressure(const struct VENTILATION_Packet*, VENTILATION_error*);

struct VENTILATION_Flow *
VENTILATION_packet_flow(const struct VENTILATION_Packet*, VENTILATION_error*);

struct VENTILATION_Volume *
VENTILATION_packet_volume(const struct VENTILATION_Packet*, VENTILATION_error*);

int
VENTILATION_packet_string(const struct VENTILATION_Packet*, char *, int, VENTILATION_error*);

/*
 * Given a pair of Resistance and Elastance, describing the lung mechanics
 * this function allocates a forward lung model opaque structure
 */
struct VENTILATION_Lung *
VENTILATION_lung_create(struct VENTILATION_Resistance *, struct VENTILATION_Elastance *, VENTILATION_error *);
/*
 * Deallocates the opaque struct allocated using VENTILATION_lung_create
 * Notice that if a null pointer is passed, error will be set to VENTILATION_ERROR_NULL
 */
void
VENTILATION_lung_delete(struct VENTILATION_Lung*, VENTILATION_error*);
/*
 * Retrieves the lung elastance from the forward linear model
 */
struct VENTILATION_Elastance *
VENTILATION_lung_elastance(const struct VENTILATION_Lung*, VENTILATION_error*);
/*
 * Retrieves the lung resistance from the forward linear model
 */
struct VENTILATION_Resistance *
VENTILATION_lung_resistance(const struct VENTILATION_Lung*, VENTILATION_error*);
/*
 * Changes the lung elastance in the forward linear model
 */
void
VENTILATION_lung_set_elastance(
          struct VENTILATION_Lung*
        , const VENTILATION_Elastance*
        , VENTILATION_error*
        );
/*
 * Changes the lung resistance in the forward linear model
 */
void
VENTILATION_lung_set_resistance(
          struct VENTILATION_Lung*
        , const VENTILATION_Resistance*
        , VENTILATION_error*
        );
/*
 * Runs the lung forward model, estimating the airway pressure from
 * the given elastance, resistance, flow and volume measurements
 */
struct VENTILATION_Pressure *
VENTILATION_lung_forward(
          const struct VENTILATION_Lung*
        , const struct VENTILATION_Flow*
        , const struct VENTILATION_Volume*
        , VENTILATION_error*);

struct VENTILATION_Frequency *
VENTILATION_frequency_hertz(float, VENTILATION_error*);

struct VENTILATION_Frequency *
VENTILATION_frequency_bpm(float, VENTILATION_error*);

void
VENTILATION_frequency_delete(struct VENTILATION_Frequency*, VENTILATION_error*);

struct VENTILATION_Ratio *
VENTILATION_ratio_create(float, float, VENTILATION_error*);

void
VENTILATION_ratio_delete(struct VENTILATION_Ratio*, VENTILATION_error*);

struct VENTILATION_Cycle *
VENTILATION_cycle_create(const struct VENTILATION_Frequency*, const struct VENTILATION_Ratio*, VENTILATION_error*);

void
VENTILATION_cycle_delete(struct VENTILATION_Cycle*, VENTILATION_error*);
/*
 * Creates a pressure controlled ventilator.
 * It requires:
 *     - A ventilation cycle description
 *     - Positive End Expiratory Pressure target for the expiratory phase
 *     - Pressure Peak at the inspiration target for the inspiratory phase
 */
struct VENTILATION_Ventilator *
VENTILATION_ventilator_pcv(
          const struct VENTILATION_Cycle*
        , const struct VENTILATION_PEEP*
        , const struct VENTILATION_Pressure_Peak*
        , VENTILATION_error*
        );
/*
 * Creates a volume controlled ventilator.
 * It requires:
 *     - A ventilation cycle description
 *     - Positive End Expiratory Pressure target for the expiratory phase
 *     - The target flow for the inspiratory phase
 */
struct VENTILATION_Ventilator *
VENTILATION_ventilator_vcv(
          const struct VENTILATION_Cycle*
        , const struct VENTILATION_PEEP*
        , const struct VENTILATION_Flow*
        , VENTILATION_error*
        );
/*
 * Given a ventilator mode and a patient, described by the lung,
 * excites the system and estimates the airway pressure, flow and volume.
 */
struct VENTILATION_Packet *
VENTILATION_ventilator_control(
          struct VENTILATION_Ventilator *
        , struct VENTILATION_Lung *
        , VENTILATION_error *
        );
/*
 * Deallocates the ventilator, cleaning up the resources.
 */
void
VENTILATION_ventilator_delete(struct VENTILATION_Ventilator*, VENTILATION_error*);
/*
 * Adjusts the ventilator peep.
 */
void
VENTILATION_ventilator_set_peep(
          struct VENTILATION_Ventilator*
        , struct VENTILATION_PEEP*
        , VENTILATION_error*
        );
/*
 * Adjusts the ventilator peak pressure.
 * Notice that VCV modes do not have pressure peak, therefore this is a nop
 * when VENTILATION_Ventilator holds a VCV ventilator.
 */
void
VENTILATION_ventilator_set_pressure_peak(
          struct VENTILATION_Ventilator*
        , struct VENTILATION_Pressure_Peak*
        , VENTILATION_error*
        );
/*
 * Adjusts the ventilator target flow
 * Notice that PCV modes do not have target flow, therefore this is a nop
 * when VENTILATION_Ventilator holds a PCV ventilator.
 */
void
VENTILATION_ventilator_set_flow(
          struct VENTILATION_Ventilator*
        , struct VENTILATION_Flow*
        , VENTILATION_error*
        );
/*
 * Adjusts the ventilator cycle parameters.
 */
void
VENTILATION_ventilator_set_cycle(
          struct VENTILATION_Ventilator*
        , struct VENTILATION_Cycle*
        , VENTILATION_error*
        );

#ifdef __cplusplus
}
#endif

#endif // VENTILATION_H__
