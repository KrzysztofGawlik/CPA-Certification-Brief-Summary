#include <iostream>
using namespace std;

void Pointers() {

    int *p; // Declaration of a pointer "*"
    p = 0; // Null pointer
    p = NULL; // Also null pointer; NULL refers only to pointers (cstring or iostream needed)

    int i;
    p = &i; // & is a reference operator - finds the address of the argument
    cout << *p; // Dereference - gets a value stored at the location

    int *ptr, array[3];
    ptr = array; // ptr points to the 1st element of an array

    // Pointers arithmetic
    int *ptr2 = ptr; // ptr2 point to the same location as ptr
    ptr2 = ptr2 + 2; // Automatically calculates (2 * sizeof(int)), moves to the second int ahead

    i = ptr2 - ptr; // Assign more than 0 if ptr2 is after ptr in memory; < 0 if ptr2 is before
    ptr = &array[2];
    ptr2 = &array[0];
    cout << ptr - ptr2; // The output will be 2; ptr is 2 ints after ptr2 

}

void Functions() {

    // Function declaration (prototype).
    float square(float x); // First float defines the result type, second type of a parameter.

    // Function definition (declaration + body).
    float add(float x, float y){ // x and y are actual parameters (transferred to the function).
        float sum; // Sum will be accessible only within the function scope.
        sum = x + y; // Some operations; sum is a formal parameter (created inside a function).
        return sum; // Indicates which value will be returned and terminates the function execution.
    }

    /*
    To use functions in a program you have to write declaration it before you use it.
    Body could be written at the end of the program.
    You can define a whole function before the main function.
    You can return any type including void (no result) or omit return type - default will be int.
    */

    void sayHello(void){ // No result is returned and function takes no parameters.
        cout << "Hello!" << endl;
        return; // Could be omitted.
    }
    sayHello(); // Function invocation.

    void increment_x(int x); // Passing parameter by value - x will not leave the function.
    void increment_y(int & y); // Passing parameter by reference - y will be changed outside a function.

    void repeat(string str, int rep = 1); // Sets the default parameter value.

    /*
    Functions from compiler side:
        # Prologue - part of code implicitly executed before the function:
            transfer parameter from invoker and store in a stack.
        # Epilogue - implicitly executed right after the function's code:
            transfer the result and clear the stack.
    */

    // Use inline when the function is short and fast and will be invoked very often.
    // More time effective but code size will be significantly larger.
    inline int increment(int x);

    // main > prologue > function > epilogue > main
    // main > inline > main

}

void Overloaded_Functions() {

    //Based on parameters quantity
    void doSomething(int a);
    void doSomething(int a, int b);

    doSomething(1, 2);
    doSomething(3);

    // Based on type
    void doSomething2(int x); // "The best candidate" for the first invoker
    void doSomething2(float x); // "The best candidate" for the third invoker

    doSomething(1); // Pass integer
    doSomething(1.0); // C++ compiler promotes 1.0 to double (more precise) - compiler error
    doSomething(1.0f); // f indicates float

}

void Sorting() {

    

}