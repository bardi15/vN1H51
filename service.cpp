#include "service.h"

using namespace std;


service::service()
{

}

void service::selectAction()
{
    infoDisplay display;

    display.splashScreen();

        do
        {
            workingobject.eraseVector();
            workingobject.readFile();
            vector<scientist> v;
            v = workingobject.getVector();

            display.mainMenu();
            int sel = selection();
            switch(sel)
                {
                case 1:
                    display.clearScreen();
                    workingobject.AddScientist();
                    break;
                case 2:
                    display.clearScreen();
                    v = workingobject.getVector();
                    display.displayList(v);
                    display.dispSelectScientistToDelete(v);
                    workingobject.eraseVector();
                    workingobject.readFile();
                    break;
                case 3:
                    display.clearScreen();
                    display.displayChangeScientist();
                    break;
                case 4:
                    display.clearScreen();
                    display.displaySearchScientist();
                    break;
                case 5:
                    unsigned int sel;
                    chooseSortion(v);
                    do
                    {
                        display.clearScreen();
                        //workingobject.readFile();
                        //v = workingobject.getVector();
                        display.displayList(v);
                        sel = display.moreInfoOnScientist(v);
                        if(sel > 0 && sel <= v.size())
                        {
                            display.displayOneScientist(v.at(sel-1));
                        }
                        else
                        {
                            break;
                        }
                    }while(sel > 0);
                        break;
                case 6:
                    display.clearScreen();
                    display.splashScreen();
                    break;

                default:
                    display.clearScreen();
                    display.addEmtyLines(10);
                    cout << "Thank you, come again!." << endl;
                    display.addEmtyLines(10);
                    exit(0);
                    break;
               }
            }
            while(true);
}

int service::selection()
{
    int select;
    cin>>select;
    cin.ignore();
    return select;
}

void service::editScientistDisplayService()
{
    infoDisplay display;
    workingobject.readFile();
    vector<scientist> tempVector = workingobject.getVector();
    display.displayList(tempVector);
}

void service::editScientistService(int i) //(int selection, int scientist)
{
    vector<scientist> v;
    v = workingobject.getVector();
    infoDisplay display;
    workingobject.readFile();

    scientist sO;

    string name, gender, descr, link;
    int selectedGender, yob, yod;

    name = v.at(i).getName();
    selectedGender = v.at(i).getGender();
    descr = v.at(i).getDescription();
    link = v.at(i).getLink();
    yob = v.at(i).getYearOfBirth();
    yod = v.at(i).getYearOfDeath();

    bool continueP = false;

    while (continueP == false)
    {
        workingobject.addScientistChange(name,gender,yob,yod,descr,link,selectedGender);
        continueP = workingobject.addScientistCheck(name,selectedGender,yob,yod,descr,link);
    }

    sO.setName(name);
    sO.setGender(selectedGender);
    sO.setDescription(descr);
    sO.setLink(link);
    sO.setYearOfBirth(yob);
    sO.setYearOfDeath(yod);

    v.at(i) = sO;

    workingobject.VectorToFile(v,'O');
}

void service::searchSelection(int select)
{
    workingobject.readFile();
    infoDisplay display;
    char cont;

    switch (select)
    {
    case 1:

        do
        {
            string tempName;
            bool found = false;
            vector<scientist> v;
            display.clearScreen();
            display.addEmtyLines(5);
            cout << "\tPlease enter a part of the name you would like to find: ";
            cin >> tempName;
            v = workingobject.searchByName(tempName, found);
            if( found == true)
            {
                unsigned int sel;
                do
                {
                    display.clearScreen();
                    display.displayList(v);
                    sel = display.moreInfoOnScientist(v);
                    if(sel > 0 && sel <= v.size())
                    {
                        display.displayOneScientist(v.at(sel-1));
                    }
                    else
                    {
                        break;
                    }
                }while(sel > 0);
                cont = 'N';
            }
            else
            {
                cout << "\tNothing found! - Do you want to try again? (Y/N): ";
                cin >> cont;
            }
        }while(toupper(cont) == 'Y');
        break;
    case 2:
        do
        {
            string tempGender;
            bool found = false;
            vector<scientist> v;
            display.clearScreen();
            display.addEmtyLines(5);
            cout << "\tPlease enter the gender you would like to see: ";
            cin >> tempGender;
            v = workingobject.searchByGender(tempGender, found);
            if( found == true)
            {
                unsigned int sel;
                do
                {
                    display.clearScreen();
                    display.displayList(v);
                    sel = display.moreInfoOnScientist(v);
                    if(sel > 0 && sel <= v.size())
                    {
                        display.displayOneScientist(v.at(sel-1));
                    }
                    else
                    {
                        break;
                    }
                }while(sel > 0);
                cont = 'N';
            }
            else
            {
                cout << "\tNothing found! - Do you want to try again? (Y/N): ";
                cin >> cont;
            }
        }while(toupper(cont) == 'Y');

        break;
    case 3:
        do
        {
            int yr;
            bool found = false;

            display.clearScreen();
            display.addEmtyLines(5);
            cout << "\tPlease enter the year you would like to search for: ";
            cin >> yr;
            vector<scientist> v;
            v = workingobject.searchByYear(yr, 'b', found);

            if( found == true)
            {
                unsigned int sel;
                do
                {
                    display.clearScreen();
                    display.displayList(v);
                    sel = display.moreInfoOnScientist(v);
                    if(sel > 0 && sel <= v.size())
                    {
                        display.displayOneScientist(v.at(sel-1));
                    }
                    else
                    {
                        break;
                    }
                }while(sel > 0);
                cont = 'N';
            }
            else
            {
                cout << "\tNothing found! - Do you want to try again? (Y/N): ";
                cin >> cont;
            }

        }while(toupper(cont) == 'Y');
        break;
    case 4:
        do
        {
            int yr;
            bool found = false;

            display.clearScreen();
            display.addEmtyLines(5);
            cout << "\tPlease enter the year you would like to search for: ";
            cin >> yr;
            vector<scientist> v;
            v = workingobject.searchByYear(yr, 'd', found);
            if( found == true)
            {
                unsigned int sel;
                do
                {
                    display.clearScreen();
                    display.displayList(v);
                    sel = display.moreInfoOnScientist(v);
                    if(sel > 0 && sel <= v.size())
                    {
                        display.displayOneScientist(v.at(sel-1));
                    }
                    else
                    {
                        break;
                    }
                }while(sel > 0);
                cont = 'N';
            }
            else
            {
                cout << "\tNothing found! - Do you want to try again? (Y/N): ";
                cin >> cont;
            }

        }while(toupper(cont) == 'Y');
        break;
    case 5:
        display.clearScreen();
        display.mainMenu();
        break;
    default:
        display.addEmtyLines(5);
        cout << "\tIlligal selection!!" << endl;
        cout << "\tReturning to Search menu" << endl;
        sleep(3);
        display.displaySearchScientist();
        break;
    }
}

void service::chooseSortion(vector<scientist>& v)
{
    infoDisplay display;
    int choice = display.displaySortOptions();

    switch(choice)
    {
        case 1:
            display.clearScreen();
            workingobject.sortAlph(v);
            break;
        case 2:
            display.clearScreen();
            workingobject.sortRevAlph(v);
            break;
        case 3:
            display.clearScreen();
            workingobject.sortYOB(v);
            break;
        case 4:
            display.clearScreen();
            workingobject.sortYOD(v);
        default:
            display.clearScreen();
            break;
    }
}
