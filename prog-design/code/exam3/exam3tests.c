#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXLEN 5

int readline(char *str, int maxlength) {
    char ch; 
    int i = 0; 
    while (isspace(ch = getchar())); 
    str[i++] = ch; 
    while ((ch = getchar()) != '\n') { 
        if (i < maxlength) {
            str[i++] = ch;
        }
    }

    str[i] = '\0';
    return i; 
}

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
    FILE *pfile = fopen(filename, "r");
    if (pfile == NULL) {
        return 0;
    }
    char buff[1001]; 
    for (int i = 1; i < n && !feof(pfile); i++) {
        fscanf(pfile, "%[^\n]\n", buff);
        // printf("%s", buff);
    }
    if (feof(pfile)) {
        return 0;
    } 
    fscanf(pfile, "%[^\n]\n", buff);
    fclose(pfile);
    return strlen(buff); 
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
    while (fgets(chs, 1001, pfile) != NULL) {
        chcount+=strlen(chs);
    }
    rewind(pfile);
    while (!ferror(pfile) && !feof(pfile)) {
        if (fscanf(pfile, "%s", chs) == 1) {
            wcount++;
        }
    }
    rewind(pfile);
    while (!ferror(pfile) && !feof(pfile)) {
        if (fscanf(pfile, "%[^\n]\n", chs) == 1) {
            lcount++;
        } 
    }
    fclose(pfile);
    fprintf(stdout, "Number of chars: %d\n", chcount);
    fprintf(stdout, "Number of words: %d\n", wcount);
    fprintf(stdout, "Number of lines: %d\n", lcount);
    return;
}

int count_chars(const char *filename) {
    char str[1001]; 
    int count = 0; 
    FILE *pfile = fopen(filename, "r"); 
    if (pfile == NULL) {
        return 0;
    }
    while (!feof(pfile) && !ferror(pfile)) {
        if (fgets(str, 1000, pfile))count+=strlen(str); 
    }
    return count;
}

void append_sentence(const char * filename) {
    FILE *fp; 
    fp = fopen(filename, "a"); 
    fprintf(fp, "That's all, folks!\n");
    fclose(fp); 
}

void scanfiles(const char * filename) {
    FILE *pfile = fopen(filename, "r"); 
    if (pfile == NULL) { 
        fprintf(stderr, "Failed to open file\n"); 
        return;
    }
    char buffer[101]; 
    while (fgets(buffer, 100, pfile) != NULL) {
        printf("%s", buffer);
    }
    fclose(pfile);
    return; 
}

void demo() {
    char str1[100];
    char str2[100]; 

    fscanf(stdin, "%[^,]%[^,]" , str1, str2); 
    printf("%s\n", str1);
    printf(str2); 
}

int intcmp(const void *p, const void* q) {
    return *(int *)p - *(int *)q; 
}

void read_ints(const char* filename) {
    FILE * pfile = fopen(filename, "r"); 
    if (pfile == NULL) {
        printf("no such file");
        return; 
    }
    int arr[1100];
    int i = 0;
    while (!feof(pfile) && !ferror(pfile)) {
        fscanf(pfile, "%d", &arr[i++]);        
    }
    qsort(arr, i, sizeof(int), intcmp); 
    printf("Maximum element in file is: %d\n", arr[i - 1]);
    printf("Minimum element in file is: %d\n", arr[0]);
    return;
}


int main(int argc, char * argv[]) {
    // append_sentence(argv[1]);
    // scanfiles(argv[1]);
    // demo();
    // rewindtest();
    // printf("%d", line_length_with_fscanf("test.txt", 5));
    // upperify(argv[1]);
    // for (int i = 1; i < argc; i++) {
    //     fcat(argv[i]);
    // }
    fileanalysis(argv[1]);
    // read_ints(argv[1]);
    // printf("%d\n", count_chars("test.txt"));
    return 0;
}