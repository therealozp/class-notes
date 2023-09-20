#include <stdio.h>

int find_largest(int a[], int l) {
    int largest_index = 0; 
    for (int i = 0; i < l; i++) {
        if (a[i] > a[largest_index]) {
            largest_index = i;
        }
    }
    return largest_index;
}

void selection_sort(int a[], int l) {
    int largest_index = find_largest(a, l);
    if (l == 1) {
        return;
    }
    int tmp = a[l - 1];
    a[l - 1] = a[largest_index];
    a[largest_index] = tmp;
    selection_sort(a, l - 1);
}

int main() { 
    int n;
    printf("Enter length of array: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("\n");
    selection_sort(arr, n);
    printf("Sorted order: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

