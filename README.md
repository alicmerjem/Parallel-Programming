## ASSIGNMENT 5
### OVERVIEW
- Implemented 3 vectorization optimizations 
- Successfully compiled the timestep_3_opt
- Achieved the vectorization used 256-bit AVX instructions 
- Verified the vector insturction execution 

### COMPILER OUTPUT AND PERFORMANCE RESULT FOR TIMESTEP 1
merjem@LAPTOP-HJN4TB2I:~/Parallel-Programming$ gcc -g -O3 -fno-trapping-math -fno-math-errno -fstrict-aliasing -ftree-vectorize -fopenmp-simd -march=native -mtune=native -mprefer-vector-width=256 -fopt-info-vec-optimized -fopt-info-vec-missed -c timestep_opt1.c -o timestep_opt1.o
timestep_opt1.c:9:9: optimized: loop vectorized using 32 byte vectors
timestep_opt1.c:11:7: optimized: loop vectorized using 32 byte vectors
timestep_opt1.c:9:9: optimized: loop vectorized using 32 byte vectors

--------------------------------------------------------------------------------
CPU name:       Intel(R) Core(TM) i7-8665U CPU @ 1.90GHz
CPU type:       Intel Kabylake processor
CPU clock:      0.00 GHz
--------------------------------------------------------------------------------
Minimum dt is 0.016964
--------------------------------------------------------------------------------
Group 1: MEM_DP
+------------------------------------------+---------+------------+
|                   Event                  | Counter | HWThread 0 |
+------------------------------------------+---------+------------+
|             INSTR_RETIRED_ANY            |  FIXC0  |   85244025 |
|           CPU_CLK_UNHALTED_CORE          |  FIXC1  |  282125410 |
|           CPU_CLK_UNHALTED_REF           |  FIXC2  |  144751288 |
|              PWR_PKG_ENERGY              |   PWR0  |          0 |
|              PWR_DRAM_ENERGY             |   PWR3  |          0 |
| FP_ARITH_INST_RETIRED_128B_PACKED_DOUBLE |   PMC0  |          2 |
|    FP_ARITH_INST_RETIRED_SCALAR_DOUBLE   |   PMC1  |         88 |
| FP_ARITH_INST_RETIRED_256B_PACKED_DOUBLE |   PMC2  |   20000001 |
|                DRAM_READS                | MBOX0C1 |      -     |
|                DRAM_WRITES               | MBOX0C2 |      -     |
+------------------------------------------+---------+------------+

+-----------------------------------+------------+
|               Metric              | HWThread 0 |
+-----------------------------------+------------+
|        Runtime (RDTSC) [s]        |          0 |
|        Runtime unhalted [s]       |          0 |
|            Clock [MHz]            |          0 |
|                CPI                |     3.3096 |
|             Energy [J]            |          0 |
|             Power [W]             |          0 |
|          Energy DRAM [J]          |          0 |
|           Power DRAM [W]          |          0 |
|            DP [MFLOP/s]           |          0 |
|          AVX DP [MFLOP/s]         |          0 |
|          Packed [MUOPS/s]         |          0 |
|          Scalar [MUOPS/s]         |          0 |
|  Memory load bandwidth [MBytes/s] |          0 |
|  Memory load data volume [GBytes] |          0 |
| Memory evict bandwidth [MBytes/s] |          0 |
| Memory evict data volume [GBytes] |          0 |
|    Memory bandwidth [MBytes/s]    |          0 |
|    Memory data volume [GBytes]    |          0 |
| Operational intensity [FLOP/Byte] |          0 |
|      Vectorization ratio [%]      |    99.9996 |
+-----------------------------------+------------+

### COMPILER OUTPUT AND PERFORMANCE RESULT FOR TIMESTEP 2
merjem@LAPTOP-HJN4TB2I:~/Parallel-Programming$ gcc -g -O3 -fno-trapping-math -fno-math-errno -fstrict-aliasing -ftree-vectorize -fopenmp-simd -march=native -mtune=native -mprefer-vector-width=256 -fopt-info-vec-optimized -fopt-info-vec-missed -c timestep_opt2.c -o timestep_opt2.o
timestep_opt2.c:9:9: optimized: loop vectorized using 32 byte vectors
timestep_opt2.c:11:7: optimized: loop vectorized using 32 byte vectors
timestep_opt2.c:9:9: optimized: loop vectorized using 32 byte vectors

merjem@LAPTOP-HJN4TB2I:~/Parallel-Programming$ sudo likwid-perfctr -C 0 -f -g MEM_DP ./stream_triad_opt2
CPU name:       Intel(R) Core(TM) i7-8665U CPU @ 1.90GHz
CPU type:       Intel Kabylake processor
CPU clock:      0.00 GHz
Minimum dt is 0.016964
Group 1: MEM_DP
+------------------------------------------+---------+------------+
|                   Event                  | Counter | HWThread 0 |
+------------------------------------------+---------+------------+
|             INSTR_RETIRED_ANY            |  FIXC0  |   85244052 |
|           CPU_CLK_UNHALTED_CORE          |  FIXC1  |  278747389 |
|           CPU_CLK_UNHALTED_REF           |  FIXC2  |  152490096 |
|              PWR_PKG_ENERGY              |   PWR0  |          0 |
|              PWR_DRAM_ENERGY             |   PWR3  |          0 |
| FP_ARITH_INST_RETIRED_128B_PACKED_DOUBLE |   PMC0  |          2 |
|    FP_ARITH_INST_RETIRED_SCALAR_DOUBLE   |   PMC1  |         88 |
| FP_ARITH_INST_RETIRED_256B_PACKED_DOUBLE |   PMC2  |   20000001 |
|                DRAM_READS                | MBOX0C1 |      -     |
|                DRAM_WRITES               | MBOX0C2 |      -     |
+------------------------------------------+---------+------------+

+-----------------------------------+------------+
|               Metric              | HWThread 0 |
+-----------------------------------+------------+
|        Runtime (RDTSC) [s]        |          0 |
|        Runtime unhalted [s]       |          0 |
|            Clock [MHz]            |          0 |
|                CPI                |     3.2700 |
|             Energy [J]            |          0 |
|             Power [W]             |          0 |
|          Energy DRAM [J]          |          0 |
|           Power DRAM [W]          |          0 |
|            DP [MFLOP/s]           |          0 |
|          AVX DP [MFLOP/s]         |          0 |
|          Packed [MUOPS/s]         |          0 |
|          Scalar [MUOPS/s]         |          0 |
|  Memory load bandwidth [MBytes/s] |          0 |
|  Memory load data volume [GBytes] |          0 |
| Memory evict bandwidth [MBytes/s] |          0 |
| Memory evict data volume [GBytes] |          0 |
|    Memory bandwidth [MBytes/s]    |          0 |
|    Memory data volume [GBytes]    |          0 |
| Operational intensity [FLOP/Byte] |          0 |
|      Vectorization ratio [%]      |    99.9996 |
+-----------------------------------+------------+

### COMPILER OUTPUT AND PERFORMANCE RESULT FOR TIMESTEP 3
merjem@LAPTOP-HJN4TB2I:~/Parallel-Programming$ sudo likwid-perfctr -C 0 -f -g MEM_DP ./stream_triad
CPU name:       Intel(R) Core(TM) i7-8665U CPU @ 1.90GHz
CPU type:       Intel Kabylake processor
CPU clock:      0.00 GHz
Minimum dt is 0.016964
Group 1: MEM_DP
+------------------------------------------+---------+------------+
|                   Event                  | Counter | HWThread 0 |
+------------------------------------------+---------+------------+
|             INSTR_RETIRED_ANY            |  FIXC0  |   85244137 |
|           CPU_CLK_UNHALTED_CORE          |  FIXC1  |  298623990 |
|           CPU_CLK_UNHALTED_REF           |  FIXC2  |  154262680 |
|              PWR_PKG_ENERGY              |   PWR0  |          0 |
|              PWR_DRAM_ENERGY             |   PWR3  |          0 |
| FP_ARITH_INST_RETIRED_128B_PACKED_DOUBLE |   PMC0  |          2 |
|    FP_ARITH_INST_RETIRED_SCALAR_DOUBLE   |   PMC1  |         88 |
| FP_ARITH_INST_RETIRED_256B_PACKED_DOUBLE |   PMC2  |   20000001 |
|                DRAM_READS                | MBOX0C1 |      -     |
|                DRAM_WRITES               | MBOX0C2 |      -     |
+------------------------------------------+---------+------------+

+-----------------------------------+------------+
|               Metric              | HWThread 0 |
+-----------------------------------+------------+
|        Runtime (RDTSC) [s]        |          0 |
|        Runtime unhalted [s]       |          0 |
|            Clock [MHz]            |          0 |
|                CPI                |     3.5032 |
|             Energy [J]            |          0 |
|             Power [W]             |          0 |
|          Energy DRAM [J]          |          0 |
|           Power DRAM [W]          |          0 |
|            DP [MFLOP/s]           |          0 |
|          AVX DP [MFLOP/s]         |          0 |
|          Packed [MUOPS/s]         |          0 |
|          Scalar [MUOPS/s]         |          0 |
|  Memory load bandwidth [MBytes/s] |          0 |
|  Memory load data volume [GBytes] |          0 |
| Memory evict bandwidth [MBytes/s] |          0 |
| Memory evict data volume [GBytes] |          0 |
|    Memory bandwidth [MBytes/s]    |          0 |
|    Memory data volume [GBytes]    |          0 |
| Operational intensity [FLOP/Byte] |          0 |
|      Vectorization ratio [%]      |    99.9996 |
+-----------------------------------+------------+
merjem@LAPTOP-HJN4TB2I:~/Parallel-Programming$ 

### ANALYSIS 
- We can see that everything is fully vectorized (99.9996%)
- We used 256-bit (32 byte) AVX instructions
- Vector insturctions that were executed - 20,000,001 FP_ARITH_INST_RETIRED_256B_PACKED_DOUBLE
- For scalar instructions we have 88 FP_ARITH_INST_RETIRED_SCALAR_DOUBLE
- Used required flags 


### OPTIMIZATION APPROACH
- We achieved it through:
1) OpenMP SIMD pragmas 
2) Declaring variables inside the loop
3) Aggressive compiler flags that override conditional and math operation
obstacles
4) 256-bit vector width matching processor capabilities 

### CONCLUSION
- By optimizing the code and using all the flags we enabled GCC to vectorize properly 
- We can conclude that we can get near perfect vectorization when properly utilizing all the resources

### QUESTIONS FROM THE ASSIGNMENT
1) Is it fully vectorized?
- Yes. 

2) What vector length instructions were used?
- 256-bit AVX instructions, that match perfectly for the Intel i7-8665U processor that my laptop is using.

3) Which of the code runs is the best?
- OPT2 performed the best with the CPI of 3.2700. 

### NOTE ABOUT MEMORY METRICS
- As we can see we have 0 values for memory bandwidth and DRAM metrics 
- This is likely due to the limited virtualization that WSL offers
- This does not affect the vectorization analysis which relies on CPU performance counters 