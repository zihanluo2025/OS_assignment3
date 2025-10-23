## Project Number/Title

### Authors

- **Di Zhu** — a1919727
- **Jinchao Yuan** — a1936476
- **Zihan Luo** — a1916700

### Group name: Assignment 3 Groups 92

## Overview

This project implements a **multi-threaded merge sort** using the **pthread** library in C.  
It explores how concurrency improves performance by sorting subarrays in parallel up to a user-defined thread depth (`cutoff`).  
The assignment demonstrates **inter-thread synchronization**, **recursion**, and **shared memory coordination**.

## Manifest

comp2002-os-mergesort/
├── Makefile # Compilation instructions for building the project
├── mergesort.c # Core implementation: merge, my_mergesort, parallel_mergesort, buildArgs
├── mergesort.h # Header file: struct definitions, function prototypes, and global variables
├── test-mergesort.c # Entry file: generates random input, runs sorting, and checks correctness
└── README.md # Project overview

## Building the project

### 🧩 Compile

```bash
make
```

This generates the executable: **test-mergesort**

### Clean

```bash
make clean
```

### Environment

- macOS
- GCC

## Features and usage

### Run Command

```bash
./test-mergesort <array_size> <cutoff_level> <random_seed>
```

### Example

```bash
./test-mergesort 100000 3 42
```

## Testing

- Basic Execution Test : Serial execution (cutoff=0) with 100 random elements
- Parallel Execution Test: Parallel sorting (cutoff=2) with 1000 elements
- Medium Input Test: Parallel sorting (cutoff=3) with 10,000 elements

## Known Bugs

List known bugs that you weren't able to fix (or ran out of time to fix).

## Reflection and Self Assessment

At first, we had a problem where the main thread finished too early because pthread_exit() was called in the wrong place.
As a result, the program ended before it could print the final sorting result on Gradescope.
We fixed this by making only non-root threads call pthread_exit(NULL), while the main thread simply returned normally.

We also learned that recursive parallel sorting needs careful management of the argument structures — each thread must have its own data to avoid conflicts or memory leaks.
After testing different configurations, we realized that efficient multithreading depends on finding the right balance between the number of threads and the amount of work each thread handles.

This project helped us better understand thread synchronization, performance optimization, and concurrency at the system level.

## Sources Used

If you used any sources outside of the textbook, you should list them here.
If you looked something up on stackoverflow.com or you use help from AI, and
fail to cite it in this section, it will be considered plagiarism and dealt
with accordingly. So be safe CITE!
