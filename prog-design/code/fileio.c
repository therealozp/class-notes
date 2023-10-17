#include <stdio.h>
#define STRLEN 50
// using fgets
int read_text (char* filepath) {
    // initializes tring
    char str[STRLEN + 1];
    // init file ptr
    FILE *pfile = fopen(filepath, "r");
    if (pfile == NULL) {
        printf("Error opening file \n");
        return 1; 
    }
    fgets(str, STRLEN+1,pfile);
    printf("%s", str);
    // flcose allows user to close file, and returns EOF if not closed successfully.
    fclose(pfile);
    return 0;
}

int line_by_line (char* filepath) {
    char str[STRLEN + 1];
    FILE *pfile = fopen(filepath, "r");
    if (pfile == NULL) {
        // pfile == null when there is an error
        printf("Error opening file \n"); 
        return 1;
    }
    while (fgets(str, STRLEN+1, pfile) != NULL) {
        // fgets == null when end of input 
        printf("%s", str);
    }
    fclose(pfile);
    return 0;
}

int line_by_line_write (char* filepath) {
    char str[STRLEN + 1];
    char outputpath[STRLEN + 1];
    FILE *pfile = fopen(filepath, "r");
    if (pfile == NULL) {
        // pfile == null when there is an error
        printf("Error opening file \n"); 
        return 1;
    }

    // get output file path
    char ch, *o = outputpath; 
    printf("enter output name: ");
    while ((ch = getchar()) != '\n' && o < outputpath + STRLEN - 1) { 
        *o = ch; 
        o++;
    }

    FILE *pout = fopen(outputpath, "w");
    if (pout == NULL) {
        printf("Error opening output file\n");
        return 1;
    } 

    while (fgets(str, STRLEN+1, pfile) != NULL) {
        // fgets == null when end of input
        char *p;
        // remove \n to get space
        for (p = str; *p != '\0'; p++) { 
            if (*p == '\n') {
                *p = ' ';
            }
        }
        fputs(str, pout);
    }
    fclose(pfile);
    return 0;
}

int main() { 
    // FILE *pfile; 
    char filepath[STRLEN + 1];
    char ch, *p = filepath; 
    printf("enter file name: ");
    while ((ch = getchar()) != '\n' && p < filepath + STRLEN - 1) { 
        *p = ch; 
        p++;
    }
    *p = '\0';
    // read_text(filepath);
    // line_by_line(filepath);
    line_by_line_write(filepath);
    return 1;
}

