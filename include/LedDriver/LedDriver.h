//LedDriver.h
#ifndef LED_DRIVER_H
#define LED_DRIVER_H

#include "stdint.h"  // for uint16_t

void LedDriver_Create(uint16_t* address);
void LedDriver_Destroy(void);

#endif
