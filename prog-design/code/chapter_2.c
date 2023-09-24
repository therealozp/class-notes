#include <stdio.h>

void dollar_amount(int dollars) {
    int save = dollars; 
    int twenties, tens, fives, ones, rem;
    while (dollars != 0) {
        if (dollars > 20) {
            dollars -= 20; 
            twenties += 1; 
        } else if (dollars > 10) {
            dollars -= 10; 
            tens += 1; 
        } else if (dollars > 5) {
            dollars -= 5; 
            fives += 1;
        } else {
            dollars -= 1; 
            ones += 1; 
        }
    }
    printf("You can make %d dollars using: \n", save);
    printf("%d twenties \n", twenties); 
    printf("%d tens \n", tens); 
    printf("%d fives \n", fives); 
    printf("%d ones \n", ones); 
}

int main () {
    dollar_amount(93); 
    return 0; 
}