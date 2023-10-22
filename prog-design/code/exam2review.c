#include <stdio.h>

void find_max_min(int *a, int *largest, int *smallest, int n) {
    *largest = *smallest = *a;
    int *p; 
    for (p = a; p < a + n; p++) {
        if (*p > *largest) {
            *largest = *p;
        }

        if (*p < *smallest) {
            *smallest = *p;
        }
    }

}

int* find_largest_ptr(int *a, int n) {
    int *p, *arr_max = a;
    for (p = a; p < a + n; p++) {
        if (*p > *arr_max) {
            arr_max = p; 
        }
    }

    return arr_max;
}

void multi_vec (int* v1, int* v2, int* v3, int n) {
    int *p, *q, *r; 
    for (p = v1, q = v2, r = v3; p < v1 + n; p++, q++, r++) {
        *r = *p * *q;
    }
}

int duplicates(int *a, int n) {
    int *p, *q, found = 0; 
    for (p = a; p < a + n; p++) {
        for (q = p + 1; q < a + n; q++) {
            if  (*p == *q) { 
                found = 1;
                break;
            }  
        }
        if (found) { 
            break;
        }
    }

    return found;
}

void concat(char* s1, char* s2) {
    for (; *s1 != '\0'; s1++) ;
    for (; *s2 != '\0'; s2++, s1++) {
        *s1 = *s2;
    }
    *s1 = '\0';
}

int readline(char* str, int n) {
    char ch; 
    char *p = str; 
    int count = 0; 
    while ((ch = getchar()) != '\n' && count < n) {
        if (ch == ' ' &&  p == str) { 
            continue;
        }
            *p++ = ch; 
    }
    *p = '\0';

    return count;
}

void reduce(int n, int d, int *rn, int *rd) {
    int gcd = 1; 
    int min = n < d ? n : d;

    for (int i = 1; i <= min; i++) {
        if (n % i == 0 && d % i == 0 && i > gcd) {
            gcd = i;
        }
    }

    *rd = d / gcd;
    *rn = n / gcd;
}

void read_pal() { 
    char str[1000], *s;
    char ch; 
    s = str;
    int is_pal, len = 0;
    while ((ch = getchar()) != '\n' && s < str + 1000 - 1) {
        if ((ch >= 'A' && ch <= 'Z') || (ch >='a' && ch <= 'z')) {
            if (ch >= 'A' && ch <= 'Z') {
            ch = ch - 'A' + 'a';
        }
        
        *s++ = ch;
        len++; 
        }
    }
    *s = '\0';
    // printf("%s", str);

    for (char *c = str, *r = str + len - 1; c < r; c++, r--) {
        if (*c != *r) {
            is_pal = 0;
        }
    }

    if(is_pal) {
        printf("pal\n");
    } else {
        printf("not pal\n");
    }
}

void rmfilename(char *url) {
    // traverse to the end
    char *p = url; 
    while (*p) {
        p++; 
    }

    for (; *p != '/' && p != url; p--) {
        *p = '\0';
    }
    *p = '\0';

}

int main () {
    // reading str with scanf doesnt need &
    // char str[100];
    // scanf("%s", str);

    // printf("%s", str); 

    // int n = 9; 
    // int a[] = {82, 4, 6, 19, 4, 40, 29, 73, 90};
    // int found = duplicates(a, n); 
    // int *max, min; 
    // find_max_min(a, &max, &min, n);
    // printf("%d %d \n", max, min);

    // max = find_largest_ptr(a, n);
    // printf("%d at %p \n", *max, max);
     
    // int n = 3; 
    // int v1[] = {1, 2, 3};
    // int v2[] = {4, 5, 6};
    // int v3[3]; 

    // multi_vec(v1, v2, v3, n); 

    // for (int *p = v3; p < v3 + n; p++) {
        // printf("%d ", found);
    // } 

    // char s1[100] = "Program";
    // char s2[100] = "Design";

    // concat(s1, s2);
    // printf("%s", s1);

//     char *planets[] = {"Mercury", "Venus", "Earth",
// "Mars", "Jupiter", "Saturn",
// "Uranus", "Neptune", "Pluto"};

//     for (char **p = planets; p < planets + 9; p++) {
//         printf("%s ", *p);
//     }

    // char s1[100]; 
    // readline(s1, 100); 
    // printf("%s", s1);
    // int n = 4;
    // int d = 6;
    // int rd, rn; 
    // reduce(n, d, &rn, &rd);
    // printf("The reduction of %d/%d is %d/%d", n, d, rn, rd);

    // read_pal();
    char url[] = "https://www.youtube.com/index.html"; 
    rmfilename(url); 
    printf("%s", url);

    return 0;
}