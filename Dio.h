/*
 * Dio.h
 *
 *  Created on: Oct 22, 2023
 *      Author: EVA
 */

#ifndef DIO_H_
#define DIO_H_
#include <avr/io.h>
#define F_CPU 16000000
#include <util/delay.h>
#include "Bit_math.h"
#include "std_types.h"
#include "Dio_types.h"
#include "Dio_Config.h"

extern Dio_pin_config pin[PIN_COUNT];




void Dio_init();
void Dio_Write(channel_t ch,Dio_state_t state);
Dio_state_t Dio_Read(channel_t ch);



#endif
