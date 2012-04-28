#include "CppUTest/TestHarness.h"

extern "C"
{
#include "LightScheduler.h"
#include "LightControllerSpy.h"
#include "FakeTimeService.h"
}
TEST_GROUP(LightScheduler)
{
	void setup()
	{
		LightController_Create();
	}
	void teardown()
	{
		LightController_Destroy();
	}
};

TEST(LightScheduler, NoChangeToLightsDuringInitialization)
{
	LONGS_EQUAL(LIGHT_ID_UNKNOWN, LightControllerSpy_GetLastId());
	LONGS_EQUAL(LIGHT_STATE_UNKNOWN, LightControllerSpy_GetLastState());
}
/*
TEST(LightScheduler, ScheduleOnEverydayNotTimeYet)
{
	//the light with id equals to 3 to turn on every day at the 1200th minute of the day(8 pm)
	LightScheduler_ScheduleTurnOn(3, EVERYDAY, 1200);
	//it is Monday at 7:59 pm
	FakeTimeService_SetDay(MONDAY);
	FakeTimeService_SetMinute(1999);

	//test simulates a call back
	LightScheduler_Wakeup();

	//no schedule event
	LONGS_EQUAL(LIGHT_ID_UNKNOWN, LightControllerSpy_GetLastId());
	LONGS_EQUAL(LIGHT_STATE_UNKNOWN, LightControllerSpy_GetLastState());
}
*/
