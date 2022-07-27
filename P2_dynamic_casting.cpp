#include <iostream>
using namespace std;

class Pet{
    protected:
        string name;
    public:
        Pet(string name){ this->name = name; }
        virtual void makeSound(void){ cout << this->name << " is silent." << endl; }
};
class Dog : public Pet{
    public:
        Dog(string name) : Pet(name){}
        void makeSound(void){ cout << this->name << " says: Woof" << endl; }
};
class GermanShepherd : public Pet{
    public:
        GermanShepherd(string name) : Pet(name){}
        void makeSound(void){ cout << this->name << " says: Wuuf" << endl; }
        void Laufen(void){ cout << this->name << " is running through Germany." << endl; }
};
class MastinEspanol : public Pet{
    public:
        MastinEspanol(string name) : Pet(name){}
        void makeSound(void){ cout << this->name << " says: Guau" << endl; }
        void Ejacutar(void){ cout << this->name << " is running through Spain." << endl; }
};
void playWithPet(Pet *pet){
    GermanShepherd *gs;
    MastinEspanol *me;
    pet->makeSound();
    // Dynamic casting return a new fully usable pointer if the conversion is possible.
    if(gs = dynamic_cast<GermanShepherd *>(pet)){
        gs->Laufen();
    }
    if(me = dynamic_cast<MastinEspanol *>(pet)){
        me->Ejacutar();
    }
}
void playWithPet(Pet &pet){
    pet.makeSound();
    // If we don't want to use a variable we can pass the object by reference.
    try{
        dynamic_cast<GermanShepherd &>(pet).Laufen();
    } catch (...) {}
    try{
        dynamic_cast<MastinEspanol &>(pet).Ejacutar();
    } catch (...) {}
}

int main(void){

    Pet *pet = new Pet("Peter");
    Dog *dog = new Dog("Doger");
    GermanShepherd *gs = new GermanShepherd("George");
    MastinEspanol *me = new MastinEspanol("Maestro");
    
    playWithPet(pet);
    playWithPet(dog);
    playWithPet(gs);
    playWithPet(me);
    cout << "---------------------" << endl;
    
    Pet pet2("Peter 2");
    Dog dog2("Doger 2");
    GermanShepherd gs2("George 2");
    MastinEspanol me2("Maestro 2");
    playWithPet(pet2);
    playWithPet(dog2);
    playWithPet(gs2);
    playWithPet(me2);

    return 0;
}