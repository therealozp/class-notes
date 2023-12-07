#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int readline(char *str, int maxlength) {
    char ch; 
    int i = 0; 
    // while (isspace(ch = getchar())); 
    // str[i++] = ch; 
    while ((ch = getchar()) != '\n') { 
        if (i < maxlength) {
            str[i++] = ch;
        }
    }

    str[i] = '\0';
    return i; 
}

int comparestrs(const void *p, const void *q) {
    return strcmp(*(char**)p, *(char**)q); 
}

void sortstringinputs() {
    char inputbuffer[1001], *sentence = NULL;
    char* sentences[50];  
    int length;
    int i = 0;

    readline(inputbuffer, 1000); 
    length = strlen(inputbuffer);

    while (length != 0) {
        sentence = malloc(length * sizeof(char));
        if (sentence == NULL) {
            fprintf(stdout, "failed to allocate memory"); 
            return; 
        } 
        strcpy(sentence, inputbuffer);
        sentences[i++] = sentence; 
        readline(inputbuffer, 1000); 
        length = strlen(inputbuffer);
    }
    qsort(sentences, i, sizeof(char *), comparestrs); 
    for (int p = 0; p < i; p++) {
        printf("%s\n", sentences[p]);
    }  
}

void readingtest() { 
    char buff[11]; 
    FILE *pfile = fopen("test.txt", "r"); 
    fgets(buff, 10, pfile); 
    fclose(pfile);
    printf("%s", buff);
}

void f(int x) {
    if (x > 27) {
        return;
    }
    printf("%d ", x);
    x*=3; 
    f(x);
    printf("%d ", x);
}

int main() { 
    // readingtest();
    f(3);
    return 0; 
}