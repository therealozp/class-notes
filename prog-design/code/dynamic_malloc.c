#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STRLEN 1000

void readline(char *str, int* n) {
    char ch;
    while ((ch = getchar()) != '\n') {
        *str++ = ch;
        (*n)++;
    }
    *str = '\0';
    return;
}

void dynamic_string () {
    char buffer[STRLEN + 1];
    int num_chars = 0; 
    char *str;

    readline(buffer, &num_chars);
    // allocate memory
    str = malloc(num_chars * sizeof(char));
    // check for null ptrs
    if (str == NULL) {
        printf("Memory could not allocated at dynamic_string()\n");
        return;
    }
    strcpy(str, buffer);
    printf("%s", str);
    // dalloc / free memory
    free(str);
}

int compare_strs(const void *p, const void *q ) {
    return strcmp(*(char **)p, *(char **)q);
}


void dynamic_sentences() {
    char input_buffer[1001];
    int length = 0; 
    char *sentence = NULL; 
    char *sentences[50]; 
    int num_sentences = 0; 

    do {
        length = 0; 
        readline(input_buffer, &length);
        if (length == 0) break;
        sentence = malloc(length * sizeof(char));
        if (sentence == NULL) {
            printf("Memory allocation failed at dynamic_sentences()\n");
            return;
        }
        strcpy(sentence, input_buffer);
        sentences[num_sentences] = sentence;
        // free(sentence);
        num_sentences++;
    } while (num_sentences <= 50);
    // printf("%d", num_sentences);
    qsort(sentences, num_sentences, sizeof(char *), compare_strs);

    for (int i = 0; i < num_sentences; i++) {
        printf("%s\n", sentences[i]);
    }
    return;
}

int dynamic_ints() {
    int *a; 
    a = malloc(sizeof(int));
    if (a == NULL) {
        printf("Memory cannot be allocated\n");
        return 1;
    }
    return 0;
}

int main() {
    dynamic_sentences();
    return 0;
}