#ifndef HAL_H
#define HAL_H

#include <stdint.h>

/* pointer to hal functions */
typedef float (*fp_ReadADC_Volts)(int adc_index, int adc_channel);
typedef float (*fp_ADC_VoltsToTemp)(float voltage);

/* object to store function pointers */
struct HAL_FunctionPointers {
    fp_ReadADC_Volts read_adc_volts;
    fp_ADC_VoltsToTemp adc_volts_to_temp;
};

/* setters for hal functions */
void set_read_adc_volts_ptr(fp_ReadADC_Volts newFunc);
void set_adc_volts_to_temp(fp_ADC_VoltsToTemp newFunc);

/* default hal function declaration */
float read_adc_volts(int adc_index, int adc_channel);
float adc_volts_to_temp(float voltage);

#endif // HAL_H