#include <iostream>
using namespace std;

class Super{
    private:
        int storage;
    protected:
        int storage_2;
    public:
        void put(int val){ storage = val; }
        int get(void){ return storage; }
};
// Subclass with default access modifier (private)
class SubPriv : Super{
    // All components will be inaccessible (Super is private)
};
class SubPubl : public Super{
    // Private components will remain private, public components will remain public.
    // Protected components will be accessible in this class, but inaccessible to the outside.
    public:
        SubPubl(){ storage_2 = 5; }
        int get(void) { return storage_2; }
};


// Objects of the superclass are compatible with objects of the subclass.
// Objects of the subclass are not compatible with objects of the superclass.
class Pet{
    protected:
        string name;
    public:
        Pet(string name){ this->name = name; }
        void run(void){ cout << name << " is running." << endl; }
};
class Dog : public Pet {
    public:
        Dog(string name) : Pet(name) {}
        void makeSound(void) { cout << name << " barks." << endl; }
};
class Cat : public Pet {
    public:
        Cat(string name) : Pet(name) {}
        void makeSound(void) { cout << name << " meows." << endl; }
};


int main(void){
    SubPubl pub;
    cout << "Inherited component storage_2 = " << pub.get() << endl;

    Dog a_dog("Max");
    a_dog.run(); a_dog.makeSound();

    Pet *a_pet = new Cat("Tom"); // Cat is not compatible with Pet
    a_pet -> run(); // a_pet -> makeSound(); -- is not allowed, pet cannot make sound

    Pet *dog_as_pet = new Dog("Goofy");
    static_cast<Dog *>(dog_as_pet) -> makeSound(); // static_cast - I guarantee that the proper object exists
    // Static casts also works for arbitrarily long inheritance chain (e.g. Pet < Cat < Persian)

    return 0;
}