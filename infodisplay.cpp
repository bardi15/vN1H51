#include "infodisplay.h"

using namespace std;

void infoDisplay::displayList(vector<scientist>& v)
{
    //workingclass worker;

    //vector<scientist> tempVector = worker.returnVector();

    //Header á listann
    addEmtyLines(5);
    cout.setf(ios::left);
    cout << "\t Nr.";
    cout.width(30);
    cout << "\tName";
    cout << "Gender\tBorn" << endl;
    cout << "\t-----------------------------------------------------" << endl;
    for(unsigned int i = 0; i < v.size(); i++)
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
    cout << "\t-----------------------------------------------------" << endl;
}
void infoDisplay::moreInfoOnScientist(vector<scientist>& v)
{
    int sel;
    cout << "\tWould you like more info on any of the scientist?" << endl;
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
void infoDisplay::dispSelectScientistToDelete(vector<scientist>& v)
{
    int sel;
    cout << "\tWhich scientist would you like delete?" << endl;
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
        cout << "female" << endl;
    }
    cout << "\tDate of birth: " << s.getYearOfBirth() << endl;
    cout << "\tDate of death: " << s.getYearOfDeath() << endl;
    if(s.getDescription().size() > 60)
    {
        string less;
        less = s.getDescription().substr(0,80);
        cout << "\tDecsription: " << less << endl;
        for(unsigned int i = 0; i*100+80 < s.getDescription().size(); i++)
        {

            less = s.getDescription().substr(i*100+80,100);
            cout << "\t\t" << less << endl;
        }
    }
    //cout << "\t Decsription: " << s.getDescription() << endl;
    cout << "\tLink: " << s.getLink() << endl;
    addEmtyLines(1);
    cout << "\t-------------------------------------------------------------" << endl;
    cout << "\tEnter any character to continue";
    cin >> ans;
}




void infoDisplay::clearScreen()
{
    system("cls");
}

void infoDisplay::mainMenu()
{
    service serviceobject;

    //clearScreen();
    int sel;
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
    cin >> sel;
    cin.ignore();
    serviceobject.selectAction(sel);
}


//void infoDisplay::selectAction(int sel)
//{
//    workingclass workingobject;

//    switch(sel)
//        {
//        case 1:
//            clearScreen();
//            workingobject.AddScientist();
//            break;
//        case 2:
//            clearScreen();
//            displayRemoveScientist();
//            break;
//        case 3:
//            clearScreen();
//            displayChangeScientist();
//            break;
//        case 4:
//            clearScreen();
//            displaySearchScientist();
//            break;
//        case 5:
//            clearScreen();
//            displayListOfScientists();
//            break;
//        case 6:
//            clearScreen();
//            splashScreen();
//            break;

//        default:
//            clearScreen();
//            addEmtyLines(10);
//            cout << "Thank you, come again!." << endl;
//            addEmtyLines(10);
//            exit(0);
//            break;
//       }
//}
infoDisplay::infoDisplay()
{

}

void infoDisplay::splashScreen()
{
    opengreeting greet;

    //greet.greetingPost();
    mainMenu();
}

//void infoDisplay::screenSelection()
//{

//}

//void infoDisplay::AddScientist()
//{
//    int selectedGender;
//    bool wYLTContinue = true;

//    scientist sO;

//    workingclass workingobject;

//    while(wYLTContinue == true)
//    {
//        clearScreen();
//        cout<<"Creating a new Scientist: "<<endl;
//        cout<<"======================================"<<endl;

//        string name = " ", gender = " ", descr = " ", link = " ";
//        int yob = 0, yod = 0;

//        name = (addScientistName(name));
//        selectedGender = addScientistGender(gender);

//        yob = (addScientistYearOfBirth());


//        bool addEvenMore = true;

//        while (addEvenMore == true)
//        {
//            addEvenMore = addScientistMore(yod, descr, link);
//        }

//        bool changeInput = false;

//        do
//        {
//            changeInput = addScientistCheck(name,selectedGender,yob,yod,descr,link);

//            if (changeInput == false)
//            {
//                addScientistChange(name,gender,yob,yod,descr,link,selectedGender);
//            }
//        }
//        while (changeInput == false);


//        wYLTContinue = addScientistContinue();

//        sO.setName(name);
//        sO.setGender(selectedGender);
//        sO.setYearOfBirth(yob);
//        sO.setYearOfDeath(yod);
//        sO.setDescription(descr);
//        sO.setLink(link);

//        vector<scientist> tempVector;
//        tempVector = workingobject.returnVector();
//        tempVector.push_back(sO);
//        workingobject.pushToVector(sO);
//    };

//    cout<<"output out of vector: "<<endl<<endl;
//    workingobject.printVector();

//    mainMenu();

//}

//string infoDisplay::addScientistName(string &name)
//{
//    workingclass workingobject;
//    bool badName = false;

//    do
//    {
//        cout<<"Enter name: ";
//        getline(cin, name);
//        name = workingobject.nameCorrection(name, badName);
//        if (badName == true)
//        {
//            cout<<"Incorrect name format!"<<endl;
//        }
//    }
//    while(badName == true);

//    return name;
//}

//int infoDisplay::addScientistGender(string &gender)
//{
//    workingclass workingobject;
//    int selectedGender;
//    cout<<"Enter gender: ";
//    cin>>gender;

//    for(unsigned int i = 0; i < gender.length(); ++i)
//    {
//        gender[i] = tolower(gender[i]);
//    }

//    selectedGender = workingobject.genderCorrection(gender);

//    return selectedGender;
//}

//int infoDisplay::addScientistYearOfBirth()
//{
//    string tempInput;
//    int temp;

//    bool errorInYear = false;
//    workingclass workingobject;

//    do
//    {
//        cout<<"Enter year of birth: ";
//        cin>>tempInput;

//        stringstream stringToInt (tempInput);
//        stringToInt >> temp;

//        temp = workingobject.yearCorrection(temp, errorInYear);

//        if (errorInYear == true)
//        {
//            cout<<"Incorrect year format!"<<endl;
//        }
//    }
//    while (errorInYear == true);

//    return temp;
//}

//bool infoDisplay::addScientistMore(int &yod, string &descr, string &link)
//{
//    workingclass workingobject;
//    addEmtyLines(2);
//    cout<<"1. Add year of Death, 2. Description, 3. "
//          "Website link, any other key skips."<<endl;

//    char choice;
//    cin>>choice;
//    cin.ignore();

//    switch(choice)
//    {
//        case '1':
//        yod = addScientistYearOfDeath();
//        break;

//        case '2':
//        descr = addScientistDescription(descr);
//        break;

//        case '3':
//        link = addScientistLink(link);
//        break;

//        default:
//        cout<<"Nothing selected. "<<endl;
//    }

//    cout<<"Add more fields? Y/N? ";
//    bool addAnother = loopFunction();
//    return addAnother;
//}

//int infoDisplay::addScientistYearOfDeath()
//{
//    bool errorInYear = false;

//    string tempInput;
//    int temp;

//    workingclass workingobject;

//    do
//    {
//        cout<<"Year of Death: ";
//        cin>>tempInput;

//        stringstream stringToInt (tempInput);
//        stringToInt >> temp;

//        temp = workingobject.yearCorrection(temp, errorInYear);

//        if (errorInYear == true)
//        {
//            cout<<"Incorrect year format!"<<endl;
//        }
//    }
//    while (errorInYear == true);
//    return temp;
//}

//string infoDisplay::addScientistDescription(string &descr)
//{
//    cout<<"Description: ";
//    getline(cin, descr);
//    return descr;
//}

//string infoDisplay::addScientistLink(string &link)
//{
//    cout<<"Website Link:";
//    getline(cin, link);
//    return link;
//}


//bool infoDisplay::addScientistCheck(string name, int gender, int yob, int yod, string desc, string link)
//{
//    clearScreen();
//    //char input;
//    cout<<"Current entry: "<<endl;
//    cout<<"======================================"<<endl;
//    cout<<"Name: "<<name<<endl;
//    if (gender == 1)
//    {
//        cout<<"Gender: Male"<<endl;
//    }
//    else if (gender == 0)
//    {
//        cout<<"Gender: Female"<<endl;
//    }
//    else
//    {
//        cout<<"Gender: Unspecified"<<endl;
//    }
//    cout<<"Year of Birth: "<<yob<<endl;
//    cout<<"Year of Death: "<<yod<<endl;
//    cout<<"Description: "<<desc<<endl;
//    cout<<"Link: "<<link<<endl<<endl;

//    cout<<"Are you happy with this input ? Y/N:";

//    bool cont = loopFunction();

//    return cont;
//}

//void infoDisplay::addScientistChange(string &name, string gender, int &yob, int &yod, string &desc, string &link, int &selectedGender)
//{
//    clearScreen();
//    int input = 0;
//    addEmtyLines(5);
//    cout<<"What would you like to change? Choose: "<<endl;
//    cout<<"1. Name, 2. Gender, 3. Year of Birth, 4. "
//          "Year of Death, 5. Description, 6. Link"<<endl;
//    cin>>input;
//    cin.ignore();

//    switch (input)
//    {
//    case 1:
//        name = addScientistName(name);
//        break;
//    case 2:
//        selectedGender = addScientistGender(gender);
//        break;
//    case 3:
//        //yob = addScientistYearOfBirth(yob);
//        yob = addScientistYearOfBirth();
//        break;
//    case 4:
//        yod = addScientistYearOfDeath();
//        break;
//    case 5:
//        desc = addScientistDescription(desc);
//        break;
//    case 6:
//        link = addScientistLink(link);
//        break;
//    }
//}

//bool infoDisplay::addScientistContinue()
//{
//    //char input;
//    addEmtyLines(1);
//    cout<<"Would you like to add more Scientists? Y/N: ";

//    bool input = loopFunction();
//    return input;
//}



void infoDisplay::displayRemoveScientist()
{

}

void infoDisplay::displayChangeScientist()
{
    string name; //, age, yob, yod, descr, link;
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

void infoDisplay::displayListOfScientists()
{
    workingclass workingobject;

    vector<scientist> tempVector;

    cout<<"output out of vector: "<<endl<<endl;

    cout<<tempVector.size();

    workingobject.printVector();
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
