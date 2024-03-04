#include <stdint.h>
#include <stdio.h>

#include "hal.h"

#define ADC_INDEX 0
#define ADC_CHANNEL 4
/* 
* this file contains the logic, abstracting away
* hardware to HAL - Hardware Abstraction Layer 
*/

extern struct HAL_FunctionPointers halFuncs; // defined in hal.c 

int main(void){
    set_halFuncs_default();

    if (!halFuncs.fp_read_adc_volts || !halFuncs.fp_adc_volts_to_temp) {
        // Handle error: Function pointers are not initialized
        printf("error, functions not initialized\n");
        return -1;
    }

    float adc_voltage = halFuncs.fp_read_adc_volts(ADC_INDEX, ADC_CHANNEL);
    float temperature = halFuncs.fp_adc_volts_to_temp(adc_voltage);

    printf("ADC volts: %f\n", adc_voltage);
    printf("ADC temps: %f\n", temperature);
}