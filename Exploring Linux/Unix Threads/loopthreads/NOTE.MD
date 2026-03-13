## Creating Threads in a Loop

* We need to manage multiple pthread_t structs so we put them in an array
* the issue if normal for loop is that thread, wait thread , wait so we wait till first thread is completed then launch the second thread. that's sad
* Thus we should lanuch all the threads in loop and wait for them in seperate loop.

### IMPORTANT
* The output observed is thread 0,1,2,3 at launch as well as print
* While they are printed in that manner is because of kernel message buffers are queues designed such that they will be printed in that way. threads could execute arbitarily.
