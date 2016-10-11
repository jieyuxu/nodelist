#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {int i; struct node *next;};

/*
print_list
Should take a pointer to a node struct and print out all of the data in the list

insert_front
Should take a pointer to the existing list and the data to be added, create a new node, put it at the beginning of the list and return a pointer to the beginning of the list.

free_list
Should take a pointer to a list as a parameter and then go through the entire list freeing each node and return a pointer to the beginning of the list (which should be NULL by then).    
*/

int print_list(struct node *s){
	while (s->next){
		printf("value is: %d\n", s->i);
		s = s->next;
	}
	printf("value is: %d\n", s->i);
	return 0;
}

struct node * insert_front(struct node *s, int k){
	struct node *head = (struct node *)malloc(sizeof(*s));
	head->i = k;
	head->next = s;
	return head;
}

struct node * free_list(struct node *s){
	struct node * hold = (struct node *)malloc(sizeof(*s));
	hold = s;
	while (s->next){
		s = s->next;
		free(hold);
		hold = s;
	}
	hold = s->next;
	free(s);
	printf("%d\n", hold);
	return hold;
}

int main(){
	struct node *n1 = (struct node *)malloc(sizeof(n1));
	struct node *n2 = (struct node *)malloc(sizeof(n2));
	struct node *n3 = (struct node *)malloc(sizeof(n3));
	struct node *n4 = (struct node *)malloc(sizeof(n4));
	n1->i = 5;
	n1->next = n2;
	n2->i = 10;
	n2->next = n3;
	n3->i = 15;
	n3->next = NULL;
	printf("%s\n", "testing print_list");
	print_list(n1);
	struct node * ton1 = n1;
	printf("\n%s\n", "testing insert_front by adding a new node of value 4 to front of n1");
	n4 = insert_front(ton1, 4);
	print_list(n4);
	printf("\n%s\n", "testing free:");
	printf("%d", free_list(n4));
	return 0;
}
