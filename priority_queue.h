/*
 * priority_queue.h
 *
 *  Created on: Nov 7, 2019
 *      Author: msalman
 */

#ifndef PRIORITY_QUEUE_H_
#define PRIORITY_QUEUE_H_

/* Node struct */
typedef struct node {
	void (*task_ptr)(void *vargp);		/* pointer to the task */
	void *vargp;						/* task arguments */
	int priority;          				/* Lower values indicate higher priority */
	struct node* next;
} Node;


/*=========================== APIs ===========================*/
Node* newNode(void *ptr, void *arg, int p);
void pop(Node** head);
void push(Node** head,void *ptr, void *arg, int p);



#endif /* PRIORITY_QUEUE_H_ */
