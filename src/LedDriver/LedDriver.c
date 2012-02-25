#include "LedDriver.h"

enum {ALL_LEDS_ON = ~0, ALL_LEDS_OFF = ~ALL_LEDS_ON};
static uint16_t *ledsAddress;

void LedDriver_Create(uint16_t* address)
{
  ledsAddress = address;
  *ledsAddress = 0;
}

void LedDriver_Destroy(void)
{
}

int convertLedNumberToBit(int ledNumber)
{
    return 1 << (ledNumber - 1);
}

void LedDriver_TurnOn(int ledNumber)
{
  *ledsAddress |= convertLedNumberToBit(ledNumber);
}

void LedDriver_TurnOff(int ledNumber)
{
  *ledsAddress = 0;
}

void LedDriver_TurnAllOn()
{
	*ledsAddress = ALL_LEDS_ON;
}
