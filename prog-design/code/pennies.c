#include <stdio.h>

int main(void) {
    int quarters, dimes, nickels, pennies; 
    printf("Enter quarters: ");
    scanf("%d", &quarters);
    printf("Enter dimes: ");
    scanf("%d", &dimes);
    printf("Enter nickels: ");
    scanf("%d", &nickels);
    printf("Enter pennies: ");
    scanf("%d", &pennies);
    pennies += quarters * 25 + dimes * 10 + nickels * 5;
    printf("Your total: %d pennies", pennies);
    return 0;
}