#include <stdio.h>

void reverse(int a[], int n) {
    int tmp;
    for (int i = 0; i < n / 2; i++) {
        tmp = a[i];
        a[i] = a[n - i - 1];
        a[n - i - 1] = tmp;
    } 
    return;
}

void pointers() {
    int i = 4; 
    int *p = &i;
    p = &i; 

    printf("%p\n", p); 
    printf("%p\n", &i); 
    printf("%d\n", i); 
    return; 
}

void ptr_arr(int a[], int n) {
    int *p; 
    for (int i = 0; i < n; i++) {
        p = &a[i];
        printf("%p: %d\n", p, *p);
    }
    return;
}

void single_ptr() {
    int i = 4, j = 6; 
    int *p; 
    int *q;
    p = &i; 
    q = &j; 
    printf("The values of i and *p are, respectively: %d, %d\n", i, *p); 
    printf("The addresses of &i and p are, respectively: %p, %p\n", &i, p);
    *p = 32;  
    printf("The values of i and *p are, respectively: %d, %d\n", i, *p);
    p = q; 
    printf("%d %d %d %d", i, j, *p, *q);
}

int recur(int x, int y) {
    if (x == 0) {
        return y;
    } else {
        return recur(x - 1, x + y);
    }
}

int main() {
    // int n = 6; 
    // int a[] = {5, 5, 4, 23, 2, 17};
    // for (int i = 0; i < n; i++) {
    //     printf("%d ", a[i]);
    // }
    // printf("\n");
    // reverse(a, n);
    // for (int i = 0; i < n; i++) {
    //     printf("%d ", a[i]);
    // }

    // pointers();
    // ptr_arr(a, n);
    // printf("%d", recur(2, 3));
    single_ptr();
    return 0;
}