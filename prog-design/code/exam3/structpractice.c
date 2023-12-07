#include <stdio.h>
#include <stdlib.h>
#define sf struct frac
#define sfp struct frac *

struct complex {
    double real; 
    double imaginary; 
}; 

struct complex makecomplex(double real, double imaginary) {
    struct complex new; 
    new.real = real; 
    new.imaginary = imaginary;
    return new;
}

struct complex addcomplex(struct complex c1, struct complex c2) {
    struct complex new = makecomplex(c1.real + c2.real, c1.imaginary + c2.imaginary); 
    return new;
}

struct date { 
    int month; 
    int day; 
    int year;
}; 

int dayofyear(struct date d) {
    int currday = 0; 
    for (int i = 1; i < d.month; i++) {
        switch (i) {
            case 2: 
                currday += ((d.year % 100 % 4 == 0) || d.year % 400 == 0) ? 29 : 28;
                break;
            case 1: 
            case 3: 
            case 5:
            case 7: 
            case 8: 
            case 10: 
            case 12:
                currday += 31;
                break;
            default: 
                currday += 30; 
                break;
        }
    }
    currday += d.day; 
    return currday;
}

int datecmp(struct date d1, struct date d2) {
    if (d1.year > d2.year) {
        return 1;
    } else if (d1.year < d2.year) {
        return -1;
    } else {
        if (d1.month > d2.month) {
            return 1;
        } else if (d1.month < d2.month) {
            return -1;
        } else {
            return d1.day > d2.day ? 1 : d1.day < d2.day ? -1 : 0;
        }
    }
}

struct frac { 
    int num; 
    int dec; 
}; 

int gcd(int a, int b) {
    if (a < 0) a = -a; 
    if (b < 0) b = -b; 
    if (a == 0) return b; 
    if (b == 0) return a; 
    int mod = a > b ? a % b : b % a; 
    if (a > b) { 
        return gcd(b, mod);
    } else {
        return gcd(a, mod);
    }
}

void simplify(struct frac * b) {
    int g = gcd(b->num, b->dec); 
    b->num = b->num/g; 
    b->dec = b->dec/g;
}

sfp addf(sfp f1, sfp f2) {
    sfp new = malloc(sizeof(sf));
    new->num = f1->num * f2->dec + f2->num * f1->dec;
    new->dec = f1->dec * f2->dec; 
    simplify(new); 
    return new; 
}

sfp subf(sfp f1, sfp f2) {
    sfp new = malloc(sizeof(sf));
    new->num = f1->num * f2->dec - f2->num * f1->dec;
    new->dec = f1->dec * f2->dec; 
    simplify(new); 
    return new; 
}

sfp mulf(sfp f1, sfp f2) {
    sfp new = malloc(sizeof(sf));
    new->num = f1->num * f2->num;
    new->dec = f1->dec * f2->dec; 
    simplify(new); 
    return new; 
}

sfp divf(sfp f1, sfp f2) {
    sfp new = malloc(sizeof(sf));
    new->num = f1->num *  f2->dec;
    new->dec = f1->dec * f2->num; 
    simplify(new); 
    return new; 
}

int main() {
    struct frac * f = malloc(sizeof(struct frac)); 
    f->num = 4; 
    f->dec = 12; 

    sfp f2 = malloc(sizeof(sf)); 
    f2->num = 5; 
    f2->dec = 13;
    
    sfp f3 = mulf(f, f2);
    simplify(f3); 
    printf("simplified: %d/%d", f3->num, f3->dec);
    // struct complex c1, c2, c3;
    // c1 = makecomplex(4, 5);
    // c2 = makecomplex(7, 1); 
    // c3 = addcomplex(c1, c2);

    // printf("complex c3: %lf %lf", c3.real, c3.imaginary); 

    // struct date d1, d2;
    // d1.day = 12; 
    // d1.month = 8; 
    // d2.year = 2023; 

    // d2.day = 3; 
    // d2.month = 2; 
    // d2.year = 2024;

    // printf("%d %d", dayofyear(d2), datecmp(d2, d1));

    return 0;
}