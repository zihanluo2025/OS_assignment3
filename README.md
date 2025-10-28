
# 7064_Assignment3
## Assignment 3: Concurrency

* Authors: Di Zhu a1919727; Jinchao Yuan a1936476; Zihan Luo a1916700
* Group name: Group 92

## Overview

This program implements a merge sort algorithm through the pthread library, 
which is a multi-threaded version to improve performance. It is used to sort a randomly-generated array.

## Manifest
```
comp2002-os-mergesort/
├── Makefile # Compilation instructions for building the project
├── mergesort.c # Core implementation: merge, my_mergesort, parallel_mergesort, buildArgs
├── mergesort.h # Header file: struct definitions, function prototypes, and global variables
├── test-mergesort.c # Entry file: generates random input, runs sorting, and checks correctness
└── README.md # Project overview
```

## Building the project

To build this project, run `make` under the same path with the makefile `./comp2002-os-mergesort`.

## Features and usage

### Features
1. Implement multi-threaded merge sort through the pthread library
2. Adjust the cutoff level to control the number of created threads
3. Use the divide and conquer idea
4. The performance of parallel sorting is about twice as fast as serial sorting

### Usage
Run the test file
   ```
   ./test-mergesort <input size> <cutoff level> <seed> 
   ```
   For example:
   ```
    ./test-mergesort 100 1 1234
   Sorting 100 elements took 0.00 seconds. </br>
   ```
Parameters:
* input size: the size of the array
* cutoff level: the maximum level of recursion
* seed: a random seed number


## Testing

Use test cases from myUni. 
The idea is to fixed the input size and seed value, gradually increase the cutoff level, and check the excution time of sorting.</br>
<img width="669" height="257" alt="Screenshot 2025-10-24 at 11 53 17 AM" src="https://github.com/user-attachments/assets/072137a6-66ef-48c9-907b-018bf6dc19c8" />



## Known Bugs

We did not identify bugs.

## Reflection and Self Assessment
1. Understanding of cutoff and level </br>
When we built this project, we did not understand the meaning of cutoff and level and the difference between them in the `mergesort.c file`. We checked the `test-mergesort.c file` and found that the level was set to 0 initially. Also, we read the myUni assignment content and understood that the cutoff is the value that we input. This process help us to build project and implement test.
   
2. Parallel sorting and serial sorting performance </br>
Based on the test results, we found that before the cutoff level is less than 4, the execution time can be reduced by about twice. This significantly improves performance. However, after the cutoff level 4, the execution time has a slight reduce or increase, which can not improve performance. Therefore, it is important to select a suitable cutoff level to improve performance. If the performance can not be improved significantly through parallel, using serial sorting may be easier and more suitable.

3. Difficulties </br>
The most difficult point in this project was to have a proper understanding of recurrence in parallel merge sort. Recursion is more abstract than iteration and hard to step through in detail wiht the debug mode of VSCode. I prepared 32 pieces of paper and wrote down the numbers and simulated the code from myuni and performed the whole process of parallel merge sort.
Finally, what I have learned is: Once the program commences running, it will divide the array into two new threads and add one level each time.When the level reaches the cutoff, it will not create any more new threads but will run in serial merge sort until the size of the results is reduced to two numbers to compare. The process above may be regarded as a serial recursive logic inside a parallel recursive logic.

## Sources Used
HackerRank 2016, *Algorithms: Merge Sort* YouTube, 28 September, viewed 24 Oct 2025, <https://www.youtube.com/watch?v=KF2j-9iSf4Q&t=372s>. </br>

Arpaci-Dusseau, R.H., Arpaci-Dusseau, A.C., 2018a. 'Concurrency: An Introduction', *Operating Systems: Three Easy Pieces*. Createspace Independent Publishing Platform, pp.1-16. </br>

Arpaci-Dusseau, R.H., Arpaci-Dusseau, A.C., 2018b. 'Interlude: Thread API', *Operating Systems: Three Easy Pieces*. Createspace Independent Publishing Platform, pp.1-12. </br>

University of Adelaide, *Assignment 3: Concurrency*, Myuni, viewed 24 Oct 2025, <https://myuni.adelaide.edu.au/courses/101182/assignments/465389>. </br>


We acknowledge the use of ChatGPT[https://chatgpt.com/share/68ff368c-8cfc-800d-8305-1b6b41371c1e] to help us understand and use C language. The following prompts were entered into ChatGPT on 27th Oct 2025:
   * You are an expert in operating systems, and are familiar with C language. Answer the following questions: In struct argument * buildArgs(int left, int right, int level){ return NULL; } what does the * mean?
   * what does & mean?
   * Do we always add & or * before using a variable?
   * Given: int x = 10; int *p = &x; int y = *p; x = 11; What is y now?
   * In the above code, which of these can be used in arithmetic: x, &x, *p, y?
   * What use memcpy rather than for loop. What is the difference between them?

