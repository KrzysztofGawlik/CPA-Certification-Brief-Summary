#include <iostream>
using namespace std;

class Engine{
    public:
        Engine(Engine &source) { cout << "Copying engine..." << endl; };
        Engine() { cout << "Setting up new engine..." << endl; };
};

class Body{
    public:
        Body(Body &source) { cout << "Copying body..." << endl; }
        Body() { cout << "Setting up new body..." << endl; }
};

// COMPOSITION - nothing in common with inheritance
class Car{
    public:
        Car(Car &source) : engine(source.engine), body(source.body) { cout << "Copying car..." << endl; }
        Car() { cout << "New car created!" << endl; }
        Engine engine;
        Body body;
};

int main(void){

    Car car_A;
    Car car_B = car_A;

    return 0;
}