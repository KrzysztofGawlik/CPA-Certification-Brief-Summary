#include <iostream>
using namespace std;

class Human {
    public:
        Human() { ++counter; } // Increment while new object created
        ~Human() {
            --counter; // Decrement while object destructed
            cout << "Human killed." << endl;
            if(counter == 0) cout << "No one left..." << endl;
        }
        // Static functions could be accessed when no objects are created
        static void count(void) { cout << "We've got " << counter << " human(s)." << endl; }
    private: // When private we protect the variable from modifying
        static int counter; // Could be used as objects counter
};

void auto_var(void){
    int x = 0; // Default "automatic" creation and deletion of variable (auto)
    cout << ++x << "\t";
}

void static_var(void){
    static int x = 0; // Static creation in program prologue and deletion in epilogue
    cout << ++x << "\t";
}

int Human::counter = 0;
int main(void){

    for(int i = 0; i < 5; i++)
        auto_var(); // 5 times "x" will be initiated
    cout << endl;
    for(int i = 0; i < 5; i++)
        static_var(); // "x" will be initiated once and once removed
    cout << endl;

    Human::count();
    Human Eve, Tom;
    Tom.count();
    Human Ern, Lisa;
    Eve.count();

    return 0;
}