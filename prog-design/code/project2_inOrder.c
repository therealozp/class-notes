// Name: Phu Anh Khang Le
// Description: This program gets input with getchar() and checks if the input is in alphabetical order

#include <stdio.h>
#include <ctype.h>

int main() {
    // declare current character and previous character
    char curr, prev;    

    // initializes boolean variables
    int inOrder = 1;
    int valid = 1;
    printf("Enter input:");
    do {
        curr = getchar();
        
        // only keeps checking if string is valid
        if (valid) {
            // have to put this block here, else isalpha() will keep returning "valid" for subsequent characters
            if (curr != '\n') {
                valid = isalpha(curr);
                curr = tolower(curr);
            } else {
                // if it is a newline, ignore the rest of the code (because whitespace is the largest character)
                continue;
            }
            // only keeps checking if string is still in order
            if (inOrder) {
                // check if prev exists, else assign prev to curr and move on
                if (prev) {
                    // if prev appears sooner then curr, then it is still in order
                    inOrder = prev < curr;
                    prev = curr;
                } else {
                    prev = curr;
                }
            } 
        } else {
            continue;
        }
    } while (curr != '\n');

    if (!valid) {
        printf("invalid input\n");
    } else {
        if (inOrder) {
            printf("in order\n");
        } else {
            printf("not in order\n");
        }
    }
    return 0;
}