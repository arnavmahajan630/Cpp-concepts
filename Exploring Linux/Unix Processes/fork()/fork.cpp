#include <iostream>
#include <string>
#include <unistd.h>
using namespace std;


int main() {
    printf("hello world\n");
    int id = fork();
    printf("hello to fork()! from: %d\n", id);
}