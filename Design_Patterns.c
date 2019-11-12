/*
 ============================================================================
 Name        : Design_Patterns.c
 Author      : Mostafa Salman
 Description : Design_Patterns
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Design_Patterns.h"
int x, pr1, pr2;
int x_ptr1[30];
int x_ptr2[30];
char *s;

pthread_t thr[NUM_THREADS];
Node* pq1;
Node* pq2;
pthread_mutex_t lock_x;
pthread_mutex_t lock_var;

/**********************************************/
void func1(void *ptr_data){
	int *a = (int *)ptr_data;
	printf("hello from func1: %d\n", *a);

}

void func2(void *ptr_data){
	char *b = (char *)ptr_data;
	printf("hello from func2: %s\n",b);
}

void func3(void *ptr_data){
	int *a = (int *)ptr_data;
	printf("hello from func3: %d\n", *a);
}

void func4(void *ptr_data){
	char *b = (char *)ptr_data;
	printf("hello from func4: %s\n",b);
}

/**********************************************/
/* generation timer pthread */
void *timer(void *arg){
	int c, t;
	srand (time(NULL));
	while(1){
		t = rand()%100000 + 1;
		for (c = 1; c<t; c++) ;
		pthread_mutex_lock(&lock_var);
		x = rand() % 100 + 1;
		pr1 = rand() % 10 + 1;
		pr2 = rand() % 10 + 1;
		pthread_mutex_unlock(&lock_var);
	}
	pthread_exit(NULL);
}

/* Generation thread function */
void *thr_post(void *arg){
	int i=0;
	while(1){
		pthread_mutex_lock(&lock_var);
		pthread_mutex_lock(&lock_x);
		s="test_1";
		push(&pq1, &func2, (void*)s, pr1);
		pthread_mutex_unlock(&lock_x);
		pthread_mutex_unlock(&lock_var);

		pthread_mutex_lock(&lock_var);
		pthread_mutex_lock(&lock_x);
		x_ptr1[i] = x;
		push(&pq1, &func1, (void*)&x_ptr1[i], pr1);
		pthread_mutex_unlock(&lock_x);
		pthread_mutex_unlock(&lock_var);

		pthread_mutex_lock(&lock_var);
		pthread_mutex_lock(&lock_x);
		s="test_2";
		push(&pq2, &func4, (void*)s, pr2);
		pthread_mutex_unlock(&lock_x);
		pthread_mutex_unlock(&lock_var);

		pthread_mutex_lock(&lock_var);
		pthread_mutex_lock(&lock_x);
		x_ptr2[i] = x;
		push(&pq2, &func3, (void*)&x_ptr2[i], pr1);
		pthread_mutex_unlock(&lock_x);
		pthread_mutex_unlock(&lock_var);

		i++;
		if (i==30)
			i=0;
	}

	pthread_exit(NULL);
}

/* thread 2 function */
void *thr_func1(void *pq1) {
	Node *queue1 = (Node *)pq1;
	while(1){
		if(size_pq1>0){
			pthread_mutex_lock(&lock_x);
			pop(&queue1);
			pthread_mutex_unlock(&lock_x);
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
			pthread_mutex_lock(&lock_x);
			pop(&queue2);
			pthread_mutex_unlock(&lock_x);
			(queue2->task_ptr)(queue2->vargp);
			size_pq2--;
		}
	}

	pthread_exit(NULL);
}
