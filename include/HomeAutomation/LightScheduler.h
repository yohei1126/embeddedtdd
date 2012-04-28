#ifndef D_LIGHT_SCHEDULER_H
#define D_LIGHT_SCHEDULER_H

typedef enum {
    NONE=-1, EVERYDAY=10, WEEKDAY, WEEKEND,
    SUNDAY=1, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY
} Day;


void LightScheduler_Create(void);
void LightScheduler_Destroy(void);
void LightScheduler_ScheduleTurnOn(int id, Day day, int minute);
void LightScheduler_Wakeup(void);

#endif
