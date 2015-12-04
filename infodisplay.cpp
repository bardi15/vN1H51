#include "infodisplay.h"

using namespace std;

infoDisplay::infoDisplay()
{

}

void infoDisplay::listheader()
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

void infoDisplay::displaySciList(vector<scientist>& v)
{
    int vSize = v.size();
    unsigned int scrollFactor;
    if (vSize > holyScroll)
    {
         scrollFactor = holyScroll;
    }
    else
    {
        scrollFactor = vSize;
    }
    unsigned int scrollBase = 0;
    bool continueF;
    if (vSize < holyScroll)
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

bool infoDisplay::scrollFunction(unsigned int vSize, unsigned int &scrollBase, unsigned int &scrollFactor)
{

    //int size = vSize;
    bool scroll = false;
    char input;

//    if (vSize > holyScroll)
//    {
//        scrollFactor = holyScroll;
//        scroll = true;
//    }
//    else
//    {
//        scrollFactor = vSize;
//        scroll = false;
//    }
    int scrollCount = 1;

   // do
   // {
        //listheader();



        if (vSize > holyScroll)
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
                    scrollBase = vSize - holyScroll;
                }
                scrollFactor = scrollBase + holyScroll;
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
    //}
    //while(scroll == true);

    return scroll;
}

int infoDisplay::moreInfoOnScientist(vector<scientist>& v)
{
    unsigned int sel;
    if(v.size() > 0)
    {
        cout << "\tWould you like more info on any of the scientist?" << endl;
        cout << "\tPlease enter your choice, or 0 (zero) to quit: ";
        sel = inputNumberToFunction();
        return sel;
//        if(sel == 0)
//        {
//            mainMenu();
//        }
//        else if ((sel > 0)&&(sel <= v.size()))
//        {
//            displayOneScientist(v.at(sel-1));
//        }
//        else
//        {
//            cout<<"Incorrect selection!"<<endl;
//        }
//    }

//    return sel;
    }
}

void infoDisplay::dispSelectScientistToDelete(vector<scientist>& v)
{
    int sel;

    cout << "\tWhich scientist would you like delete?" << endl;
    cout << "\tPlease enter your choise, or 0 (zero) to quit: ";
    sel = inputNumberToFunction();
    if(sel > 0)
    {
        displayOneScientist(v.at(sel-1));
        if(dispSureToRemove(v.at(sel-1).getGender()))
        {
//            serviceObject.servRemoveScientist(v.at(sel-1));
            serviceObject.servReadSqlScientists();
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
//    ans = inputCharacterToFunction();
//    if(ans == 'Y')
//    {
//        return true;
//    }
//    return false;

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

    //addEmptyLines(1);
    //cout << "\t-------------------------------------------------------------" << endl;
    printLines(1,"thin");
    cout << "\tEnter any character to continue ";
    ans = inputCharacterToFunction();
}

void infoDisplay::clearScreen()
{
    //system("cls");
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

void infoDisplay::menuForScientists(vector<scientist> &v)
{    
    menuForScientistsDisplay();
    menuForScientistsSwitch(v);
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

void infoDisplay::menuForScientistsSwitch(vector<scientist> &v)
{
    int i = inputNumberToFunction();

    switch (i)
    {
    case 1:
        addScientist();
        break;
    case 2:
        displaySciList(v);
        dispSelectScientistToDelete(v);
        serviceObject.servEraseVector();
        //serviceObject.servReadFile();
        serviceObject.servReadSqlScientists();
        break;
    case 3:
        displayChangeScientist();
        break;
    default:
        cout<<"Bad input."<<endl;
    }
}




void infoDisplay::menuForComputers(vector<computer> &c)
{


    menuForComputersDisplay();
    menuForComputersSwitch(c);

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

void infoDisplay::menuForComputersSwitch(vector<computer> &c)
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
    displaySearchScientistMenu();
    sel = inputNumberToFunction();
    searchSelection(sel);

}
void infoDisplay::displaySearchComputer()
{
    int sel;
    displaySearchComputersMenu();
    sel = inputNumberToFunction();
    searchSelection(sel);
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
    cout << "\t5) Return to main menu." << endl;
    printLines(1, "thick");
    cout << "\tEnter your selection: ";
}


void infoDisplay::printLines(int lines, string thickness)
{

    if (thickness == "thick")
    {
        for (int i = 0; i < lines; i++)
        {
            cout<<"\t===================================================="<<endl;
        }
    }
    else if (thickness == "thin")
    {
        for (int i = 0; i < lines; i++)
        {
            cout<<"\t----------------------------------------------------"<<endl;

        }
    }
    else
    {
        cout<<"Error in printLines..."<<endl;
    }

}

int infoDisplay::displaySortOptions(int choice)
{
    //  Þessi menu getur gengið fyrir bæði tölvur og scientista, ef aðeins breytt.
    serviceObject.servSortScientists(choice);
    clearScreen();
    addEmptyLines(5);
    cout << "\tHow would you like the list to be sorted? \n";
    addEmptyLines(1);
    cout << "\t1) In alphabetical order. \n";
    cout << "\t2) In reverse alphabetical order. \n";
    cout << "\t3) By year of birth. \n";
    cout << "\t4) By year of death. \n";
    addEmptyLines(1);
    cout << "\tInput choice here: ";
    choice = inputNumberToFunction();
    return choice;

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
            //  Þetta þarf að fara inn í hverja undirvalmynd eftir því hvað við erum að fara að gera.
            serviceObject.servEraseVector();
            serviceObject.servReadSqlScientists();

            vector<scientist> sV;
            sV = serviceObject.servGetSciVector();
            cout<<"vector:::::"<<endl;
            cout<<sV.at(0).getName()<<endl;

            vector<computer> cV;
            cV = serviceObject.servGetComVector();

            mainMenu();
            int sel = serviceObject.selection();
            switch(sel)
                {
                case 1:
                    clearScreen();
                    menuForScientists(sV);
                    break;
                case 2:
                    clearScreen();
                    //v = serviceObject.servGetVector();
                    menuForComputers(cV);
                    break;
                case 3:
                    clearScreen();
                    displaySearchScientist();
                    break;
                case 4:
                    clearScreen();
                    displaySearchComputer();
                    break;
                case 5:
                    unsigned int sel;
                    chooseSortion(sV);
                    do
                    {
                        //  Hér þarf að lesa inn úr grunni eftir að ákv. hefur verið hvaða sort er í gangi.  Þ.e. sortið þarf að kalla á innlesturinn.
                        clearScreen();
                        displaySciList(sV);
                        sel = moreInfoOnScientist(sV);
                        if(sel > 0 && sel <= sV.size())
                        {
                            displayOneScientist(sV.at(sel-1));
                        }
                        else
                        {
                            break;
                        }
                    }while(sel > 0);
                        break;
                case 6:
                    sel;
                    //chooseSortion(cV);
                    do
                    {
                        //  Hér þarf að lesa inn úr grunni eftir að ákv. hefur verið hvaða sort er í gangi.  Þ.e. sortið þarf að kalla á innlesturinn.
                        clearScreen();
                        //displaySciList(cV);
                        sel = moreInfoOnScientist(sV);
                        if(sel > 0 && sel <= sV.size())
                        {
                            displayOneScientist(sV.at(sel-1));
                        }
                        else
                        {
                            break;
                        }
                    }while(sel > 0);
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
void infoDisplay::editScientistDisplayService()
{
    serviceObject.servReadSqlScientists();
    vector<scientist> tempVector = serviceObject.servGetSciVector();
    displaySciList(tempVector);
}
void infoDisplay::editScientistService(int i)
{
    //vector<scientist> v;
    //v = serviceObject.servGetVector();


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

void infoDisplay::searchSelection(int select)
{
    serviceObject.servReadSqlScientists();
    bool continueF = false;
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
            addEmptyLines(5);
            cout << "\tPlease enter a part of the name you would like to find: ";
            cin >> tempName;
            v = serviceObject.servSearchByName(tempName, found);
            if( found == true)
            {
                unsigned int sel;
                do
                {
                    clearScreen();
                    displaySciList(v);
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
                continueF = yesOrNo();
            }
        }
        while(continueF == true);
        break;
    case 2:
        do
        {
            string tempGender;
            bool found = false;
            vector<scientist> v;
            clearScreen();
            addEmptyLines(5);
            cout << "\tPlease enter the gender you would like to see: ";
            cin >> tempGender;
            v = serviceObject.servSearchByGender(serviceObject.genderCorrection(tempGender), found);
            if( found == true)
            {
                unsigned int sel;
                do
                {
                    clearScreen();
                    displaySciList(v);
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
                //cont = inputCharacterToFunction();
                continueF = yesOrNo();
            }
        }
        while(continueF == true);

        break;
    case 3:
        do
        {
            int yr;
            bool found = false;

            clearScreen();
            addEmptyLines(5);
            cout << "\tPlease enter the year you would like to search for: ";
            yr = inputNumberToFunction();
            vector<scientist> v;
            v = serviceObject.servSearchByYear(yr, 'b', found);

            if( found == true)
            {
                unsigned int sel;
                do
                {
                    clearScreen();
                    displaySciList(v);
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
                //cont = inputCharacterToFunction();
                continueF = yesOrNo();
            }

        }
        while(continueF == true);
        break;
    case 4:
        do
        {
            int yr;
            bool found = false;

            clearScreen();
            addEmptyLines(5);
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
                    displaySciList(v);
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
                continueF = yesOrNo();
            }

        }
        while(continueF == true);
        break;
    case 5:
        clearScreen();
        mainMenu();
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
    cin.ignore();
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

        name = (addScientistName(name));
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
//        vector<scientist> tempVector;
//        tempVector = serviceObject.servGetVector();
//        tempVector.push_back(sO);
//        serviceObject.servPushToVector(sO);
//        serviceObject.servAddLineToFile(sO, 'A');
        serviceObject.servAddscientist(sO);

    };
    mainMenu();

}
bool infoDisplay::addScientistMore(int yob, int &yod, string &descr, string &link)
{
    addEmptyLines(5);
    cout<<"\t1. Add year of Death, 2. Description, "<<endl<<"\t3. Website link, any other digit continues: ";

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
void infoDisplay::addScientistChange(string &name, string gender, int &yob, int &yod, string &desc, string &link, int &selectedGender)
{

    int input = 0;
    int yOBirth = yob;

    clearScreen();
    addEmptyLines(5);
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
        //getline(cin, name);
        cin>>name;
        //cin.ignore();
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
    //cin.ignore();

    cout<<"\tEnter gender: ";

    cin>>gender;



    selectedGender = serviceObject.genderCorrection(gender);
    return selectedGender;
}
int infoDisplay::addScientistYearOfBirth()
{
    int temp;
    bool errorInYear = false;
    do
    {
        cout<<"\tEnter year of birth: ";

        temp = inputNumberToFunction();
        cin.ignore();

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



        compName = (addComputerName(compName));

        compYear = (addComputerYear(compYear));

        compType = (addComputerType(compType));

        compBuilt = (addComputerBuilt(compBuilt));

        compDescr = (addComputerDescr(compDescr));


//        bool addEvenMore = true;

//        while (addEvenMore == true)
//        {
//            addEvenMore = addScientistMore(yob, yod, descr, link);
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

        cout<<"Would you like to continue? Y/N: ";
        wYLTContinue = yesOrNo();
        //        computer::computer(string cName, int cYear, int cType, bool cBuilt, string cDescr)

        cO.setComName(compName);
        cO.setComYear(compYear);
        cO.setComType(compType);
        cO.setComBuilt(compBuilt);
        cO.setComDescription(compDescr);


//        vector<scientist> tempVector;
//        tempVector = serviceObject.servGetVector();
//        tempVector.push_back(sO);
//        serviceObject.servPushToVector(sO);
//        serviceObject.servAddLineToFile(sO, 'A');
        serviceObject.servAddcomputer(cO);

    };
    mainMenu();
}
string infoDisplay::addComputerName(string &compName)
{
    bool badName = false;

    //ATH LAGA FYRIR TÖLVU SÉRSTAKLEGA!!!!!

    do
    {
        cout<<"\tEnter name: ";
        getline(cin, compName);
        compName = serviceObject.nameCorrection(compName, badName);
        if (badName == true)
        {
            cout<<"\tIncorrect name format!"<<endl;
        }
    }
    while(badName == true);

    return compName;
}
//        computer::computer(string cName, int cYear, int cType, bool cBuilt, string cDescr)

int infoDisplay::addComputerYear(int &compYear)
{
    return 1984;
}

int infoDisplay::addComputerType(int &compType)
{
    return 6;
}

bool infoDisplay::addComputerBuilt(bool &compBuilt)
{
    return true;
}

string infoDisplay::addComputerDescr(string &compDescr)
{
    return "cool description";
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

