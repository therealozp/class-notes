#include <stdio.h>
#define DAY_HRS 24
#define WEEK_DAYS 7

int main(void) {
    int equipment; 
    printf("Please select from four equipment: 1, 2, 3, and 4\n"); 
    printf("Enter equipment selection: ");
    scanf("%d", &equipment); 
    if (equipment < 1 || equipment > 4) {
        printf("Invalid selection. Select from 1 to 4.");
        return 0;
    } 

    int hours, days, four_hour_sessions; 
    int hourly_cap, daily_cap, weekly_cap; 
    double week_day_ratio; 
    // normally the day_hour_ratio will be somewhere close to 1 anyway,
    // so any periods over 4 hours can automatically be as to a day. 
    int total_charges = 0;

    printf("Enter days: "); 
    scanf("%d", &days);
    printf("Enter hours: "); 
    scanf("%d", &hours);

    // printf("You have %d days and %d hours", days, hours);

    if (hours < 0 || hours >= 24) {
        printf("Invalid hours.");
        return 0;
    }

    switch (equipment) {
        case 1 : 
            hourly_cap = 7;
            daily_cap = 10; 
            weekly_cap = 40;
            break;
        case 2 : 
            hourly_cap = 27; 
            daily_cap = 39; 
            weekly_cap = 156;
            break;
        case 3 : 
            hourly_cap = 61; 
            daily_cap = 87; 
            weekly_cap = 348;
            break;
        case 4 : 
            hourly_cap = 59; 
            daily_cap = 84; 
            weekly_cap = 336;
            break;
    } 

    // round up the two ratios, because integer division automatically floors the answers
    week_day_ratio = weekly_cap / daily_cap + 1; 

    if (hours > 4) {
        four_hour_sessions = 0; 
        days += 1;
    } else {
        four_hour_sessions = 1;
    }

    if ( days > week_day_ratio ) {
        int num_weekly_charges = days / 7; // find out how many weeks to pay
        int leftover_days = days % 7; 
        total_charges += num_weekly_charges * weekly_cap;
        int temp_excess_charges = leftover_days * daily_cap + four_hour_sessions * hourly_cap;

        if (temp_excess_charges > weekly_cap) {
            total_charges += weekly_cap;
        } else {
            total_charges += temp_excess_charges;
        }
    }  else {
        total_charges += days * daily_cap + four_hour_sessions * hourly_cap; 
    }
        printf("Charge($): %d", total_charges);

    return 0;
}