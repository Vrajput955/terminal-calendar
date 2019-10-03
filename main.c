#include <stdio.h>
#include "calendar.h"

enum Months month;
enum Days_of_week day;
int starting_day[] = {Tuesday, Friday, Friday, Monday, Wednesday, Saturday, Monday, Thursday, Sunday, Tuesday, Friday, Sunday};
int num_days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(void) {

    disp_menu();

    return 0;
}