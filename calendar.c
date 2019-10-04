#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "calendar.h"
#define newline printf("\n")
#define MAX_CHAR_IN_MONTH 10
#define CHARS_IN_YEAR 4
#define NUM_ROWS 6
#define NUM_COLUMNS 7


enum Months {January, February, March, April, May, June, July, August, September, October, November, December};
enum Days_of_week {Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday};

struct Calendar {
    enum Months month;
    enum Days_of_week day;
    int starting_day[NUM_MONTHS];
    int num_days[NUM_MONTHS];
};


/*
/void choose_tframe(void) {
    
}
*/

void disp_month(struct Calendar *calendar) {
    struct tm* current_time;
    char month_str[MAX_CHAR_IN_MONTH];
    int month_dates[NUM_ROWS][NUM_COLUMNS] = {0};

    switch(calendar->month) {
        case(January): strcpy(month_str, "January"); break;
        case(February): strcpy(month_str, "February"); break;
        case(March): strcpy(month_str, "March"); break;
        case(April): strcpy(month_str, "April"); break;
        case(May): strcpy(month_str, "May"); break;
        case(June): strcpy(month_str, "June"); break;
        case(July): strcpy(month_str, "July"); break;
        case(August): strcpy(month_str, "August"); break;
        case(September): strcpy(month_str, "September"); break;
        case(October): strcpy(month_str, "October"); break;
        case(November): strcpy(month_str, "November"); break;
        case(December): strcpy(month_str, "December"); break;
    }

    calendar->day = calendar->starting_day[calendar->month];

    for (int i = 1, j = 0; i <= calendar->num_days[calendar->month]; i++) {
        month_dates[j][calendar->day++] = i;
        if (calendar->day % 7 == 0) {
           calendar->day = Sunday;
           j++; 
        }
    }

    newline;
    printf("%s", month_str); newline;
    printf("-------------------------"); newline;
    printf("S   M   T   W   T   F   S\n");
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLUMNS; j++) {
            if (month_dates[i][j])
                printf("%-4d", month_dates[i][j]);
            else
                printf("%-4c", '\0');
        }
        newline;
    }
    newline;
}


void disp_year(void) {
    char year_str[CHARS_IN_YEAR+1];
    strcpy(year_str, "2019");

    printf("\n******************\n");
    printf("*      %s      *", year_str);
    printf("\n******************\n");

    for (int i = January; i <= December; i++) {
        disp_month(i);
    }
}


void disp_menu(void) {
    printf("\n|********************|");
    printf("\n|        Menu        |");
    printf("\n| 1. Display Year    |");
    printf("\n| 2. Display Month   |");
    printf("\n| 3. Set Reminder    |");
    printf("\n| 4. Clear Reminders |");
    printf("\n| 5. Quit            |");
    printf("\n**********************");
    newline;
}
