## Introduction to Threads in C

* pThreads is the POSIX Thread library which provides the rules set by unix for threading

### Knowledge

* Functions are not values but have memory addess and can be stored in pointers.
* void * is a typeless pointer. any data can be converted to and from void * without loosing info

### Basics
* pthread_t is a a pointer to a structure in memory called the Thread Control Block.this contains varios info about the thread.
* The os see's only 1 of this parameter called the TID much like the PID. This is a result of clone() syscall made by the pthread_create()
* this is because fork() is implemented as a syscall wand operates in the kernel space. ptherad is a library implemented in the userspace.
* clone() is the share memory version of Fork()

### Adapter Pattern
* pthread_create only supports function signature (void * ) func (void * ). To have a different arguments running as a thread we need adapter pattern.
* We create a new struct for arguments embed it in a void * function and call that through a wrapper function that matches the desired signature.

### More info
* the pthread_create() takes 1)ID, 2)fine-tune/NULL  3) pointer to function 4) additional data
* pthread_join is the wait syscall for threads

### Differnce Between Process and Thread

| Process | Thread |
| :---            | :---            |
| Comtains PID (same as first TID)      |  Has a unique TID for each      |
| KILL PID kills all the threads of that process      | KILL Tid kills a specific thread of the process      |
| Process is never scheduled. fork() schedules the main thread     | Actual entities that are scheduled      |

### Clone SysCall

* when pthread_create is called a flag called CLONE_VM is passed which is refferencing to the same virtual memory
* in fork() this flag is absent so a new mm_struct is innitializsed with COW mechanism

* At the schular level everything is a task_struct. at resource level Process and threads are different.

## A thread calling a Fork() ?
* only that specific thread is cloned. not the entirity of the process. similarly since at the schedular level everything is a task_struct so that specific ts is only copied no other threads are copied. ever.

### Race Conditions
* Deadlocks, Livelocks, Starvation. when two threads try to modify / access the same shared memory. Corrupted inconsistant and false results can be displayed. these are race conditions.



