/*
 ============================================================================
 Name        : pthread.c
 Author      : Mostafa Salman
 Description : pthread
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <priority_queue.h>

#define NUM_THREADS 2

pthread_mutex_t lock_x;
pthread_mutex_t lock_y;

/* thread 1 function */
void *thr_func1(void *pq1) {
	pthread_mutex_lock(&lock_x);
		(pq1->task_ptr)(pq1->vargp);
	pthread_mutex_unlock(&lock_x);
	pop(&pq1);
	while(pq1 != NULL){
		pthread_mutex_lock(&lock_x);
			(pq1->task_ptr)(pq1->vargp);
		pthread_mutex_unlock(&lock_x);
		pop(&pq1);
	}

	pthread_exit(NULL);
}

/* thread 2 function */
void *thr_func2(void *pq2) {
	pthread_mutex_lock(&lock_y);
		(pq2->task_ptr)(pq2->vargp);
	pthread_mutex_unlock(&lock_y);
	pop(&pq2);
	while(pq2 != NULL){
		pthread_mutex_lock(&lock_y);
			(pq2->task_ptr)(pq2->vargp);
		pthread_mutex_unlock(&lock_y);
		pop(&pq2);
	}

	pthread_exit(NULL);
}

/* main function */
int main() {

	/* Create a Priority Queue
	Node* pq1 = newNode(&main,"4", 1);
	push(&pq1, &push, "salman", 3);
	push(&pq1, &pop, "mostafa", 0);
	push(&pq1, &newNode, "5565", 2);
	push(&pq1, &push, "0", 0);

	while (pq1 != NULL) {
			printf("%s ",(char *)(pq1)->vargp);
			printf(" %p ",(void *)(pq1)->task_ptr);
			printf("\t\t");
			pop(&pq1);
		}*/

	Node* pq1;
	Node* pq2;

	pthread_t thr[NUM_THREADS];
	printf("%d",thr[0]);
	int i, rc;

	/* initialize pthread mutex protecting */
	pthread_mutex_init(&lock_x, NULL);

	/* create threads */
	if ((rc = pthread_create(&thr[0], NULL, thr_func1, &pq1))){
		fprintf(stderr, "error: pthread_create, rc: %d\n", rc);
		return EXIT_FAILURE;
	}

	if ((rc = pthread_create(&thr[1], NULL, thr_func1, &pq2))){
		fprintf(stderr, "error: pthread_create, rc: %d\n", rc);
		return EXIT_FAILURE;
	}

	/* block until all threads complete */
	for (i = 0; i < NUM_THREADS; ++i) {
		pthread_join(thr[i], NULL);
	}

	return EXIT_SUCCESS;
}
