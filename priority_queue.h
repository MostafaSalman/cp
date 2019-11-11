/*
 * priority_queue.h
 *
 *  Created on: Nov 7, 2019
 *      Author: msalman
 */

#ifndef PRIORITY_QUEUE_H_
#define PRIORITY_QUEUE_H_

typedef void (*ptr_func)();
extern int size_pq1;
extern int size_pq2;

/* Node struct */
typedef struct node {
	ptr_func task_ptr;					/* pointer to the task */
	void *vargp;						/* task arguments */
	int priority;          				/* Lower values indicate higher priority */
	struct node* next;
} Node;

/*=========================== APIs ===========================*/
Node* newNode(void *ptr, void *arg, int p);
void pop(Node** head);
void push(Node** head,void *ptr, void *arg, int p);



#endif /* PRIORITY_QUEUE_H_ */
