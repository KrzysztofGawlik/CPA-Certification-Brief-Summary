#include <iostream>
#include <string>
using namespace std;

void f(int x);
float g(void){
    return -1;
}

int main(void){

    // ARRAY OF POINTERS (TRIANGULAR ARRAY)
    int rows = 5, cols = 5;
    int **ptrArr;
    // Allocate and initialize
    ptrArr = new int * [rows];
    for(int r = 0; r < rows; r++){
        ptrArr[r] = new int [r + 1];
        for(int c = 0; c <= r; c++)
            ptrArr[r][c] = (r+1) * 10 + (c+1);
    }
    // Print the array
    for(int r = 0; r < rows; r++){
        for(int c = 0; c <= r; c++)
            cout << ptrArr[r][c] << " ";
        cout << endl;
    }
    // Free the array
    for(int r = 0; r < rows; r++)
        delete[] ptrArr[r];
    delete[] ptrArr;

    // IMPLICIT CONVERSIONS - automatically done by compiler
    int Int = 1;
    short Short = 2;
    long Long = 3;
    float Float = 4.0f;
    double Double = 5.0;

    Int = Int + Short; // short converted to int
    if(Double) Double--; // double converted to int
    Float = 1; // int converted to float
    f(Float); // float converted to int
    g(); // see the body - return type: float; returned -1; int converted to float

    // TYPE CASTING - EXPLICIT CONVERSIONS
    float fl = 3.14;
    long ln = 12L; // avoided conversion from 12(int) to 12(long) by adding "L" or "l" at the end
    cout << int (fl) << endl; // functional notation; output will be 3
    cout << (int) ln << endl; // C-style casting

    // GAINS AND LOSSES FOR CONVERSIONS
    short a = 123;
    int b = a; // No loss - memory representation increases (could remain the same)
    int x = 2147483647;
    short y = x; // Loss - memory representation descreases - no space available to represent 2147483647 in short

    // STRINGS (#INCLUDE <STRING>)
    string name = "Krzysztof ";
    string sec_name("Adrian");
    cout << name + sec_name << endl; // output will be "Krzysztof Adrian"
    // Concatenation (+) operator cannot concatenate literals.
    getline(cin, name); // to ignore any whitespaces

    // Comparisons
    name == sec_name; // equality
    name != sec_name; // unequality
    name >= sec_name; // NOTE: a > A; z > a; a < 1

    // Object-oriented approach
    name.compare(sec_name); // string memeber function; return 0 if identical, 1 if different
    name.compare(sec_name) == 0; // name == sec_name
    name.compare(sec_name) > 0; // name > sec_name
    name.compare(sec_name) < 0; // name < sec_name
    
    name.substr(0, 3); // Cut a string starting from the 0 position and take 3 positions ahead - "Krz"
    name.substr(2); // From 2 position - 3rd letter, to the end
    name.substr(); // Copy of a whole string

    name.length();
    name.size(); // Both member functions will return the number of characters

    sec_name.compare(0, 3, "Adr"); // Compare sec_name.substr(0,3) with "Adr"
    name.compare(2, 3, "rzyszt", 1, 3); // Compare name.substr(2,3) with "rzyszt".substr(1,3)

    if(name.find("to") != string::npos) // Search for "to"; find('y', 3) - start from position 3
        cout << "Found \"to\" at " << name.find("to") << " position!" << endl;

    int buffer = name.capacity(); // Will show you what is the size of currently allocated buffer
    name.max_size(); // Will show you what is the max buffer size
    name.reserve(100); // Adjust the size of the buffer for the string name
    name.resize(20, '-'); // String will be expanded and filled with '-', default char is null char ('\0')
    name.empty(); // Checks if the string is empty - return boolean
    name.clear(); // Truncate the string
    sec_name[4]; // Return the char under index 4 

    return 0;
}