#include <stdio.h>

void exclusive_or(int *a, int n1, int *b, int n2, int *c, int *size) {
    // intialize pointers for array a, b, and c
    int *p, *q, *r;
    int *curr = c; // initialize a pointer pointing to the first element of output
    for (p = a; p < (a + n1); p++) {
        int found = 0; // not found yet
        for (q = b; q < (b + n2); q++) {
            if (*p == *q) { // these two have the same value
                found = 1; 
                break;
            }
        }
        if (!found) {
            // set the value of the current pointer to the not-found value
            *curr = *p;
            // and increment it to the next
            curr++;
            // and increment size
            *size += 1;
        }
    }
    // and do it again to get difference of b and a
    for (q = b; q < (b + n2); q++) {
        int found = 0; // not found yet
        for (p = a; p < (a + n1); p++) {
            if (*p == *q) { // these two have the same value
                found = 1; 
                break;
            }
        }
        if (!found) {
            // do the same, but just point it to q (the bigger element) instead
           *curr = *q;
            curr++;
            *size += 1;
        }
    }
    printf("Output: ");
    for (r = c; r < (c + *size); r++) {
        printf("%d ", *r);
    }
};

int main() {
    int n1, n2;
    int size = 0;
    printf("Enter length of array #1: ");
    scanf("%d", &n1); 
    int a[n1];
    printf("Enter array elements: ");
    for (int i = 0; i < n1; i++) {
        scanf("%d", &a[i]);
    }
    // for (int i = 0; i < n1; i++) {
    //     printf("%d ", a[i]);
    // }
    printf("Enter length of array #2: ");
    scanf("%d", &n2); 
    int b[n2];
    printf("Enter array elements: ");
    for (int i = 0; i < n2; i++) {
        scanf("%d", &b[i]);
    }
    //  for (int i = 0; i < n2; i++) {
    //     printf("%d ", b[i]);
    // }
    int c[n1 + n2]; 

    exclusive_or(a, n1, b, n2, c, &size);
    return 0; 
}