// Name: Phu Anh Khang Le
// Description: Program takes in a file (database) of animals
// and outputs the sorted list into a file.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLEN 100
#define MAXITEMS 200

// declare an animal struct, with the requisite props
struct animal {
    char name[MAXLEN + 1];
    char species[MAXLEN + 1];
    char gender[MAXLEN + 1];
    int age; 
    double weight;
};
// compare functions should take in the generic pointer
int species_comp(const void *p, const void *q) {
    // can return the result from strcmp directly, through typecasting the pointer
    // and accessing the species property
    return strcmp(((struct animal *)p)->species, ((struct animal *)q)->species);
}

int age_comp(const void *p, const void *q) {
    // do the same thing for this compare function, but instead can use the subtract operator
    return ((struct animal *)p)->age - ((struct animal *)q)->age;
}

int main() { 
    char* input_filename = "animals.txt";
    char* output_filename = "results.txt";

    FILE *infile = fopen(input_filename, "r");
    FILE *outfile = fopen(output_filename, "w");
    
    // initialize animals array to store and loop over
    struct animal animals [MAXITEMS];
    // with num_animals being the index
    int num_animals = 0;

    while (!ferror(infile) && !feof(infile)) {
        // scan all of the matching data into the current item of animals directly
        int readitems = fscanf(infile, "%s %s %s %d %lf", 
        animals[num_animals].name,
        animals[num_animals].species, 
        animals[num_animals].gender,
        &animals[num_animals].age,
        &animals[num_animals].weight);
        // since it will still scan the last item, make sure to exclude it 
        // not incrementing the numanimals will exclude the last element of the struct array
        if (readitems == 5)
            num_animals++;
    }

    // use quicksort
    qsort(animals, num_animals, sizeof(struct animal), age_comp);
    qsort(animals, num_animals, sizeof(struct animal), species_comp);

    for (int i = 0; i < num_animals; i++) {
        fprintf(outfile, "%s %d %s %.2lf %s\n",animals[i].species, animals[i].age, animals[i].name, animals[i].weight, animals[i].gender);
    }

    printf("Output file name: %s", output_filename);
    return 0;
}