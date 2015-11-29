//#include <QCoreApplication>
#include <iostream>
#include "scientist.h"
#include "infodisplay.h"
#include "workingclass.h"


using namespace std;
void clearscreen();
int main()
{
//    workingclass jon;
//    jon.readFile();
//    jon.printVector();
//    scientist gunna;
//    gunna.setName("gunna");
//    gunna.setGender(0);
//    gunna.setYearOfBirth(2010);
//    gunna.setYearOfDeath(0);
//    gunna.setDescription(" ");
//    gunna.setLink(" ");
//    jon.pushToVector(gunna);
//    clearscreen();
//    jon.printVector();

    infoDisplay display;

    display.mainMenu();
    //display.displayAddScientist();

    return 0;
}
void clearscreen()
{
    system("cls");
}
