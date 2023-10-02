// Name: Phu Anh Khang Le
// Description: This program accepts an array of arrival timestamps of people into an escalator
// and calculate the total time it will operate

#include <stdio.h>

int active_seconds(int *arrival, int n) {
    // secs for total second, and end for expected final second that the escalator operates
    int secs = 0;
    int end = 0;
    int *curr_ptr;
    // point prev_ptr to the first element of arrival

    for (curr_ptr = arrival; curr_ptr < (arrival + n); curr_ptr++) {
        if (!end) {
            // if there has not been already an end (or end is 0),
            //  then it is the time that the person boards the escalator + 10
        } else {
            if (*curr_ptr > end) {
                // if the arrival time of the next person is greater than the current ending time
                // then the previous person would have already gotten off the escalator.
                // so add 10 to the operating time and initialize a new end point.
                secs += 10;
            } else {
                // if it is NOT greater, then the total seconds operate are the difference between two timestamps
                // but the end should still be 10s more than the arrival of the current person
                secs += (*curr_ptr - *(curr_ptr - 1));
            }
        }        
        end = *curr_ptr + 10;
    }
    // so far, the loop only runs until the last person boarded, 
    // so add 10 for the last customer
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