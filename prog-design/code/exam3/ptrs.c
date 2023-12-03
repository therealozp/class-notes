#include <stdio.h>
#include <stdlib.h>

void pointers(int *a, int n) { 
    for (int *i = a; i < a + n; i++ ) {
        printf("%d ", *i); 
    }
    printf("\n"); 
}

int main() { 
    int a[5] = {1, 2, 3, 4, 5}; 
    pointers(a, 5);
    return 0; 
}