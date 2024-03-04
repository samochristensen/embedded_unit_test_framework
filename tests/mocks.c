#include "mocks.h"
/* 
* this file contains the alternative function implementations
* for testing the logic - may include the following doubles:
* dummy, fake, stub, spy, mock
*/

extern struct HAL_FunctionPointers halFuncs;

/* unit testing function implementation */
float read_adc_volts_mock(int adc_index, int adc_channel){
    /* TODO: implement test case for unit test */
    return 1;
}

float adc_volts_to_temp_mock(float voltage){
    return 1;
}