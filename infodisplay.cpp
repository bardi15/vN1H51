#include "infodisplay.h"

using namespace std;

void infoDisplay::listheader()
{
    clearScreen();
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
    //cout << "\t6) Play greeting. \n";
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
        editScientistDisplayService();

        int i = 0;
        string name;

        cout << "\tEnter the number of the scientist you would like to edit: ";
        i = inputNumberToFunction() - 1;
        editScientistService(i);
        clearScreen();
        continueP = addScientistContinue();

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
    cout << "\t2) Search by gender." << endl;
    cout << "\t3) Search by year of birth." << endl;
    cout << "\t4) Search by year of death." << endl;
    cout << "\t5) Return to main menu." << endl;
    cout << "\t======================================" << endl;
    cout << "\tEnter your selection: ";
    cin >> sel;
    searchSelection(sel);
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
    addEmtyLines(1);
    cout << "\tInput choice here: ";
    choice = inputNumberToFunction();
    return choice;

}

void infoDisplay::addEmtyLines(int numLines)
{
    do
    {
        cout << endl;
        numLines--;
    }while(numLines>0);
}

void infoDisplay::quitProgram()
{
    char ans;
    cout << "Are you sure you want to quit?  (Y/N): ";
    cin >> ans;
    if (toupper(ans) == 'Y')
    {
        cout << "Thank you, come again!." << endl;
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
    else
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
void infoDisplay::selectAction()
{
    splashScreen();

        do
        {
            serviceObject.servEraseVector();
            serviceObject.servReadFile();
            vector<scientist> v;
            v = serviceObject.servGetVector();

            mainMenu();
            int sel = serviceObject.selection();
            switch(sel)
                {
                case 1:
                    clearScreen();
                    addScientist();
                    break;
                case 2:
                    clearScreen();
                    //v = serviceObject.servGetVector();
                    displayList(v);
                    dispSelectScientistToDelete(v);
                    serviceObject.servEraseVector();
                    serviceObject.servReadFile();
                    break;
                case 3:
                    clearScreen();
                    displayChangeScientist();
                    break;
                case 4:
                    clearScreen();
                    displaySearchScientist();
                    break;
                case 5:
                    unsigned int sel;
                    chooseSortion(v);
                    do
                    {
                        clearScreen();
                        displayList(v);
                        sel = moreInfoOnScientist(v);
                        if(sel > 0 && sel <= v.size())
                        {
                            displayOneScientist(v.at(sel-1));
                        }
                        else
                        {
                            break;
                        }
                    }while(sel > 0);
                        break;
                case 6:
                    clearScreen();
                    splashScreen();
                    break;

                default:
                    clearScreen();
                    addEmtyLines(10);
                    quitProgram();

                    addEmtyLines(10);
                    exit(0);
                    break;
               }
            }
            while(true);
}

void infoDisplay::chooseSortion(vector<scientist>& v)
{

    int choice = displaySortOptions();

    switch(choice)
    {
        case 1:
            clearScreen();
            serviceObject.servSortAlph(v);
            break;
        case 2:
            clearScreen();
            serviceObject.servSortRevAlph(v);
            break;
        case 3:
            clearScreen();
            serviceObject.servSortYOB(v);
            break;
        case 4:
            clearScreen();
            serviceObject.servSortYOD(v);
        case 5:
            clearScreen();
        default:
            clearScreen();
            break;
    }
}
void infoDisplay::editScientistDisplayService()
{
    serviceObject.servReadFile();
    vector<scientist> tempVector = serviceObject.servGetVector();
    displayList(tempVector);
}
void infoDisplay::editScientistService(int i)
{
    vector<scientist> v;
    v = serviceObject.servGetVector();
    //workingObject.readFile();  Af hverju í ósköpunum er þessi lína hér?

    scientist sO;

    if (i < 0)
    {
        i = 0;
    }

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
        addScientistChange(name,gender,yob,yod,descr,link,selectedGender);
        continueP = addScientistCheck(name,selectedGender,yob,yod,descr,link);
    }

    sO.setName(name);
    sO.setGender(selectedGender);
    sO.setDescription(descr);
    sO.setLink(link);
    sO.setYearOfBirth(yob);
    sO.setYearOfDeath(yod);

    v.at(i) = sO;

    serviceObject.servVectorToFile(v,'O');
}

void infoDisplay::searchSelection(int select)
{
    serviceObject.servReadFile();

    char cont;

    switch (select)
    {
    case 1:

        do
        {
            string tempName;
            bool found = false;
            vector<scientist> v;
            clearScreen();
            addEmtyLines(5);
            cout << "\tPlease enter a part of the name you would like to find: ";
            cin >> tempName;
            v = serviceObject.servSearchByName(tempName, found);
            if( found == true)
            {
                unsigned int sel;
                do
                {
                    clearScreen();
                    displayList(v);
                    sel = moreInfoOnScientist(v);
                    if(sel > 0 && sel <= v.size())
                    {
                        displayOneScientist(v.at(sel-1));
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
            clearScreen();
            addEmtyLines(5);
            cout << "\tPlease enter the gender you would like to see: ";
            cin >> tempGender;
            v = serviceObject.servSearchByGender(serviceObject.genderCorrection(tempGender), found);
            if( found == true)
            {
                unsigned int sel;
                do
                {
                    clearScreen();
                    displayList(v);
                    sel = moreInfoOnScientist(v);
                    if(sel > 0 && sel <= v.size())
                    {
                        displayOneScientist(v.at(sel-1));
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

            clearScreen();
            addEmtyLines(5);
            cout << "\tPlease enter the year you would like to search for: ";
            cin >> yr;
            vector<scientist> v;
            v = serviceObject.servSearchByYear(yr, 'b', found);

            if( found == true)
            {
                unsigned int sel;
                do
                {
                    clearScreen();
                    displayList(v);
                    sel = moreInfoOnScientist(v);
                    if(sel > 0 && sel <= v.size())
                    {
                        displayOneScientist(v.at(sel-1));
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

            clearScreen();
            addEmtyLines(5);
            cout << "\tPlease enter the year you would like to search for: ";
            cin >> yr;
            vector<scientist> v;
            v = serviceObject.servSearchByYear(yr, 'd', found);
            if( found == true)
            {
                unsigned int sel;
                do
                {
                    clearScreen();
                    displayList(v);
                    sel = moreInfoOnScientist(v);
                    if(sel > 0 && sel <= v.size())
                    {
                        displayOneScientist(v.at(sel-1));
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
        clearScreen();
        mainMenu();
        break;
    default:
        addEmtyLines(5);
        cout << "\tIlligal selection!!" << endl;
        cout << "\tReturning to Search menu" << endl;
        sleep(3);
        displaySearchScientist();
        break;
    }
}
bool infoDisplay::addScientistContinue()
{

    addEmtyLines(1);
    cout<<"\tWould you like to continue? Y/N: ";

    bool input = loopFunction();
    return input;
}
void infoDisplay::addScientist()
{
    int selectedGender;
    bool wYLTContinue = true;

    scientist sO;

    while(wYLTContinue == true)
    {
        clearScreen();
        addEmtyLines(5);
        cout<<"\tCreating a new Scientist: "<<endl;
        cout<<"\t======================================"<<endl;

        string name = " ", gender = " ", descr = " ", link = " ";
        int yob = 0, yod = 0;

        name = (addScientistName(name));
        selectedGender = addScientistGender(gender);

        yob = (addScientistYearOfBirth());


        bool addEvenMore = true;

        while (addEvenMore == true)
        {
            addEvenMore = addScientistMore(yob, yod, descr, link);
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
        workingclass wO;
        vector<scientist> tempVector;
        tempVector = serviceObject.servGetVector();
        tempVector.push_back(sO);
        serviceObject.servPushToVector(sO);
        wO.addLineToFile(sO, 'A');

    };
    mainMenu();

}
bool infoDisplay::addScientistMore(int yob, int &yod, string &descr, string &link)
{
    addEmtyLines(5);
    cout<<"\t1. Add year of Death, 2. Description, "<<endl<<"\t3. Website link, any other key skips: ";

    bool addAnother = true;


    int choice;
    choice = inputNumberToFunction();
    cin.ignore();

    switch(choice)
    {
        case 1:
        yod = addScientistYearOfDeath(yob);
        break;

        case 2:
        descr = addScientistDescription(descr);
        break;

        case 3:
        link = addScientistLink(link);
        break;

        default:
        cout<<"\tNothing selected."<<endl;
        addAnother = false;
        sleep(1);
    }

    if (addAnother == true)
    {
        cout<<"\tAdd more fields? Y/N? ";
        addAnother = loopFunction();
    }

    return addAnother;

}
int infoDisplay::addScientistYearOfDeath(int yob)
{
    bool errorInYear = false;

    string tempInput;
    int temp;

    //workingclass workingobject;

    do
    {
        cout<<"\tYear of Death: ";
        cin>>tempInput;

        stringstream stringToInt (tempInput);
        stringToInt >> temp;

        temp = serviceObject.yearCorrection(temp, errorInYear);



        if (errorInYear == true)
        {
            cout<<"\tIncorrect year format!"<<endl;
        }

        if (temp < yob)
        {
            errorInYear = true;
            cout<<"\tYou can not die, before you have lived!"<<endl;
        }
    }
    while (errorInYear == true);
    return temp;
}
string infoDisplay::addScientistDescription(string &descr)
{
    cout<<"\tDescription: ";
    getline(cin, descr);
    return descr;
}
string infoDisplay::addScientistLink(string &link)
{
    cout<<"\tWebsite Link:";
    getline(cin, link);
    return link;
}
bool infoDisplay::addScientistCheck(string name, int gender, int yob, int yod, string desc, string link)
{
    clearScreen();
    addEmtyLines(5);
    //char input;
    cout<<"\tCurrent entry: "<<endl;
    cout<<"\t======================================"<<endl;
    cout<<"\tName: "<<name<<endl;
    if (gender == 1)
    {
        cout<<"\tGender: Male"<<endl;
    }
    else if (gender == 0)
    {
        cout<<"\tGender: Female"<<endl;
    }
    else
    {
        cout<<"\tGender: Unspecified"<<endl;
    }
    cout<<"\tYear of Birth: "<<yob<<endl;
    cout<<"\tYear of Death: "<<yod<<endl;

    if (desc.size() > 40)
    {
        cout<<"\tDescription: "<<desc.substr(0,40)<<"..."<<endl;
    }
    else
    {
        cout<<"\tDescription: "<<desc<<endl;
    }
    cout<<"\tLink: "<<link<<endl<<endl;

    cout<<"\tAre you happy with this input ? Y/N:";

    bool cont = loopFunction();

    return cont;
}
void infoDisplay::addScientistChange(string &name, string gender, int &yob, int &yod, string &desc, string &link, int &selectedGender)
{

    int input = 0;
    int yOBirth = yob;

    clearScreen();
    addEmtyLines(5);
    cout<<"\tWhat would you like to change? Choose: "<<endl;
    cout<<"\t1. Name, 2. Gender, 3. Year of Birth, "<<endl<<"\t4. Year of Death, 5. Description, 6. Link: ";
    input = inputNumberToFunction();
    cin.ignore();

    switch (input)
    {
    case 1:
        name = addScientistName(name);
        break;
    case 2:
        selectedGender = addScientistGender(gender);
        break;
    case 3:
        yob = addScientistYearOfBirth();
        break;
    case 4:
        yod = addScientistYearOfDeath(yOBirth);
        break;
    case 5:
        desc = addScientistDescription(desc);
        break;
    case 6:
        link = addScientistLink(link);
        break;

    default:
        cout<<"Bad selection."<<endl;
        break;
    }
}

string infoDisplay::addScientistName(string &name)
{
    bool badName = false;

    do
    {
        cout<<"\tEnter name: ";
        getline(cin, name);
        name = serviceObject.nameCorrection(name, badName);
        if (badName == true)
        {
            cout<<"\tIncorrect name format!"<<endl;
        }
    }
    while(badName == true);

    return name;
}
int infoDisplay::addScientistGender(string &gender)
{
    int selectedGender;
    cout<<"\tEnter gender: ";
    cin>>gender;



    selectedGender = serviceObject.genderCorrection(gender);

    return selectedGender;
}
int infoDisplay::addScientistYearOfBirth()
{
    string tempInput;
    int temp;

    bool errorInYear = false;
    do
    {
        cout<<"\tEnter year of birth: ";
        cin>>tempInput;

        stringstream stringToInt (tempInput);
        stringToInt >> temp;

        temp = serviceObject.yearCorrection(temp, errorInYear);

        if (errorInYear == true)
        {
            cout<<"\tIncorrect year format!"<<endl;
        }
    }
    while (errorInYear == true);

    return temp;
}
int infoDisplay::inputNumberToFunction()
{
    string input;
    bool badInput = false;
    int temp;

    do
    {
        cin>>input;

        stringstream stringToInt (input);
        stringToInt >> temp;
        if (temp == 0)
        {
            cout<<endl;
            cout<<"\tBad input, please try again: ";
            badInput = true;
        }
        else
        {
            badInput = false;
        }
    }
    while (badInput == true);

    return temp;
}
