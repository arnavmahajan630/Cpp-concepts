#include <iostream>
#include <string>
#include <unistd.h>
using namespace std;


int main() {
    printf("hello world\n");
    fork();
    printf("hello to fork()!\n");
}