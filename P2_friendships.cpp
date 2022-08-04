#include <iostream>
using namespace std;

class A; // It tells the compiler that the A class will be in use
class C{
    public:
        // Method resetPassword has access to A components as the method is declared as FRIEND
        void resetPassword(A &src);
};

// Class A has no access to any other classes as it is not declared anywhere as FRIEND
class A{
    friend class B;
    friend void C::resetPassword(A &);
    private:
        string password = "secret@123";
        void revealPassword(void) { cout << "A: My password is " << password << endl; }
};

void C::resetPassword(A &src) { src.password = "default"; }

// Class B has access to all components of class A as it is declared as FRIEND
class B{
    public:
        void askForPassword(A &src) { src.revealPassword(); }
        void changePassword(A &src, string pwd) { src.password = pwd; }
};

// A friend's friend isn't my friend!
// Friendship isn't inherited!

int main(void){

    A someone; B buddy; C admin;
    buddy.askForPassword(someone);
    buddy.changePassword(someone, "change@321");
    buddy.askForPassword(someone);
    admin.resetPassword(someone);
    buddy.askForPassword(someone);

    return 0;
}