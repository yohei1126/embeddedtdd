#include "LightScheduler.h"
#include "TimeService.h"
#include "LightController.h"

typedef struct
{
	int id;
	int minuteOfDay;
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

	Light_Controller_On(scheduledLightEvent.id);
}
