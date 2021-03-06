#ifndef _exti__H__
#define _exti__H__

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include "gpio.h"

void exti_config(GPIO_TypeDef * port, uint32_t pin, bool rtsr, bool ftsr, bool ie);
void getTimeStamps(int pin);

#endif
