#include "unity.h"
#include "hal.h"
#include "mocks.h"

#define ADC_INDEX 0
#define ADC_CHANNEL 4

extern struct HAL_FunctionPointers halFuncs;

// Global setup function (runs before each test)
void setUp(void) {
    /* configure HAL for mock definitions */
    set_fp_adc_volts_to_temp(adc_volts_to_temp_mock);
    set_fp_read_adc_volts(read_adc_volts_mock);
}

// Global teardown function (runs after each test)
void tearDown(void) {
}

void test_ReadAdcVolts(void) {
    float adc_voltage = halFuncs.fp_read_adc_volts(ADC_INDEX, ADC_CHANNEL);
    float temperature = halFuncs.fp_adc_volts_to_temp(adc_voltage);

    float delta = 1.0;
    float expected_voltage = 1; // Assuming these are the expected values
    float expected_temperature = 1; // Adjust according to your expectations

    // Assertions
    TEST_ASSERT_FLOAT_WITHIN(delta, expected_voltage, adc_voltage);
    TEST_ASSERT_FLOAT_WITHIN(delta, expected_temperature, temperature);
}

