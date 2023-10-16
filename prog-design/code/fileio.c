#include <stdio.h>
#define STRLEN 50
// using fgets
int read_text (char* filepath) {
    // initializes tring
    char str[STRLEN + 1];
    // init file ptr
    FILE *pfile = fopen(filepath, "r");

}

int main() { 
    // FILE *pfile; 
    read_text("source.txt");
    return 1
}