## Communication Between Processes

* Problem: We want to communicate with the child processes after it has been created.
* Solution: Pipe. Pipe is an "in-memory File" that has a buffer which can we written and read to-by.
            It is a unidirectional byte stream for Interprocess Communication.

### NOTE: File Descriptors
* Just an integer stored in the FD Table for tracking an active File.
* FD(process handler) -> struct_file(open instance of file) -> Inode(actual file). arrow means points to

### NOTE: Sockets
* Sockets are also FD's
* FD -> struct_file -> socket Object

###  Pause. What is a struct File ?
* IT defines the state of an Open Instance. A session of the file.
* Provides Polymorphism (functional abstraction using interfaces) at the kernel level.
* struct implements the basic Read() write() methods that work on sockets files and everything


## IPC Continued
* pipe() takes in 2 Fd's each pointing to the same struct_file for data transfer.
* bytes written on Fd[1] can be read from Fd[0]. returns 0 if successful else -1.
* Closing an FD means removing it from the table. the pipe is there now only with read end. No Write.
### NOTE: The FD Table is also Copied on the fork().
* This means that close(fd[0]) means the pipe is closed only in child's context. not the parents.
* The FD Table is different but the struct file underneath is the SAME. !!!
* This means i can techincally write to the file as a parent. but this is not the intent tho ^_^

* Here we don't need to wait for child process. this is because we are reading. and Read is a Blocking call.
