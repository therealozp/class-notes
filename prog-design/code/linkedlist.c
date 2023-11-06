#include <stdio.h>
#include <stdlib.h>

struct node {
    int val; 
    struct node *next; 
};

struct node * add_element(struct node *head, int n) {
    struct node *new_node; 
    struct node *p;
    new_node = malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Malloc failed");
        return head;
    }
    if (head == NULL) {
        new_node->val=n;
        new_node->next=NULL;
        return new_node;
    }
    for (p = head; p!= NULL; p = p->next);

    p->next=new_node;
    new_node->val=n;
    new_node->next=NULL;
    return head;
}

struct node * add_left(struct node *head, int n) {
    struct node *new_node; 
    new_node=malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("malloc failed");
        return head;
    }
    new_node->val=n;
    new_node->next=head;
    return new_node;
}

int count_n(struct node *head, int n) {
    struct node *p; 
    int count = 0;
    for (p = head; p != NULL; p = p->next) {
        if (p->val == n) {
            count++;
        }
    }
    return count;
}

int search_list(struct node *head, int search) {
    struct node *p; 
    for (p = head; p != NULL; p = p->next) {
        if (p->val == search) {
            return 1;
        }
    }
    return 0;
}

struct node * find_largest(struct node *head) {
    struct node *p; 
    struct node *max = head;
    for (p = head->next; p != NULL; p = p->next)  {
        if (p->val > max->val) {
            max = p;
        }
    }
    return max;
}

void clear(struct node *head) {
    struct node *p;
    while (head != NULL) {
        p = head;
        head = head->next;
        if (p != NULL) {
            free(p);
        }
    }
}

int main() {
    struct node *head = NULL; 
    // int number, ct = 0; 

    head = add_left(head, 15);
    head = add_left(head, 7);
    head = add_left(head, 98);
    head = add_left(head, 54);
    head = add_left(head, 1);
    head = add_left(head, 42);
    head = add_left(head, 22);
    head = add_left(head, 17);

    struct node *largest = find_largest(head);

    printf("The largest element of the link list is: %d", largest->val);
    clear(head);
    return 0;
}