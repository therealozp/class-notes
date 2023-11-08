#include <stdio.h>
#include <stdlib.h>

struct node {
    int val; 
    struct node *next;
};

struct node * push(struct node *top, int val) {
    struct node *new; 
    new = malloc(sizeof(struct node));
    if (new == NULL) {
        printf("malloc failed");
        return top;
    }
    new->val = val;
    new->next = top; 
    return new;
}

struct node * pop(struct node *top) {
    if (top == NULL) {
        printf("cannot pop off an empty list");
        return NULL; 
    }
    struct node *next_top = top->next;
    free(top);
    return next_top;
}

void print_stack(struct node *top) {
    printf("top\n");
    struct node *p; 
    for (p = top; p!=NULL; p=p->next) {
        printf("[%d]\n", p->val);
    }
    printf("end\n");
    return;
}

int main() {
    struct node * top = NULL;
    char op;
    int input;
    do {
        printf("What to do? "); 
        scanf("%c", &op); 
        if (op == 'p') {
            printf("pushing value of? ");
            scanf("%d", &input);
            top = push(top, input);
        } else if (op == 'r') {
            top = pop(top);
        } else {
            if (op != '\n') {
                print_stack(top);
            }
        }
    } while (op != 'q');
    return 0;
}