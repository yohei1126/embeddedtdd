#include "LightControllerSpy.h"

static int lastId;
static int lastState;

void LightController_Create()
{
	lastId = LIGHT_ID_UNKNOWN;
	lastState = LIGHT_STATE_UNKNOWN;
}

void LightController_Destroy()
{
}

int LightControllerSpy_GetLastId(void)
{
	return lastId;
}

int LightControllerSpy_GetLastState(void)
{
	return lastState;
}

void Light_Controller_On(int id)
{
	lastId = id;
	lastState = LIGHT_ON;
}

void Light_Controller_Off(int id)
{
	lastId = id;
	lastState = LIGHT_OFF;
}
