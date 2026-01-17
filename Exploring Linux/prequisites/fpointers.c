#include <stdio.h>

void function(int x ) {
    printf("%d", x);
}

int add(int a, int b){
    return a + b;
}

int max(int a, int b){
    return a > b ? a : b;
}

int (*selectOperation())(int, int) { // takes argument as a function of specific prototype;
    int opt = 0;
    printf("Press 1 to select add. Press 2 to get max: ");
    scanf("%d", &opt);

    return opt == 1 ? add : max;
}


int main() {
    
    void (* fpointer)(int); // similar to arrays functions decay to pointers. this is similar to struct Node * ig but a function prototype
    fpointer = &function; 
    printf("testing function_pointers in C \n");

    (*fpointer)(4); // using the pointer to call the function with a param. we can never modify anything in this function it will always stay as it was defined.

    int (*addptr)(int, int);
    addptr = &add;
    int sum = (*addptr)(2, 3);
    printf("The sum of 2 and 3 is: %d\n", sum);


    int (*arr[])(int, int) = {add, max}; // this is cool. an array of functions of similar arg type. weak oop type feeling.
    int mx = (*arr[1])(15, 3);
    printf("max of 15, 3 is: %d\n", mx);


    // Functions returning pointers to functions / functions accepting pointers to other functions as arguments

    int (*operation)(int,int) = selectOperation(); //execute the function. in the end function is returning int this we have int at start
    printf("%d\n", operation(20, 5));
    return 0;
}