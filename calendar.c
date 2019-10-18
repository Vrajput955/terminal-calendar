#include <stdio.h>
#include <stdlib.h>
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
int starting_day[NUM_MONTHS] = {Tuesday, Friday, Friday, Monday, Wednesday, Saturday, Monday, Thursday, Sunday, Tuesday, Friday, Sunday};
int num_days[NUM_MONTHS] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

struct Calendar {
    enum Months month;
    enum Days_of_week day;
};


/*
/void choose_tframe(void) {
    
}
*/

void disp_month(enum Months month) {
    struct Calendar *calendar = malloc(sizeof(struct Calendar));
    struct tm* current_time;
    char month_str[MAX_CHAR_IN_MONTH];
    int month_dates[NUM_ROWS][NUM_COLUMNS] = {0};

    calendar->month = month;

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

    calendar->day = starting_day[calendar->month];

    for (int i = 1, j = 0; i <= num_days[calendar->month]; i++) {
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
                printf("%-4c", ' ');
        }
        newline;
    }
    newline;

    free(calendar);
}

/*----------------------------------------------------//
*                  disp_chosen_month                  *
*  Notes:                                             *              
*      ~Add in input validation                       * 
//----------------------------------------------------*/

void disp_chosen_month(void) {
    int choice;

    printf("\nWhat month would you like to display?"); newline;
    printf("\n---------------------------");
    printf("\n|    1.  January          |");
    printf("\n|    2.  February         |");
    printf("\n|    3.  March            |");
    printf("\n|    4.  April            |");
    printf("\n|    5.  May              |");
    printf("\n|    6.  June             |");
    printf("\n|    7.  July             |");
    printf("\n|    8.  August           |");
    printf("\n|    9.  September        |");
    printf("\n|    10. October          |");
    printf("\n|    11. November         |");
    printf("\n|    12. December         |");
    printf("\n---------------------------"); newline;

    do {
        printf("\nEnter: ");

        scanf("%d", &choice);
        
        switch(choice) {
            case 1: disp_month(January); break;
            case 2: disp_month(February); break;
            case 3: disp_month(March); break;
            case 4: disp_month(April); break;
            case 5: disp_month(May); break;
            case 6: disp_month(June); break;
            case 7: disp_month(July); break;
            case 8: disp_month(August); break;
            case 9: disp_month(September); break;
            case 10: disp_month(October); break;
            case 11: disp_month(November); break;
            case 12: disp_month(December); break;
            default: printf("\nNot a valid choice...\n");
        }
    } while (choice < 1 || choice > 12);
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
