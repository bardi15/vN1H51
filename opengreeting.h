#ifndef OPENGREETING_H
#define OPENGREETING_H

#include <iostream>

using namespace std;

class opengreeting
{
public:
    opengreeting();
    //Default constructor for class.

    void printscreen (char ascii [][80]);
    //  Precondition:   array has been filled.
    //  Postcondition:  array is printed to screen.
    void fillarray (char ascii [][80], char input);
    //  Precondition:   array is empty.
    //  Postcondition:  array has been filled with spaces.
    void art (char ascii [][80]);
    //  Precondition:   array is filled with spaces
    //  Postcondition:  X is added to the array in specific areas.
    void greetingPost();
    //  Precondition:   screen is blank
    //  Postcondition:  ascii art has been printed to screen.

    char input;
    char ascii [20][80];
};

#endif // OPENGREETING_H
