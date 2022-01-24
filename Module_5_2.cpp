#include <iostream>
using namespace std;

class Class {
    public:
        Class(void) { this -> value = -1; } // Empty initialization
        Class(int val) { this -> value = val; } // Overloaded constructor, initialize with value
        void setVal(int value) { this -> value = value; } // "this" is a pointer to the current object
        void setVal(void) { value = 13; } // Overloaded function setVal
        int getVal(void) { return value; }
    private:
        int value;
};

class Class_2 {
    public:
        Class_2(void) { this -> value = 10; }
        Class_2(Class_2 const & source) { value = source.value + 15; } // Copying constructor, added 15 to see the result
        // "const" above is a promise that the function won't attempt to change the referenced object
        int getVal() { return value; }
    private:
        int value;
};

class MemoryLeak {
    public:
        // Constructor (allocate memory)
        MemoryLeak(void){
            value = new int[1000];
            cout << "Allocation (" << value << ") done." << endl;
        }
        // Desctructor (free the memory)
        ~MemoryLeak(void){ // Must be parameter-less
            delete[] value;
            cout << "Deletion done." << endl;
        }
        int *value;
};

int main(void){

    Class object_A, object_B(77);

    cout << "Object A initial value: " << object_A.getVal() << endl;
    cout << "Object B initial value: " << object_B.getVal() << endl;
    object_A.setVal();
    object_B.setVal(14);
    cout << "Object A - setVal(): " << object_A.getVal() << endl;
    cout << "Object A - setVal(14): " << object_B.getVal() << endl;

    // Copying objects 
    Class_2 object_C, object_D = object_C;

    cout << "Object_C value: " << object_C.getVal() << endl;
    cout << "Object_D value: " << object_D.getVal() << endl;

    // Preventing memory leak (check the class constructor and deconstructor)
    MemoryLeak handle;

    return 0;
}