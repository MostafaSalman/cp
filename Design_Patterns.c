/*
 ============================================================================
 Name        : Design_Patterns.c
 Author      : Mostafa Salman
 Description : Design_Patterns
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Design_Patterns.h"

pthread_t thr[NUM_THREADS];
Node* pq1;
Node* pq2;

/**********************************************/
void func1(int a){
	printf("hello from func1: %d\n",a);
}

void func2(char *b){
	printf("hello from func2: %s\n",b);
}

void func3(int a){
	printf("hello from func3: %d\n",a);
}

void func4(char *b){
	printf("hello from func4: %s\n",b);
}

/**********************************************/

/* Generation thread function */
void *thr_post(void *arg){
	push(&pq1, &func2, (void*)"salman", 5);
	push(&pq1, &func1, (void*)15, 6);
	push(&pq2, &func4, (void*)"mostafa", 2);
	push(&pq2, &func3, (void*)25, 1);
	push(&pq2, &func3, (void*)23, 0);
	push(&pq1, &func1, (void*)11, 0);

	pthread_exit(NULL);
}

/* thread 2 function */
void *thr_func1(void *pq1) {
	Node *queue1 = (Node *)pq1;
	while(1){
		if(size_pq1>0){
			pop(&queue1);
			(queue1->task_ptr)(queue1->vargp);
			size_pq1--;
		}
	}

	pthread_exit(NULL);
}

/* thread 3 function */
void *thr_func2(void *pq2) {
	Node *queue2 = (Node *)pq2;
	while(1){
		if(size_pq2>0){
			pop(&queue2);
			(queue2->task_ptr)(queue2->vargp);
			size_pq2--;
		}
	}

	pthread_exit(NULL);
}
