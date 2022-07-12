#include <iostream>
using namespace std;

class Pet{
    protected:
        string name;
    public:
        void nameMe(string name) { this->name = name; }
        void jump(void) { cout << name << " is jumping." << endl; }
        void makeSound(void) { cout << name << " says: hello!" << endl; }
};

void playWithPetByPointer(string name, Pet *pet){
    pet -> nameMe(name);
    pet -> jump();
}
void playWithPetByReference(string name, Pet &pet){
    pet.nameMe(name);
    pet.jump();
}

void talkWithCatByValue(string name, Pet pet){
    pet.nameMe(name);
}
void talkWithCatByPointer(string name, Pet *pet){
    pet -> nameMe(name);
}
void talkWithCatByReference(string name, Pet &pet){
    pet.nameMe(name);
}

int main(void){

    Pet *pet_ptr = new Pet; // Stored in the heap
    Pet pet_obj;            // Stored in the stack

    // Let you modify the object state inside the function
    playWithPetByPointer("Pointer Dog", pet_ptr);
    playWithPetByPointer("Pointer Dog", &pet_obj); // pet_obj is the subject to the & operator

    // Reference makes alias for the variable
    playWithPetByReference("Reference Dog", pet_obj);
    playWithPetByReference("Reference Dog", *pet_ptr); // pet_ptr is dereferenced by the * operator

    // Passing by value works on copy of the object
    Pet pet;
    pet.nameMe("no_name");
    talkWithCatByValue("Value Cat", pet);
    pet.makeSound();
    talkWithCatByPointer("Pointer Cat", &pet);
    pet.makeSound();
    talkWithCatByReference("Reference Cat", pet);
    pet.makeSound();

    return 0;
}