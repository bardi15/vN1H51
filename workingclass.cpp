#include "scientist.h"
#include "infodisplay.h"
#include "workingclass.h"



//const string WORKFILE = "Scientistinfo.txt";
//const int MAXFIELDS = 6;
//const int MAXNAMELENGTH = 30;
//const int CURRENTYEAR = 2015;

workingclass::workingclass()
{

}
vector<scientist> workingclass::getVector()
{
    return scientistVector;
}
void workingclass::setVector(vector<scientist>& v)
{
    scientistVector = v;
}

void workingclass::readFile()
{
    ifstream skra_inn;
    skra_inn.open(WORKFILE.c_str());
    if(skra_inn.fail())
    {
        cout << "error opening readFile file";
        exit(1);
    }
    readLinesFromFile(skra_inn);
    skra_inn.close();

}
void workingclass::VectorToFile(vector<scientist>& v, char AppOver) const
{
    for(unsigned int i = 0; i < v.size(); i++)
    {
        if(toupper(AppOver) == 'A')
        {
            addLineToFile(v.at(i), 'A');
        }
        else
        {
            addLineToFile(v.at(i), 'O');
        }
    }
}
void workingclass::addLineToFile(scientist& s, char AppOver) const
{


    string outstring;
    ofstream file_out;
    if (toupper(AppOver) == 'A')
    {
        file_out.open(WORKFILE.c_str(), ios::app);
    }
    else if (toupper(AppOver) == 'O')
    {
        file_out.open(WORKFILE.c_str());
    }
    if(file_out.fail())
    {
        cout << "error opening addToFile file";
        exit(1);
    }
    outstring = scientistToString(s);
    file_out << outstring;
    file_out.close();

}

string workingclass::scientistToString(scientist& s) const
{
    string nextline;
    nextline += s.getName();
    nextline += ";";
    nextline += s.getGender();
    nextline += ";";
    nextline += s.getYearOfBirth();
    nextline += ";";
    nextline += s.getYearOfDeath();
    nextline += ";";
    nextline += s.getDescription();
    nextline += ";";
    nextline += s.getLink();
    nextline += ";";

    return nextline;
}

void workingclass::readLinesFromFile(ifstream& fileWithLines)
{
    while(!fileWithLines.eof())
    {
        int loc = 0;
        string next= "";
        char nextchar;
        fileWithLines.get(nextchar);
        while(!fileWithLines.eof() && nextchar != '\n')
        {
            next += nextchar;
            fileWithLines.get(nextchar);
        }
        createScientist(next, loc);
    }
}

void workingclass::pushToVector(scientist s)
{
    scientistVector.push_back(s);
}

void workingclass::createScientist(string& line, int& oldfind)
{
    string fieldtext;
    int currFind = oldfind;
    scientist s;
    int fieldno = 1;

    do
    {
        currFind = line.find(';',oldfind);
        fieldtext = line.substr(oldfind, (currFind-oldfind));
        fillScientist(fieldtext, s, fieldno);
        fieldno++;
        oldfind = currFind + 1;
    }
    while(fieldno <= 6);

    if(fieldno == MAXFIELDS+1)
    {
        pushToVector(s);
    }
}

//void workingclass::add(scientist s){
//    scientistVector.push_back(s);
//    write(s);
//}


//void workingclass::removeScientist(scientist s){

//    for(unsigned int i = 0; i < scientistVector.size(); i++){
//        if(scientistVector[i] == s){
//            scientistVector.erase(scientistVector.begin() + i);
//            break;
//        }
//    }
//    save();
//}

//void workingclass::update(scientist s, scientist &replace){
//    //Searches for the name and removes it from the vector.
//    for(unsigned int i = 0; i < scientistVector.size() ; i++){
//        if(scientistVector[i] == s){
//            scientistVector[i] = replace;
//            break;
//        }
//    }
//    save();
//}


void workingclass::printVector() const
{
    infoDisplay disp;
    vector<scientist> v = scientistVector;
    disp.displayList(v);
    //disp.moreInfoOnScientist(v);
    // disp.displayList(scientistVector);
    // This shoul not be hear!! - display fall - Jón
//    for(unsigned int i = 0; i < scientistVector.size(); i++)
//    {
//        //scientist s = scientistVector.at(i);
//        cout << "Nafn: " << scientistVector[i].getName() << endl;
//        cout << "kyn: " << scientistVector[i].getGender() << endl;
//        cout << "fd: " << scientistVector[i].getYearOfBirth() << endl;
//        cout << "dd: " << scientistVector[i].getYearOfDeath() << endl;
//        cout << "descr: " << scientistVector[i].getDescription() << endl;
//        cout << "url: " << scientistVector[i].getLink() << endl;
//        cout << endl;

        //s.getName() << endl;
    //}
}

void workingclass::fillScientist(string text, scientist& s, const int field)
{
    switch (field)
    {
    case 1:
        s.setName(text);
        //cout << "Nafn: " << text << endl;
        break;
    case 2:
        s.setGender(atoi(text.c_str()));
        //cout << "Gender: " << atoi(text.c_str()) << endl;
        break;
    case 3:
        s.setYearOfBirth(atoi(text.c_str()));
        //cout << "YOB: " << atoi(text.c_str()) << endl;
        break;
    case 4:
        s.setYearOfDeath(atoi(text.c_str()));
        //cout << "YOD: " << atoi(text.c_str()) << endl;
        break;
    case 5:
        s.setDescription(text);
        //cout << "Descr: " << text << endl;;
        break;
    case 6:
        s.setLink(text);
        //cout << "Link: " << text << endl;
        break;
    default:
        cout << "error" << endl << endl;
        break;
    }
}

vector<scientist> workingclass::returnVector ()
{
    return scientistVector;
}

void workingclass::modifyVector(vector<scientist> mVector)
{
    scientistVector = mVector;
}

string workingclass::nameCorrection(string name, bool& badName)
{
    int spaceCount = 0;
    vector<int> spacePositions;
    badName = false;

    for (unsigned int i = 0; i < name.length(); i++)
    {
        name[i] = (tolower(name[i]));


        if ((i < MAXNAMELENGTH) && (i > 1))
        {
           spaceCount = (name.find(" ", i));
        }

        if (find(spacePositions.begin(), spacePositions.end(), spaceCount) ==
                spacePositions.end())
        {
            if (spaceCount != 0)
            {
                spacePositions.push_back(spaceCount);
            }
        }

        if (string::npos != name.find_first_of("0123456789"))
        {
            badName = true;
        }
        else
        {
            badName = false;
        }
    }

    for (unsigned int i = 0; i < spacePositions.size(); i++)
    {
        int spacePos = spacePositions.at(i) + 1;
        name[spacePos] = toupper(name[spacePos]);
    }

    return name;
}

int workingclass::genderCorrection(string gender)
{

    string male[14] = {"karlmadur", "karlkyns", "karl", "kk", "male", "man", "guy", "bro",
                      "kall", "gaur", "dude", "sjomli", "strakur", "piltur"};

    vector<string> maleVector (male, male + sizeof(male) / sizeof(male[0]));

    string female[12] = {"kona", "kvenmadur", "kvenkyns", "kvk", "stelpa", "female", "stulka",
                        "kerling", "lady", "woman", "girl", "gal"};

    vector<string> femaleVector (female, female + sizeof(female) / sizeof(female[0]));

    bool isMale = find(maleVector.begin(), maleVector.end(), gender) != maleVector.end();
    bool isFemale = find(femaleVector.begin(), femaleVector.end(), gender) != femaleVector.end();

    if (isMale == true)
    {
        return 1;
    }

    else if (isFemale == true)
    {
        return 0;
    }
    else
    {
        return 2;
    }
}

int workingclass::yearCorrection(int year, bool &errorInYear)
{

    int tempYear = year;

    if ((tempYear >= 20) && (tempYear < 100))
    {
        tempYear += 1900;
    }
    else if ((tempYear > 0) && (tempYear < 20))
    {
        tempYear += 2000;
    }

    if ((tempYear > 0) && (tempYear < CURRENTYEAR))
    {
        errorInYear = false;
    }
    else
    {
        errorInYear = true;
    }

    return tempYear;
}

vector<scientist> workingclass::searchByName(string subName, bool& isFound)
{
    vector<scientist> v;
    scientist s;
    for(unsigned int i = 0; i < scientistVector.size(); i++)
    {
        if( subName.find( scientistVector.at(i).getName()))
       {
            s = scientistVector.at(i);
            v.push_back(s);
            isFound = true;
       }
    }
    return v;
}

vector<scientist> workingclass::searchByGender(string sex, bool& isFound)
{
    vector<scientist> v;
    scientist s;
    int tempGender = genderCorrection(sex);

    for(unsigned int i = 0; i < scientistVector.size(); i++)
    {
        if(scientistVector.at(i).getGender() == tempGender)
       {
            s = scientistVector.at(i);
            v.push_back(s);
            isFound = true;
       }
    }
    return v;
}

vector<scientist> workingclass::searchByYear(int& yr, char bORd, bool& isFound)
{
    vector<scientist> v;
    scientist s;
    bool error;
    yr = yearCorrection(yr, error);
    if (error)
    {
        return v;
    }
    for(unsigned int i = 0; i < scientistVector.size(); i++)
    {
        if(bORd == 'b')
        {
           if(scientistVector.at(i).getYearOfBirth() == yr)
           {
                s = scientistVector.at(i);
                v.push_back(s);
                isFound = true;
           }
        }
        else if(scientistVector.at(i).getYearOfDeath() == yr)
        {
            s = scientistVector.at(i);
            v.push_back(s);
            isFound = true;
        }
    }
    return v;
}

void workingclass::AddScientist()
{
    int selectedGender;
    bool wYLTContinue = true;

    scientist sO;

    //workingclass workingobject;

    infoDisplay display;

    while(wYLTContinue == true)
    {
        display.clearScreen();
        cout<<"Creating a new Scientist: "<<endl;
        cout<<"======================================"<<endl;

        string name = " ", gender = " ", descr = " ", link = " ";
        int yob = 0, yod = 0;

        name = (addScientistName(name));
        selectedGender = addScientistGender(gender);

        yob = (addScientistYearOfBirth());


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
        //tempVector = returnVector();
        tempVector = returnVector();
        tempVector.push_back(sO);
        //workingobject.pushToVector(sO);
        pushToVector(sO);

    };

    cout<<"output out of vector: "<<endl<<endl;
    //workingobject.printVector();
    printVector();

    display.mainMenu();

}

string workingclass::addScientistName(string &name)
{
    //workingclass workingobject;
    bool badName = false;

    do
    {
        cout<<"Enter name: ";
        getline(cin, name);
        name = nameCorrection(name, badName);
        if (badName == true)
        {
            cout<<"Incorrect name format!"<<endl;
        }
    }
    while(badName == true);

    return name;
}

int workingclass::addScientistGender(string &gender)
{
    //workingclass workingobject;
    int selectedGender;
    cout<<"Enter gender: ";
    cin>>gender;

    for(unsigned int i = 0; i < gender.length(); ++i)
    {
        gender[i] = tolower(gender[i]);
    }

    selectedGender = genderCorrection(gender);

    return selectedGender;
}

int workingclass::addScientistYearOfBirth()
{
    string tempInput;
    int temp;

    bool errorInYear = false;
    //workingclass workingobject;

    do
    {
        cout<<"Enter year of birth: ";
        cin>>tempInput;

        stringstream stringToInt (tempInput);
        stringToInt >> temp;

        temp = yearCorrection(temp, errorInYear);

        if (errorInYear == true)
        {
            cout<<"Incorrect year format!"<<endl;
        }
    }
    while (errorInYear == true);

    return temp;
}

bool workingclass::addScientistMore(int &yod, string &descr, string &link)
{
    //workingclass workingobject;
    infoDisplay display;
    display.addEmtyLines(2);
    cout<<"1. Add year of Death, 2. Description, 3. "
          "Website link, any other key skips."<<endl;

    char choice;
    cin>>choice;
    cin.ignore();

    switch(choice)
    {
        case '1':
        yod = addScientistYearOfDeath();
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
    bool addAnother = display.loopFunction();
    return addAnother;
}

int workingclass::addScientistYearOfDeath()
{
    bool errorInYear = false;

    string tempInput;
    int temp;

    //workingclass workingobject;

    do
    {
        cout<<"Year of Death: ";
        cin>>tempInput;

        stringstream stringToInt (tempInput);
        stringToInt >> temp;

        temp = yearCorrection(temp, errorInYear);

        if (errorInYear == true)
        {
            cout<<"Incorrect year format!"<<endl;
        }
    }
    while (errorInYear == true);
    return temp;
}

string workingclass::addScientistDescription(string &descr)
{
    cout<<"Description: ";
    getline(cin, descr);
    return descr;
}

string workingclass::addScientistLink(string &link)
{
    cout<<"Website Link:";
    getline(cin, link);
    return link;
}


bool workingclass::addScientistCheck(string name, int gender, int yob, int yod, string desc, string link)
{
    infoDisplay display;
    display.clearScreen();
    //char input;
    cout<<"Current entry: "<<endl;
    cout<<"======================================"<<endl;
    cout<<"Name: "<<name<<endl;
    if (gender == 1)
    {
        cout<<"Gender: Male"<<endl;
    }
    else if (gender == 0)
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

    bool cont = display.loopFunction();

    return cont;
}

void workingclass::addScientistChange(string &name, string gender, int &yob, int &yod, string &desc, string &link, int &selectedGender)
{
    infoDisplay display;
    display.clearScreen();
    int input = 0;
    display.addEmtyLines(5);
    cout<<"What would you like to change? Choose: "<<endl;
    cout<<"1. Name, 2. Gender, 3. Year of Birth, 4. "
          "Year of Death, 5. Description, 6. Link"<<endl;
    cin>>input;
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
        //yob = addScientistYearOfBirth(yob);
        yob = addScientistYearOfBirth();
        break;
    case 4:
        yod = addScientistYearOfDeath();
        break;
    case 5:
        desc = addScientistDescription(desc);
        break;
    case 6:
        link = addScientistLink(link);
        break;
    }
}

bool workingclass::addScientistContinue()
{
    infoDisplay display;

    //char input;
    display.addEmtyLines(1);
    cout<<"Would you like to add more Scientists? Y/N: ";

    bool input = display.loopFunction();
    return input;
}

//void workingclass::searchSelection(int select)
//{
//    workingclass work;
//    infoDisplay display;
//    //infoDisplay disp;
//    char cont;

//    switch (select)
//    {
//    case 1:

//        do
//        {
//            string tempName;
//            bool found = false;

//            display.clearScreen();
//            cout << "Please enter a part of the name you would like to find: " << endl;
//            cin >> tempName;
//            work.searchByName(tempName, found);
//            if( found == true)
//            {
//                work.printVector();
//                cont = 'N';
//            }
//            else
//            {
//                cout << "Nothing found! - Do you want to try again? (Y/N): ";
//                cin >> cont;
//            }
//        }while(toupper(cont) == 'Y');
//        break;
//    case 2:
//        do
//        {
//            string tempGender;
//            bool found = false;

//            display.clearScreen();
//            cout << "Please enter the gender you would like to see: " << endl;
//            cin >> tempGender;
//            work.searchByGender(tempGender, found);
//            if( found == true)
//            {
//                work.printVector();
//                cont = 'N';
//            }
//            else
//            {
//                cout << "Nothing found! - Do you want to try again? (Y/N): ";
//                cin >> cont;
//            }
//        }while(toupper(cont) == 'Y');

//        break;
//    case 3:
//        do
//        {
//            int yr;
//            bool found = false;

//            display.clearScreen();
//            cout << "Please enter the year you would like to search for: " << endl;
//            cin >> yr;
//            work.searchByYear(yr, 'b', found);
//            if( found == true)
//            {
//                work.printVector();
//                cont = 'N';
//            }
//            else
//            {
//                cout << "Nothing found! - Do you want to try again? (Y/N): ";
//                cin >> cont;
//            }

//        }while(toupper(cont) == 'Y');
//        break;
//    case 4:
//        do
//        {
//            int yr;
//            bool found = false;

//            display.clearScreen();
//            cout << "Please enter the year you would like to search for: " << endl;
//            cin >> yr;
//            work.searchByYear(yr, 'd', found);
//            if( found == true)
//            {
//                work.printVector();
//                cont = 'N';
//            }
//            else
//            {
//                cout << "Nothing found! - Do you want to try again? (Y/N): ";
//                cin >> cont;
//            }

//        }while(toupper(cont) == 'Y');
//        break;
//    case 5:
//        display.clearScreen();
//        display.mainMenu();
//        break;
//    default:
//        display.addEmtyLines(5);
//        cout << "Illigal selection!!" << endl;
//        cout << "Returning to Search menu" << endl;
//        sleep(3);
//        display.displaySearchScientist();
//        break;
//    }
//}
