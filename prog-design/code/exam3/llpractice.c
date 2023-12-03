#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char * duplicate(char *str) {
    char *p = str; 
    int len = 0; 
    for (; *p != '\0'; p++) {
        len++;
    }
    char * newstr = malloc(len + 1); 
    if (newstr == NULL) {
        fprintf(stderr, "Failed to allocate memory"); 
        return NULL; 
    }
    for (p = str; *p != '\0'; p++) {
        *newstr = *p; 
        newstr++; 
    }
    *newstr = '\0'; 
    return newstr; 
}

int *create_array(int n, int init) {
    int *a;
    a = malloc(sizeof(int) * n); 
    for (int i = 0; i < n; i++) {
        *(a + i) = init; 
    }
    return a;
}

struct point { 
    int x; 
    int y; 
}; 

struct rect {
    struct point upleft, lowright; 
}; 

void declare_rect() { 
    struct rect * p = malloc(sizeof(struct rect)); 
    p->lowright.x = 20; 
    p->lowright.y = 15; 
    p->upleft.x = 10; 
    p->upleft.y = 25; 
}

struct node { 
    int val; 
    struct node * next; 
};

void cfree(struct node *list) { 
    struct node * p; 
    while (list) {
        p = list; 
        list = list->next; 
        if (p != NULL) {
            free(p); 
        }
    }
}

struct node * push(struct node *list, int val) {
    struct node * new = malloc(sizeof(struct node)); 
    if (new == NULL) {
        fprintf(stderr, "Error allocating memory"); 
        return NULL; 
    }
    new->val = val; 
    new->next = list; 
    return new; 
}

struct node * find_last(struct node * list, int n) {
    struct node *p, *r = NULL; 
    int count = 0; 
    for (p = list; p != NULL; p = p->next) {
        if (p->val == n) {
            r = p;
            printf("Pointer reassignment occured %d times \n", count++);
        }
    }
    return r; 
}

void printll(struct node *list) {
    for (struct node *p = list; p != NULL; p = p->next) {
        printf("[%d]\n", p->val);
    }
}

struct node *insertBefore(struct node *list, int nb, int n) { 
    struct node *prev, *curr; 
    for (prev = NULL, curr = list; curr != NULL && curr->val != nb; prev = curr, curr = curr->next);
    
    if (curr == NULL) {
        return list; 
    }
    struct node * new = malloc(sizeof(struct node)); 
    new->val = n; 

    if (prev == NULL) {
        new->next = list; 
        return new;
    }

    prev->next = new; 
    new->next = curr; 
    return list;
}

struct node * insertAfter(struct node *list, int nb, int n) {
    struct node *p, *c; 
    for (c = list, p = NULL; c != NULL; c = c->next) {
        if (p != NULL && p->val == nb) {
            break;
        }
        p = c; 
    }

    if (p == NULL || p->val != nb) {
        // no pointer found
        printf("No pointer of value found\n"); 
        return list;
    }

    struct node *new = malloc(sizeof(struct node)); 
    if (new == NULL) {
        printf("failed"); 
        return list; 
    }

    new->val = n; 
    new->next = c; 
    p->next = new; 

    return list;
}

struct node * delete(struct node * list, int n) {
    struct node *curr, *prev = NULL; 
    for (curr = list, prev = NULL; curr != NULL && curr->val != n; prev = curr, curr = curr->next); // locate node to delete

    // at this time, either empty list, whole list traversed, first element, or normal case.
    if (curr == NULL) {
        return list;
    }

    if (prev == NULL) {
        list = list->next; 
        free(curr);
    } else {
        prev->next = curr->next; 
        free(curr); 
    }
    return list; 
}

int size(struct node *list) {
    int s = 0; 
    for (struct node * p = list; p != NULL; p = p->next) {
        s++; 
    }
    return s; 
}

struct node *delete_all(struct node * list, int n) {
    int c_size, p_size;
    c_size = size(list); 
    p_size = 0; 
    while (c_size != p_size) {
        list = delete(list, n);
        p_size = c_size; 
        c_size = size(list); 
    }
    return list;
}

struct node * move_first_to_last(struct node * list) {
    struct node * first = list; 
    struct node * last = list; 
    for (; last != NULL && last->next != NULL; last = last->next);
    if (list == NULL) {
        return list; 
    }
    list = list->next; 
    last->next = first; 
    first->next = NULL; 
    return list; 
}

struct node * move_last_to_first(struct node * list) {
    struct node * last = list; 
    struct node * prev = NULL; 
    for (; last != NULL && last->next != NULL; prev = last, last = last->next);
    if (last == NULL) {
        return list;
    }
    
    prev->next = last->next; 
    last->next = list; 
    return last; 
}

struct node * find_largest(struct node * list) {
    if (list == NULL) {
        return list; 
    }
    struct node * max = list; 
    for (struct node * p = list; p != NULL; p = p->next) {
        if (p->val > max->val) {
            max = p;
        }
    }
    return max; 
}

int duplicates(struct node * list) {
    if (list == NULL) {
        return 0;
    }

    for (struct node *p = list; p != NULL; p = p->next) {
        for (struct node *q = p->next; q != NULL; q = q->next) {
            if (p->val == q->val) {
                return 1; 
            }
        }
    }

    return 0;
}

struct node * push_ordered(struct node * list, int n) {
    struct node *prev, *curr; 
    for (prev = NULL, curr = list; curr != NULL && curr->val < n; prev = curr, curr = curr->next); 
    struct node * new = malloc(sizeof(struct node));
    if (new == NULL) {
        fprintf(stderr, "Cannot allocate memory\n");
        return list; 
    }

    new->val = n; 
    new->next == curr; 

    if (prev == NULL) {
        return new;
    }

    prev->next = new; 
    return list; 
}

struct node * find_ordered(struct node * list, int n) {
    struct node *curr; 
    for (curr = list; curr != NULL && curr->val < n; curr = curr->next);
    if (curr != NULL && curr->val == n) {
        return curr; 
    }
    return NULL;
}

int main() { 
    struct node * head = NULL; 
    head = push(head, 89); 
    head = push(head, 6); 
    head = push(head, 87); 
    head = push(head, 15); 
    head = push(head, 0); 
    head = push(head, 32);
    head = push(head, 64);
    head = push(head, 15);
    head = push(head, 64);
     
    // head = push_ordered(head, 6); 
    // head = push_ordered(head, 87); 
    // head = push_ordered(head, 15); 
    // head = push_ordered(head, 0); 
    // head = push_ordered(head, 32);
    // head = push_ordered(head, 64);
    // head = push_ordered(head, 15);
    // head = push_ordered(head, 64);

    // head = delete_all(head, 15); 
    // head = move_last_to_first(head); 
    head = move_first_to_last(head); 
    // head = insertBefore(head, 0, 17);
    // head = insertBefore(head, 64, 6464);
    // head = insertAfter(head, 32, 69); 
    // head = insertAfter(head, 89, 6969); 
    printll(head); 
    // struct node *found = find_largest(head);
    // printf(duplicates(head) == 1 ? "list has duplicated elements\n" : "no dupes\n");
    // if (found == NULL) {
    //     printf("nothing found\n"); 
    // } else { 
    //     printf("Found value is: %d\n", found->val);
    // }
    return 0; 
}