// Name: Phu Anh Khang Le
// Description: This program takes input from the CLI, and checks whether the input is in order.

#include <stdio.h>

int inOrder(char *input) {
    char *i;
    // loop stops if next character is null
    for (i = input; *(i + 1) != '\0'; i++) {
        if (*i > '0' && *i < '9') {
            // if it's a digit, return -1
            return -1;
        } else if (*i > *(i + 1)) {
            // if it's not in order, return 0 
            return 0;
        }
    }
    // if it manages to make it through the whole loop without encountering any of the cases, then it's good
    return 1;
}

int main(int argc, char* argv[]) {
    // if there is more or less than 2 arguments
    if (argc != 2) {
        printf("invalid input\n");
    } else {
        const int isInOrder = inOrder(argv[1]);
        if (isInOrder == -1) {
            printf("invalid input\n");
        } else if (isInOrder) {
            printf("in order\n");
        } else { 
            printf("not in order\n");
        }
    }
    return 0;
}