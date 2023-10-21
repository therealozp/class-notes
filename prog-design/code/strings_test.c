#include <stdio.h>
#include <string.h>

void time_split(int total, int* hr, int* min, int* sec) {
    *hr = total / 3600; 
    *min = (total - *hr * 3600) / 60; 
    *sec = total - *hr * 3600 - *min * 60;
    return;
}

void edge(int *a1, int *a2, int n) {
    int *p, *q;
    q = a2; 
    *q++ = 0;
    for (p = a1; p < a1 + n - 1; p++, q++) {
        if (*p != *(p + 1)) {
            *q = 1;
        } else { 
            *q = 0;
        }
    }
}

void shift(char *message, int shift) {
    char *p; 
    for (p = message; *p != '\0'; p++) {
        if (*p >= 'A' && *p <='Z') {
            *p = (*p - 'A' + shift) % 26 + 'A'; 
        } else if (*p >='a' && *p <='z') {
            *p = (*p - 'a' + shift) % 26 + 'a'; 
        }
    }
}

void get_extension (char *filename, char *extension) {
    char *p, *q; 
    q = extension; 
    for (p = filename; *p != '.' && *p != '\0'; p++) ;
    p++; 
    if (*p == '\0') {
        *q = '\0';
    } else {
        while (*p != '\0') {
            *q++ = *p; 
            p++;
        }
        *q = '\0';
    }
}

void div_three(int *a, int*  b, int n1, int* n2) {
    int *p, *q;
    q = b;
    *n2 = 0;
    for (p = a; p < a + n1; p++) {
        if (*p % 3 == 0) {
            *q++ = *p;
            *n2 += 1;
        }
    } 
}

void div_three_no_q(int *a, int*  b, int n1, int* n2) {
    int *p, *q;
    *n2 = 0;
    for (p = a; p < a + n1; p++) {
        if (*p % 3 == 0) {
            *b++ = *p;
            *n2 += 1;
        }
    } 
}

void pre_star(char *s1, char *s2) {
    char *p; 
    for (p = s1; *p != '*' && *p != '\0'; p++) {
        *s2++ = *p;
    }
    *s2 = '\0';
}

void swap(char* a, char* b) { 
    char tmp[4];
    strcpy(tmp, a);
    strcpy(a, b);
    strcpy(b, tmp);
}

void general_case () {
    char w[3][4] = {"dog","rat", "cat"};
    for (int i = 0; i < 3; i++) {
        for (int j = i; j < 3; j++) {
            if (strcmp(w[j], w[i] )< 0) {
                swap(w[j], w[i]);
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        printf("%s, ", w[i]);
    }
}

int main(int argc, char* argv[]) {
    // int i, flag = 1; 
    // for (i = 1; i < argc; i++) {
    //     int m = strcmp(argv[i], argv[argc - i]);
    //     printf("The compared value between %s and %s is: %d \n", argv[i], argv[i-1],m);
    //     if (strcmp(argv[i], argv[argc - i])) {
    //         flag = 0;
    //         printf("flag set to 0");
    //     }
    // }
    // if (flag) {
    //     printf("YES");
    // } else { 
    //     printf("NO");
    // }
    // return 0;

    // int total = 36201, hr, min, sec;
    // time_split(total, &hr, &min, &sec);
    // printf("%d seconds is %d hr %d mins %ds from midnight.", total, hr, min, sec);

    // int a1[] = {0, 0, 1, 0, 1, 1, 0, 1};
    // int a2[8] = {0}; 
    // int n = 8;
    // int *p; 
    // edge(a1, a2, n);
    // for (p = a2; p < a2 + n; p++) {
    //     printf("%d", *p);
    // }
    // printf("\n");

    // char message[] = "Jr dkhdg, pdnh pb gdb.";
    // shift(message, 23);
    // printf("%s",message);

    // char filename1[] = "text.txt";
    // char filename2[] = "test.";
    // char ext1[10], ext2[10];

    // get_extension(filename1, ext1);
    // get_extension(filename2, ext2);

    // printf("%s\n", ext1);
    // printf("%s\n", ext2);

    // int a[5] = {99, 4, 3, 2, 6};
    // int b[5]; 
    // int b_noq[5];
    // int n1 = 5; 
    // int n2; 
    // int n2_noq; 


    // div_three(a, b, n1, &n2);
    // div_three_no_q(a, b_noq, n1, &n2_noq);

    // printf("using extra pointer: "); 
    // for (int i = 0; i < n2; i++) {
    //     printf("%d ", b[i]);
    // } 
    // printf("\n");

    // printf("without using extra pointer: "); 
    // for (int i = 0; i < n2_noq; i++) {
    //     printf("%d ", b_noq[i]);
    // }
    
    // char s1[20] = "cheese*cake";
    // char s2[10];

    // pre_star(s1, s2);
    // printf("%s\n", s2);

    // general_case();

    return 0;
}