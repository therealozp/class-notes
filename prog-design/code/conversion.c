#include <stdio.h>
#define weekly 7
#define biweekly weekly+weekly

int main() {
    int days = 10 * biweekly;
    printf("%d", days);
    return 0;
}