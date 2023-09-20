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

int main() {
    int n = 6; 
    int a[] = {5, 5, 4, 23, 2, 17};
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    reverse(a, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}