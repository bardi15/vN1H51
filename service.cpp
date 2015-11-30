#include "service.h"

using namespace std;


service::service()
{

}
vector<scientist> service::getWCVector()
{
    workingclass wc;
    return wc.getVector();
}
void service::setWCVector(vector<scientist>& v)
{
    workingclass wc;
    wc.setVector(v);
}

void service::selectAction(int sel)
{
    workingclass workingobject;
    infoDisplay display;

    switch(sel)
        {
        case 1:
            display.clearScreen();
            workingobject.AddScientist();
            break;
        case 2:
            display.clearScreen();
            display.displayRemoveScientist();
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
            display.clearScreen();
            display.displayListOfScientists();
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

void service::searchSelection(int select)
{
    workingclass work;
    infoDisplay display;
    //infoDisplay disp;
    char cont;

    switch (select)
    {
    case 1:

        do
        {
            string tempName;
            bool found = false;

            display.clearScreen();
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

            display.clearScreen();
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

            display.clearScreen();
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

            display.clearScreen();
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
        display.clearScreen();
        display.mainMenu();
        break;
    default:
        display.addEmtyLines(5);
        cout << "Illigal selection!!" << endl;
        cout << "Returning to Search menu" << endl;
        sleep(3);
        display.displaySearchScientist();
        break;
    }
}
