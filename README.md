# Map Reduce

## SCREENSHOTS OF THE TERMINAL OUTPUT
### EXAMPLE 1
![alt text](image-2.png)
![alt text](image-3.png)

### EXAMPLE 2 w/ 4 PROCESSES
![alt text](image.png)
![alt text](image-1.png)

### EXAMPLE 2 w/ 2 PROCESSES 
![alt text](image-4.png)
![alt text](image-5.png)

## DIFFERENCE BETWEEN SEQUENTIAL AND PARALLEL IMPLEMENTATION
### SEQUENTIAL IMPLEMENTATION (Example_01)
- One process handles all files (2808 of them in total), which means it's single-threaded
- File are processed one after another (linear processing)
- Single hash table is used for accumulating all word counts
- There is no communication overhead, which makes things simple but is limited to only 1 CPU core 
- How it works:
1) read all .txt files from the folder
2) for each file inside the folder:
- tokenize
- clean words
- update hash table
3) sort results
4) display the top words

### PARALLEL IMPLEMENTATION (Example_02)
- Files are divided among MPI processes
- Each process independently processes its file subset 
- Each process maintains local word counts (local hash tables)
- How it works:
1) root process / rank 0 gathers all filenames
2) filenames are then distributed using `MPI_Bcast`
3) round-robin distribution of files to processes 
4) each process counts words in assigned files
5) local results are collected via `MPI_Gatherv`
6) root process merges all local hash tables 
- Also, `MPI_WORD_COUNT` was used for efficient data transfer 

**Key difference**: Sequential version interleaves Map and Reduce phases (hash table get updates instantly), while the parallel version separatesthem (local map -> gather -> global reduce). 

### EXECUTION TIME COMPARISON 
- Using 2 processes takes 79.24 seconds, rather than 94.00 seconds (1.19x faster)
- Using 4 processes takes 52.19 seconds, rather than 94.00 seconds (1.80x faster)
- 4 processes is the fastest option 

### RESULTS COMPARISON
- All tests produced the same output
- This proves that parallel code works correctly 

### HASH TABLE VS SORTING 
#### Current method - hash table
- Puts each word into a hash table bucket
- Very fast, finds words in constant time
- Memory efficient, only stores each unique words once

#### Alternative method - sorting
- Would need to collect all words first
- After that sort them alphabetically
- Then count identical words
- We can conclude that this is much slower, especially for larger datasets

#### Why hash table is better
- Faster for the kind of dataset we are dealing with
- Uses less memory
- Works better w/ parallel processing
- We have proof it works well (1.80x speedup with 4 processes)