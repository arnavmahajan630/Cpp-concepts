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

