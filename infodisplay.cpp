#include "scientist.h"
#include "infodisplay.h"
#include "workingclass.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <stdio.h>
#include <string>

//new

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
    clearScreen();
    addEmtyLines(5);
    cout << "\t Welcome to the computer scientist database! \n";
    cout << "\t What would you like to do? \n";
    cout << endl;
    cout << "\t 1) Add a new computer scientist. \n";
    cout << "\t 2) Delete existing information. \n";
    cout << "\t 3) Edit existing information. \n";
    //cout << "\t 4) Browse the list of computer scientists. \n";
    cout << "\t 4) Search for a computer scientists. \n";
    cout << "\t All other entries exit the program. \n";
    cin >> sel;
    selectAction(sel);
}

void infoDisplay::selectAction(int sel)
{

    switch(sel)
           {
           case 1:
               clearScreen();
               AddScientist();
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
               addEmtyLines(10);
               cout << "Thank you, come again!." << endl;
               addEmtyLines(10);
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

void infoDisplay::AddScientist()
{
    int selectedGender;
    bool wYLTContinue = true;
    //bool badInput = false;
    //bool quit = false;

    scientist sO;

    workingclass workingobject;

    while(wYLTContinue == true)
    {

        clearScreen();
        cout<<"Creating a new Scientist: "<<endl;
        cout<<"======================================"<<endl;

        string name = " ", gender = " ", descr = " ", link = " ";
        int yob = 0, yod = 0;

        name = (addScientistName(name));
        selectedGender = addScientistGender(gender);

        yob = (addScientistYearOfBirth(yob));


        bool addEvenMore = true;

        while (addEvenMore == true)
        {
            addEvenMore = addScientistMore(yod, descr, link);
        }

        bool changeInput = false;

        do
        {
            changeInput = addScientistCheck(name,selectedGender,yob,yod,descr,link);

            if (changeInput == false)
            {
                addScientistChange(name,gender,yob,yod,descr,link,selectedGender);
            }
        }
        while (changeInput == false);


        wYLTContinue = addScientistContinue();

        sO.setName(name);
        sO.setGender(selectedGender);
        sO.setYearOfBirth(yob);
        sO.setYearOfDeath(yod);
        sO.setDescription(descr);
        sO.setLink(link);

        vector<scientist> tempVector;
        tempVector = workingobject.returnVector();
        tempVector.push_back(sO);
        workingobject.modifyVector(tempVector);
    };

    cout<<"output out of vector: "<<endl<<endl;
    workingobject.printVector();

}

string infoDisplay::addScientistName(string &name)
{
    workingclass workingobject;
    bool badName = false;

    do
    {
        cout<<"Enter name: ";
        //getline(cin, name);  <---- ÞARF AÐ LAGA!!!!!!!!!!!!!!!!!
        cin>>name;
        name = workingobject.nameCorrection(name, badName);
        if (badName == true)
        {
            cout<<"bad name!"<<endl;
        }
    }
    while(badName == true);

    return name;


}

int infoDisplay::addScientistGender(string &gender)
{
    workingclass workingobject;
    int selectedGender;
    cout<<"Enter gender: ";
    cin>>gender;

    for(unsigned int i = 0; i < gender.length(); ++i)
    {
        gender[i] = tolower(gender[i]);
    }

    selectedGender = workingobject.genderCorrection(gender);

    return selectedGender;
}

int infoDisplay::addScientistYearOfBirth(int &yob)
{
    workingclass workingobject;
    cout<<"Enter year of birth: ";
    cin>>yob;
    yob = workingobject.yearCorrection(yob);

    return yob;
}

bool infoDisplay::addScientistMore(int &yod, string &descr, string &link)
{
    workingclass workingobject;
    addEmtyLines(2);
    cout<<"1. Add year of Death, 2. Description, 3. "
          "Website link, everything else quits."<<endl;

    char choice;
    cin>>choice;

    switch(choice)
    {
        case '1':
        yod = addScientistYearOfDeath(yod);
        break;

        case '2':
        descr = addScientistDescription(descr);
        break;

        case '3':
        link = addScientistLink(link);
        break;

        default:
        cout<<"Nothing selected. "<<endl;
    }

    cout<<"Add more fields? Y/N? ";
    bool addAnother = loopFunction();
    cout<<"just before"<<endl;
    return addAnother;
}

int infoDisplay::addScientistYearOfDeath(int &yod)
{
    workingclass workingobject;
    cout<<"Year of Death: ";
    cin>>yod;
    yod = workingobject.yearCorrection(yod);
    return yod;
}

string infoDisplay::addScientistDescription(string &descr)
{
    cout<<"Description: ";
    cin>>descr;
    return descr;
}

string infoDisplay::addScientistLink(string &link)
{
    cout<<"Website Link:";
    cin>>link;
    return link;
}


bool infoDisplay::addScientistCheck(string name, int gender, int yob, int yod, string desc, string link)
{
    clearScreen();
    //char input;
    cout<<"Current entry: "<<endl;
    cout<<"======================================"<<endl;
    cout<<"Name: "<<name<<endl;
    if (gender == 0)
    {
        cout<<"Gender: Male"<<endl;
    }
    else if (gender == 1)
    {
        cout<<"Gender: Female"<<endl;
    }
    else
    {
        cout<<"Gender: Unspecified"<<endl;
    }
    cout<<"Year of Birth: "<<yob<<endl;
    cout<<"Year of Death: "<<yod<<endl;
    cout<<"Description: "<<desc<<endl;
    cout<<"Link: "<<link<<endl<<endl;

    cout<<"Are you happy with this input ? Y/N:";

    bool cont = loopFunction();

    return cont;
}

void infoDisplay::addScientistChange(string &name, string gender, int &yob, int &yod, string &desc, string &link, int &selectedGender)
{
    clearScreen();
    int input = 0;
    addEmtyLines(5);
    cout<<"What would you like to change? Choose: "<<endl;
    cout<<"1. Name, 2. Gender, 3. Year of Birth, 4. "
          "Year of Death, 5. Description, 6. Link"<<endl;
    cin>>input;

    switch (input)
    {
    case 1:
        name = addScientistName(name);
        break;
    case 2:
        selectedGender = addScientistGender(gender);
        break;
    case 3:
        yob = addScientistYearOfBirth(yob);
        break;
    case 4:
        yod = addScientistYearOfDeath(yod);
        break;
    case 5:
        desc = addScientistDescription(desc);
        break;
    case 6:
        link = addScientistLink(link);
        break;
    }
}

bool infoDisplay::addScientistContinue()
{
    //char input;
    addEmtyLines(1);
    cout<<"Would you like to add more Scientists? Y/N: ";

    bool input = loopFunction();
    return input;

//    cin>>input;
//    (toupper(input));

//    if (input == 'Y')
//    {
//        return true;
//    }
//    else
//    {
//        return false;
//    }
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
    int sel;
    addEmtyLines(5);
    cout << "= = = = = M e n u  f o r  S e a r c h = = = = = " << endl;
    cout << "Enter \"1\" to search by name or part of name." << endl;
    addEmtyLines(1);
    cout << "Enter \"2\" to search by gender." << endl;
    addEmtyLines(1);
    cout << "Enter \"3\" to search by year of birth." << endl;
    addEmtyLines(1);
    cout << "Enter \"4\" to search by year of death." << endl;
    addEmtyLines(1);
    cout << "Enter \"5\" to return to main menu." << endl;
    addEmtyLines(1);
    cout << "= = = = = = = = = = = = = = = = = = = = = = = ";
    addEmtyLines(2);
    cout << "Enter your selection: ";
    cin >> sel;
    searchSelection(sel);
    mainMenu();

}

void infoDisplay::searchSelection(int select)
{
    workingclass work;
    //infoDisplay disp;
    char cont;

    switch (select)
    {
    case 1:

        do
        {
            string tempName;
            bool found = false;

            clearScreen();
            cout << "Please enter a part of the name you would like to find: " << endl;
            cin >> tempName;
            work.searchByName(tempName, found);
            if( found == true)
            {
                work.printVector();
                cont = 'N';
            }
            else
            {
                cout << "Nothing found! - Do you want to try again? (Y/N): ";
                cin >> cont;
            }
        }while(toupper(cont) == 'Y');
        break;
    case 2:
        do
        {
            string tempGender;
            bool found = false;

            clearScreen();
            cout << "Please enter the gender you would like to see: " << endl;
            cin >> tempGender;
            work.searchByGender(tempGender, found);
            if( found == true)
            {
                work.printVector();
                cont = 'N';
            }
            else
            {
                cout << "Nothing found! - Do you want to try again? (Y/N): ";
                cin >> cont;
            }
        }while(toupper(cont) == 'Y');

        break;
    case 3:
        do
        {
            int yr;
            bool found = false;

            clearScreen();
            cout << "Please enter the year you would like to search for: " << endl;
            cin >> yr;
            work.searchByYear(yr, 'b', found);
            if( found == true)
            {
                work.printVector();
                cont = 'N';
            }
            else
            {
                cout << "Nothing found! - Do you want to try again? (Y/N): ";
                cin >> cont;
            }

        }while(toupper(cont) == 'Y');
        break;
    case 4:
        do
        {
            int yr;
            bool found = false;

            clearScreen();
            cout << "Please enter the year you would like to search for: " << endl;
            cin >> yr;
            work.searchByYear(yr, 'd', found);
            if( found == true)
            {
                work.printVector();
                cont = 'N';
            }
            else
            {
                cout << "Nothing found! - Do you want to try again? (Y/N): ";
                cin >> cont;
            }

        }while(toupper(cont) == 'Y');
        break;
    case 5:
        clearScreen();
        mainMenu();
        break;
    default:
        addEmtyLines(5);
        cout << "Illigal selection!!" << endl;
        cout << "Returning to Search menu" << endl;
        sleep(3);
        displaySearchScientist();
        break;
    }
}

void infoDisplay::addEmtyLines(int numLines)
{
    do
    {
        cout << endl;
        numLines--;
    }while(numLines > 0);
}

void infoDisplay::quitProgram()
{
    char ans;
    cout << "Are you sure you want to quit?  (Y/N): ";
    cin >> ans;
    if (toupper(ans) == 'Y')
    {
        exit(0);
    }
    mainMenu();
}


bool infoDisplay::loopFunction()
{
    char input;
    cin>>input;

    input = (toupper(input));

    if (input == 'Y')
    {
        return true;
    }
    else //if (input == 'N')
    {
        return false;
    }

}
