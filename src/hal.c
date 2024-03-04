#include "hal.h"
/* 
* this file contains the default implementation to which the
* function pointers will refer - for unit testing these functions
* definitions will be reimplemented as doubles
*/

/* constants */
#define VOLTS2TEMP 50

/* object to store function pointers */
struct HAL_FunctionPointers halFuncs = {
    .read_adc_volts = read_adc_volts,
    .adc_volts_to_temp = adc_volts_to_temp
};

/* default function implementation */
float read_adc_volts(int adc_index, int adc_channel){
    return -1;
}

float adc_volts_to_temp(float voltage){
    return -1;
}

/* setters for hal function pointers (for unit testing) */
void set_fp_read_adc_volts(fp_ReadADC_Volts newFunc){
    halFuncs.read_adc_volts = newFunc;
}
void set_fp_adc_volts_to_temp(fp_ADC_VoltsToTemp newFunc){
    halFuncs.adc_volts_to_temp = newFunc;
}
