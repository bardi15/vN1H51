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
    void selectAction(int sel);
    void mainMenu();
    void clearScreen();
    void splashScreen();
    void screenSelection();
    void AddScientist();
        string addScientistName(string &name);
        int addScientistGender(string &gender);
        int addScientistYearOfBirth();
        bool addScientistMore(int &yod, string &descr, string &link);
        int addScientistYearOfDeath();
        string addScientistDescription(string &descr);
        string addScientistLink(string &link);
        bool addScientistCheck(string name, int gender, int yob, int yod, string desc, string link);
        void addScientistPushToVector(workingclass &workingobject, scientist sO);
        bool addScientistContinue();
        void addScientistChange(string &name, string gender, int &yob, int &yod, string &desc, string &link, int &selectedGender);
    void displayRemoveScientist();
    void displayChangeScientist();
    void displaySearchScientist();
    void displayListOfScientists();
    void quitProgram();
    bool loopFunction();

};

#endif // INFODISPLAY_H
