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
        return 2 + recur(x - 1, 2 * y);
    }
}

void switches (int grade) {
    switch (grade) {
        case 4: printf("Excellent"); 
        case 3: printf("Good");
        case 2: printf("Average");
        case 1: printf("Poor");
        case 0: printf("Failing");
        default: printf("Illegal");
    }

    return;
}

void test_ifs () {
    int i;
    scanf("%d", &i);
    printf("This is an if statement without block def: \n");
    if (i > 9) 
        printf("executed \n");
    else 
        printf("also executed \n");
    return; 
}

void test_fors () {
    int i = 0;
    for (i = 0; i < 10; i++);
        printf("%d ", i);
    return;
}

int find_elements(int a[], int n1, int b[], int n2, int c[]) {
    int c_index = 0; 
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            if (a[i] == b[j]) {
                c[c_index] = a[i]; 
                c_index++;
                break;
            }
        }
    }

    return c_index;
}

void my_sort(int a[], int n) {
    int i, j; 
    for (int i = 0; i < n - 1; i++) {
        int smallest = i;
        for (j = i; j < n; j++) {
            if (a[j] < a[smallest]) {
                smallest = j;
            }
        }
        int tmp; 
        tmp = a[i]; 
        a[i] = a[smallest]; 
        a[smallest] = tmp;
    }
}

int log_base_2(int n) {
    if (n == 1) {
        return 0; 
    } else {
        return 1 + log_base_2(n / 2);
    }
}

int find_difference(int a[], int n1, int b[], int n2, int c[]) {
    int c_index = 0; 
    for (int i = 0; i < n1; i++) {
        int is_found = 0;
        for (int j = 0; j < n2; j++) {
            if (a[i] == b[j]) {
                is_found = 1;
                break;
            }
        }
        if (!is_found) {
            c[c_index] = a[i]; 
            c_index++;
        }
    }
    return c_index;
}

int main() {
    // int n = 6; 

    // int i, j, k;
    // int a[] = {5, 5, 4, 23, 2, 17};

    // i = 7; j = 8;
    // i *= j + 1;
    // printf("%d %d \n", i, j); // 63, 8

    // i = j = k = 1;
    // i += j += k;
    // printf("%d %d %d\n", i, j, k); // 3, 2, 1

    // i = 1; j = 2; k = 3;
    // i -= j -= k;
    // printf("%d %d %d\n", i, j, k); // 2, -1, 3

    // i = 2; j = 1; k = 0;
    // i *= j *= k;
    // printf("%d %d %d\n", i, j, k); // 0, 0, 0

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
    printf("%d", recur(2, 3));
    // single_ptr();
    // switches(3); 
    // test_ifs();
    // test_fors();

    // int a[] = {1, 2, 3, 8, 9};
    // int b[] = {3, 2, 6, 7}; 
    // int c[5]; 
    // int res = find_difference(a, 5, b, 4, c);

    // printf("There is %d elements in c. \n", res);

    // my_sort(a, 6);
    // for (int i = 0; i < 6; i++) {
    //     printf("%d ", a[i]);
    // }

    // printf("%d", log_base_2(8));

    return 0;
}