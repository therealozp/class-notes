#include <stdio.h>
#define MAXLEN 1000

void compress(char *input, char *output) {
    // traverse through the string and take note
    char *i, *o = output; 
    // default character count is 1
    int count = 1; 
    // if the previous character is not null, then keep going
    for (i = input + 1; *(i-1) != '\0'; i++) {
        // either append it, or keep going
        // first check if previous character is same as this one
        if (*i == *(i - 1)) {
            // if it is, increase the count and move on
            count++;
        } else {
            // if not, write previous character(s)
            // first check if character count is greater than 2
            if (count > 2) {
                // if yes, log the number (typecasted) and the character
                *o++ = '0' + count;
                *o++ = *(i - 1);
            } else if (count == 2) {
                // if it is = 2, then nothing happens, so append it twice: 
                *o++ = *(i - 1); 
                *o++ = *(i - 1);

            } else {
                // just write it out
                *o++ = *(i - 1);
            }
            count = 1;
        }
    }
    // after everything is over, write out a null character
    *o = '\0';
    return;
}

int main() {
    char str[MAXLEN], out[MAXLEN]; 
    char ch, *p = str; 
    printf("Enter message: ");
    // reserving space for the null character here
    while ((ch = getchar()) != '\n' && p < str + MAXLEN - 1) {
        *p = ch;
        p++; 
    }
    // printf("%s\n", str);
    // initializes null character
    *p++ = '\0';
    compress(str, out);
    printf("Output: %s", out);
    // printf("Your entered string is: %s", str);
    return 0;
}