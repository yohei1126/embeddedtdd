#include "FakeTimeService.h"
#include "TimeService.h"

static Time myTime;

void TimeService_Create(void)
{
	myTime.dayOfWeek = TIME_UNKNOWN;
	myTime.minuteOfDay = TIME_UNKNOWN;
}

void TimeService_Destroy(void)
{
}

void TimeService_GetTime(Time *time)
{
	time->dayOfWeek = myTime.dayOfWeek;
	time->minuteOfDay = myTime.minuteOfDay;
}

void FakeTimeService_SetDay(Day day)
{
}

void FakeTimeService_SetMinute(int minute)
{
}
