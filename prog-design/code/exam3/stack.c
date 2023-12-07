#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct node {
    int val; 
    struct node * next; 
};

struct node * push(struct node * list, int n ) {
    struct node * new = malloc(sizeof(struct node));
    if (new == NULL) {
        return list;
    } 
    new->val = n; 
    new->next = list; 
    return new;
} 

struct node * pop(struct node * list, int* i) {
    struct node * curr = list;
    if (list == NULL) {
        return list; 
    } 
    list = list->next; 
    *i = curr->val;
    free(curr); 
    return list; 
}

void printll(struct node *list) {
    printf("[top]\n"); 
    for (struct node *p = list; p != NULL; p = p->next) {
        printf("[%d]\n", p->val);
    }
}

struct node * clear(struct node * list) {
    struct node * curr; 
    while (list != NULL) {
        curr = list; 
        list = list->next; 
        if (curr != NULL) {
            free(curr); 
        }
    }
    return NULL; 
}

int main(void) {
    int n;
    struct node *head = NULL;
    struct node *stack2 = NULL;

    head = push(head, 25);
    head = push(head, 32);
    head = push(head, 8);
    head = push(head, 94);

    stack2 = push(stack2, 21);

    printf("head:\n");
    printll(head);

    printf("stack2:\n");
    printll(stack2);

    head = pop(head, &n);
    printf("Popped %d from head\n", n);
    printf("head:\n");

    printll(head);
    stack2 = push(stack2, n);
    printf("stack2:\n");
    printll(stack2); 
    return 0; 
}