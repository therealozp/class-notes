#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

struct node *add_to_list(struct node *list, int n)
{
	  struct node *new_node;
	
	  new_node = malloc(sizeof(struct node));
	  if (new_node == NULL) {
	    printf("malloc failed in add_to_list\n");
	    return list;
	  }
	  new_node->value = n;
	  new_node->next = list;
	  return new_node;
}

struct node *search_list(struct node *list, int n)
{
	  struct node *p;
	
	  for (p = list; p != NULL; p = p->next)
	    if (p->value == n)
	      return p;
	  return NULL;
}

struct node *delete_from_list(struct node *list, int n)
{
  struct node *cur, *prev;
	  
  for (cur = list, prev = NULL;
       cur != NULL && cur->value != n;
       prev = cur, cur = cur->next)
    ;
  if (cur == NULL) 
    return list;             /* n was not found */
  if (prev == NULL)
    list = list->next;       /* n is in the first node */
  else
    prev->next = cur->next;  /* n is in some other node */
  free(cur);
  return list;
}

void print_list(struct node *list)
{
	struct node *p;
	for(p= list; p!=NULL; p = p->next)
		printf("%d\t", p->value);
	printf("\n");
}

void clear_list(struct node *list)
{
  struct node *p;
  while(list != NULL)
  {
	 p = list;
     list = list->next;
     if( p!= NULL)
           free(p);
  }
}

int count_n(struct node *list, int n){

	  struct node *p;
	  int count = 0;
	
          for (p = list; p != NULL; p = p->next)
            if (p->value == n)
              count++;

          return count;

}

int duplicates(struct node *list){

	  struct node *p, *q;
	 
	  if(list!=NULL){
             for (p = list; p != NULL; p = p->next)
		for(q= p->next; q!=NULL; q = q->next)
            		if (p->value == q->value)
          			return 1;
			
	  }
          return 0;

}


struct node *find_largest(struct node *list)
{
  struct node *p = list;
  struct node *largest = list;
 
  for(p = list; p!=NULL; p = p->next)
  {	
	  if(p->value>largest->value)
	    largest = p;
  }
  return largest;
  
}
  

