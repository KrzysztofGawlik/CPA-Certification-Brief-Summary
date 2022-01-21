#include <iostream>
using namespace std;

class Stack {
    private: // Default option, can be omitted
        int storage[100];
        int SP; // Stack Pointer
    public: // Accessible to every class's user
        Stack(void) { SP = 0; } // Constructor - it’s responsible for the proper construction of each new object of the class
        void push(int value); // Declared outside of a class
        int pop(void){ // Declared inside of a class
            return storage[--SP];
        }
};

class AddingStack : Stack { // Subclass derives all components of superclass (Stack) - inheritance
    private:
        int sum;
    public:
        AddingStack(void); // Constructor build outside of the class
        void push(int value); // New push function which adds the value to the sum
        int pop(void); // New pop function which substracts the value from the sum
        int getSum(){
            return sum;
        }
};

AddingStack::AddingStack(void) : Stack() { // :Stack() - invoke superclass constructor before the current constructor
    sum = 0; // Body of the constructor of the class AddingStack
}

void Stack::push(int value){ // Qualified with name of class and ::
    storage[SP++] = value;
}

void AddingStack::push(int value){
    sum += value;
    Stack::push(value); // Use already existing push function from the superclass
}

int AddingStack::pop(void){
    int value = Stack::pop(); // Use already existing pop function from the superclass
    sum -= value;
    return sum;
}

int main(void){

    // Use of declared classes
    AddingStack aStack; // Got access to public components of the class and no access for private
    for(int i = 0; i < 10; i++){
        aStack.push(i * 3);
    }
    cout << aStack.getSum() << endl;
    for(int i = 0; i < 5; i++){
        aStack.pop();
    }
    cout << aStack.getSum() << endl;

    return 0;
}