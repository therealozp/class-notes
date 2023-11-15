#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

int main()  
{

 	struct node *first = NULL;
	struct node *largest;

	/* inserting nodes */
	first = add_to_list(first, 3);
	first = add_to_list(first, 64);
	first = add_to_list(first, 98);
	first = add_to_list(first, 3);
    first = add_to_list(first, 64);
	first = add_to_list(first, 3);
	first = add_to_list(first, 136);

	print_list(first);

	int result = duplicates(first);
	if(result)
		printf("There are duplicated nodes in the list.\n");
	else
		printf("no duplicates.\n");
	

	if((largest =find_largest(first))!=NULL) 
	  printf("The largest value is : %d\n", largest->value);
	
	clear_list(first);
	return 0;

}