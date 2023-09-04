#include <stdio.h>
#define weekly 7
#define biweekly weekly+weekly

int ceiling(double x) {
    // this converts it to an integer form first
    int x_int = x;
    if (x > x_int) {
        return x_int + 1;
    }
    return x;
}

int main() {
    int b;
    float a, c;
    scanf("%f%d%f", &a, &b, &c);
    printf("%f\n", a);
    printf("%d\n", b);
    printf("%f\n", c);
    // printf("%d", days);
    return 0;
}