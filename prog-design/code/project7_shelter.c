// Name: Phu Anh Khang Le
// Description: Program takes in a file (database) of animals
// and outputs the queried animals onto another output file

#include <stdio.h>
#include <string.h>
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
        fscanf(infile, "%s %s %s %d %lf", 
        animals[num_animals].name,
        animals[num_animals].species, 
        animals[num_animals].gender,
        &animals[num_animals].age,
        &animals[num_animals].weight);

        num_animals++;
    }

    char species_query[MAXLEN + 1];
    char gender_query[MAXLEN + 1];
    printf("Enter species: ");
    scanf("%s", species_query);
    printf("Enter gender: ");
    scanf("%s", gender_query);

    for (int i = 0; i < num_animals; i++) {
        // here, check whether EITHER of the strcmps return anything OTHER THAN 0
        // because if they do, then it's already different 
        if (strcmp(gender_query, animals[i].gender) || strcmp(species_query, animals[i].species)) {
            // skip the printf statement if so
            continue;
        }
        fprintf(outfile, "%s %d %.2lf\n", animals[i].name, animals[i].age, animals[i].weight);
    }

    printf("Output file name: %s", output_filename);
    return 0;
}