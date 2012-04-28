#ifndef D_FAKE_TIME_SERVICE_H
#define D_FAKE_TIME_SERVICE_H

#include "LightScheduler.h"

enum {TIME_UNKNOWN = -1};

void FakeTimeService_SetDay(Day day);
void FakeTimeService_SetMinute(int minute);

#endif
