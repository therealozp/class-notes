// Name: Phu Anh Khang Le
// Description: Programs check if an entered number is a magic number, which contains a 3 in it and is divisible by 3

#include <stdio.h>

int main() {
    // first initializes remainder
    int number, remainder;
    printf("Enter input:");
    scanf("%d", &number);

    // checks if number is divisible by 3, else it is not a magic number
    if (number % 3 == 0) {
        // sets up a loop to terminate when number cannot be divided any further 
        while (number != 0) {
            // gets the remainder of the number when modding by 10 (which is the last digit)
            remainder = number % 10;
            if (remainder == 3) {
                // if the remainder is 3, then it is a magic number, and ends program immediately
                printf("yes\n");
                return 0;
            } else {
                // if not, then divide the number by 10 to get rid of the last digit (597 / 10 gives 59)
                number /= 10;
            }
        }
        printf("no\n");
    } else {
        printf("no\n");
    }
    return 0;
}