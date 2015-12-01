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
    //void printVector() const;
//    void selectAction(int sel);
    void mainMenu();
    void clearScreen();
    void splashScreen();
    void listheader();
    void displayOneScientist(scientist& s);
    //  Precondition:   Takes in one scientist to display as a parameter.
    //  Postcondition:  Displays all information about the scientist on screen
    void displayList(vector<scientist>& v);
    int moreInfoOnScientist(vector<scientist>& v);  //Á þetta kannski heima í service?
    void dispScientistToEdit(vector<scientist>& v);
    void dispSelectScientistToDelete(vector<scientist>& v);
    bool dispSureToRemove(int gender);
    void displayChangeScientist();
    void displaySearchScientist();
    void displayListOfScientists();
    void displaySortOptions();
    void quitProgram();
    bool loopFunction();
    void addEmtyLines(int numLines);
    int getCurrentDate (string date);
};

#endif // INFODISPLAY_H
