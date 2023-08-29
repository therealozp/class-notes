#include <stdio.h>
#include <ctype.h>

int main() {
    char curr, prev;    
    int inOrder = 1;
    int valid = 1;
    printf("Enter input: ");
    do {
        curr = getchar();
        // printf("%c", curr);
        
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
        printf("invalid input");
    } else {
        if (inOrder) {
            printf("in order");
        } else {
            printf("not in order");
        }
    }
    // printf(lesser ? "true" : "false");
    return 0;
}