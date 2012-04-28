#ifndef TIME_SERVICE_H
#define TIME_SERVICE_H

#include "LightScheduler.h"

typedef struct {
	int minuteOfDay;
	Day dayOfWeek;
} Time;

void TimeService_Create(void);
void TimeService_Destroy(void);
void TimeService_GetTime(Time *time);

#endif
