#include <iostream>
#include <string>
#include <unistd.h>
using namespace std;


int main() {
    // printf("hello world\n");
    // int id = fork();
    // printf("hello to fork()! from: %d\n", id);


    fork();
    fork(); // 2^n processes are created reasoning is understood.
    printf("hello from fork()\n");
}