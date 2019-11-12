/*
 * main.c
 *
 *  Created on: Nov 11, 2019
 *      Author: msalman
 */

#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.h"
#include "Design_Patterns.h"

/* main function */
int main() {

	int i, rc;
	pq1 = newNode(&thr_post, (void*)0, 0);
	pq2 = newNode(&thr_post, (void*)0, 0);

	/* create threads */
	/* timer thread */
	rc = pthread_create(&thr[0], NULL, timer, NULL);
	if (rc){
		fprintf(stderr, "error: pthread_create, rc: %d\n", rc);
		return EXIT_FAILURE;
	}

	/* Generation thread */
	rc = pthread_create(&thr[1], NULL, thr_post, NULL);
	if (rc){
		fprintf(stderr, "error: pthread_create, rc: %d\n", rc);
		return EXIT_FAILURE;
	}

	/* thread 2 */
	rc = pthread_create(&thr[2], NULL, thr_func1, (void*)pq1);
	if (rc){
		fprintf(stderr, "error: pthread_create, rc: %d\n", rc);
		return EXIT_FAILURE;
	}

	/* thread 3 */
	rc = pthread_create(&thr[3], NULL, thr_func2, (void*)pq2);
	if (rc){
		fprintf(stderr, "error: pthread_create, rc: %d\n", rc);
		return EXIT_FAILURE;
	}

	/* block until all threads complete */
	for (i = 0; i < NUM_THREADS; ++i) {
		pthread_join(thr[i], NULL);
	}

	while(1){

	}

	return EXIT_SUCCESS;
}

