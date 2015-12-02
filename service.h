#ifndef SERVICE_H
#define SERVICE_H

#include <iostream>
#include <string>
#include "infodisplay.h"
#include "workingclass.h"

using namespace std;

class service
{
public:
    service();
    //  Default constructor for class.
    void selectAction();
    //  Precondition:   The program is running.
    //  Postcondition:  Displays the main menu and takes in the selection from made.
    int selection();
    //  Precondition:   A need for a selection is present.
    //  Postcondition:  Returns a integer corresponding to the selection made.
    void searchSelection(int select);
    //  Precondition:   A specific search option has been selected. Takes in the
    //      selection as an integer.
    //  Postcondition:  A vector of the correct scientist/s is displayed.
    void chooseSortion(vector<scientist>& v);
    //  Precondition:   A list of scientist is about to be displayed on screen.  Takes
    //      in a reference to the vector about to be sorted.
    //  Postcondition:  The vector is now sorted correctly according to the selection.
    void editScientistDisplayService();
    //  Precondition:
    //  Postcondition:
    void editScientistService(int i); //(int selection, int scientist);
    //  Precondition:   A scientist is about to be edited.
    //  Postcondition:  The scientist has been edited and file updated.
    workingclass workingobject;
    // A object of the data layer class.  To be used in good computing :)
};

#endif // SERVICE_H
