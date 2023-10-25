/*
 * Dio_config.h
 *
 *  Created on: Oct 22, 2023
 *      Author: EVA
 */

#ifndef DIO_CONFIG_H_
#define DIO_CONFIG_H_
#define PIN_COUNT 19
#include "Dio_types.h"

typedef struct{
    Dio_port_t port;
	Dio_pin_t pin;
	Dio_dir_t direction;
}Dio_pin_config;

#endif /* DIO_CONFIG_H_ */
