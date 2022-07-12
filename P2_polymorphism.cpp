#include <iostream>
using namespace std;

class Pet{
    protected:
        string name;
    public:
        Pet(string name){ this->name = name; }
        void makeSound(void) { cout << name << " is silent." << endl; }
        // POLYMORPHISM is defined by virtual keyword
        // Method will be redefined - not overriden
        virtual void eat(void) { cout << name << " eats enything." << endl; }
};
class Dog : public Pet{
    public:
        Dog(string name) : Pet(name) {};
        void makeSound(void) { cout << name << " is barking." << endl; }
        void eat(void) { cout << name << " eats dogs food." << endl; }
};
class Cat : public Pet{
    public:
        Cat(string name) : Pet(name) {}
        void makeSound(void) { cout << name << " is meowing." << endl; }
        void eat(void) { cout << name << " eats cats food." << endl; }
};

int main(void){

    Pet *somePet; Dog *dog; Cat *cat;
    somePet = new Pet("Peter");
    dog = new Dog("Goofy");
    cat = new Cat("Tom");

    // METHOD OVERLOADING - subclass declares a method previously known in its superclass
    // The original method is overriden
    somePet->makeSound();
    dog->makeSound();
    cat->makeSound();
    // UPPERCASTING here reveals the original makeSound() method
    static_cast<Pet *>(dog)->makeSound();
    // DOWNCASTING here treats the Pet as it was a Dog
    static_cast<Dog *>(somePet)->makeSound();

    // POLYMORPHISM - a method to redefine the behaviour of a superclass without touching its implementation
    // Polymorphism gives the ability to realize class behaviour in multiple ways
    somePet->eat();
    dog->eat();
    cat->eat();
    // Binding between the original method and its polymorphic implementation is established when the object is created (not sooner)

    

    return 0;
}