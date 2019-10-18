#include <stdbool.h>
#include "calendar.h"
#include "reminder.h"

void disp_menu(void) {
    printf("\n|********************|");
    printf("\n|        Menu        |");
    printf("\n| 1. Display Year    |");
    printf("\n| 2. Display Month   |");
    printf("\n| 3. Set Reminder    |");
    printf("\n| 4. Edit Reminder   |");
    printf("\n| 5. Quit            |");
    printf("\n**********************\n");
}

void menu(void) {
    int choice;

    disp_menu();
    printf("\nEnter: ");

    while (true) {
        scanf("%d", &choice);
        switch (choice) {
            case 1: disp_year(); break;
            case 2: disp_chosen_month(); break;
            case 3: // set_reminder(); break;
            case 4: // edit_reminder();
        }
    }


}