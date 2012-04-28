#include "LightScheduler.h"
#include "TimeService.h"
#include "LightController.h"

typedef enum
{
	TURN_ON = 0, TURN_OFF
} Event;

typedef struct
{
	int id;
	int minuteOfDay;
	Event event;
} ScheduledLightEvent;

enum
{
    UNUSED = -1
};

static ScheduledLightEvent scheduledLightEvent;

void LightScheduler_Create(void)
{
	scheduledLightEvent.id = UNUSED;
}

void LightScheduler_Destroy(void)
{
}

void LightScheduler_ScheduleTurnOn(int id, Day day, int minuteOfDay)
{
	scheduledLightEvent.id = id;
	scheduledLightEvent.minuteOfDay = minuteOfDay;
	scheduledLightEvent.event = TURN_ON;
}

void LightScheduler_ScheduleTurnOff(int id, Day day, int minuteOfDay)
{
	scheduledLightEvent.id = id;
	scheduledLightEvent.minuteOfDay = minuteOfDay;
	scheduledLightEvent.event = TURN_OFF;
}

void LightScheduler_Wakeup(void)
{
	Time time;
	TimeService_GetTime(&time);

	if (scheduledLightEvent.id == UNUSED) {
		return;
	}

	if (time.minuteOfDay != scheduledLightEvent.minuteOfDay) {
		return;
	}

	if (scheduledLightEvent.event == TURN_ON) {
		Light_Controller_On(scheduledLightEvent.id);
	} else if (scheduledLightEvent.event == TURN_OFF) {
		Light_Controller_Off(scheduledLightEvent.id);
	}
}
