#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc , char * argv[]) {

    int id = fork();
    int n;
    if(id == 0) n= 1; // if child process
    else n = 6; // for parent process

    if(id != 0)wait(NULL); // we wait for child process to complete get freed and then start printing child
    for(int i = n; i < n + 5; i++){
        printf("%d", i);
        fflush(stdout); // invoke a write call to write whatever is in buffer and clear it
    }
    printf("\n");
    return 0;
}