#ifndef INFODISPLAY_H
#define INFODISPLAY_H
#include <iostream>
#include <cstdlib>
#include <vector>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <time.h>
#include <unistd.h>
#include "opengreeting.h"
#include "scientist.h"
//#include "workingclass.h"
#include "service.h"
#include <iomanip>


class infoDisplay
{
public:
    infoDisplay();
    //  Default constructor for class.
    void mainMenu();
    //  Precondition:   None.
    //  Postcondition:  Displays the main menu on screen.
    void clearScreen();
    //  Precondition:   None.
    //  Postcondition:  Screen is blank.
    void splashScreen();
    //  Precondition:   None.
    //  Postcondition:  Displays the startup greeting when program is started.
    void listheader();
    //  Precondition:   None.
    //  Postcondition:  Prints a header on the list of scientist.
    void displayOneScientist(scientist& s);
    //  Precondition:   Takes in one scientist to display as a parameter.
    //  Postcondition:  Displays all information about the scientist on screen
    void displayList(vector<scientist>& v);
    //  Precondition:   The vector v has been populated with scientist.
    //  Postcondition:  Displays all scientist according to condition on screen.
    int moreInfoOnScientist(vector<scientist>& v);
    //  Precondition:   A list of scientist has been displayed.
    //  Postcondition:  Ask for which if any scientist you want more information on.
    //      Returns the selection.
    void dispScientistToEdit(vector<scientist>& v);
    //  Precondition:   The vector v has been populated with scientist.
    //  Postcondition:  Selected scientist has is displayed on screen.
    void dispSelectScientistToDelete(vector<scientist>& v);
    //  Precondition:   The vector v has been populated with scientist.
    //  Postcondition:  Selected scientist has been removed from the file.
    bool dispSureToRemove(int gender);
    //  Precondition:   A scientist has been selected for deletion.  Takes the
    //      gender as a parameter to select text to print.
    //  Postcondition:  If answered yes, the scientist is deleted. Else the action
    //      is cancelled.
    void displayChangeScientist();
    //  Precondition:   A list of scientist has been displayed. Asks which scientist
    //      to be edited.
    //  Postcondition:  The scientists to be changed have been edited.
    void displaySearchScientist();
    //  Precondition:   The vector of scientist is populated and ready to be
    //      searched in.
    //  Postcondition:  Selected searchoption is carried out.
    int displaySortOptions();
    //  Precondition:   A list of scientist is to be displayed.
    //  Postcondition:  Displays the sorting options available and returns the selection.
    void quitProgram();
    //  Precondition:   The program is about to be terminated.  User is asked if
    //      he/she/it is sure.
    //  Postcondition:  The program has stopped running.
    bool loopFunction();
    //  Precondition:   A need for Y/N answer is present.
    //  Postcondition:  Returns true if input is 'Y', false otherwise.
    void addEmtyLines(int numLines);
    //  Precondition:   None.
    //  Postcondition:  Adds empty lines to the screen output according to
    //      the numLines parameter.
    int getCurrentDate (string date);
    //  Precondition:   A string with a date is sent as a parameter.
    //  Postcondition:  Returns the integer for the date sent in.
};

#endif // INFODISPLAY_H
