#ifndef TIME_SERVICE_H
#define TIME_SERVICE_H

typedef struct {
	int minuteOfDay;
	int dayOfWeek;
} Time;

void TimeService_Create(void);
void TimeService_Destroy(void);
void TimeService_GetTime(Time *time);

#endif
