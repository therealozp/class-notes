#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 5

void rewindtest() {
    FILE *infile = fopen("input.txt", "r+");
    FILE *outfile = fopen("output.txt", "w");
    char buffer[6];
    while (fgets(buffer, MAXLEN + 1, infile) != NULL) {
        // printf("%s", buffer);
        if (strcmp(buffer, "youre") == 0) {
            break;
        }
        fputs(buffer, outfile);
    }
    fputs("gay and ", infile);

    fclose(infile);
    fclose(outfile);
    return;
};

int line_length(const char *filename, int n) {
    int line = 1; 
    int count = 0;
    FILE *pfile = fopen(filename, "r");
    char buffer[2];
    while (line != n && !feof(pfile)) {
        while (fgets(buffer, 2, pfile) != NULL && strcmp(buffer, "\n") != 0);
        line++;
    }
    if (feof(pfile)) {
        return 0;
    }
    while (fgets(buffer, 2, pfile) != NULL && strcmp(buffer, "\n") != 0) {
        count++;
    };

    fclose(pfile);

    return count;
}

int line_length_with_fscanf(const char *filename, int n) {
    int line = 1; 
    int count = 0;
    char ch; 
    FILE *pfile = fopen(filename, "r");
    while(line != n && !ferror(pfile) && !feof(pfile)) {
        while(fscanf(pfile, "%c", &ch) && ch != '\n');
        line++; 
    }
    if (feof(pfile)) {
        return 0; 
    }

    while (fscanf(pfile, "%c", &ch) && ch != '\n') {
        count ++;
    }
    fclose(pfile);
    return count; 
}

void upperify(const char *filename) {
    FILE *pfile = fopen(filename, "r");
    char ch; 
    while (!ferror(pfile) && !feof(pfile)) {
        if (fscanf(pfile, "%c", &ch) != 1) return;
        if (ch >= 'a' && ch <= 'z') {
            ch -= 32;
        }
        fprintf(stdout, "%c", ch);
    }
    fclose(pfile);
    return;
}

void fcat(const char *filename) {
    FILE *pfile = fopen(filename, "r");
    char buffer[1001];
    if (pfile == NULL) {
        fprintf(stderr, "Error opening file"); 
        return;
    }
    while (fgets(buffer, 1000, pfile) != NULL) {
        fprintf(stdout, "%s", buffer);
    }
    fclose(pfile);
    return;
}

void fileanalysis(const char* filename) {
    FILE *pfile = fopen(filename, "r");
    int chcount = 0; 
    char ch; 
    int wcount = 0;
    char chs[1001]; 
    int lcount = 0;
    if (pfile == NULL) {
        fprintf(stderr, "error opening file\n"); 
        return;
    }
    while (!ferror(pfile) && !feof(pfile)) {
        if (fscanf(pfile, "%c", &ch) == 1) {
            chcount++;
        }
    }
    rewind(pfile);
    while (!ferror(pfile) && !feof(pfile)) {
        if (fscanf(pfile, "%s", chs) == 1) {
            wcount++;
        }
    }
    rewind(pfile);
    while (!ferror(pfile) && !feof(pfile)) {
        if (fscanf(pfile, "%c", &ch) == 1 && (ch == '\n')) {
            lcount++;
        } 
    }
    lcount++; // 1 more for eof
    fclose(pfile);
    fprintf(stdout, "Number of chars: %d\n", chcount);
    fprintf(stdout, "Number of words: %d\n", wcount);
    fprintf(stdout, "Number of lines: %d\n", lcount);
    return;
}

int main(int argc, char * argv[]) {
    // rewindtest();
    // printf("%d", line_length_with_fscanf("test2.txt", 1));
    // upperify(argv[1]);
    // for (int i = 1; i < argc; i++) {
    //     fcat(argv[i]);
    // }
    fileanalysis(argv[1]);
    return 0;
}