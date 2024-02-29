#include "unity.h"

// Function declarations for the test cases
void test_ReadAdcVolts(void);

// main function
int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_ReadAdcVolts);

    // Add RUN_TEST calls for additional test cases

    return UNITY_END();
}
