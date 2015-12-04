#ifndef COMPUTER_H
#define COMPUTER_H


#include <iostream>
#include <string>

using namespace std;

class computer
{
public:
    computer();
    // Precondition:    An instance of the class has been created.
    // Postcondition:   Initialises all string variablaes with a space, integer and boolean variables as 0.
    computer(string cName, int cYear, int cType, bool cBuilt, string cDescr);
    // Precondition:    All variables have been set with leagal values.
    // Postcondition:   Initialises all variables according to parameters.
    string getComName() const;
    // Precondition:    The class has been initialised with a computer name name.
    // Postcondition:   Returns a string with the name of the famous computer.
    int getComYear() const;
    // Precondition:    The class has been initialised with a year.
    // Postcondition:   Returns a integer with the year of birth.
    int getComType() const;
    // Precondition:    The class has been initialised with a legal year of death.
    // Postcondition:   Returns a integer with the year of death.
    string getComDescription() const;
    // Precondition:    The class has been initialised with a legal description.
    // Postcondition:   Returns a string with the description.

    void setComName(string coName);
    // Precondition:    The parameter is of a legal type and value.
    // Postcondition:   The name has been set to the parameter name.
    void setComYear(int coYear);
    // Precondition:    The parameter is of a legal type and value.
    // Postcondition:   The gender has been set to the parameter sex.
    void setComType(int coType);
    // Precondition:    The parameter is of a legal type and value.
    // Postcondition:   The YearOfBirth has been set to parameter birthYear.
    void setComDescription(string coDesc);
    // Precondition:    The parameter is of a legal type and value.
    // Postcondition:   The description has been set to parameter desc.


private:
    string comName;
    int comYear;
    int comType;
    bool comBuilt;
    string comDescr;
};

#endif // COMPUTER_H
