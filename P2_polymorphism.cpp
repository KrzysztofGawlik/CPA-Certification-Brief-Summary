#include <iostream>
using namespace std;

class Pet{
    protected:
        string name;
    public:
        Pet(string name){ this->name = name; }
        void makeSound(void) { cout << name << " is silent." << endl; }
};
class Dog : public Pet{
    public:
        Dog(string name) : Pet(name) {};
        void makeSound(void) { cout << name << " is barking." << endl; }
};
class Cat : public Pet{
    public:
        Cat(string name) : Pet(name) {}
        void makeSound(void) { cout << name << " is meowing." << endl; }
};

int main(void){

    Pet *somePet; Dog *dog; Cat *cat;
    somePet = new Pet("Peter");
    dog = new Dog("Goofy");
    cat = new Cat("Tom");

    // POLYMORPHISM - subclass declares a method previously known in its superclass
    // The original method is overriden
    somePet->makeSound();
    dog->makeSound();
    cat->makeSound();

    return 0;
}