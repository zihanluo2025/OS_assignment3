/**
 * This file implements parallel mergesort.
 */

#include <stdio.h>
#include <string.h> /* for memcpy */
#include <stdlib.h> /* for malloc */
#include "mergesort.h"

/* this function will be called by mergesort() and also by parallel_mergesort(). */
void merge(int leftstart, int leftend, int rightstart, int rightend){
	int i = leftstart;
    int j = rightstart;
    int k = leftstart;

    while (i <= leftend && j <= rightend) {
        if (A[i] <= A[j]) {
            B[k++] = A[i++];
        } else {
            B[k++] = A[j++];
        }
    }

    while (i <= leftend)
        B[k++] = A[i++];

    while (j <= rightend)
        B[k++] = A[j++];

    // copy 
    for (i = leftstart; i <= rightend; i++) {
        A[i] = B[i];
    }
}

/* this function will be called by parallel_mergesort() as its base case. */
void my_mergesort(int left, int right){
	if (left >= right)
	return;

	int mid = (left + right) / 2;

	my_mergesort(left, mid);
	my_mergesort(mid + 1, right);

	merge(left, mid, mid + 1, right);
}

/* this function will be called by the testing program. */
void *parallel_mergesort(void *arg) {
    struct argument *info = (struct argument *)arg;
    int left = info->left;
    int right = info->right;
    int level = info->level;

	// printf("[DEBUG]\n", left, right, level);
    // fflush(stdout);  // force excit

	if (cutoff == 0) {
        my_mergesort(left, right);
        return NULL;
    }

    if (left >= right)
        pthread_exit(NULL);

    int mid = (left + right) / 2;

    // If the cutoff level has been reached, switch to the single-threaded version
    if (level >= cutoff) {
        my_mergesort(left, right);
        pthread_exit(NULL);
    }

    // Otherwise, continue with parallel recursion
    pthread_t left_thread, right_thread;

    struct argument *left_arg = buildArgs(left, mid, level + 1);
    struct argument *right_arg = buildArgs(mid + 1, right, level + 1);

    // Create two threads
    pthread_create(&left_thread, NULL, parallel_mergesort, left_arg);
    pthread_create(&right_thread, NULL, parallel_mergesort, right_arg);

    // Wait for the child thread to complete
    pthread_join(left_thread, NULL);
    pthread_join(right_thread, NULL);

    // merge
    merge(left, mid, mid + 1, right);

    // Release memory
    free(left_arg);
    free(right_arg);

    if (level > 0)
    	pthread_exit(NULL);
	else
    	return NULL;
}


/* we build the argument for the parallel_mergesort function. */
struct argument * buildArgs(int left, int right, int level){
	struct argument *arg = malloc(sizeof(struct argument));
    arg->left = left;
    arg->right = right;
    arg->level = level;
    return arg;
		
}

