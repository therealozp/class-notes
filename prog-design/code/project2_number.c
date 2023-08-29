#include <stdio.h>

int main() {
    int number, remainder;
    printf("Enter input: ");
    scanf("%d", &number);

    if (number % 3 == 0) {
        while (number != 0) {
            remainder = number % 10;
            if (remainder == 3) {
                printf("yes\n");
                return 0;
            } else {
                number /= 10;
            }
        }
        printf("no\n");
    } else {
        printf("no\n");
    }
    return 0;
}