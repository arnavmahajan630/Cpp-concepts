Problem statement

Launch two processes using fork() such that the child process prints the first 5 numbers and the parent process prints the next 5 numbers.

Process creation using fork
fork() duplicates the current process. After the call, two processes exist and both continue execution from the next instruction. The only way to differentiate them is the return value of fork(). The child receives 0, while the parent receives the PID of the child.

Variable state after fork
All variables, including stack variables like id and n, are copied into the child process. These variables have the same initial values but belong to different address spaces, so changes in one process do not affect the other.

Role selection using fork return value
The condition if (id == 0) is used to identify the child process. This allows the child to start printing from 1 and the parent to start printing from 6, even though both execute the same code.

Managing the internal std buffer
printf() writes to a user-space buffer, not directly to the terminal. Since fork() duplicates process memory, unflushed buffers can get duplicated and cause repeated or corrupted output.

Why fflush(stdout) is used
Calling fflush(stdout) forces the buffered output to be written to the kernel immediately and clears the buffer. This prevents buffer duplication across processes and ensures each number is printed exactly once.

Output ordering vs execution ordering
Even though the parent and child processes may be context-switched by the scheduler, the output can still appear ordered. This is because each printf + fflush results in a serialized write to the terminal.

Important limitation
This code does not guarantee that the child prints before the parent. The observed order depends on the scheduler. To strictly enforce order, synchronization mechanisms like wait() or IPC are required.

Key takeaway
Flushing output ensures correctness of printed data, not scheduling order. Context switching can occur without being visible in the output.


* Print Child First then Parent

- The wait() system call is used by a parent process to synchronize with the lifecycle of its child processes. It does not create communication between processes; instead, it establishes a synchronization point where the parent acknowledges that a child has terminated.
- When wait() is called, the kernel checks whether any child process has already exited. If so, wait() returns immediately. If no child has exited yet, the parent process is put to sleep and removed from the scheduler until a child terminates.
- This means wait() does not “watch” the child continuously. It simply blocks or returns based on the child’s termination state at the moment it is called.

Its purpose is limited to:
Process lifecycle synchronization
Child termination acknowledgment
Zombie cleanup

