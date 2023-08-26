#include <stdio.h>
#define CONVERSION_CONSTANT (5.0/9.0)
#define FREEZING_POINT 32

int main(void) {
    double fa, ce; 
    printf("What is your degrees in Fahrenheit?\n");
    scanf("%lf", &fa);

    ce = (fa - FREEZING_POINT ) * CONVERSION_CONSTANT;
    printf("%lf degrees F is %.2lf degrees C.\n", fa, ce);
    return 0;
}