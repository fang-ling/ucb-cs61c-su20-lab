#include "list.h"
#include <stdlib.h>

#define var __auto_type

/* Add a node to the end of the linked list. Assume head_ptr is non-null. */
void append_node (node** head_ptr, int new_data) {
	/* First lets allocate memory for the new node and initialize its attributes */
	var new_node_ptr_ptr = (struct node**)malloc(sizeof(struct node*));
    *new_node_ptr_ptr = (struct node*)malloc(sizeof(struct node));
    (*new_node_ptr_ptr) -> val = new_data;
    (*new_node_ptr_ptr) -> next = NULL;

	/* If the list is empty, set the new node to be the head and return */
	if (*head_ptr == NULL) {
		*head_ptr = *new_node_ptr_ptr;
		return;
	}
	node* curr = *head_ptr;
	while (curr -> next != NULL) {
		curr = curr->next;
	}
	/* Insert node at the end of the list */
	curr -> next = *new_node_ptr_ptr;
}

/* Reverse a linked list in place (in other words, without creating a new list).
   Assume that head_ptr is non-null. */
void reverse_list (node** head_ptr) {
	node* prev = *head_ptr;
	node* curr = *head_ptr;
	node* next = NULL;
    var curr_front = NULL;
	while (curr != NULL) {
		curr_front = prev;
        if (curr -> next != NULL) {
            next = curr -> next -> next;
        } else {
            break;
        }
        prev = curr -> next;
        curr -> next = next;
        prev -> next = curr_front;
	}
	/* Set the new head to be what originally was the last node in the list */
	*head_ptr = curr_front;
}
