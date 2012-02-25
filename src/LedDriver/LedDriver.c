#include "LedDriver.h"

enum {ALL_LEDS_ON = ~0, ALL_LEDS_OFF = ~ALL_LEDS_ON};
static uint16_t *ledsAddress;
static uint16_t ledsImage;

void LedDriver_Create(uint16_t* address)
{
  ledsAddress = address;
  ledsImage = ALL_LEDS_OFF;
  *ledsAddress = ledsImage;
}

void LedDriver_Destroy(void)
{
}

int convertLedNumberToBit(int ledNumber)
{
    return 1 << (ledNumber - 1);
}

static void updateHardware(void)
{
  *ledsAddress = ledsImage;
}

void LedDriver_TurnOn(int ledNumber)
{
  ledsImage |= convertLedNumberToBit(ledNumber);
  updateHardware();
}

void LedDriver_TurnOff(int ledNumber)
{
  ledsImage &= ~(convertLedNumberToBit(ledNumber));
  updateHardware();
}

void LedDriver_TurnAllOn()
{
  ledsImage = ALL_LEDS_ON;
  updateHardware();
}
