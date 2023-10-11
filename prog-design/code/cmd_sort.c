#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void p_sel_sort(int *arr, int N) {
    if (N == 1) {
        return;
    }
    int *p; 
    int *max = arr; 
    for (p = arr; p < arr + N; p++) {
        if (*p > *max) {
            max = p;
        }
    }
    int tmp = *(arr + N - 1);
    *(arr + N - 1) = *max; 
    *max = tmp;
    p_sel_sort(arr, N - 1);
}

void sel_sort(int arr[], int n) {
    if (n == 1) {
        return;
    }
    int lg = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > arr[lg]) {
            lg = i;
        }
    }

    int tmp = arr[n - 1];
    arr[n - 1] = arr[lg];
    arr[lg] = tmp;

    sel_sort(arr, n-1);
}

int main(int argc, char* argv[]) {
    int n = argc - 1;
    int a[n];
    // int t[5] = {3, 45, 1, 93, 20};
    if (argc < 2) {
        printf("Nothing to sort\n");
        return 0;
    } else {
        int *p, q;
        for (p = a, q = 1; p < a + n; p++, q++) {
            *p = atoi(argv[q]);
        }
        // sel_sort(a, n);
        p_sel_sort(a, n);
        for (int *i = a; i < a + n; i++) {
        printf("%d ", *i);
    }
    }
    // sel_sort(t, 5);
    // for (int *i = t; i < t + 5; i++) {
    //     printf("%d ", *i);
    // }
    printf("\n");
    return 0;
}