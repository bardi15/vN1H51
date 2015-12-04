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
    void menuForScientists(vector<scientist> &v);
    //  Precondition:   On main menu working on scientist was selected.
    //  Postcondition:  Displays the menu to work on scientists on screen.
    void menuForScientistsDisplay();
    void menuForScientistsSwitch(vector<scientist> &c);
    void menuForComputers(vector<computer> &c);
    //  Precondition:   On main menu working on computers was selected.
    //  Postcondition:  Displays the menu to work on computers on screen.
    void menuForComputersDisplay();
    void menuForComputersSwitch(vector<computer> &c);
    void clearScreen();
    //  Precondition:   None.
    //  Postcondition:  Screen is blank.
    void splashScreen();
    //  Precondition:   None.
    //  Postcondition:  Displays the startup greeting when program is started.
    void listheaderSci();
    //  Precondition:   None.
    //  Postcondition:  Prints a header on the list of scientist.
    void listheaderCom();

    void displayOneScientist(scientist& s);
    //  Precondition:   Takes in one scientist to display as a parameter.
    //  Postcondition:  Displays all information about the scientist on screen
    void displaySciList(vector<scientist>& v);
    //  Precondition:   The vector v has been populated with scientist.
    //  Postcondition:  Displays all scientist according to condition on screen.
    void displayComList(vector<computer> &c);

    bool scrollFunction(unsigned int vSize, unsigned int &scrollBase, unsigned int &scrollFactor);
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
    //  Postcondition:  Selected search option is carried out.
    void displaySearchComputer();
    //  Precondition:   The vector of computers is populated and ready to be
    //      searched in.
    //  Postcondition:  Selected search option is carried out.
    void displaySearchScientistMenu();

    void displaySearchComputersMenu();

    int displaySortOptions(int choice);
    //  Precondition:   A list of scientist is to be displayed.
    //  Postcondition:  Displays the sorting options available and returns the selection.
    void quitProgram();
    //  Precondition:   The program is about to be terminated.  User is asked if
    //      he/she/it is sure.
    //  Postcondition:  The program has stopped running.
//    bool loopFunction();
    //  Precondition:   A need for Y/N answer is present.
    //  Postcondition:  Returns true if input is 'Y', false otherwise.
    void addEmptyLines(int numLines);
    //  Precondition:   None.
    //  Postcondition:  Adds empty lines to the screen output according to
    //      the numLines parameter.
    int getCurrentDate (string date);
    //  Precondition:   A string with a date is sent as a parameter.
    //  Postcondition:  Returns the integer for the date sent in.
    void selectAction();
    //  Precondition:   The program is running.
    //  Postcondition:  Displays the main menu and takes in the selection from made.
    void SelectScientistAction();
    //  Precondition:   A selection is made from the scientist menu.
    //  Postcondition:  Selects which action to take based on input.
    void SelectComputerAction();
    //  Precondition:   A selection is made from the computer menu.
    //  Postcondition:  Selects which action to take based on input.
    void chooseSortion(vector<scientist>& v);
    //  Precondition:   A list of scientist is about to be displayed on screen.  Takes
    //      in a reference to the vector about to be sorted.
    //  Postcondition:  The vector is now sorted correctly according to the selection.
    void editScientistDisplayService();
    //  Precondition:
    //  Postcondition:
    void editScientistService(int i);
    //  Precondition:   A scientist is about to be edited.
    //  Postcondition:  The scientist has been edited and file updated.
    void searchSelection(int select);
    //  Precondition:   A specific search option has been selected. Takes in the
    //      selection as an integer.
    //  Postcondition:  A vector of the correct scientist/s is displayed.
    bool addScientistContinue();
    //  Precondition:   A new scientist has been entered into the vector and the user is
    //      asked if he wants to add more scientest.
    //  Postcondition:  Returns true if answered 'Y', false otherwise.
    void addScientist();
    //  Precondition:   The option to add scientist has been selected on the main mainu.
    //  Postcondition:  One or more scientists have been added to the privat vector.
    string addScientistName(string &name);
    //  Precondition:   A name for a scientist is to be entered.
    //  Postcondition:  The name entered has been corrected or an error message has been
    //      displayed on screen.
    int addScientistGender(string &gender);
    //  Precondition:   The gender for a scientist is to be entered.
    //  Postcondition:  The gender has been corrected or an error message has been
    //      displayed on screen.
    int addScientistYearOfBirth();
    //  Precondition:   The year of birth for a scientist is to be entered.
    //  Postcondition:  The year of birth has been corrected or an error message has been
    //      displayed on screen.
    bool addScientistMore(int yob, int &yod, string &descr, string &link);
    //  Precondition:   The necessary data for a new scientist is to be entered.
    //  Postcondition:  If required the new scientist has the field for year of death,
    //      description and link have been populated.
    int addScientistYearOfDeath(int yob);
    //  Precondition:   The year of death for a scientist is to be entered.
    //  Postcondition:  The year of death has been corrected or an error message has been
    //      displayed on screen.
    string addScientistDescription(string &descr);
    //  Precondition:   The description for a scientist is to be entered.
    //  Postcondition:  The description for a scientist has been entered.
    string addScientistLink(string &link);
    //  Precondition:   The link for a scientist is to be entered.
    //  Postcondition:  The link for a scientist has been entered.
    bool addScientistCheck(string name, int gender, int yob, int yod, string desc, string link);
    //  Precondition:   All data for a new scientist has been entered.
    //  Postcondition:  If approved scientist is added to private vector, else modified.
    void addScientistChange(string &name, string gender, int &yob, int &yod, string &desc, string &link, int &selectedGender);
    //  Precondition:   Data for a new scientist have been entered. Asks if any of the
    //      inserted data is to be changed.
    //  Postcondition:  Entered data for a new scientist has been corrected.
    void addComputer();
    void displayChangeComputer();
    void displayRemoveComputer();
    string addComputerName(string &compName);
    int addComputerYear(int &compYear);
    int addComputerType(int &compType);
    bool addComputerBuilt(bool &compBuilt);
    string addComputerDescr(string &compDescr);

    int inputNumberToFunction();
    //  Precondition:   A number is about to be entered as an input
    //  Postcondition:  Returns a integer if correctly entered, or reiterate the input.
    char inputCharacterToFunction();
    //  Precondition:   A character is about to be entered as an input
    //  Postcondition:  Returns a character if correctly entered, or reiterate the input.
    bool yesOrNo();
    //  Precondition:   A character is about to be entered to continue or quit.
    //  Postcondition:  Returns true if you should continue or false if not.
    void printLines(int lines, string thickness);
    //  prints lines

    const unsigned int holyScroll = 15;


    service serviceObject;
    // A object of the service layer class.  To be used in good computing :)
};

#endif // INFODISPLAY_H
