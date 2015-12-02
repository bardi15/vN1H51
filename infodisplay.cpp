#include "infodisplay.h"

using namespace std;

void infoDisplay::listheader()
{
    clearScreen();
    //Header á listann
    addEmtyLines(5);
    cout.setf(ios::left);
    cout << "\tNr.";
    cout.width(30);
    cout << "\tName";
    cout << "Gender\tBorn" << endl;
    cout << "\t-----------------------------------------------------" << endl;
}

void infoDisplay::displayList(vector<scientist>& v)
{
    unsigned int scrollFactor = 0;
    unsigned int scrollBase = 0;
    unsigned int holyScroll = 15;
    bool scroll = false;
    char input;

    if (v.size() > holyScroll)
    {
        scrollFactor = holyScroll;
        scroll = true;
    }
    else
    {
        scrollFactor = v.size();
        scroll = false;
    }
    int scrollCount = 1;

    do
    {
        listheader();

        for(unsigned int i = scrollBase; i < scrollFactor; i++)
        {
            scientist s = v.at(i);
            cout.width(2);
            cout << "\t" << i+1 << ")\t";
            cout.width(30);
            cout << s.getName();// << "\t";
            if(s.getGender() == 0)
            {
                cout << "female";
            }
            else
            {
                cout << "male";
            }
            cout << "\t" << s.getYearOfBirth()<< "\t" << endl;
        }

        if (v.size() > holyScroll)
        {
            if (scrollFactor >= v.size())
            {
                addEmtyLines(1);
                cout<<"\tAny key continues.";
            }
            else
            {
                addEmtyLines(1);
                cout<<"\tPress D to scroll down, any other key continues.";
            }
            cin>>input;

            if ((input == 'D')||(input == 'd'))
            {
                ++scrollCount;

                scrollBase = scrollFactor;
                if (scrollBase >= v.size())
                {
                    scrollBase = v.size() - holyScroll;
                }
                scrollFactor = scrollBase + holyScroll;
                if (scrollFactor >= v.size())
                {
                    scrollFactor = v.size();
                }
            }
            else
            {
                scroll = false;
            }

        }
    }
    while(scroll == true);

    cout << "\t-----------------------------------------------------" << endl;
}

int infoDisplay::moreInfoOnScientist(vector<scientist>& v)
{
    unsigned int sel;
    if(v.size() > 0)
    {
        cout << "\tWould you like more info on any of the scientist?" << endl;
        cout << "\tPlease enter your choice, or 0 (zero) to quit: ";
        cin >> sel;
        return sel;
        if(sel == 0)
        {
            mainMenu();
        }
        else if ((sel > 0)&&(sel <= v.size()))
        {
            displayOneScientist(v.at(sel-1));
        }
        else
        {
            cout<<"Incorrect selection!"<<endl;
        }
    }

    return sel;
}

void infoDisplay::dispSelectScientistToDelete(vector<scientist>& v)
{
    int sel;
    workingclass workobj;
    cout << "\tWhich scientist would you like delete?" << endl;
    cout << "\tPlease enter your choise, or 0 (zero) to quit: ";
    cin >> sel;
    if(sel > 0)
    {
        displayOneScientist(v.at(sel-1));
        if(dispSureToRemove(v.at(sel-1).getGender()))
        {
            workobj.removeScientist(v.at(sel-1));
            workobj.readFile();
        }
    }


}
bool infoDisplay::dispSureToRemove(int gender)
{
    char ans;
    addEmtyLines(2);
    if(gender == 0)
    {
        cout << "\tAre you sure you would like to delete her: " << endl;
    }
    else if(gender == 1)
    {
        cout << "\tAre you sure you would like to delete him: " << endl;
    }
    else
    {
        cout << "\tAre you sure you would like to delete it: " << endl;
    }
    addEmtyLines(1);
    cout << "\tEnter (Y/N):";
    cin >> ans;
    if(toupper(ans) == 'Y')
    {
        return true;
    }
    return false;
}
void infoDisplay::dispScientistToEdit(vector<scientist>& v)
{
    int sel;
    cout << "\tWhich scientist would you like edit?" << endl;
    cout << "\tPlease enter your choise, or 0 (zero) to quit: ";
    cin >> sel;
    if(sel == 0)
    {
        mainMenu();
    }
    else
    {
        displayOneScientist(v.at(sel-1));
    }
}

void infoDisplay::displayOneScientist(scientist& s)
{
    char ans;
    clearScreen();
    addEmtyLines(5);
    cout << "\tNafn: " << s.getName() << endl;
    cout << "\tGender: ";
    if(s.getGender()== 0)
    {
        cout << "Female" << endl;
    }
    else if (s.getGender()== 1)
    {
        cout << "male" << endl;
    }
    else
    {
        cout << "Unspecified" <<endl;
    }
    cout << "\tDate of birth: " << s.getYearOfBirth() << endl;

    if (s.getYearOfDeath() != 0)
    {
        cout << "\tDate of death: " << s.getYearOfDeath() << endl;
        int ageAtDeath = s.getYearOfDeath() - s.getYearOfBirth();
        cout << "\tAge at death: "<<ageAtDeath<<endl;
    }
    else
    {
        cout<<"\tCurrent age: ";

        int today = (getCurrentDate("year") * 365) + getCurrentDate("day");

        int sciAge = today - (s.getYearOfBirth() * 365);

        sciAge = sciAge / 365;

        cout<<sciAge<<endl;

    }

    if(s.getDescription().size() > 48)
    {
        int jumpLength = 53;
        int firstLine = 48;
        string less;
        less = s.getDescription().substr(0,firstLine);
        cout << "\tDescription: " << less << endl;
        for(unsigned int i = 0; i * jumpLength + firstLine < s.getDescription().size(); i++)
        {
            less = s.getDescription().substr(firstLine + i * jumpLength,jumpLength);
            cout << "\t\t" << less << endl;
        }
    }
    else if ((s.getDescription().size() > 1)&&(s.getDescription().size() < 48))
    {
        cout << "\tDescription: " << s.getDescription() << endl;
    }

    if (s.getLink().size() > 1)
    {
        cout << "\tLink: " << s.getLink() << endl;
    }

    //addEmtyLines(1);
    cout << "\t-------------------------------------------------------------" << endl;
    cout << "\tEnter any character to continue ";
    cin >> ans;
}

void infoDisplay::clearScreen()
{
    system("cls");
}

void infoDisplay::mainMenu()
{
    //service serviceobject;

    //clearScreen();
    //int sel;
    clearScreen();
    addEmtyLines(5);

    cout <<"\tToday is: ";
    cout <<getCurrentDate("day")<<"."<<getCurrentDate("month")<<"."<<getCurrentDate("year")<<endl;

    cout << "\tWelcome to the computer scientist database! \n";
    cout << "\tWhat would you like to do? \n";
    cout << endl;
    cout << "\t1) Add a new computer scientist. \n";
    cout << "\t2) Delete existing information. \n";
    cout << "\t3) Edit existing information. \n";
    cout << "\t4) Search for a computer scientists. \n";
    cout << "\t5) Display list of computer scientists. \n";
    cout << "\t6) Play greeting. \n";
    cout << "\tAll other entries exit the program: ";
}

infoDisplay::infoDisplay()
{

}

void infoDisplay::splashScreen()
{
    opengreeting greet;

    greet.greetingPost();
}

void infoDisplay::displayChangeScientist()
{
    service serviceobject;
    workingclass workingobject;

    bool continueP = true;

    while(continueP == true)
    {
        clearScreen();

        workingclass workingobject;
        serviceobject.editScientistDisplayService();

        int i = 0;
        string name;

        cout << "\tEnter the number of the scientist you would like to edit: ";
        //cin >> i;
        i = workingobject.inputNumberToFunction() - 1;
        serviceobject.editScientistService(i);
        clearScreen();
        continueP = workingobject.addScientistContinue();

    }
}

void infoDisplay::displaySearchScientist()
{
    workingclass workingobject;
    service serviceobject;

    int sel;
    addEmtyLines(5);
    cout << "\tMenu for Search " << endl;
    cout<<"\t======================================"<<endl;
    cout << "\t1) Search by name or part of name." << endl;
    //addEmtyLines(1);
    cout << "\t2) Search by gender." << endl;
    //addEmtyLines(1);
    cout << "\t3) Search by year of birth." << endl;
    //addEmtyLines(1);
    cout << "\t4) Search by year of death." << endl;
    //addEmtyLines(1);
    cout << "\t5) Return to main menu." << endl;
    //addEmtyLines(1);
    //cout << "\t======================================";
    //addEmtyLines(2);
    cout << "\tEnter your selection: ";
    cin >> sel;
    serviceobject.searchSelection(sel);
    mainMenu();

}

int infoDisplay::displaySortOptions()
{
    workingclass workingobject;
    service servant;
    int choice;
    clearScreen();
    addEmtyLines(5);
    cout << "\tHow would you like the list to be sorted? \n";
    addEmtyLines(1);
    cout << "\t1) In alphabetical order. \n";
    cout << "\t2) In reverse alphabetical order. \n";
    cout << "\t3) By year of birth. \n";
    cout << "\t4) By year of death. \n";
    cout << "\tEnter any other key to return to the main menu. \n";
    addEmtyLines(1);
    cout << "\tInput choice here: ";
    choice = workingobject.inputNumberToFunction();
    return choice;
//    servant.chooseSortion(choice);

}

void infoDisplay::addEmtyLines(int numLines)
{
    do
    {
        cout << endl;
        numLines--;
    }while(numLines>0);
}

//Gerir væntanlega það sama og displayList
//void infoDisplay::displayListOfScientists()
//{
//    workingclass workingobject;

//    vector<scientist> tempVector;

//    cout<<"output out of vector: "<<endl<<endl;

//    cout<<tempVector.size();

//    workingobject.printVector();
//}

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
    cin.ignore();


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

int infoDisplay::getCurrentDate (string date)
{

    time_t theTime = time(NULL);
    struct tm *aTime = localtime(&theTime);

    int day = aTime->tm_mday;
    int month = aTime->tm_mon + 1;
    int year = aTime->tm_year + 1900;

    if (date == "day")
    {
        return day;
    }
    else if (date == "year")
    {
        return year;
    }
    else if (date == "month")
    {
        return month;
    }
    else
    {
        return 0;
    }

}
