#include <stdint.h>
#include <stdio.h>

#include "hal.h"
/* 
* this file contains the logic, abstracting away
* hardware to HAL - Hardware Abstraction Layer 
*/

extern struct HAL_FunctionPointers halFuncs; // defined in hal.c 

int main(void){
    int adc_index = 0;
    int adc_channel = 4;
    float adc_voltage = halFuncs.read_adc_volts(adc_index, adc_channel);
    float temperature = halFuncs.adc_volts_to_temp(adc_voltage);

    printf("ADC volts: %u\n", adc_voltage);
    printf("ADC temps: %u\n", temperature);
}