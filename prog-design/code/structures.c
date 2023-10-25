#include <stdio.h>
#include <string.h>
#define NUM_CHARS 30

// color struct
struct color { 
    int r, g, b; 
};

struct color build_color(int r, int g, int b) {
    struct color c; 
    c.r = r < 0 ? 0 : r > 255 ? 255 : r;
    c.g = g < 0 ? 0 : g > 255 ? 255 : g;
    c.b = b < 0 ? 0 : b > 255 ? 255 : b;

    return c; 
}

struct color brighten(struct color c) {
    c.r = c.r / 0.7 > 255 ? 255 : c.r / 0.7;
    c.g = c.g / 0.7 > 255 ? 255 : c.g / 0.7;
    c.b = c.b / 0.7 > 255 ? 255 : c.b / 0.7;

    return c; 
}

void print_color(struct color c) {
    printf("R: %d, G: %d, B: %d \n", c.r, c.g, c.b);
}

// magformer struct
struct magformer {
    char color[NUM_CHARS + 1];
    char shape[NUM_CHARS + 1];
    int quantity; 
};

// a constructor function
struct magformer build_mag(char* color, char* shape, int quantity) {
    struct magformer m; 
    strcpy(m.color, color);
    strcpy(m.shape, shape);
    m.quantity = quantity;
    return m; 
}

int compare_magformers(struct magformer m1, struct magformer m2) {
    if (strcmp(m1.color, m2.color) == 0 && strcmp(m1.shape, m2.shape) == 0) {
        return 1;
    }
    return 0;
}

int main() { 
    // initializing a struct two ways
    // struct magformer m1 = {"purple", "square", 1}; 
    // struct magformer m2;
    // struct magformer m3 = {"purple", "square", 2};
    // accessible through name.property
    // printf("Enter color: ");
    // scanf("%s", m2.color);
    // printf("Enter shape: ");
    // scanf("%s", m2.shape);
    // printf("Enter quantity: ");
    // scanf("%d", &m2.quantity);
    // printf("%d", compare_magformers(m1, m3));
    
    struct color gold = build_color(255, 215, 0);
    struct color brighter_gold = brighten(gold);

    print_color(gold);
    print_color(brighter_gold);

    return 0;
}