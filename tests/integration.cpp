#include <gtest/gtest.h>
#include <ventilation/ventilation.h>

TEST(Compliance, Identity) {
    VENTILATION_error error             = VENTILATION_ERROR_OK;
    VENTILATION_Compliance * context    = VENTILATION_compliance_create(1.0f, &error);
    ASSERT_EQ(error, VENTILATION_ERROR_OK);

    EXPECT_EQ(VENTILATION_compliance_value(context, &error), 1.0f);
    ASSERT_EQ(error, VENTILATION_ERROR_OK);

    VENTILATION_compliance_delete(context, &error);
    ASSERT_EQ(error, VENTILATION_ERROR_OK);
}

TEST(Elastance, Identity) {
    VENTILATION_error error             = VENTILATION_ERROR_OK;
    VENTILATION_Elastance * context     = VENTILATION_elastance_create(1.0f, &error);
    ASSERT_EQ(error, VENTILATION_ERROR_OK);

    EXPECT_EQ(VENTILATION_elastance_value(context, &error), 1.0f);
    ASSERT_EQ(error, VENTILATION_ERROR_OK);

    VENTILATION_elastance_delete(context, &error);
    ASSERT_EQ(error, VENTILATION_ERROR_OK);
}

TEST(Resistance, Identity) {
    VENTILATION_error error             = VENTILATION_ERROR_OK;
    VENTILATION_Resistance * context    = VENTILATION_resistance_create(1.0f, &error);
    ASSERT_EQ(error, VENTILATION_ERROR_OK);

    EXPECT_EQ(VENTILATION_resistance_value(context, &error), 1.0f);
    ASSERT_EQ(error, VENTILATION_ERROR_OK);

    VENTILATION_resistance_delete(context, &error);
    ASSERT_EQ(error, VENTILATION_ERROR_OK);
}

TEST(Flow, Identity) {
    VENTILATION_error error     = VENTILATION_ERROR_OK;
    VENTILATION_Flow * context  = VENTILATION_flow_create(1.0f, &error);
    ASSERT_EQ(error, VENTILATION_ERROR_OK);

    EXPECT_EQ(VENTILATION_flow_value(context, &error), 1.0f);
    ASSERT_EQ(error, VENTILATION_ERROR_OK);

    VENTILATION_flow_delete(context, &error);
    ASSERT_EQ(error, VENTILATION_ERROR_OK);
}

TEST(Pressure, Identity) {
    VENTILATION_error error         = VENTILATION_ERROR_OK;
    VENTILATION_Pressure * context  = VENTILATION_pressure_create(1.0f, &error);
    ASSERT_EQ(error, VENTILATION_ERROR_OK);

    EXPECT_EQ(VENTILATION_pressure_value(context, &error), 1.0f);
    ASSERT_EQ(error, VENTILATION_ERROR_OK);

    VENTILATION_pressure_delete(context, &error);
    ASSERT_EQ(error, VENTILATION_ERROR_OK);
}

TEST(Volume, Identity) {
    VENTILATION_error error         = VENTILATION_ERROR_OK;
    VENTILATION_Volume * context    = VENTILATION_volume_create(1.0f, &error);
    ASSERT_EQ(error, VENTILATION_ERROR_OK);

    EXPECT_EQ(VENTILATION_volume_value(context, &error), 1.0f);
    ASSERT_EQ(error, VENTILATION_ERROR_OK);

    VENTILATION_volume_delete(context, &error);
    ASSERT_EQ(error, VENTILATION_ERROR_OK);
}

TEST(Lung, Identity) {
    VENTILATION_error error         = VENTILATION_ERROR_OK;

    VENTILATION_Elastance * elastance   = VENTILATION_elastance_create(2.0f, &error);
    VENTILATION_Resistance * resistance = VENTILATION_resistance_create(3.0f, &error);
    ASSERT_EQ(error, VENTILATION_ERROR_OK);

    VENTILATION_Lung * context      = VENTILATION_lung_create(resistance, elastance, &error);
    ASSERT_EQ(error, VENTILATION_ERROR_OK);

    {
        VENTILATION_Resistance * actual = VENTILATION_lung_resistance(context, &error);
        ASSERT_EQ(error, VENTILATION_ERROR_OK);

        EXPECT_TRUE(VENTILATION_resistance_eq(resistance, actual, &error));
        VENTILATION_resistance_delete(actual, &error);
    }
    {
        VENTILATION_Elastance * actual = VENTILATION_lung_elastance(context, &error);
        ASSERT_EQ(error, VENTILATION_ERROR_OK);

        EXPECT_TRUE(VENTILATION_elastance_eq(elastance, actual, &error));
        VENTILATION_elastance_delete(actual, &error);
    }

    VENTILATION_resistance_delete(resistance, &error);
    VENTILATION_elastance_delete(elastance, &error);
    VENTILATION_lung_delete(context, &error);
    ASSERT_EQ(error, VENTILATION_ERROR_OK);
}

TEST(Lung, Setter) {
    VENTILATION_error error         = VENTILATION_ERROR_OK;

    VENTILATION_Elastance * elastance   = VENTILATION_elastance_create(3.0f, &error);
    VENTILATION_Resistance * resistance = VENTILATION_resistance_create(3.0f, &error);
    ASSERT_EQ(error, VENTILATION_ERROR_OK);

    VENTILATION_Lung * context      = VENTILATION_lung_create(resistance, elastance, &error);
    ASSERT_EQ(error, VENTILATION_ERROR_OK);

    {
        VENTILATION_Resistance * change = VENTILATION_resistance_create(4.0f, &error);
        VENTILATION_lung_set_resistance(context, change, &error);
        VENTILATION_Resistance * actual = VENTILATION_lung_resistance(context, &error);
        ASSERT_EQ(error, VENTILATION_ERROR_OK);

        EXPECT_TRUE(VENTILATION_resistance_neq(resistance, actual, &error));
        EXPECT_TRUE(VENTILATION_resistance_eq(change, actual, &error));

        VENTILATION_resistance_delete(actual, &error);
        VENTILATION_resistance_delete(change, &error);
    }
    {
        VENTILATION_Elastance * change = VENTILATION_elastance_create(4.0f, &error);
        VENTILATION_lung_set_elastance(context, change, &error);
        VENTILATION_Elastance * actual = VENTILATION_lung_elastance(context, &error);
        ASSERT_EQ(error, VENTILATION_ERROR_OK);

        EXPECT_TRUE(VENTILATION_elastance_neq(elastance, actual, &error));
        EXPECT_TRUE(VENTILATION_elastance_eq(change, actual, &error));

        VENTILATION_elastance_delete(actual, &error);
        VENTILATION_elastance_delete(change, &error);
    }

    VENTILATION_resistance_delete(resistance, &error);
    VENTILATION_elastance_delete(elastance, &error);
    VENTILATION_lung_delete(context, &error);
    ASSERT_EQ(error, VENTILATION_ERROR_OK);
}

TEST(Lung, Forward) {
    VENTILATION_error error = VENTILATION_ERROR_OK;

    VENTILATION_Elastance * elastance   = VENTILATION_elastance_create(2.0f, &error);
    VENTILATION_Resistance * resistance = VENTILATION_resistance_create(3.0f, &error);
    VENTILATION_Lung * context          = VENTILATION_lung_create(resistance, elastance, &error);
    ASSERT_EQ(error, VENTILATION_ERROR_OK);

    VENTILATION_Flow * flow     = VENTILATION_flow_create(3.0f, &error);
    VENTILATION_Volume * volume = VENTILATION_volume_create(4.0f, &error);
    ASSERT_EQ(error, VENTILATION_ERROR_OK);

    VENTILATION_Pressure * pressure = VENTILATION_lung_forward(context, flow, volume, &error);
    EXPECT_EQ(VENTILATION_pressure_value(pressure, &error), 17.0f);
    ASSERT_EQ(error, VENTILATION_ERROR_OK);

    VENTILATION_flow_delete(flow, &error);
    VENTILATION_volume_delete(volume, &error);
    ASSERT_EQ(error, VENTILATION_ERROR_OK);

    VENTILATION_resistance_delete(resistance, &error);
    VENTILATION_elastance_delete(elastance, &error);
    VENTILATION_lung_delete(context, &error);
    ASSERT_EQ(error, VENTILATION_ERROR_OK);
}

TEST(Frequency, Identity) {
    VENTILATION_error error         = VENTILATION_ERROR_OK;
    VENTILATION_Frequency * context = VENTILATION_frequency_hertz(1.0f, &error);
    ASSERT_EQ(error, VENTILATION_ERROR_OK);

    VENTILATION_frequency_delete(context, &error);
    ASSERT_EQ(error, VENTILATION_ERROR_OK);
}

TEST(Cycle, Identity) {
    VENTILATION_error error             = VENTILATION_ERROR_OK;
    VENTILATION_Frequency * frequency   = VENTILATION_frequency_hertz(1.0f, &error);
    VENTILATION_Ratio * ratio           = VENTILATION_ratio_create(1.0f, 1.0f, &error);

    VENTILATION_Cycle * context         = VENTILATION_cycle_create(frequency, ratio, &error);
    ASSERT_EQ(error, VENTILATION_ERROR_OK);

    VENTILATION_frequency_delete(frequency, &error);
    VENTILATION_ratio_delete(ratio, &error);
    VENTILATION_cycle_delete(context, &error);
    ASSERT_EQ(error, VENTILATION_ERROR_OK);
}

int
main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
