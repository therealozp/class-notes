// Name: Phu Anh Khang Le
// Description: This program asks user for input file name,
// and grab the first character of every word in the input and print it to the output file

#include <stdio.h>
#include <string.h>
#define MAXLEN 100
#define MAXWORDS 1000

void decode(char words[][101], int num_words, char *result) {
    // iterate over the words array
    for (int i = 0; i < num_words; i++, result++) {
        // grab the first character
        *result = words[i][0];
    }
    *result = '\0';
}

// to get the new name of the output file
void getName(char *s1, char *s2) {
    char *p, *q = s2;
    // traverse to the end of the output file, because it is initialized as "decoded_"
    while (*q) {
        q++;
    }
    // copy each character of the input to the output file
    for (p = s1; *p != '\0'; p++, q++) {
        *q = *p;
    }
    *q = '\0';
}

int main() { 
    char input_filename[MAXLEN + 1], output_filename[MAXLEN + 1] = "decoded_";
    printf("Enter file input name: ");
    scanf("%s", input_filename);

    // call the getname function to get output file name
    getName(input_filename, output_filename);

    int num_words = 0;
    // since max words is 1000, max output string should also be number of words
    char message[MAXWORDS + 1]; 
    char words[MAXWORDS][MAXLEN + 1];

    // open file as pointers here
    FILE *infile = fopen(input_filename, "r");
    FILE *outfile  = fopen(output_filename, "w");

    int i = 0;

    while (!ferror(infile) && !feof(infile)) {
        // check for errors and eof, if not read the input into the array
        fscanf(infile, "%s", words[i++]);
        num_words++; 
    }

    // decode and write output here
    decode(words, num_words, message); 
    fprintf(outfile, "%s", message);

    // and close the file
    fclose(infile); 
    fclose(outfile);
    return 0; 
}