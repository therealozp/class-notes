#include <stdio.h>
#include <stdbool.h>

int main() {
    int m1, d1, y1, m2, d2, y2;
    bool first_earlier;
    printf("Input date 1: ");
    scanf("%d/%d/%d", &m1, &d1, &y1);
    printf("Input date 2: ");
    scanf("%d/%d/%d", &m2, &d2, &y2);

    if (m2 > 12 || m1 > 12 || d1 > 31 || d2 > 31) {
        printf("Invalid date.");
        return 0;
    }

    if (y2 != y1) {
        first_earlier = y2 > y1;
    } else {
        if (m2 != m1) {
            first_earlier = m2 > m1;
        } else {
            if (d2 != d1) {
                first_earlier = d2 > d1;
            } else {
                printf("You inputted the same date.");
            }
        }
    }

    if (first_earlier) {
        printf("DATE 1 IS EARLIER");
    } else {
        printf("DATE 2 IS EARLIER");
    }
    
    return 0;
}