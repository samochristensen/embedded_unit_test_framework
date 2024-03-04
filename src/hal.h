#ifndef HAL_H
#define HAL_H

#include <stdint.h>
#include <stddef.h>

#include "driver.h"

/* pointer to hal functions */
typedef float (*fp_ReadADC_Volts)(int adc_index, int adc_channel);
typedef float (*fp_ADC_VoltsToTemp)(float voltage);

/* object to store function pointers */
struct HAL_FunctionPointers {
    fp_ReadADC_Volts fp_read_adc_volts;
    fp_ADC_VoltsToTemp fp_adc_volts_to_temp;
};

/* setters for hal functions -- only needed for test functions?*/
void set_halFuncs_default();
void set_fp_read_adc_volts(fp_ReadADC_Volts newFunc);
void set_fp_adc_volts_to_temp(fp_ADC_VoltsToTemp newFunc);

/* default hal function declaration */
float read_adc_volts(int adc_index, int adc_channel);
float adc_volts_to_temp(float voltage);

#endif // HAL_H