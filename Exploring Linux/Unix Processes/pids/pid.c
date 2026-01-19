#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char * argv[]) {
     int id = fork();
     if(id != 0)wait(NULL);
    // if(id != 0)printf("Parent PID = %d\n", getpid());
    // else printf("Child PID = %d", getpid());

    // for both parent and child would print it's pid and it's parent's pid
    // now we ensure child finishes first and then only the parent is printed. 
    if(id == 0)printf("CHILD VIEW: Current ID: %d, Parent id: %d\n", getpid(), getppid());
    else printf("PARENTS VIEW: Current ID: %d, Parent id: %d\n", getpid(), getppid());

    // btw wait autochecks if process is child or not.
    // wait returns which process has finieshed executed. i.e the id of the child who i waited for.
    return 0;
}