#include "infodisplay.h"

using namespace std;

void infoDisplay::displayList(vector<scientist>& v)
{
    //workingclass workingobject;

    //vector<scientist> vs = workingobject.getVector();


    //Header � listann
    addEmtyLines(5);
    cout.setf(ios::left);
    cout << "\t Nr.";
    cout.width(30);
    cout << "\tName";
    cout << "Gender\tBorn" << endl;
    cout << "\t-----------------------------------------------------" << endl;

    int scrollFactor = 0;
    int scrollBase = 0;
    int holyScroll = 20;
    bool scroll = false;



    cout<<"scrollBase is: "<<scrollBase<<endl;
    cout<<"scrollFactor is: "<<scrollFactor<<endl;

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
    int scrollCount = 0;

    do
    {
        scrollCount++;

        for(; scrollBase < scrollFactor; scrollBase++)
        {
            scientist s = v.at(scrollBase);
            cout.width(2);
            cout << "\t" << scrollBase+1 << ")\t";
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
        char input;

        cout<<"scrollBase is: "<<scrollBase<<endl;
        cout<<"scrollFactor is: "<<scrollFactor<<endl;


        if (v.size() > holyScroll)
        {
            cout<<"scrollCount is: "<<scrollCount<<endl;
            cout<<"Press U to scroll up, and D to scroll down, any other key to stop scrolling.";
            cin>>input;
            (toupper(input));
            if (input == 'D')
            {
                scrollBase = scrollCount * holyScroll;
                scrollFactor = scrollBase + holyScroll;
                cout<<"scrollBase is: "<<scrollBase<<endl;
                cout<<"scrollFactor is: "<<scrollFactor<<endl;
            }
            else if (input == 'U')
            {
                scrollBase = holyScroll - scrollBase;
                if (scrollBase < 0)
                {
                    scrollBase = 0;
                }
                scrollFactor = scrollFactor - holyScroll;
                if (scrollFactor < 0)
                {
                    scrollFactor = 0;
                }
                else if (scrollFactor > 20)
                {
                    scrollFactor = 20;
                }
                cout<<"scrollBase is: "<<scrollBase<<endl;
                cout<<"scrollFactor is: "<<scrollFactor<<endl;

            }
            else
            {
                cout<<"Nothing selected! "<<endl;
                scroll = false;
            }
        }
    }
    while(scroll == true);

    cout << "\t-----------------------------------------------------" << endl;
}

int infoDisplay::moreInfoOnScientist(vector<scientist>& v)
{
    int sel;
    if(v.size() > 0)
    {
        cout << "\tWould you like more info on any of the scientist?" << endl;
        cout << "\tPlease enter your choise, or 0 (zero) to quit: ";
        cin >> sel;
        return sel;
        if(sel == 0)
        {
            mainMenu();
        }
        else
        {
            displayOneScientist(v.at(sel-1));
        }
    }
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


    if(s.getDescription().size() > 60)
    {
        string less;
        less = s.getDescription().substr(0,80);
        cout << "\tDescription: " << less << endl;
        for(unsigned int i = 0; i*100+80 < s.getDescription().size(); i++)
        {

            less = s.getDescription().substr(i*100+80,100);
            cout << "\t\t" << less << endl;
        }
    }
    else if (s.getDescription().size() > 1)
    {
        cout << "\tDecsription: " << s.getDescription() << endl;
    }

    if (s.getLink().size() > 1)
    {
        cout << "\tLink: " << s.getLink() << endl;
    }

    addEmtyLines(1);
    cout << "\t-------------------------------------------------------------" << endl;
    cout << "\tEnter any character to continue ";
    cin >> ans;
}

void infoDisplay::clearScreen()
{
    //system("cls");
}

void infoDisplay::mainMenu()
{
    //service serviceobject;

    //clearScreen();
    //int sel;
    clearScreen();
    addEmtyLines(5);

    cout <<"\t Today is: ";
    cout <<getCurrentDate("day")<<"."<<getCurrentDate("month")<<"."<<getCurrentDate("year")<<endl;

    cout << "\t Welcome to the computer scientist database! \n";
    cout << "\t What would you like to do? \n";
    cout << endl;
    cout << "\t 1) Add a new computer scientist. \n";
    cout << "\t 2) Delete existing information. \n";
    cout << "\t 3) Edit existing information. \n";
    //cout << "\t 4) Browse the list of computer scientists. \n";
    cout << "\t 4) Search for a computer scientists. \n";
    cout << "\t 5) Print list of computer scientists. \n";
    cout << "\t 6) Play greeting. \n";
    cout << "\t All other entries exit the program. \n";
//    cin >> sel;
//    cin.ignore();
//    serviceobject.selectAction(sel);
}

infoDisplay::infoDisplay()
{

}

void infoDisplay::splashScreen()
{
    opengreeting greet;

    //greet.greetingPost();
    mainMenu();
}

void infoDisplay::displayRemoveScientist()
{

}

void infoDisplay::displayChangeScientist()
{
    service serviceobject;

    serviceobject.editScientistDisplayService();

    int i = 0;
    string name;

    cout << "Enter the number of the scientist you would like to edit: ";
    cin >> i;
    serviceobject.editScientistService(i);

//    cout << "Which part of " << name <<"'s profile would you like to edit? \n";
//    cout << endl;
//    cout << "1) The name. \n";
//    cout << "2) Year of birth. \n";
//    cout << "3) Year of untimely demise(Should it apply). \n";
//    cout << "4) Description. \n";
//    cout << "5) Change the link. \n";
//    cout << "Any other entrie returns to the main menu. \n";


}

void infoDisplay::displaySearchScientist()
{
    workingclass workingobject;
    service serviceobject;

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
    serviceobject.searchSelection(sel);
    mainMenu();

}

void infoDisplay::displaySortOptions()
{
    service servant;
    int choice;

    cout << "How would you like the list to be sorted? \n";
    addEmtyLines(1);
    cout << "1) In alphabetical order. \n";
    cout << "2) In reverse alphabetical order. \n";
    cout << "3) By year of birth. \n";
    cout << "4) By year of death. \n";
    cout << "Enter any other key to return to the main menu. \n";
    addEmtyLines(1);
    cout << "Input choice here: ";
    cin >> choice;
    servant.chooseSortion(choice);

}

void infoDisplay::addEmtyLines(int numLines)
{
    do
    {
        cout << endl;
        numLines--;
    }while(numLines>0);
}

//Gerir v�ntanlega �a� sama og displayList
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
