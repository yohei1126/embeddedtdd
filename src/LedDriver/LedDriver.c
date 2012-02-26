#include "LedDriver.h"
#include "RuntimeError.h"

enum {ALL_LEDS_ON = ~0, ALL_LEDS_OFF = ~ALL_LEDS_ON};
enum {FIRST_LED = 1, LAST_LED =16};
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

int IsLedOutOfBounds(int ledNumber)
{
    return (ledNumber < FIRST_LED) || (ledNumber > LAST_LED);
}

void setLedImageBit(int ledNumber)
{
    ledsImage |= convertLedNumberToBit(ledNumber);
}

void clearLedImageBit(int ledNumber)
{
    ledsImage &= ~convertLedNumberToBit(ledNumber);
}

void LedDriver_TurnOn(int ledNumber)
{
	if (IsLedOutOfBounds(ledNumber)) {
		RUNTIME_ERROR("LED Driver: out-of-bounds LED", ledNumber);
		return;
	}
	setLedImageBit(ledNumber);
	updateHardware();
}

void LedDriver_TurnOff(int ledNumber)
{
	if (IsLedOutOfBounds(ledNumber)) {
		RUNTIME_ERROR("LED Driver: out-of-bounds LED", ledNumber);
		return;
	}
	clearLedImageBit(ledNumber);
	updateHardware();
}

void LedDriver_TurnAllOn()
{
	ledsImage = ALL_LEDS_ON;
	updateHardware();
}

BOOL LedDriver_IsOn(int ledNumber)
{
	if (IsLedOutOfBounds(ledNumber)) {
		return FALSE;
	} else {
		return ledsImage & (convertLedNumberToBit(ledNumber));
	}
}

