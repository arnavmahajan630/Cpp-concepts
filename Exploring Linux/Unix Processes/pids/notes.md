Each Process is Assigned a Unique ID called PID

* I am seeing that A parent has a parent ? A parent that i started ??
- Every unix process has a parent. nothing starts from the root.
- The shell started the parent process in question and it is the parent of this process.
- Shell calls the fork() + execve() over the executable to start a new child process

* init/Systemmd is the first og (PID=1) process created directly by kernel.

* Copy on Write Concept (i like this one)
Q - How does fork ensure that process is independed.
Well whenever a new process is forked a child and parent share the same memory initially. They ofcourse have different virtual addressing space but essentially the actual physical memory is the same. Is this not the same as threading ? same memory atomic problems ?
* The Kernel keeps these virtual pages in a Read only mode. the moment p1 p2 exist and p2 tries to modfy a shared variable that var say x is copied on demand and made exclusive for p2 and modified.

Q So how to make the process compeltely independent ? 
- Call the execve() this will clean everything setup fresh tables to fresh memory allocate fresh stack and heap. If the process is completely different from the parent and does not even require reading from the parent memory this is the best.

All the parameters below are freshly assigned.
new ELF
new entry point
new runtime state

code
data
heap
stack
mappings

* A caveat is that kernel never shares the live sate of parent. it's just a snapshot
if there are 2 process say p1 and variable n = 10; fork() now p2 can see n = 10; if p1 modifies it's own n then the n for p2 never get's modified. p2's n will always be 10; 
moment anyone writes any of the variables a new COW + physical page is allocated and that specific variable becomes private. Reading a variable on snapshot at time of forK() not live situation.


* What if we don't wait for a child to complete before exiting parent process ? (we must do it)
Then in the output we see that the child now has a different parent id. not the orignal parent.
This is because, the parent is done and child remains so a new process is creted and assigned as it's parent. This is the OG systemd prcoess which is assigned as the default parent.