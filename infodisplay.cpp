#include "infodisplay.h"

using namespace std;

infoDisplay::infoDisplay()
{

}

void infoDisplay::listheaderSci()
{
    clearScreen();
    addEmptyLines(5);
    cout.setf(ios::left);
    cout << "\tNr.";
    cout.width(30);
    cout << "\tName";
    cout << "Gender\tBorn" << endl;
    //cout << "\t-----------------------------------------------------" << endl;
    printLines(1,"thin");
}

void infoDisplay::listheaderCom()
{
    clearScreen();
    addEmptyLines(5);
    cout.setf(ios::left);
    cout << "\tNr.";
    cout.width(30);
    cout << "\tName";
    cout << "\tYear\tType" << endl;
    //cout << "\t-----------------------------------------------------" << endl;
    printLines(1,"thin");
}



void infoDisplay::displaySciList()
{

    unsigned int vSize = serviceObject.servGetSciVector().size();
    unsigned int scrollFactor;
    if (vSize > HOLYSCROLL)
    {
         scrollFactor = HOLYSCROLL;
    }
    else
    {
        scrollFactor = vSize;
    }
    unsigned int scrollBase = 0;
    bool continueF;
    if (vSize < HOLYSCROLL)
    {
         continueF = false;
    }
    else
    {
        continueF = true;
    }
    cout<<"vSize1: "<<vSize<<" scrollBase1: "<<scrollBase<<" scrollFactor1: "<<scrollFactor<<endl;

    do
    {
        listheaderSci();
        for(unsigned int i = scrollBase; i < scrollFactor; i++)
        {
            scientist s = serviceObject.servGetSciVector().at(i);
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

        if (continueF == true)
        {
            continueF = scrollFunction(vSize, scrollBase, scrollFactor);
            cout<<"vSize2: "<<vSize<<" scrollBase2: "<<scrollBase<<" scrollFactor2: "<<scrollFactor<<endl;
        }
    }
    while (continueF == true);

    cout<<"vSize3: "<<vSize<<" scrollBase3: "<<scrollBase<<" scrollFactor3: "<<scrollFactor<<endl;


    //cout << "\t-----------------------------------------------------" << endl;
    printLines(1, "thin");
}

void infoDisplay::displayComList()
{
    unsigned int cSize = serviceObject.servGetComVector().size();
    unsigned int scrollFactor;
    if (cSize > HOLYSCROLL)
    {
         scrollFactor = HOLYSCROLL;
    }
    else
    {
        scrollFactor = cSize;
    }
    unsigned int scrollBase = 0;
    bool continueF;
    if (cSize < HOLYSCROLL)
    {
         continueF = false;
    }
    else
    {
        continueF = true;
    }
//    cout<<"vSize1: "<<cSize<<" scrollBase1: "<<scrollBase<<" scrollFactor1: "<<scrollFactor<<endl;



    do
    {

        listheaderCom();
        serviceObject.servReadSqlCompTypes();
        for(unsigned int i = scrollBase; i < scrollFactor; i++)
        {
            computer c = serviceObject.servGetComVector().at(i);

            cout.width(2);
            cout << "\t" << i+1 << ")\t";
            cout.width(30);
            cout << c.getComName();// << "\t";
            cout << "\t" << c.getComYear()<< "\t";
            computertype ct = serviceObject.servGetComTypeVector().at(c.getComType()-1);
            cout<< ct.getName() << endl;
        }
        if (continueF == true)
        {
            continueF = scrollFunction(cSize, scrollBase, scrollFactor);
//            cout<<"vSize2: "<<cSize<<" scrollBase2: "<<scrollBase<<" scrollFactor2: "<<scrollFactor<<endl;
        }
    }while (continueF == true);

//    cout<<"vSize3: "<<cSize<<" scrollBase3: "<<scrollBase<<" scrollFactor3: "<<scrollFactor<<endl;


    //cout << "\t-----------------------------------------------------" << endl;
    printLines(1, "thin");
}

bool infoDisplay::scrollFunction(unsigned int vSize, unsigned int &scrollBase, unsigned int &scrollFactor)
{

    //int size = vSize;
    bool scroll = false;
    char input;
    int scrollCount = 1;



        if (vSize > HOLYSCROLL)
        {
            if (scrollFactor >= vSize)
            {
                addEmptyLines(1);
                cout<<"\tAny key continues.";
            }
            else
            {
                addEmptyLines(1);
                cout<<"\tPress D to scroll down, any other letter continues.";
            }
            input = inputCharacterToFunction();

            if (input == 'D')
            {
                scroll = true;

                ++scrollCount;

                scrollBase = scrollFactor;
                if (scrollBase >= vSize)
                {
                    scrollBase = vSize - HOLYSCROLL;
                }
                scrollFactor = scrollBase + HOLYSCROLL;
                if (scrollFactor >= vSize)
                {
                    scrollFactor = vSize;
                }
            }
            else
            {
                scroll = false;
            }

        }
    return scroll;
}

int infoDisplay::moreInfoOnScientist()
{
    unsigned int sel;
    if(serviceObject.servGetSciVector().size() > 0)
    {
        cout << "\tWould you like more info on any of the scientist?" << endl;
        cout << "\tPlease enter your choice, or 0 (zero) to quit: ";
        sel = inputNumberToFunction();
    }
    return sel;

}
int infoDisplay::moreInfoOnComputer()
{
    unsigned int sel;
    if(serviceObject.servGetComVector().size() > 0)
    {
        cout << "\tWould you like more info on any of the computers?" << endl;
        cout << "\tPlease enter your choice, or 0 (zero) to quit: ";
        sel = inputNumberToFunction();
    }
    return sel;

}

void infoDisplay::dispSelectScientistToDelete()
{
    unsigned int sel;

    cout << "\tWhich scientist would you like delete?" << endl;
    cout << "\tPlease enter your choise, or 0 (zero) to quit: ";
    sel = inputNumberToFunction();
    if(sel > 0  && sel < serviceObject.servGetSciVector().size())
    {
        displayOneScientist(serviceObject.servGetSciVector().at(sel-1));
        if(dispSureToRemove(serviceObject.servGetSciVector().at(sel-1).getGender()))
        {
            serviceObject.servDeleteScientist(serviceObject.servGetSciVector().at(sel-1).getID());
        }
    }
}
bool infoDisplay::dispSureToRemove(int gender)
{
    //char ans;
    addEmptyLines(2);
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
    addEmptyLines(1);
    cout << "\tEnter (Y/N):";
    bool continueF = yesOrNo();

    return continueF;
}
void infoDisplay::dispScientistToEdit(vector<scientist>& v)
{
    int sel;
    cout << "\tWhich scientist would you like edit?" << endl;
    cout << "\tPlease enter your choise, or 0 (zero) to quit: ";
    sel = inputNumberToFunction();
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
    addEmptyLines(5);
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
    vector<computer> v;
    v = serviceObject.servGetComputersLinkedToScientists(s.getID());
    if(v.size() > 0)
    {
        addEmptyLines(1);
        cout << "\tHe worked on the following computer/s:" << endl;
        printLines(1,"thin");
        for(unsigned i = 0; i < v.size(); i++)
        {
            cout << "\t" << v.at(i).getComName() << endl;
        }
        printLines(1,"thick");
    }
    cout << "\tEnter any character to continue ";
    ans = inputCharacterToFunction();
}

void infoDisplay::displayOneComputer(computer& c)
{
    unsigned int jumpLength = 53;
    unsigned int firstLine = 48;
    char ans;
    clearScreen();
    addEmptyLines(5);
    printLines(1, "thin");
    cout << "\tNafn: " << c.getComName() << endl;
    cout << "\tType: ";
    cout << serviceObject.servGetComTypeVector().at(c.getComType()-1).getName() << endl;
    cout << "\tProduction year: " <<  c.getComYear() << endl;

    if(c.getComDescription().size() > firstLine)
    {
        string less;
        less = c.getComDescription().substr(0,firstLine);
        cout << "\tDescription: " << less << endl;
        for(unsigned int i = 0; i * jumpLength + firstLine < c.getComDescription().size(); i++)
        {
            less = c.getComDescription().substr(firstLine + i * jumpLength,jumpLength);
            cout << "\t\t" << less << endl;
        }
    }
    else if ((c.getComDescription().size() > 1)&&(c.getComDescription().size() < 48))
    {
        cout << "\tDescription: " << c.getComDescription() << endl;
    }
    vector<scientist> v;
    v = serviceObject.servGetScientistsLinkedToComputer(c.getId());
    if(v.size() > 0)
    {
        addEmptyLines(1);
        cout << "\tThe following scientist/s worked on this computer:" << endl;
        printLines(1,"thin");
        for(unsigned i = 0; i < v.size(); i++)
        {
            cout << "\t" << v.at(i).getName() << endl;
        }
        printLines(1,"thick");
    }

    cout << "\tEnter any character to continue ";
    ans = inputCharacterToFunction();
}

void infoDisplay::clearScreen()
{
    system("cls");
}

void infoDisplay::mainMenu()
{
    clearScreen();
    addEmptyLines(5);

    cout <<"\tToday is: ";
    cout <<getCurrentDate("day")<<"."<<getCurrentDate("month")<<"."<<getCurrentDate("year")<<endl;

    cout << "\tWelcome to the computers and scientists database! \n";
    printLines(1, "thin");
    cout << "\tWhat would you like to do? \n";
    cout << endl;
    cout << "\t1) Work on the scientists information. \n";
    cout << "\t2) Work on the computers information. \n";
    cout << "\t3) Search for a computer scientists. \n";
    cout << "\t4) Search for a famous computer \n";
    cout << "\t5) Display a list of computer scientists. \n";
    cout << "\t6) Display a list of famous computers. \n";
    printLines(1, "thick");
    cout << "\tAll other entries exit the program: ";
}

void infoDisplay::menuForScientists()
{    
    serviceObject.servReadSqlScientists();
    menuForScientistsDisplay();
    menuForScientistsSwitch();
}

void infoDisplay::menuForScientistsDisplay()
{
    clearScreen();
    addEmptyLines(5);
    cout << "\tMenu for Scientists " << endl;
    printLines(1, "thin");
    cout << "\t1) Add a new computer scientist. \n";
    cout << "\t2) Delete existing information. \n";
    cout << "\t3) Edit existing information. \n";
    printLines(1, "thin");
    cout << "\tAll other digits for main menu. \n";
    printLines(1, "thick");
    cout << "\tEnter your selection: ";
    //sleep(2);
}

void infoDisplay::menuForScientistsSwitch()
{
    int i = inputNumberToFunction();

    switch (i)
    {
    case 1:     //  Add scientist
        addScientist();
        break;
    case 2:     //  Delete scientist
        displaySciList();
        dispSelectScientistToDelete();
        break;
    case 3:     //  Change scientist
        displayChangeScientist();
        break;
    default:
        cout<<"Bad input."<<endl;
    }
}




void infoDisplay::menuForComputers()
{
    serviceObject.servReadSqlComputers();
    menuForComputersDisplay();
    menuForComputersSwitch();
}

void infoDisplay::menuForComputersDisplay()
{
    clearScreen();
    addEmptyLines(5);
    cout << "\tMenu for Computers " << endl;
    printLines(1, "thin");
    cout << "\t1) Add a new computer. \n";
    cout << "\t2) Delete existing information. \n";
    cout << "\t3) Edit existing information. \n";
    printLines(1, "thin");
    cout << "\tAll other digits for main menu. \n";
    printLines(1, "thick");
    cout << "\tEnter your selection: ";
    sleep(2);
}

void infoDisplay::menuForComputersSwitch()
{
    int i = inputNumberToFunction();
    switch (i)
    {
    case 1:
        addComputer();
        break;
    case 2:
        displayRemoveComputer();
        break;
    case 3:
        displayChangeComputer();
        break;
    default:
        cout<<"Bad input!"<<endl;
    }


}



void infoDisplay::SelectScientistAction()
{
   // ok, hér á að koma switch í samræmi við menuForScientist

}
void infoDisplay::SelectComputerAction()
{
   // ok, hér á að koma switch í samræmi við menuForComputer
}


void infoDisplay::splashScreen()
{
    opengreeting greet;

    //greet.greetingPost();
}

void infoDisplay::displayChangeScientist()
{
    service serviceobject;


    bool continueP = true;

    while(continueP == true)
    {
        clearScreen();
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
    int sel;
    serviceObject.servReadSqlScientists();
    displaySearchScientistMenu();
    sel = inputNumberToFunction();
    searchScientistSelection(sel);

}
void infoDisplay::displaySearchComputer()
{

    int sel;
    serviceObject.servReadSqlComputers();
    displaySearchComputersMenu();
    sel = inputNumberToFunction();
    searchComputerSelection(sel);
}


void infoDisplay::displaySearchScientistMenu()
{
    addEmptyLines(5);
    cout << "\tMenu for Search " << endl;
    printLines(1, "thick");
    cout << "\t1) Search by name or part of name." << endl;
    cout << "\t2) Search by gender." << endl;
    cout << "\t3) Search by year of birth." << endl;
    cout << "\t4) Search by year of death." << endl;
    cout << "\t5) Return to main menu." << endl;
    printLines(1, "thick");
    cout << "\tEnter your selection: ";
}
void infoDisplay::displaySearchComputersMenu()
{
    addEmptyLines(5);
    cout << "\tMenu for Search " << endl;
    printLines(1, "thick");
    cout << "\t1) Search by name or part of name." << endl;
    cout << "\t2) Search by type." << endl;
    cout << "\t3) Search by the building year." << endl;
    cout << "\t4) Return to main menu." << endl;
    printLines(1, "thick");
    cout << "\tEnter your selection: ";
}


void infoDisplay::printLines(int lines, string thickness)
{

    if (thickness == "thick")
    {
        for (int i = 0; i < lines; i++)
        {
            cout<<"\t========================================================"<<endl;
        }
    }
    else if (thickness == "thin")
    {
        for (int i = 0; i < lines; i++)
        {
            cout<<"\t--------------------------------------------------------"<<endl;

        }
    }
    else
    {
        cout<<"Error in printLines..."<<endl;
    }

}

void infoDisplay::displaySortScientistOptions()
{

    int choice = 1;
    clearScreen();
    addEmptyLines(5);
    cout << "\tHow would you like the list to be sorted? \n";
    printLines(1, "thin");
    cout << "\t1) In alphabetical order. \n";
    cout << "\t2) In reverse alphabetical order. \n";
    cout << "\t3) By year of birth ascending. \n";
    cout << "\t4) By year of birth descending. \n";
    printLines(1, "thick");
    cout << "\tInput choice here: ";
    choice = inputNumberToFunction();
    serviceObject.servSortScientists(choice);

}
void infoDisplay::displaySortComputersOptions()
{

    int choice = 1;
    clearScreen();
    addEmptyLines(5);
    cout << "\tHow would you like the list to be sorted? \n";
    printLines(1, "thin");
    cout << "\t1) In alphabetical order. \n";
    cout << "\t2) In reverse alphabetical order. \n";
    cout << "\t3) By the building year\n";
    cout << "\t4) By type and name. \n";
    printLines(1, "thick");
    cout << "\tInput choice here: ";
    choice = inputNumberToFunction();
    serviceObject.servSortComputers(choice);

}
void infoDisplay::addEmptyLines(int numLines)
{
    do
    {
        cout << endl;
        numLines--;
    }while(numLines>0);
}

void infoDisplay::quitProgram()
{
    cout << "Are you sure you want to quit?  (Y/N): ";
    bool continueF = yesOrNo();
    //ans = inputCharacterToFunction();
    if (continueF == true)
    {
        cout << "Thank you, come again!." << endl;
        serviceObject.servCloseDatabase();  // To close the database before quitting.
        exit(0);
    }
    mainMenu();
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
    serviceObject.servStartDatabase();
    serviceObject.henda();


    do
    {
        clearScreen();
        mainMenu();
        int sel = serviceObject.selection();
        unsigned int choice = 0;
        switch(sel)
            {
            case 1:     //  Working with scientists
                clearScreen();
                serviceObject.servEraseScientistVector();
                menuForScientists();
                break;
            case 2:     //  Working with computers
                clearScreen();
                serviceObject.servEraseComputerVector();
                menuForComputers();
                break;
            case 3:     //  Searching for scientist
                clearScreen();
                serviceObject.servEraseScientistVector();
                displaySearchScientist();
                break;
            case 4:     //  Searching for computers
                clearScreen();
                serviceObject.servEraseComputerVector();
                displaySearchComputer();
                break;
            case 5:     //  Displaying scientists
                clearScreen();
                serviceObject.servEraseScientistVector();
                displaySortScientistOptions();
                do
                {
                    displaySciList();
                    choice = moreInfoOnScientist();
                    if(choice > 0 && choice <= serviceObject.servGetSciVector().size())
                    {
                        displayOneScientist(serviceObject.servGetSciVector().at(choice-1));
                    }
                }while(choice > 0);
                    break;
            case 6:     //  Displaying computers
                clearScreen();
                serviceObject.servEraseComputerVector();
                displaySortComputersOptions();
                do
                {
                    displayComList();
                    choice = moreInfoOnComputer();
                    if(choice > 0 && choice <= serviceObject.servGetComVector().size())
                    {
                        displayOneComputer(serviceObject.servGetComVector().at(choice-1));
                    }
                }while(choice > 0);
                break;

            default:
                clearScreen();
                addEmptyLines(10);
                quitProgram();

                addEmptyLines(10);
                exit(0);
                break;
           }
        }
        while(true);

}

void infoDisplay::editScientistDisplayService()
{
    serviceObject.servReadSqlScientists();
    //vector<scientist> tempVector = serviceObject.servGetSciVector();
    displaySciList();
}
void infoDisplay::editScientistService(int i)
{
    scientist sO;

    if (i < 0)
    {
        i = 0;
    }

    string name, gender, descr, link;
    int selectedGender, yob, yod;

    name = serviceObject.servGetSciVector().at(i).getName();
    selectedGender = serviceObject.servGetSciVector().at(i).getGender();
    descr = serviceObject.servGetSciVector().at(i).getDescription();
    link = serviceObject.servGetSciVector().at(i).getLink();
    yob = serviceObject.servGetSciVector().at(i).getYearOfBirth();
    yod = serviceObject.servGetSciVector().at(i).getYearOfDeath();

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

    serviceObject.servGetSciVector().at(i) = sO;

    // hér þarf að setja inn set fall til að setja viðkomandi scientist eftir breytingar.

    //serviceObject.servVectorToFile(v,'O');
}

void infoDisplay::searchScientistSelection(int select)
{
    serviceObject.servReadSqlScientists();
    bool continueF = false;
    char cont;
//    vector<scientist> tempvector;

    switch (select)
    {
    case 1:     //  Search by name

        do
        {
            string tempName;
            bool found = false;

            clearScreen();
            addEmptyLines(5);
            cout << "\tPlease enter a part of the name you would like to find: ";
            cin >> tempName;
//            tempvector.clear();
            serviceObject.servSearchScientistByName(tempName, found);
            if( found == true)
            {
                unsigned int sel;
                do
                {
                    clearScreen();
                    displaySciList();
                    sel = moreInfoOnScientist();
                    if(sel > 0 && sel <= serviceObject.servGetSciVector().size())
                    {
                        displayOneScientist(serviceObject.servGetSciVector().at(sel-1));
                    }
                    else
                    {
                        break;
                    }
                }while(sel > 0 && sel < serviceObject.servGetSciVector().size());
                cont = 'N';
            }
            else
            {
                cout << "\tNothing found! - Do you want to try again? (Y/N): ";
                continueF = yesOrNo();
            }
        }
        while(continueF == true);
        break;
    case 2:     //  Search by gender
        do
        {
            string tempGender;
            bool found = false;
            clearScreen();
            addEmptyLines(5);
            cout << "\tPlease enter the gender you would like to see: ";
            cin >> tempGender;
            serviceObject.servSearchScientistByGender(serviceObject.genderCorrection(tempGender), found);
            if( found == true)
            {
                unsigned int sel;
                do
                {
                    clearScreen();
                    displaySciList();
                    sel = moreInfoOnScientist();
                    if(sel > 0 && sel <= serviceObject.servGetSciVector().size())
                    {
                        displayOneScientist(serviceObject.servGetSciVector().at(sel-1));
                    }
                    else
                    {
                        break;
                    }
                }while(sel > 0 && sel < serviceObject.servGetSciVector().size());
                cont = 'N';
            }
            else
            {
                cout << "\tNothing found! - Do you want to try again? (Y/N): ";
                //cont = inputCharacterToFunction();
                continueF = yesOrNo();
            }
        }
        while(continueF == true);

        break;
    case 3:     //  Search by year of birth
        do
        {
            int yr;
            bool found = false;

            clearScreen();
            addEmptyLines(5);
            cout << "\tPlease enter the year you would like to search for: ";
            yr = inputNumberToFunction();
            serviceObject.servSearchScientistByYear(yr, 'b', found);

            if( found == true)
            {
                unsigned int sel;
                do
                {
                    clearScreen();
                    displaySciList();
                    sel = moreInfoOnScientist();
                    if(sel > 0 && sel <= serviceObject.servGetSciVector().size())
                    {
                        displayOneScientist(serviceObject.servGetSciVector().at(sel-1));
                    }
                    else
                    {
                        break;
                    }
                }while(sel > 0 && sel <= serviceObject.servGetSciVector().size());
                cont = 'N';
            }
            else
            {
                cout << "\tNothing found! - Do you want to try again? (Y/N): ";
                //cont = inputCharacterToFunction();
                continueF = yesOrNo();
            }

        }
        while(continueF == true);
        break;
    case 4:     //  Search by year of death
        do
        {
            int yr;
            bool found = false;

            clearScreen();
            addEmptyLines(5);
            cout << "\tPlease enter the year you would like to search for: ";
            cin >> yr;
            serviceObject.servSearchScientistByYear(yr, 'd', found);
            if( found == true)
            {
                unsigned int sel;
                do
                {
                    clearScreen();
                    displaySciList();
                    sel = moreInfoOnScientist();
                    if(sel > 0 && sel < serviceObject.servGetSciVector().size())
                    {
                        displayOneScientist(serviceObject.servGetSciVector().at(sel-1));
                    }
                    else
                    {
                        break;
                    }
                }while(sel > 0 && sel < serviceObject.servGetSciVector().size());
                cont = 'N';
            }
            else
            {
                cout << "\tNothing found! - Do you want to try again? (Y/N): ";
                continueF = yesOrNo();
            }

        }
        while(continueF == true);
        break;
    case 5:     //  Back to main menu
        clearScreen();
        //mainMenu();
        break;
    default:
        addEmptyLines(5);
        cout << "\tIlligal selection!!" << endl;
        cout << "\tReturning to Search menu" << endl;
        sleep(3);
        displaySearchScientist();
        break;
    }
}
void infoDisplay::searchComputerSelection(int select)
{
    serviceObject.servReadSqlComputers();
    bool continueF = false;
    char cont;

    switch (select)
    {
    case 1:     //  Search by name

        do
        {
            string tempName;
            bool found = false;

            clearScreen();
            addEmptyLines(5);
            cout << "\tPlease enter a part of the name you would like to find: ";
            cin >> tempName;
            serviceObject.servSearchComputerByName(tempName, found);
            if( found == true)
            {
                unsigned int sel;
                do
                {
                    clearScreen();
                    displayComList();
                    sel = moreInfoOnComputer();
                    if(sel > 0 && sel <= serviceObject.servGetComVector().size())
                    {
                        displayOneComputer(serviceObject.servGetComVector().at(sel-1));
                    }

                }while(sel > 0 && sel < serviceObject.servGetComVector().size());
                cont = 'N';
            }
            else
            {
                cout << "\tNothing found! - Do you want to try again? (Y/N): ";
                continueF = yesOrNo();
            }
        }
        while(continueF == true);
        break;
    case 2:     //  Search by type
        do
        {
            string tempType;
            bool found = false;
            clearScreen();
            addEmptyLines(5);
            cout << "\tPlease enter a part of the type you would like to see: ";
            cin >> tempType;
            serviceObject.servSearchComputerByType(tempType, found);
            if( found == true)
            {
                unsigned int sel;
                do
                {
                    clearScreen();
                    displayComList();
                    sel = moreInfoOnComputer();
                    if(sel > 0 && sel <= serviceObject.servGetComVector().size())
                    {
                        displayOneComputer(serviceObject.servGetComVector().at(sel-1));
                    }
                }while(sel > 0 && sel < serviceObject.servGetComVector().size());
                cont = 'N';
            }
            else
            {
                cout << "\tNothing found! - Do you want to try again? (Y/N): ";
                continueF = yesOrNo();
            }
        }
        while(continueF == true);

        break;
    case 3:     //  Search by year
        do
        {
            int yr;
            bool found = false;

            clearScreen();
            addEmptyLines(5);
            cout << "\tPlease enter the year you would like to search for: ";
            yr = inputNumberToFunction();
            serviceObject.servSearchComputerByYear(yr, found);

            if( found == true)
            {
                unsigned int sel;
                do
                {
                    clearScreen();
                    displayComList();
                    sel = moreInfoOnComputer();
                    if(sel > 0 && sel <= serviceObject.servGetComVector().size())
                    {
                        displayOneComputer(serviceObject.servGetComVector().at(sel-1));
                    }

                }while(sel > 0 && sel <= serviceObject.servGetComVector().size());
                cont = 'N';
            }
            else
            {
                cout << "\tNothing found! - Do you want to try again? (Y/N): ";
                //cont = inputCharacterToFunction();
                continueF = yesOrNo();
            }

        }
        while(continueF == true);
        break;
    case 4:     //  Back to main menu
        clearScreen();
        //mainMenu();
        break;
    default:
        addEmptyLines(5);
        cout << "\tIlligal selection!!" << endl;
        cout << "\tReturning to Search menu" << endl;
        sleep(3);
        displaySearchScientist();
        break;
    }
}
bool infoDisplay::addScientistContinue()
{

    addEmptyLines(1);
    cout<<"\tWould you like to continue? Y/N: ";

    bool input = yesOrNo();
    //cin.ignore();
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
        addEmptyLines(5);
        cout<<"\tCreating a new Scientist: "<<endl;
        printLines(1, "thick");
        string name = " ", gender = " ", descr = " ", link = " ";
        int yob = 0, yod = 0;

        name = (addScientistName());
        //cin.ignore();
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

        serviceObject.servAddscientist(sO);

    };
    //mainMenu();

}
bool infoDisplay::addScientistMore(int yob, int &yod, string &descr, string &link)
{
    addEmptyLines(5);
    cout<<"\t1. Add year of Death, 2. Description, "<<endl<<"\t3. Website link; \n";
    cout << "any other digit continues: ";

    bool addAnother = true;


    int choice;
    choice = inputNumberToFunction();
    //cin.ignore();

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
        addAnother = yesOrNo();
    }

    return addAnother;

}
int infoDisplay::addScientistYearOfDeath(int yob)
{
    bool errorInYear = false;
    int temp;

    do
    {
        cout<<"\tYear of Death: ";
        temp = inputNumberToFunction();

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
    cin.ignore();
    cout<<"\tDescription: ";
    getline(cin, descr);
    return descr;
}
string infoDisplay::addScientistLink(string &link)
{
    cin.ignore();
    cout<<"\tWebsite Link:";
    getline(cin, link);
    return link;
}
bool infoDisplay::addScientistCheck(string name, int gender, int yob, int yod, string desc, string link)
{
    clearScreen();
    addEmptyLines(5);
    //char input;
    cout<<"\tCurrent entry: "<<endl;
    //cout<<"\t======================================"<<endl;
    printLines(1, "thick");
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

    bool cont = yesOrNo();

    return cont;
}

bool infoDisplay::addComputerCheck(string cName, int cYear, int cType, bool cBuilt, string cDescr)
{
    clearScreen();
    addEmptyLines(5);
    //char input;
    cout<<"\tCurrent entry: "<<endl;
    //cout<<"\t======================================"<<endl;
    printLines(1, "thick");
    cout<<"\tName: "<<cName<<endl;
    cout<<"\tYear of Creation: "<<cYear<<endl;
    if (cType == 1)
    {
        cout<<"\tComputer Type: Electronic"<<endl;
    }
    else if (cType == 2)
    {
        cout<<"\tComputer Type: Mechanic"<<endl;
    }
    else if (cType == 3)
    {
        cout<<"\tComputer Type: Ternary"<<endl;
    }
    cout<<"\tWas the Computer built?: ";
    if (cBuilt == true)
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }

    if (cDescr.size() > 40)
    {
        cout<<"\tDescription: "<<cDescr.substr(0,40)<<"..."<<endl;
    }
    else
    {
        cout<<"\tDescription: "<<cDescr<<endl;
    }
    cout<<"\tAre you happy with this input ? Y/N:";

    bool cont = yesOrNo();

    return cont;
}

void infoDisplay::addScientistChange(string &name, string gender, int &yob, int &yod, string &desc, string &link, int &selectedGender)
{

    int input = 0;
    int yOBirth = yob;

    clearScreen();
    addEmptyLines(5);
    cout<<"\tWhat would you like to change? Choose: "<<endl;
    cout<<"\t1. Name, 2. Gender, 3. Year of Birth, "<<endl<<"\t4. Year of Death, 5. Description, 6. Link: ";
    input = inputNumberToFunction();
    //cin.ignore();

    switch (input)
    {
    case 1:
        name = addScientistName();
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

string infoDisplay::addScientistName()
{
    cin.ignore();
    string name;
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
    //cin.ignore();

    return name;
}
int infoDisplay::addScientistGender(string &gender)
{
    int selectedGender;
    cout<<"\tEnter gender: ";

    //getline(cin, gender, '\n');
    cin>>gender;

    selectedGender = serviceObject.genderCorrection(gender);
    return selectedGender;
}
int infoDisplay::addScientistYearOfBirth()
{
    //cin.ignore();

    int temp;
    bool errorInYear = false;
    do
    {
        cout<<"\tEnter year of birth: ";

        temp = inputNumberToFunction();
        //cin.ignore();

        temp = serviceObject.yearCorrection(temp, errorInYear);

        if (errorInYear == true)
        {
            cout<<"\tIncorrect year format!"<<endl;
        }
    }
    while (errorInYear == true);

    return temp;
}

void infoDisplay::addComputer()
{
    //int selectedGender;
    bool wYLTContinue = true;
    bool changeInput = false;

    computer cO;

    while(wYLTContinue == true)
    {
        clearScreen();
        addEmptyLines(5);
        cout<<"\tCreating a new Computer: "<<endl;


        printLines(1, "thick");
        string compName = " ", compDescr = " ";
        int compYear = 0, compType = 0;
        bool compBuilt;

        compName = (addComputerName());

        compYear = (addComputerYear());

        compType = (addComputerType());

        compBuilt = (addComputerBuilt());

        compDescr = (addComputerDescr());

        do
        {
            changeInput = addComputerCheck(compName, compYear, compType, compBuilt, compDescr);

            if (changeInput == false)
            {
                addComputerChange(compName,compYear,compType,compBuilt,compDescr);
            }
        }
        while (changeInput == false);

        cout<<"\tWould you like to continue? Y/N: ";
        wYLTContinue = yesOrNo();
        //        computer::computer(string cName, int cYear, int cType, bool cBuilt, string cDescr)

        cO.setComName(compName);
        cO.setComYear(compYear);
        cO.setComType(compType);
        cO.setComBuilt(compBuilt);
        cO.setComDescription(compDescr);

        serviceObject.servAddcomputer(cO);

    };
    //mainMenu();
}
string infoDisplay::addComputerName()
{
    cin.ignore();
    //bool badName = false;
    string compName;

    //ATH LAGA FYRIR TÖLVU SÉRSTAKLEGA!!!!!

//    do
//    {
        cout<<"\tEnter name: ";
        getline(cin, compName);

    return compName;
}
//        computer::computer(string cName, int cYear, int cType, bool cBuilt, string cDescr)

int infoDisplay::addComputerYear()
{
    int temp;
    bool errorInYear = false;
    do
    {
        cout<<"\tEnter year of creation: ";

        temp = inputNumberToFunction();
        //cin.ignore();

        temp = serviceObject.yearCorrection(temp, errorInYear);

        if (errorInYear == true)
        {
            cout<<"\tIncorrect year format!"<<endl;
        }
    }
    while (errorInYear == true);

    return temp;
}

int infoDisplay::addComputerType()
{
    int selection = 0;
    bool continueF = false;
    cout<<"\tSelect computer type: "<<endl;
    cout<<"\t1) Electronic\n\t2) Mechanical\n\t3) Ternary\n\t";

    do
    {
        continueF = false;

        selection = inputNumberToFunction();
        if ((selection < 1)||(selection > 3))
        {
            cout<<"Bad selection, try again: ";
            continueF = true;
        }
    }
    while(continueF == true);

    return selection;

}

bool infoDisplay::addComputerBuilt()
{
    cout<<"\tWas the computer built? Y/N: ";
    bool built = yesOrNo();

    return built;
}

string infoDisplay::addComputerDescr()
{
    cin.ignore();
    string descr;
    cout<<"\tDescription: ";
    getline(cin, descr);
    return descr;
}

void infoDisplay::addComputerChange(string &cName, int &cYear, int &cType, bool &cBuilt, string &cDescr)
{
    int input = 0;
    clearScreen();
    addEmptyLines(5);
    cout<<"\tWhat would you like to change? Choose: "<<endl;
    cout<<"\t1. Name, 2. Year of Creation, 3. Type, "<<endl;
    cout << "\t4. Built, 5. Description \n";
    cout << "\tAny other digit to go back.";
    input = inputNumberToFunction();
    //cin.ignore();

    switch (input)
    {
    case 1:
        cName = addComputerName();
        break;
    case 2:
        cYear = addComputerYear();
        break;
    case 3:
        cType = addComputerType();
        break;
    case 4:
        cBuilt = addComputerBuilt();
        break;
    case 5:
        cDescr = addComputerDescr();
        break;
    default:
        //cout<<"Bad selection."<<endl;
        break;
    }
}

void infoDisplay::displayChangeComputer()
{
    cout<<"Change computer!"<<endl;
}

void infoDisplay::displayRemoveComputer()
{
    cout<<"Remove computer!"<<endl;
}

int infoDisplay::inputNumberToFunction()
{
    string input;
    bool badInput = false;
    unsigned int temp;
    unsigned int digitCounter = 0;
    do
    {
        cin>>input;
        //cin.ignore();

        for (unsigned int i = 0; i < input.size(); i++)
        {
            if (isdigit(input[i]))
            {
                digitCounter++;
            }
        }

        stringstream stringToInt (input);
        stringToInt >> temp;
        if (digitCounter < input.size())
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

char infoDisplay::inputCharacterToFunction()
{
    char input;
    bool badInput = false;
    char returnInput;
    do
    {
        cin>>input;

        if (isdigit(input))
        {
            cout<<endl;
            cout<<"\tBad input, please try again: ";
            badInput = true;
        }
        else
        {
            badInput = false;
            //input = returnInput;
            returnInput = toupper(input);
        }
    }
    while(badInput == true);

    return returnInput;
}

bool infoDisplay::yesOrNo()
{
    bool repeatF = false;
    bool sendBack = false;

    do
    {
        repeatF = false;
        char input = inputCharacterToFunction();

        if (input == 'Y')
        {
            sendBack = true;
        }
        else if (input == 'N')
        {
            sendBack = false;
        }
        else
        {
            cout<<"\tBad input, please try again: ";
            repeatF = true;
        }
    }
    while(repeatF == true);

    return sendBack;
}

//bool infoDisplay::loopFunction()
//{
//    char input;
//    input = inputCharacterToFunction();
//    cin.ignore();

//    if (input == 'Y')
//    {
//        return true;
//    }
//    else
//    {
//        return false;
//    }
//}
//void infoDisplay::selectAction()
//{
//    splashScreen();
//    serviceObject.servStartDatabase();

//        do
//        {
//            //  Þetta þarf að fara inn í hverja undirvalmynd eftir því hvað við erum að fara að gera.
//            serviceObject.servEraseVector();
//            serviceObject.servReadSqlScientists();

//            vector<scientist> v;
//            v = serviceObject.servGetVector();

//            mainMenu();
//            int sel = serviceObject.selection();
//            switch(sel)
//                {
//                case 1:
//                    clearScreen();
//                    addScientist();
//                    break;
//                case 2:
//                    clearScreen();
//                    //v = serviceObject.servGetVector();
//                    displaySciList(v);
//                    dispSelectScientistToDelete(v);
//                    serviceObject.servEraseVector();
//                    serviceObject.servReadSqlScientists();
//                    break;
//                case 3:
//                    clearScreen();
//                    displayChangeScientist();
//                    break;
//                case 4:
//                    clearScreen();
//                    displaySearchScientist();
//                    break;
//                case 5:
//                    unsigned int sel;
//                    chooseSortion(v);
//                    do
//                    {
//                        //  Hér þarf að lesa inn úr grunni eftir að ákv. hefur verið hvaða sort er í gangi.  Þ.e. sortið þarf að kalla á innlesturinn.
//                        clearScreen();
//                        displaySciList(v);
//                        sel = moreInfoOnScientist(v);
//                        if(sel > 0 && sel <= v.size())
//                        {
//                            displayOneScientist(v.at(sel-1));
//                        }
//                        else
//                        {
//                            break;
//                        }
//                    }while(sel > 0);
//                        break;
//                case 6:
//                    clearScreen();
//                    splashScreen();
//                    break;

//                default:
//                    clearScreen();
//                    addEmptyLines(10);
//                    quitProgram();

//                    addEmptyLines(10);
//                    exit(0);
//                    break;
//               }
//            }
//            while(true);

//}

//void infoDisplay::chooseSortion(vector<scientist>& v)
//{

//    int choice = displaySortOptions();

//    switch(choice)
//    {
//        case 1:
//            clearScreen();
//            serviceObject.servSortAlph(v);
//            break;
//        case 2:
//            clearScreen();
//            serviceObject.servSortRevAlph(v);
//            break;
//        case 3:
//            clearScreen();
//            serviceObject.servSortYOB(v);
//            break;
//        case 4:
//            clearScreen();
//            serviceObject.servSortYOD(v);
//        case 5:
//            clearScreen();
//        default:
//            clearScreen();
//            break;
//    }
//}

//void infoDisplay::displaySciList(vector<scientist>& v)
//{

//    unsigned int vSize = v.size();
//    unsigned int scrollFactor;
//    if (vSize > HOLYSCROLL)
//    {
//         scrollFactor = HOLYSCROLL;
//    }
//    else
//    {
//        scrollFactor = vSize;
//    }
//    unsigned int scrollBase = 0;
//    bool continueF;
//    if (vSize < HOLYSCROLL)
//    {
//         continueF = false;
//    }
//    else
//    {
//        continueF = true;
//    }
//    cout<<"vSize1: "<<vSize<<" scrollBase1: "<<scrollBase<<" scrollFactor1: "<<scrollFactor<<endl;

//    do
//    {
//        listheaderSci();
//        for(unsigned int i = scrollBase; i < scrollFactor; i++)
//        {
//            scientist s = v.at(i);
//            cout.width(2);
//            cout << "\t" << i+1 << ")\t";
//            cout.width(30);
//            cout << s.getName();// << "\t";
//            if(s.getGender() == 0)
//            {
//                cout << "female";
//            }
//            else
//            {
//                cout << "male";
//            }
//            cout << "\t" << s.getYearOfBirth()<< "\t" << endl;
//        }

//        if (continueF == true)
//        {
//            continueF = scrollFunction(vSize, scrollBase, scrollFactor);
//            cout<<"vSize2: "<<vSize<<" scrollBase2: "<<scrollBase<<" scrollFactor2: "<<scrollFactor<<endl;
//        }
//    }
//    while (continueF == true);

//    cout<<"vSize3: "<<vSize<<" scrollBase3: "<<scrollBase<<" scrollFactor3: "<<scrollFactor<<endl;


//    //cout << "\t-----------------------------------------------------" << endl;
//    printLines(1, "thin");
//}
