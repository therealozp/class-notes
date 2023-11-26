#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "guest.h"
#include "read_line.h"

struct guest * find_guest(struct guest *list, char* number) {
  // a custom find function that returns a pointer if the searched struct exists
  // else, just return NULL
  struct guest *p; 
  // iterate through the entire linked list until the NULL element
  for (p = list; p != NULL; p = p->next) {
    // if they are the same, then return the guest
    if (!strcmp(number, p->phone)) {
      return p;
    }
  }
  return NULL;
}

struct guest *add_guest(struct guest *list){
  struct guest *new_guest; 
  // allocate some memory for the new object
  new_guest = malloc(sizeof(struct guest));
  // if it fails to allocate, return the original linked list along with a message
  if (new_guest == NULL) {
    printf("malloc failed at add_guest()");
    return list;
  }
  // enter the phone number and call find() on the new guest immediately
  printf("Enter phone number: ");
  read_line(new_guest->phone, PHONE_LEN);
  if (find_guest(list, new_guest->phone) != NULL) {
    printf("guest already exists.");
    // if a guest is found, no point in keeping it, so free it to avoid any memory leaks
    free(new_guest);
    // and return the head of the list
    return list;
  }
  // scan in the expected values
  new_guest->next = NULL;
  printf("Enter guest's last name: ");
  read_line(new_guest->last, NAME_LEN);
  printf("Enter guest's first name: ");
  read_line(new_guest->first, NAME_LEN);
  printf("Enter party size: ");
  scanf("%d", &new_guest->party_size);

  // check if it's an empty list
  if (list == NULL) {
    return new_guest;
  }
  // traverse to the end
  struct guest *p;
  for (p = list; p->next != NULL; p = p->next);
  // and append the guest to the list
  p->next = new_guest; 
  // and return the head
  return list; 
} 

struct guest * remove_guest(struct guest *list) {
  char removing_last[NAME_LEN + 1];
  char removing_first[NAME_LEN + 1]; 
  char removing_phone[PHONE_LEN + 1]; 

  // enter the information of the guest to remove
  printf("Enter phone number: ");
  read_line(removing_phone, PHONE_LEN);
  printf("Enter guest's last name: ");
  read_line(removing_last, NAME_LEN);
  printf("Enter guest's first name: ");
  read_line(removing_first, NAME_LEN);

  // initialize traversal pointers
  struct guest *prev, *curr;
  prev = NULL;
  curr = list; 

  for (; curr != NULL; curr = curr->next) {
    // check if the current guest of list has same info as guest to remove
    if ((strcmp(removing_phone, curr->phone) == 0) && (strcmp(removing_last, curr->last) == 0) && (strcmp(removing_first, curr->first) == 0)) {
      // if same, proceed to removal
      if (curr == list) {
        // if removing the first element, then return the next element as the list
        struct guest * next;
        // having another temp variable allows curr to be freed without complications
        if (curr->next) {
          next = curr->next; 
        } else {
          next = NULL; 
        }
        free(curr);
        return next; 
      }
      // if it's not the first element, simply re-route the next of the prev to the next of the curr
      prev->next = curr->next;
      // then free it and return list
      free(curr);
      return list; 
    }
    // if it's not matching, assign the prev to curr and move on
    prev = curr; 
  }
  printf("guest does not exist");
  return list; 
};

void print_list(struct guest *list){
  // loops through the list and prints out according to format
  struct guest *p; 
  for (p = list; p != NULL; p = p->next) {
    printf("%-15s%-20s%-20s%5d\n", p->phone, p->last, p->first,  p->party_size);
  }
}

void clear_list(struct guest *list){
 // declare the starting node
  struct guest *p; 
  // while there are still elements in the list
  while (list != NULL) {
    // first, set the pointer to the current first element of the list
    p = list; 
    // move the list forward entirely,  
    // leaving p so that we don't get a dangling pointer
    list = list->next; 

    // if p is not a NULL ptr, then go ahead and free it up
    if (p != NULL) {
      free(p);
    }
  }
}