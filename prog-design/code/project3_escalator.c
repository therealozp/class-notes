#include <stdio.h>

int active_seconds(int arrival[], int n) {
    int secs = 0;
    int end = 0;
    for (int i = 0; i < n; i++) {
        if (!end) {
            end = arrival[i] + 10;
        } else {
            if (arrival[i] > end) {
                secs += 10;
                end = arrival[i] + 10;
            } else {
                secs += (arrival[i] - arrival[i-1]);
                end = arrival[i] + 10;
            }
        }
    }
    // add 10 for the last customer
    return secs + 10;
}

int main() {
    int people, result;
    printf("Enter number of people: ");
    scanf("%d", &people);

    int arrival[people];
    printf("Enter arrival times: ");
    for (int i = 0; i < people; i++) {
        scanf("%d", &arrival[i]);
    }
    
    result = active_seconds(arrival, people);
    printf("Active seconds: %d", result);
    return 0;
}