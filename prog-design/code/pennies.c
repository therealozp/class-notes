#include <stdio.h>

int main(void) {
    int numbers; 
    int originalNumber = 0;
    while (numbers < 50) {
        int currNumber = originalNumber;
        int reversedNumber = 0; 
        int remainder = 0;

        while (currNumber != 0) {
            remainder = currNumber % 10;
            currNumber /= 10;
            reversedNumber = reversedNumber * 10 + remainder;
        }
        
        if (originalNumber == reversedNumber) {
            numbers += 1;
            printf("%d \n", originalNumber);
        }
        originalNumber++;
    }
    return 0;
}