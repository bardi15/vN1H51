#include "scientist.h"
#include "infodisplay.h"
#include "workingclass.h"
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

void infoDisplay::printVector() const
{
    for(unsigned int i = 0; i < scientistVector.size(); i++){
        scientist s = scientistVector.at(i);
    cout << s.getName();
    cout << s.getGender();
    cout << s.getYearOfBirth();
    cout << s.getYearOfDeath();
    cout << s.getDescription();
    cout << s.getLink();
    }

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
