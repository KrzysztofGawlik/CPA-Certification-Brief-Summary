#include <iostream>
using namespace std;

// Automatic variables created by declaration are stored in STACK (no control)
// On demand variables created by new keyword are stored in HEAP (full control)

class someClass {
    public:
        someClass(void) { cout << "Object constructed." << endl; }
        ~someClass(void) { cout << "Object destructed." << endl; }
        int value;
        void IncAndPrint(void) { cout << "Value is: " << ++value << endl; }
};

class Element {
        int value = 0; // Private
    public:
        Element(void) { cout << "Element constructed." << endl; }
        int getValue(void) { return value; }
        void setValue(int v) { value = v; }
};

class Collection {
        Element el_1, el_2; // Object inside object
    public:
        Collection(void) { cout << "Collection constructed." << endl; }
        int getElementValue(int x) { return x == 1 ? el_1.getValue() : el_2.getValue(); }
        void setElementValue(int x, int v) { x == 1 ? el_1.setValue(v) : el_2.setValue(v); }
};

int main(void){

    someClass *ptr; // Declare pointer
    ptr = new someClass(); // Create new object and assign to pointer
    delete ptr; // Destroy the object

    cout << "-----------------------------------" << endl;

    someClass *ptr_2;
    ptr_2 = new someClass();
    ptr_2 -> value = 0; // Access to the object from heap resembles the access to dynamically allocated structures
    ptr_2 -> IncAndPrint(); // This rule applies also for methods
    cout << ++(ptr -> value) + 10 << endl;
    delete ptr;

    cout << "-----------------------------------" << endl;

    Collection coll; // Objects inside other objects (inner) are always created first, then outer objects are created
    for(int i = 1; i <= 2; i++)
        coll.setElementValue(i, i * 10);
    for(int i = 1; i <= 2; i++)
        cout << "Elem. #" << i << " value: " << coll.getElementValue(i) << endl;

    return 0;
}