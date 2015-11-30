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
#include "infodisplay.h"
#include "workingclass.h"
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
    void displayOneScientist(scientist& s);
    void displayList(vector<scientist>& v);
    void moreInfoOnScientist(vector<scientist>& v);  //Á þetta kannski heima í service?
    void dispScientistToEdit(vector<scientist>& v);
    void dispSelectScientistToDelete(vector<scientist>& v);
//    void screenSelection();

//    void AddScientist();
//        int addScientistYearOfDeath(int &yod);
//        void searchSelection(int select);
//        string addScientistName(string &name);
//        int addScientistGender(string &gender);
//        int addScientistYearOfBirth();
//        bool addScientistMore(int &yod, string &descr, string &link);
//        int addScientistYearOfDeath();
//        string addScientistDescription(string &descr);
//        string addScientistLink(string &link);
//        bool addScientistCheck(string name, int gender, int yob, int yod, string desc, string link);
//        void addScientistPushToVector(workingclass &workingobject, scientist sO);
//        bool addScientistContinue();
//        void addScientistChange(string &name, string gender, int &yob, int &yod, string &desc, string &link, int &selectedGender);
    void displayRemoveScientist();
    void displayChangeScientist();
    void displaySearchScientist();
    void displayListOfScientists();
    void quitProgram();
    bool loopFunction();
    void addEmtyLines(int numLines);
    int getCurrentDate (string date);
};

#endif // INFODISPLAY_H
