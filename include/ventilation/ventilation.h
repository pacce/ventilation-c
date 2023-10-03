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

struct VENTILATION_Compliance;
struct VENTILATION_Elastance;
struct VENTILATION_Resistance;

struct VENTILATION_Flow;
struct VENTILATION_Pressure;
struct VENTILATION_Volume;

struct VENTILATION_Packet;

struct VENTILATION_Compliance *
VENTILATION_compliance_create(const float, VENTILATION_error*);

void
VENTILATION_compliance_delete(struct VENTILATION_Compliance*, VENTILATION_error*);

float
VENTILATION_compliance_value(const struct VENTILATION_Compliance*, VENTILATION_error*);

struct VENTILATION_Compliance *
VENTILATION_compliance_add(
          const struct VENTILATION_Compliance*
        , const struct VENTILATION_Compliance*
        , VENTILATION_error*
        );

struct VENTILATION_Compliance *
VENTILATION_compliance_sub(
          const struct VENTILATION_Compliance*
        , const struct VENTILATION_Compliance*
        , VENTILATION_error*
        );

struct VENTILATION_Compliance *
VENTILATION_compliance_mul(
          const struct VENTILATION_Compliance*
        , const struct VENTILATION_Compliance*
        , VENTILATION_error*
        );


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

VENTILATION_bool
VENTILATION_compliance_gt(
          const struct VENTILATION_Compliance*
        , const struct VENTILATION_Compliance*
        , VENTILATION_error*
        );

VENTILATION_bool
VENTILATION_compliance_ge(
          const struct VENTILATION_Compliance*
        , const struct VENTILATION_Compliance*
        , VENTILATION_error*
        );

VENTILATION_bool
VENTILATION_compliance_lt(
          const struct VENTILATION_Compliance*
        , const struct VENTILATION_Compliance*
        , VENTILATION_error*
        );

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

#ifdef __cplusplus
}
#endif

#endif // VENTILATION_H__
