#include <iostream> // Preprocessor directive - takes place before compilation
using namespace std; // STL elements; namespace - abstract container to hold a logical grouping of unique entities (blocks)

int main(void) // Prototype
// Function body
{
    string sample = "Demo program"; // Variable declaration of type (attribute): string - stored as array
    char character = 'X'; // Single character type

    // Escape characters
    sample = " \n "; // new line (LF - Line Feed)
    sample = " \r "; // return to the beggining of the new line (CR - Carriage Return)
    sample = " \a "; // alarm (BEL - Bell)
    sample = " \0 "; // does not represent any character (NULL - None)

    int bl = 1 > 0; // 1 while TRUE; 0 while FALSE 

    // Literals - uniquely identifies its value: 10 / 10.0 / 'A'
    // Not literals: character (could be the name) / i + 100 (it's expression)

    float number = .123; // Decimal
    number = 0123; // Octal
    number = 0x123; // Hexadecimal
    number = 1.4E4; // Scientific notation for 14000, E-4 for left shift

    number = 255.;
    cout << number << ", " << hex << number << dec; // Manipulator affects the display form, here: 255, FF

    number++; number--; // Postincrementation; postdecrementation (use original value and increment/decerement)
    ++number; --number; // Preincrementation; predecrementation (use incremented/decremented value)

    // Conditional statements
    bool condition = 4 > 2;
    if (condition) { return true; } else { return false; }

    return 0; // Successfull execution of a program
    return 1; // Failed execution of a program
}