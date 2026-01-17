Hands on Notes for FORK ()
* It is a child process that inherits the current state / arguments of a process when it is called
* Whenever fork() is invoded the next instructrn to be executed is the same.
* It's a whole process of it's own

But since it's a child process it shares the follwing aspects with the parent
Code, Physical pages, Open File descriptors, stdiout/stderr

Child is now a process of it's own. can outlive the parent is not depended on it can exec something else has it's own PID.



* A main point to be noted here is that when the \n charecter is missing I observe that i get printed both statements both times. meaninng output observed is as follows:

hello world hello fork hello world hello fork

on forking() a child process created and IP starts from the next point of calling of fork
This happends due the STD buffers which also get copied since the \n charecter is not present.

Since \n charector is used the buffers are dropped and new process output works fine.
A Classic trap indeed.

printf uses user spaced buffer managed by libc and buffer is in the process memory.
a mode of stdout says \n means flush the buffer. buffer = ""; internal poninters reset.


* Return Type of the Fork() Sys Call

output for second scenario:
hello world
hello to fork()! from: 122735 (parent)
hello to fork()! from: 0 (child)

ayien 0 ? 

fork() returns the following things
- PID of the child process to the parent process
- 0 to the child processes
- -1 for any errors

=> The child is a process of it's own but the vruntime is the same as it's parent. it also gets forked 
    Thus i cannot assume lowe runtime is immediately scheduled. (on blocking / waiting) best is chosen from the Red/black tree.
=> A Timer Interrupt exists that checks curernt vrumtime with competitors in the tree. if "unfair" forcefully preeempt the process. unfair is decided based on scheudled latency.

(If there was 0 printed first that would mean that child picked by CFS nothing wrong with it)

* To prevent exponential forking of process if we are on child process i.e if p_id == 0 don't fork
The first process is the Parent. then we launch a child. Now we have 2 running processes.
whenever they run we check if ihe id != 0 i.e a child must not fork again only main can fork. this is donce once and another process is created. thus 3 processes in total