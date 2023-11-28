#include <stdio.h>
#include <stdlib.h>

int f1(int f(int)); 
int f2(int); 
int sum(int g(int), int i, int j); 

int square(int i) {
    return i*i; 
}

int collatz(int i) {
    return 3*i - 1; 
}

int intcmp(const void *p, const void *q) {
    return *(int *)p - *(int *)q; 
}

void sortlast50() {
    int a[100] = {61, 6, 3, 21, 94, 80, 8, 1, 23, 9, 28, 13, 80, 12, 13, 22, 66, 74, 31, 15, 100, 44, 65, 20, 71, 71, 24, 61, 46, 47, 8, 29, 66, 80, 47, 50, 13, 90, 52, 8, 12, 98, 67, 7, 59, 18, 86, 57, 45, 82, 33, 33, 29, 7, 42, 63, 90, 52, 64, 43, 95, 51, 91, 21, 36, 44, 87, 61, 59, 100, 98, 18, 43, 100, 9, 1, 51, 13, 35, 58, 69, 1, 50, 96, 52, 73, 53, 30, 37, 3, 37, 3, 43, 91, 91, 20, 52, 45, 88, 97};
    qsort(a + 50, 50, sizeof(int), intcmp); 
    for (int i = 0; i < 100; i++) {
        printf("%d ", a[i]);
    }
}

int main () {
    // printf("Answer: %d\n", f1(f2));
    // printf("sum of squares from 1 to 10: %d\n", sum(square, 1, 10)); 
    // printf("sum of first collatz units from 1 to 10: %d\n", sum(collatz, 1, 10)); 
    sortlast50();
    return 0; 
}

int f1(int f(int)) {
    int n = 0; 
    while (f(n)) n++; 
    return n;
}

int f2(int i) {
    return i*i + i - 12;
}

int sum(int g(int), int i, int j) {
    int s = 0; 
    for (int p = i; p <= j; p++) {
        s += g(p); 
    }
    return s; 
}

