#include <stdio.h>

void ptr_min_max(int *a, int n, int *max, int *min) {
    *max = *a; 
    *min = *a;
    int *p; 
    for (p = a; p < a + n; p ++) {
        if (*p > *max) {
            // note: using max = p basically assigns the two pointers together - ergo, you're getting nowhere
            // as when you're incrementing p, 
            // you're also incrementing max and min.
            // that's why the value needs to be dereferenced and pointed to instead.
            *max = *p; 
        }
        if (*p < *min) {
            *min = *p;
        }
    }

    return;
}

void ptr_compare_array(int a[], int n, int val, int *ct) {
    int *p; 
    // int ct = 0; 
    for (p = &a[0]; p < &a[n]; p++) {
        if (*p > val) {
            ct++;
        }
    }
    // return count; 
}

int main() {
    int n = 10; 
    int a[] = {82, 4, 6, 19, 1, 40, 29, 73, 90, 81};
    int max, min; 
    // int *ptr_max;
    int count = 0; 
    // ptr_min_max(a, n, &max, &min);
    // printf("%d %d \n", max, min);

    ptr_compare_array(a, n, 40, &count);
    printf("%d", count);

    return 0;
}