#include "scientist.h"
#include "infodisplay.h"
#include "workingclass.h"
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

void infoDisplay::printVector() const
{
    workingclass worker;

    vector<scientist> tempVector = worker.returnVector();

    for(unsigned int i = 0; i < tempVector.size(); i++){
        scientist s = tempVector.at(i);
    cout << s.getName();
    cout << s.getGender();
    cout << s.getYearOfBirth();
    cout << s.getYearOfDeath();
    cout << s.getDescription();
    cout << s.getLink();
    }
}

void infoDisplay::mainMenu()
{
    int select;
    cout << "Welcome to the computer scientist database!";
    cout << "What would you like to do?" << endl;

    cout << "1) Add a new computer scientist. \n";
    cout << "2) Delete existing information. \n";
    cout << "3) Edit existing information. \n";
    cout << "4) Browse the list of computer scientists. \n";
    cin >> select;
    selectAction(sel);
}


infoDisplay::infoDisplay()
{

}

void infoDisplay::splashScreen()
{

}

void infoDisplay::screenSelection()
{

}

void infoDisplay::displayAddScientist()
{

}

void infoDisplay::displayRemoveScientist()
{

}

void infoDisplay::displayChangeScientist()
{

}

void infoDisplay::displaySearchScientist()
{

}

void infoDisplay::quitProgram()
{

}
