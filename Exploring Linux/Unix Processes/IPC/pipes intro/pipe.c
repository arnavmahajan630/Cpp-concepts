#include <stdio.h>
#include <unistd.h>

int main(int argc, char * argv[]) {
    int fd[2]; // fd[0] <- fd[1] These are not fd's but a palce to store those fd's
    if(pipe(fd) == -1) {
        perror("An error occured in opening the pipe");
    }

    int id = fork();
    if(id == 0){
        close(fd[0]); // never even gonna read so don't care.
        // in the child process rn
        int x = 0;
        printf("Input a number: ");
        scanf("%d", &x);

        printf("Written %d by child to the File Successfully ! ", x);
        write(fd[1], &x, sizeof(int)); // write to fd 1
        close(fd[1]); // clsed the write channel
    }
    else {
        close(fd[1]); // never gonna write so don't care
        int y = 0;
        if(read(fd[0], &y, sizeof(int)) == -1)perror("Error while reading from the piped file");
        else printf("Read %d by parent from the dile successfully ! ", y);
        close(fd[0]); // Completed reading
    }
}