#include <stdio.h>
#include <stdbool.h>

int main() {
    char gpa = 'A'; // 'A' is a character %c
    char s[] = "Hello World!\n"; // "Hello World!\n" is a string  %s

    float f = 0.666; // 4 bytes 0.666 is a floating point (7-8 digits) %f
    double d = 0.23; // 8 bytes 0.23 is a double (15-16 digits) %lf

    bool b = true; // true is a boolean %
    
    char ascii = 65; // 65 is an ascii character %c
    unsigned char ch = 255; // stores 0-255 %c
    
    short int h = 32767; // 2 bytes %d (from -32768 to 32767)
    unsigned short int uh = 65535; // 2 bytes %d (from 0 to 65535)

    int i = 2147483647; // 4 bytes %d (from -2147483648 to 2147483647)
    unsigned int ui = 4294967295; // 4 bytes %u (from 0 to 4294967295)

    long long int lli = 9223372036854775807; // 8 bytes %lld (from -9 quintillion to 9 quintllion)
    unsigned long long int ulli = 18446744073709551615; // 8 bytes %llu (from 0 to 18 quintillion)

    // format specifiers
    // %c - character
    // %s - string
    // %f - float
    // %lf - double
    // %d - integer
    // %u - unsigned integer
    // %lld - long long integer
    // %llu - unsigned long long integer
    // %h - short integer
    // %uh - unsigned short integer
    // %b - boolean

    // %.1f - decimal place precision
    // %10 - minimum width
    // %- - left align
    
    printf(s);
    return 0;
};