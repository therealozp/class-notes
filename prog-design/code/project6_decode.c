#include <stdio.h>
#include <string.h>
#define MAXLEN 100
#define MAXWORDS 1000

void decode(char words[][101], int num_words, char *result) {
    
}

void getName(char *s1, char *s2) {
    char *p, *q;
    for (p = s1, q = s2; *p != '.'; p++, q++) {
        *q = *p;
    }
    *q = '\0';
}

int main() { 
    char input_filename[MAXLEN + 1], output_filename[MAXLEN + 1];
    printf("Enter file input name: ");
    scanf("%s", input_filename);
    // printf("Enter output file name: ");
    // scanf("%s", output_filename);
    getName(input_filename, output_filename);
    strcat(output_filename, "_decoded.txt"); 

    int num_words = 0;
    char message[MAXWORDS + 1];
    char words[MAXWORDS][MAXLEN + 1];

    FILE *infile = fopen(input_filename, "r");
    FILE *outfile  = fopen(output_filename, "w");
    int i = 0;
    while (!ferror(infile) && !feof(infile)) {
        fscanf(infile, "%s", words[i++]);
        num_words++; 
    }

    // for (int i = 0; i < num_words; i++) {
    //     printf("%s\n", words[i]);
    // }

    fclose(infile); 
    fclose(outfile);
    return 0; 
}