/*
 ============================================================================
 Name        : priority_queue.c
 Author      : Mostafa Salman
 Description : priority queue to arrange tasks according to its priority
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <priority_queue.h>

/* Function to Create A New Node */
Node* newNode(void *ptr, void *arg, int p)
{
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->task_ptr = ptr;
	new_node->vargp = arg;
	new_node->priority = p;
	new_node->next = NULL;

	return new_node;
}

/* Function to Remove the element with the highest priority form the list */
void pop(Node** head)
{
	Node* new_node = *head;
	(*head) = (*head)->next;
	free(new_node);
}

/* Function to push Node in a position according to priority */
void push(Node** head,void *ptr, void *arg, int p)
{
	Node* start = (*head);

	/* Create new Node */
	Node* new_node = newNode(ptr,arg, p);

	/* If The head of list has lesser priority than new node.
	 * So insert new node before head node and change head node. */
	if ((*head)->priority > p) {

		/* Insert New Node before head */
		new_node->next = *head;
		(*head) = new_node;
	}
	else {

		/* find a position to insert new node */
		while (start->next != NULL && start->next->priority <= p) {
			start = start->next;
		}

		/* Either at the ends of the list or at required position */
		new_node->next = start->next;
		start->next = new_node;
	}
}

/*main function
int main()
{
	// Create a Priority Queue
	Node* pq = newNode(&main,"4", 1);
	push(&pq, &push, "salman", 3);
	push(&pq, &pop, "mostafa", 0);
	push(&pq, &newNode, "5565", 2);
	push(&pq, &push, "0", 0);
	//pop(&pq);

	while (pq != NULL) {
		printf("%s ",(char *)(pq)->vargp);
		printf(" %p ",(void *)(pq)->task_ptr);
		printf("\t\t");
		pop(&pq);
	}

	return 0;
} */
