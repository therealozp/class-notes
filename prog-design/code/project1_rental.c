// Name: Phu Anh Khang Le
// Description: This program asks the user to input the number of a product, the period of time used, 
// and will calculate the total charges.

#include <stdio.h>
// macro defintion: 7 days in a week
#define WEEK_DAYS 7

// math.h is not available in gcc v 4.0.7 so im implementing my own ceil function
int ceiling(double x) {
    // this converts it to an integer form first
    int x_int = x;
    if (x > x_int) {
        return x_int + 1;
    }
    return x;
}

int main(void) {
    int equipment; 
    printf("Please select from four equipment: 1, 2, 3, and 4\n"); 
    printf("Enter equipment selection: ");
    scanf("%d", &equipment); 
    if (equipment < 1 || equipment > 4) {
        printf("Invalid selection. Select from 1 to 4.\n");
        // exit the program if invalid selection is inputted
        return 0;
    } 

    // initialize variables
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
        printf("Invalid hours.\n");
        return 0;
    }

    // using a switch-case statement here because if-else is not as clean
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
        // no default case because already checked for invalid input
    } 

    // round up the ratios, because integer division automatically floors the answers
    week_day_ratio = weekly_cap / daily_cap;
    week_day_ratio = ceiling(week_day_ratio);
     

    // since 8-hour sessions for all products exceed the daily cap, we just need to check if the number of sessions exceed 4
    // if yes, increment days by 1
    // else, just keep the four sessions
    if (hours > 4) {
        four_hour_sessions = 0; 
        days += 1;
    } else {
        four_hour_sessions = 1;
    }

    if ( days > week_day_ratio ) {
        // find out how many weeks to pay
        int num_weekly_charges = days / WEEK_DAYS; 
        // the leftover days can be calculated with mod
        int leftover_days = days % WEEK_DAYS; 
        total_charges += num_weekly_charges * weekly_cap;
        // if the excess charges (not included as a weekly charge) exceed the weekly cap,
        int temp_excess_charges = leftover_days * daily_cap + four_hour_sessions * hourly_cap;

        if (temp_excess_charges > weekly_cap) {
            // just increase it by the weekly cap, 
            total_charges += weekly_cap;
        } else {
            // else increment it by the excess charge itself
            total_charges += temp_excess_charges;
        }
    }  else {
        // if there is definitely less than a week's worth of charges, just need to take the charge normally
        // if the previous four_hour_sessions have been accounted for, this instance is just 0.
        total_charges += days * daily_cap + four_hour_sessions * hourly_cap; 
    }
        printf("Charge($): %d\n", total_charges);
    return 0;
}