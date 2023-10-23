#include <stdio.h>

int find_largest(int a[], int l) {
    int largest_index = 0; 
    for (int i = 0; i < l; i++) {
        if (a[i] > a[largest_index]) {
            largest_index = i;
        }
    }
    return largest_index;
}

void selection_sort(int a[], int l) {
    int largest_index = find_largest(a, l);
    if (l == 1) {
        return;
    }
    int tmp = a[l - 1];
    a[l - 1] = a[largest_index];
    a[largest_index] = tmp;
    selection_sort(a, l - 1);
}


int sort_file (char* inputname, char* outputname) {
    FILE *input = fopen(inputname, "r"); 
    FILE *output = fopen(outputname, "w"); 

    if (input == NULL || output == NULL) {
        printf("Error opening input file");
        return 1;
    }

    int a[1000]; 
    int i = 0;
    // fgets doesn't need this loop cuz it returns null 
    while (!feof(input) && !ferror(input)) {
        // fscanf is better for this
        if (fscanf(input, "%d", &a[i]) == 1) i++;
    }

    printf("There are %d numbers in this file", i);
    selection_sort(a, i);

    for (int *p = a; p < a + i; p++) {
        // also fprintf(file_ptr, format, variables
        )
        fprintf(output, "%d\n", *p);
    }

    fclose(input);
    fclose(output);

    return 1;
}

int main() {
    char input[15], output[15];
    printf("Enter name: ");
    scanf("%s", input);
    printf("Enter name: ");
    scanf("%s", output);

    sort_file(input, output);
}