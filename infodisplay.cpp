#include "scientist.h"
#include "infodisplay.h"
#include "workingclass.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <stdio.h>

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

void infoDisplay::clearScreen()
{
    system("cls");
}

void infoDisplay::mainMenu()
{
    int sel;
    cout << "Welcome to the computer scientist database! \n";
    cout << "What would you like to do? \n";
    cout << endl;
    cout << "1) Add a new computer scientist. \n";
    cout << "2) Delete existing information. \n";
    cout << "3) Edit existing information. \n";
    cout << "4) Browse the list of computer scientists. \n";
    cout << "All other entries exit the program. \n";
    cin >> sel;
    selectAction(sel);
}

void infoDisplay::selectAction(int sel)
{

    switch(sel)
           {
           case 1:
               clearScreen();
               displayAddScientist();
               break;
           case 2:
               clearScreen();
               displayRemoveScientist();
               break;
           case 3:
               clearScreen();
               displayChangeScientist();
               break;
           case 4:
               clearScreen();
               displaySearchScientist();
               break;
           default:
               clearScreen();
               cout << "Thank you, come again!." << endl;
               exit(0);
               break;
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
    string name, gender, yob, yod, descr, link;

    int choice;
    char wYLTContinue = 'Y';
    bool badInput = true;
    bool quit = false;

    workingclass workingobject;

    workingobject.returnVector();

    scientist sO;

    cout<<"Enter name: ";
    cin>>name;
    //sO.setName(name);

    cout<<"Enter gender: ";
    cin>>gender;
    //sO.setGender(gender);

    cout<<"Enter year of birth: ";
    cin>>yob;
    //sO.setYearOfBirth(yob);

    cout<<"Would you like to add more information?: "<<endl;


    while (badInput == true)
    {

    cout<<"1. Add year of Death, 2. Description, 3. "
          "Website link, everything else quits."<<endl;

    cin>>choice;

        switch(choice)
        {
            case 1:
            cout<<"Year of Death: ";
            cin>>yod;
            //sO.setYearOfDeath(yod);
            break;

            case 2:
            cout<<"Description: ";
            cin>>descr;
            //sO.setDescription(descr);
            break;

            case 3:
            cout<<"Website Link:";
            cin>>link;
            //sO.setLink(link);
            break;

            default:
            quit = true;
            badInput = false;
        }

        if (quit == false)
        {
            cout<<"Would you like to continue? Y/N: ";
            cin>>wYLTContinue;
            (toupper(wYLTContinue));

            if (wYLTContinue == 'Y')
            {
                badInput = true;
            }
            else
            {
                badInput = false;
            }
        }
    }

    cout<<"finished!!!!!!!";
}

void infoDisplay::displayRemoveScientist()
{

}

void infoDisplay::displayChangeScientist()
{
    string name; //, age, yob, yod, descr, link;
    //char y = 1, n = 0;
    int choice = 0;

    cout << "Enter the name of the scientist you would like to edit: ";
    cin >> name;

    cout << "Which part of " << name <<"'s profile would you like to edit? \n";
    cout << endl;
    cout << "1) The name. \n";
    cout << "2) Year of birth. \n";
    cout << "3) Year of untimely demise(Should it apply). \n";
    cout << "4) Description. \n";
    cout << "5) Change the link. \n";
    cout << "Any other entrie returns to the main menu. \n";
    cin >> choice;

    switch(choice)
    {
        default:
            clearScreen();
            mainMenu();
            break;
    }
}

void infoDisplay::displaySearchScientist()
{

}

void infoDisplay::quitProgram()
{

}
