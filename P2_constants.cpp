#include <iostream>
using namespace std;

class Class{
    private:
        const int field;
    public:
        Class(void) : field(0) {}
        Class(int n) : field(n) {};
        Class(Class &src) : field(-1) {};
};

class MaybeConstObject{
    public:
        int field;
        MaybeConstObject() : field(1) {};
        void set(int n) { field = n; }
        int get(void) const { return field; } // CONSTANT MEMBER FUNCTION
};

const char * fun(void){ return "Caution!"; }

int main(void){

    // CONSTANT "VARIABLES"
    // Read-only variables - must be initialized with value
    const int points = 0;
    int const pts = 0;

    // CONSTANT AGGREGATES
    const int points[3] = {1, 2, 3};
    const struct{
        int key;
    } data = {10};
    // FORBIDDEN: --points[2];
    // FORBIDDEN: data.key = 0;
    
    // CONSTANT POINTERS
    int arr[2] = {0, 1};
    int * const iptr = arr;
    char * const cptr = "text";
    // FORBIDDEN: --iptr; ++cptr;
    // ALLOWED:
    *iptr = -1;
    *cptr = 'T';

    // POINTERS TO CONSTANTS
    const int * iptr2 = arr;
    const char * cptr2 = "text";
    // FORBIDDEN: *iptr2 = -1; *cptr2 = 'T';
    // ALLOWED:
    --iptr2;
    ++cptr2;

    // CONSTANT POINTERS TO CONSTANTS
    const int * const iptr2 = arr;
    const char * const cptr2 = "text";
    // FORBIDDEN: any modifications (++iptr2; *cptr2 = 'T';)

    // CONSTANT FUNCTION RESULT
    const char *txt = fun();
    // FORBIDDEN: char *txt = fun();

    // CONSTANT CLASS VARIABLES
    Class classObject_noParam; // Constructor initiates const field with 0 (default)
    Class classObject_withParam(1); // Constructor initiates const field with 1
    Class classObject_Copy(classObject_noParam); // Constructor initiates const field with -1 while copying
    // FORBIDDEN: any modification of "field"

    // CONSTANT OBJECTS
    MaybeConstObject const o1;
    cout << o1.field << endl;
    MaybeConstObject o2 = o1;
    o2.field = 2;
    o2.set(o1.get()); // o1.get() can be used as the METHOD is declared as CONST
    // FORBIDDEN: o1.set(0); o1.field = 0;

    return 0;
}