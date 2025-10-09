# Parallel-Programming
## MAKEFILE ERRORS
student@itcenter-lab128:~/Desktop/alicmerjemrepo/Parallel-Programming$ ls
main.c  Makefile  README.md
student@itcenter-lab128:~/Desktop/alicmerjemrepo/Parallel-Programming$ make
Makefile:9: *** missing separator.  Stop.
student@itcenter-lab128:~/Desktop/alicmerjemrepo/Parallel-Programming$ make
Makefile:12: *** missing separator.  Stop.
student@itcenter-lab128:~/Desktop/alicmerjemrepo/Parallel-Programming$ make
Makefile:15: *** missing separator.  Stop.
student@itcenter-lab128:~/Desktop/alicmerjemrepo/Parallel-Programming$ make
Makefile:18: *** missing separator.  Stop.

Fixed the issue by making proper indentation in the Makefile. Since I pasted the Makefile from the previous lab document, on certain lines of code the indendation was not done properly (likely due to me pasting the file. If I had written it by hand, this wouldn't have happened). I erased the indentation and redid it using the tab key on the keyboard.

## MEMORY LEAK ERROR
make valgrind
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./testing_main
==10384== Memcheck, a memory error detector
==10384== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==10384== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==10384== Command: ./testing_main
==10384== 
==10384== Invalid write of size 4
==10384==    at 0x1091D4: main (main.c:11)
==10384==  Address 0x4a9e068 is 0 bytes after a block of size 40 alloc'd
==10384==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==10384==    by 0x109193: main (main.c:6)
==10384== 
==10384== Invalid read of size 4
==10384==    at 0x1091FD: main (main.c:15)
==10384==  Address 0x4a9e068 is 0 bytes after a block of size 40 alloc'd
==10384==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==10384==    by 0x109193: main (main.c:6)
==10384== 
==10384== 
==10384== HEAP SUMMARY:
==10384==     in use at exit: 40 bytes in 1 blocks
==10384==   total heap usage: 1 allocs, 0 frees, 40 bytes allocated
==10384== 
==10384== 40 bytes in 1 blocks are definitely lost in loss record 1 of 1
==10384==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==10384==    by 0x109193: main (main.c:6)
==10384== 
==10384== LEAK SUMMARY:
==10384==    definitely lost: 40 bytes in 1 blocks
==10384==    indirectly lost: 0 bytes in 0 blocks
==10384==      possibly lost: 0 bytes in 0 blocks
==10384==    still reachable: 0 bytes in 0 blocks
==10384==         suppressed: 0 bytes in 0 blocks
==10384== 
==10384== For lists of detected and suppressed errors, rerun with: -s
==10384== ERROR SUMMARY: 3 errors from 3 contexts (suppressed: 0 from 0)

Fixed the error by adding the free(iarray) at the end of the C file to prevent memory leaks. I also added return 0 at the end of the file since it was missing.  

## ERRORS IN THE FOR LOOP 
student@itcenter-lab128:~/Desktop/alicmerjemrepo/Parallel-Programming$ make valgrind
gcc -Wall -Wextra -g -std=c99 -o testing_main main.c
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./testing_main
==10479== Memcheck, a memory error detector
==10479== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==10479== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==10479== Command: ./testing_main
==10479== 
==10479== Invalid write of size 4
==10479==    at 0x1091F4: main (main.c:11)
==10479==  Address 0x4a9e068 is 0 bytes after a block of size 40 alloc'd
==10479==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==10479==    by 0x1091B3: main (main.c:6)
==10479== 
==10479== Invalid read of size 4
==10479==    at 0x10921D: main (main.c:15)
==10479==  Address 0x4a9e068 is 0 bytes after a block of size 40 alloc'd
==10479==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==10479==    by 0x1091B3: main (main.c:6)
==10479== 
==10479== 
==10479== HEAP SUMMARY:
==10479==     in use at exit: 0 bytes in 0 blocks
==10479==   total heap usage: 1 allocs, 1 frees, 40 bytes allocated
==10479== 
==10479== All heap blocks were freed -- no leaks are possible
==10479== 
==10479== For lists of detected and suppressed errors, rerun with: -s
==10479== ERROR SUMMARY: 2 errors from 2 contexts (suppressed: 0 from 0)
student@itcenter-lab128:~/Desktop/alicmerjemrepo/Parallel-Programming$ ^C
student@itcenter-lab128:~/Desktop/alicmerjemrepo/Parallel-Programming$ ^C
student@itcenter-lab128:~/Desktop/alicmerjemrepo/Parallel-Programming$ make valgrind
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./testing_main
==11038== Memcheck, a memory error detector
==11038== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==11038== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==11038== Command: ./testing_main
==11038== 
==11038== Invalid write of size 4
==11038==    at 0x1091F4: main (main.c:11)
==11038==  Address 0x4a9e068 is 0 bytes after a block of size 40 alloc'd
==11038==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==11038==    by 0x1091B3: main (main.c:6)
==11038== 
==11038== Invalid read of size 4
==11038==    at 0x10921D: main (main.c:15)
==11038==  Address 0x4a9e068 is 0 bytes after a block of size 40 alloc'd
==11038==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==11038==    by 0x1091B3: main (main.c:6)
==11038== 
==11038== 
==11038== HEAP SUMMARY:
==11038==     in use at exit: 0 bytes in 0 blocks
==11038==   total heap usage: 1 allocs, 1 frees, 40 bytes allocated
==11038== 
==11038== All heap blocks were freed -- no leaks are possible
==11038== 
==11038== For lists of detected and suppressed errors, rerun with: -s
==11038== ERROR SUMMARY: 2 errors from 2 contexts (suppressed: 0 from 0)

Inside of the both for loops i changed "i<=10" to "i<10". Writing the for loop the first way would be incorrect because we have allocated 10 memory spaces according to the line 6 in main.c file, but we are allowing 11. That is also part of the uninitialized memory issue. That one extra memory space is uninitialized, and C doesn't allow it. 

## UNINITIALIZED VARIABLE ERROR 
main.c:10:45: warning: ‘ipos’ may be used uninitialized [-Wmaybe-uninitialized]
   10 |     for (int i = 0; i<=10; i++) { iarray[i] = ipos; }

The error said ipos variable was uninitialized, which means that it was declared but it had no value attached to it. I fixed the error by assigning it the value 0. The value of 0 does not mess with any results, so it's safe to say this was the correct way to go. While I was at it, I also initialized the ival variable to avoid the same issue. 

## FINAL RESULT AFTER FIXING EVERYTHING
student@itcenter-lab128:~/Desktop/alicmerjemrepo/Parallel-Programming$ make valgrind
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./testing_main
==13034== Memcheck, a memory error detector
==13034== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==13034== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==13034== Command: ./testing_main
==13034== 
==13034== 
==13034== HEAP SUMMARY:
==13034==     in use at exit: 0 bytes in 0 blocks
==13034==   total heap usage: 1 allocs, 1 frees, 40 bytes allocated
==13034== 
==13034== All heap blocks were freed -- no leaks are possible
==13034== 
==13034== For lists of detected and suppressed errors, rerun with: -s
==13034== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)