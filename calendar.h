#ifndef CALENDAR_H
#define CALENDAR_H

#include "reminder.h"
#define NUM_MONTHS 12

enum Months;
enum Days_of_week;
struct Calendar;

/*
struct Calendar {
    enum Months month;
    enum Days_of_week day;
    int starting_day[NUM_MONTHS];
    int num_days[NUM_MONTHS];
};
*/

void disp_chosen_month();
void disp_year(void);
void disp_menu(void);
void menu(void);

#endif