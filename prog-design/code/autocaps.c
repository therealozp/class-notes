#include <stdio.h>

void to_upper() {
    char ch; 
    do {
        if (ch >= 'a' && ch <= 'z') {
            ch = ch - 'a' + 'A'; 
            printf("%c", ch);
        } else {
            printf("%c");
        }
    } while (ch != '\n');
    
    return;
}

int main () {
    char ch; 
    while ((ch = getchar()) != '\n') {
        if (ch >= 'A' && ch <= 'Z') {
            ch = ch - 'A' + 'a'; 
            printf("%c", ch);
        } else {
            printf("%c", ch);
        }
    }
    return 0;
}