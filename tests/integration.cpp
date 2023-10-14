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
    VENTILATION_Lung * context      = VENTILATION_lung_create(1.0f, 1.0f, &error);
    ASSERT_EQ(error, VENTILATION_ERROR_OK);

    VENTILATION_Elastance * elastance   = VENTILATION_lung_elastance(context, &error);
    ASSERT_EQ(error, VENTILATION_ERROR_OK);
    EXPECT_EQ(VENTILATION_elastance_value(elastance, &error), 1.0f);
    ASSERT_EQ(error, VENTILATION_ERROR_OK);
    VENTILATION_elastance_delete(elastance, &error);
    ASSERT_EQ(error, VENTILATION_ERROR_OK);

    VENTILATION_Resistance * resistance = VENTILATION_lung_resistance(context, &error);
    ASSERT_EQ(error, VENTILATION_ERROR_OK);
    EXPECT_EQ(VENTILATION_resistance_value(resistance, &error), 1.0f);
    ASSERT_EQ(error, VENTILATION_ERROR_OK);
    VENTILATION_resistance_delete(resistance, &error);
    ASSERT_EQ(error, VENTILATION_ERROR_OK);

    VENTILATION_lung_delete(context, &error);
    ASSERT_EQ(error, VENTILATION_ERROR_OK);
}

int
main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
