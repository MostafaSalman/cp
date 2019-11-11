/*
 * Design_Patterns.h
 *
 *  Created on: Nov 11, 2019
 *      Author: msalman
 */

#ifndef DESIGN_PATTERNS_H_
#define DESIGN_PATTERNS_H_
#include <pthread.h>
#include "priority_queue.h"

#define NUM_THREADS 3
extern pthread_t thr[NUM_THREADS];
extern Node* pq1;
extern Node* pq2;

/*=========================== APIs ===========================*/
void func1(int a);
void func2(char *b);
void func3(int a);
void func4(char *b);
void *thr_post(void *arg);
void *thr_func1(void *pq1);
void *thr_func2(void *pq2);

#endif /* DESIGN_PATTERNS_H_ */
