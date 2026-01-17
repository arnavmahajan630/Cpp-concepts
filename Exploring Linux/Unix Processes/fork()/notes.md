* A main point to be noted here is that when the \n charecter is missing I observe that i get printed both statements both times. meaninng output observed is as follows:

hello world hello fork hello world hello fork

on forking() a child process created and IP starts from the next point of calling of fork
This happends due the STD buffers which also get copied since the \n charecter is not present.

Since \n charector is used the buffers are dropped and new process output works fine.
A Classic trap indeed.

printf uses user spaced buffer managed by libc and buffer is in the process memory.
a mode of stdout says \n means flush the buffer. buffer = ""; internal poninters reset.



Hands on Notes for FORK ()
* It is a child process that inherits the current state / arguments of a process when it is called
* Whenever fork() is invoded the next instructrn to be executed is the same.
* It's a whole process of it's own

But since it's a child process it shares the follwing aspects with the parent
Code, Physical pages, Open File descriptors, stdiout/stderr

Child is now a process of it's own. can outlive the parent is not depended on it can exec something else has it's own PID.


