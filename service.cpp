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
//void service::selectAction(int sel)
//{
//    vector<scientist> v;
//    workingclass workingobject;
//    workingobject.readFile();
//    infoDisplay display;

//    switch(sel)
//        {
//        case 1:
//            display.clearScreen();
//            workingobject.AddScientist();
//            break;
//        case 2:
//            display.clearScreen();
//            display.displayRemoveScientist();
//            break;
//        case 3:
//            display.clearScreen();
//            display.displayChangeScientist();
//            break;
//        case 4:
//            display.clearScreen();
//            display.displaySearchScientist();
//            break;
//        case 5:
//            unsigned int sel;
//            do
//            {
//                display.clearScreen();
//                v = workingobject.getVector();
//                display.displayList(v);
//                sel = display.moreInfoOnScientist(v);
//                if(sel > 0 && sel <= v.size())
//                {
//                    display.displayOneScientist(v.at(sel-1));
//                }
//                else
//                {
//                    break;
//                }
//            }while(sel > 0);
//                break;
//        case 6:
//            display.clearScreen();
//            display.splashScreen();
//            break;

//        default:
//            display.clearScreen();
//            display.addEmtyLines(10);
//            cout << "Thank you, come again!." << endl;
//            display.addEmtyLines(10);
//            exit(0);
//            break;
//       }
//}


void service::selectAction()
{
    workingobject.readFile();
    vector<scientist> v;
    v = workingobject.getVector();

        do
        {

//           workingobject.readFile();
            //v = workingobject.getVector();
            infoDisplay display;

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
                    do
                    {
                        display.clearScreen();
                        v = workingobject.getVector();
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

void service::searchSelection(int select)
{
    //workingclass work;
    workingobject.readFile();
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
            vector<scientist> v;
            display.clearScreen();
            display.addEmtyLines(5);
            cout << "\tPlease enter a part of the name you would like to find: " << endl;
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
                //workingobject.printVector();
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
            vector<scientist> v;
            display.clearScreen();
            cout << "Please enter the gender you would like to see: " << endl;
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

void service::chooseSortion(int choice)
{
    //workingclass Wobj;
    infoDisplay display;

    switch(choice)
    {
        case 1:
            display.clearScreen();
            workingobject.sortAlph();
            break;
        case 2:
            display.clearScreen();
            workingobject.sortRevAlph();
            break;
        case 3:
            display.clearScreen();
            workingobject.sortYOB();
            break;
        case 4:
            display.clearScreen();
            workingobject.sortYOD();
        default:
            display.clearScreen();
            //display.mainMenu();
            break;
    }


}
