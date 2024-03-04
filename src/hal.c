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
    .fp_read_adc_volts = NULL,
    .fp_adc_volts_to_temp = NULL
};

void set_halFuncs_default(){
    halFuncs.fp_adc_volts_to_temp = adc_volts_to_temp; // from driver.h
    halFuncs.fp_read_adc_volts = read_adc_volts; // from driver.h
}

/* setters for hal function pointers (for unit testing) */
void set_fp_read_adc_volts(fp_ReadADC_Volts newFunc){
    halFuncs.fp_read_adc_volts = newFunc;
}

void set_fp_adc_volts_to_temp(fp_ADC_VoltsToTemp newFunc){
    halFuncs.fp_adc_volts_to_temp = newFunc;
}
