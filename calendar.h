#ifndef CALENDAR_H
#define CALENDAR_H

#include "reminder.h"

enum Months {January, February, March, April, May, June, July, August, September, October, November, December};
enum Days_of_week {Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday};
extern enum Months month;
extern enum Days_of_week day;
extern int starting_day[];
extern int num_days[];

//void choose_tframe(void);
void disp_month(enum Months);
void disp_year(void);
void disp_menu(void);

#endif