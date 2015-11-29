#ifndef INFODISPLAY_H
#define INFODISPLAY_H
#include "scientist.h"
#include "infodisplay.h"
#include "workingclass.h"

class infoDisplay
{
public:
    infoDisplay();
    void printVector() const;
    void mainMenu();
    void splashScreen();
    void screenSelection();
    void displayAddScientist();
    void displayRemoveScientist();
    void displayChangeScientist();
    void displaySearchScientist();
    void quitProgram();
};

#endif // INFODISPLAY_H
