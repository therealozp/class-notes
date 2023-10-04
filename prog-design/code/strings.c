#include <stdio.h>
#define LENGTH 50

void concat(char *str1, char *str2) {
    char *p, *q;
    for (p = str1; *p != '\0'; p++);
    for (q = str2; *q!= '\0'; q++, p++) {
        *p = *q;
    }
}

int readline_ptr(char *str, int n) {
    // input should be an empty char
    char c, *p = str;
    int i = 0; 
    while (((c = getchar()) != '\n') && p < str + n-1) {
        if (p == str) {
            if (c == ' ') {
                continue;
            }
        }
        *p++ = c; 
        i++;    
    }
    *p = '\0';
    return i;
}

int main () {
    char st1[LENGTH+1];
    printf("Enter first string: ");
    int len = readline_ptr(st1, LENGTH + 1);
    printf("You have entered '%s' with string length of %d characters.", st1, len);
    // scanf("%s", st1);
    // char st2[LENGTH+1];
    // printf("Enter second string: ");
    // scanf("%s", st2);
    
    // concat(st1, st2);
    // printf("Concatenated string is: %s", st1);
    return 0;

}