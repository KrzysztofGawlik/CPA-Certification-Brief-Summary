#include <iostream>
using namespace std;

void Conditions() {

    // Extended if statement; TRUE - not 0, FALSE - 0
    int num = 5; // Initiator (right side of =)
    if (num > 0) { cout << "1st condition"; }
    else if (num < 0) { cout << "2nd condition"; }
    else { cout << "else block"; }

    // Switch statement
    switch ( num ) {
        case 1: cout << "Positive 1"; break;
        case -1: cout << "Negative 1"; break;
        default: cout << "Nor 1 either -1";
    }

}

void More_Int_Types() {

    // More int types
    short counter; // -32768 to 32767
    int counter; // -2147483648 to 2147483647
    long counter = 123L; // -9223372036854775808 to 9223372036854775807
    unsigned counter; // Non-negative numbers (int as the default)

    char counter; // Could store values from -128 to 127
    unsigned char counter; // Could store values from 0 to 255

    float counter; // 8 precise digits
    double counter; // 15 to 17 precise digits

}

void Loops() {

    // Loops
    short i = 0;
    while ( i < 10 ) { i++; }
    do { i--; } while ( i > 0 );
    for ( short j = 0 ; j < 10 ; j++ ) { cout << "Loop executed."; }
    // break; - exits the loop and executes the next instruction after the loop's body
    // continue; - omits the rest of the loop's body and checks the condition for the next loop

}

void Logical_Bitwise_Bitshifts_Operators(){

    // Logical operators
    bool left, right;
    if ( left && right ) cout << "Conjunction"; // Both needs to be true
    if ( left || right ) cout << "Disjunction"; // One of them needs to be true
    if ( !left ) cout << "Negation"; // Logical negation

    // Bitwise operators (not for floats, works on bits!)
    if ( left & right ) cout << "Requires two 1s to provide 1 as a result"; // Ampersand
    if ( left | right ) cout << "Requires at least one 1 to provide 1 as a result"; // Bar
    if ( left ^ right ) cout << "Requires only one 1 to provide 1 as a result"; // Caret
    if ( ~left ) cout << "Requires 0 to provide 1 as a result"; // Tilde

    int flag_register = 0; // Binary representation: 0000...0#000 (# is our's bit)
    int bitmask = 8; // Our bit is on 4th position: 2^3(index) = 8;
    if (flag_register & bitmask) {
        cout << "Bit is set (1)";
    } else {
        cout << "Bit is unset (0)";
    }
    // Resetting the bit (set to 0) without making changes on the rest
    flag_register &= ~bitmask;
    // Setting the bit (set to 1) without making changes on the rest
    flag_register |= bitmask;
    // Negate the bit
    flag_register ^= bitmask;
    // Bit shifting to the left (multiply by 2) and to the right (divide by 2)
    flag_register << 1; // 1 is the number of bits to shift
    flag_register >> 1; // flag register divided by 2

}

void Arrays() {

    // Arrays
    int nums[5] = {0, 1, 2, 3, 4}; // Creates an array of 5 elements
    nums[0] = -1; // Assign a value -1 to first element
    int chessboard[8][8]; // 2 dimensional array (matrix)
    int hotel[2][5][20]; // 3 dimensional array - 2 hotels, 5 floors for each hotel and 20 rooms for each floor

}

void Structures() {

    // Declaration of a structure called STUDENT
    struct STUDENT {
        string name;
        float gradeAverage;
        bool absolvent;
    };

    // Create a new student called stdnt and assign values to it
    struct STUDENT stdnt; // Struct keyword could be omited
    stdnt.name = "Chris";
    stdnt.gradeAverage = 4.5;
    stdnt.absolvent = false;

    // Create an array called studentsGroup of structure STUDENT
    struct STUDENT studentsGroup[100]; // Struct keyword could be omited
    studentsGroup[0].name = stdnt.name;
    studentsGroup[1].name = "Kate";

    // Nested structures
    struct DATE {
        short year, month, day;
        STUDENT stdnt2;
    } Exam; // New date called Exam - initialization after declaration
    Exam.year = 2022;
    Exam.month = 1;
    Exam.day = 10;
    Exam.stdnt2.name = "John Abraham";
    Exam.stdnt2.gradeAverage = 3.67;
    Exam.stdnt2.absolvent = true;

    // Initialize structure with values
    DATE Election {2021, 6, 12, "Luis", 5., true};
    DATE SecondElection = {}; // Empty initializer

}