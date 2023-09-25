#include <stdio.h>

void find_min_max(int a[], int n, int *max, int *min) {
    int largest = a[0]; 
    int smallest = a[0];
    for (int i = 0; i < n; i ++) {
        if (a[i] > largest) {
            largest = a[i];
        }
        if (a[i] < smallest) {
            smallest = a[i];
        }
    }

    *max = largest; 
    *min = smallest;

    return;
}

int * find_largest_ptr(int a[], int n) {
    // creates a pointer pointing to first element
    int *p = &a[0];
    for (int i = 0; i < n; i++) {
        // if current value is greater than ptr_value
        if (a[i] > *p) {
            // update ptr to point at the address of current
            p = &a[i];
        }
    }

    return p;
}

void find_two_largest(int a[], int n, int *max, int *second_max) {
    int largest = a[0]; 
    int second_largest = a[0]; 
    for (int i = 0; i < n; i++) {
        if (a[i] > largest) {
            second_largest = largest; 
            largest = a[i];
        } else {
            if (a[i] > second_largest) {
                second_largest = a[i];
            }
        }
    } 
    *max = largest;
    *second_max = second_largest;
    return;
}

int main() {
    int n = 9; 
    int a[] = {82, 4, 6, 19, 1, 40, 29, 73, 90, 81};
    int max, min, sec_max; 
    int *ptr_max;
    // find_min_max(a, n, &max, &min);
    // printf("%d %d \n", max, min);

    // ptr_max = find_largest_ptr(a, n);
    // printf("%d at %p \n", *ptr_max, ptr_max);

    find_two_largest(a, n, &max, &sec_max);
    printf("%d %d \n", max, sec_max);
    return 0;
}