#include "CppUTest/TestHarness.h"

extern "C"
{
#include "FakeTimeService.h"
#include "TimeService.h"
}
TEST_GROUP(FakeTimeService)
{
	void setup()
	{
		TimeService_Create();
	}
	void teardown()
	{
		TimeService_Destroy();
	}
};

TEST(FakeTimeService, Create)
{
	Time time;
	TimeService_GetTime(&time);

	LONGS_EQUAL(TIME_UNKNOWN, time.minuteOfDay);
	LONGS_EQUAL(TIME_UNKNOWN, time.dayOfWeek);
}
