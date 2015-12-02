#include "scientist.h"
#include "infodisplay.h"
#include "workingclass.h"

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

            if(i == 0)
            {
                addLineToFile(v.at(i), 'O');
            }
            else
            {
                addLineToFile(v.at(i), 'A');
            }
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
    cout << outstring << endl;
    file_out  << endl << s.getName() << ";" <<
                s.getGender() << ";" << s.getYearOfBirth() << ";" <<
                s.getYearOfDeath() << ";" << s.getDescription() << ";" <<
                s.getLink();
    file_out.close();

}

string workingclass::scientistToString(scientist& s) const
{
    string nextline;
    nextline += s.getName();
    nextline += ";";
    stringstream ss;
    ss << s.getGender();
    nextline += ss.str();
    nextline += ";";
    ss << s.getYearOfBirth();
    nextline += ss.str();
    nextline += ";";
    ss << s.getYearOfDeath();
    nextline += ss.str();
    nextline += ";";
    nextline += s.getDescription();
    nextline += ";";
    nextline += s.getLink();
    nextline += ";";
    nextline += "\n";

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
        if( next.size() > 3)
        {
            createScientist(next, loc);
        }

    }
}
void workingclass::pushToVector(scientist s)
{
    scientistVector.push_back(s);
}
void workingclass::eraseVector()
{
    scientistVector.clear();
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
void workingclass::removeScientist(scientist& s)
{
    readFile();
    for(unsigned int j = 0; j < scientistVector.size(); j++)
    {
        if(scientistVector[j].getName() == s.getName())
        {
            scientistVector.erase(scientistVector.begin() + j);

              ofstream newFile(WORKFILE.c_str());
              if(newFile.is_open())
              {
                  for(unsigned int i = 0; i < scientistVector.size(); i++)
                  {
                      if(i == 0)
                      {
                        addLineToFile(scientistVector[i], 'O');
                      }
                      else
                      {
                          addLineToFile(scientistVector[i], 'A');
                      }
//                      newFile << scientistVector[i].getName() << ";" <<
//                                 scientistVector[i].getGender() << ";" <<
//                                 scientistVector[i].getYearOfBirth() << ";" <<
//                                 scientistVector[i].getYearOfDeath() << ";" <<
//                                 scientistVector[i].getDescription() << ";" <<
//                                 scientistVector[i].getLink() << endl;
                  }
              }else {
                  cout << "can't open file";
              }
              break;
        }
   }

}
void workingclass::printVector() const
{
//    infoDisplay disp;
//    vector<scientist> v = scientistVector;
//    disp.displayList(v);
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

    for(unsigned int i = 0; i < gender.length(); ++i)
    {
        gender[i] = tolower(gender[i]);
    }

    string male[15] = {"m","karlmadur", "karlkyns", "karl", "kk", "male", "man", "guy", "bro",
                      "kall", "gaur", "dude", "sjomli", "strakur", "piltur"};

    vector<string> maleVector (male, male + sizeof(male) / sizeof(male[0]));

    string female[13] = {"f", "kona", "kvenmadur", "kvenkyns", "kvk", "stelpa", "female", "stulka",
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

    if ((tempYear > 0) && (tempYear <= CURRENTYEAR))
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
    vector<scientist> returnVector;
    scientist s;

    for(unsigned int i = 0; i < scientistVector.size(); i++)
    {
        if( scientistVector.at(i).getName().find( subName) < 30 )
       {
            s = scientistVector.at(i);
            returnVector.push_back(s);
            isFound = true;
       }
    }
    return returnVector;
}
vector<scientist> workingclass::searchByGender(string sex, bool& isFound)
{
    vector<scientist> tempReturn;
    scientist s;
    int tempGender = genderCorrection(sex);

    for(unsigned int i = 0; i < scientistVector.size(); i++)
    {
        if(scientistVector.at(i).getGender() == tempGender)
       {
            s = scientistVector.at(i);
            tempReturn.push_back(s);
            isFound = true;
       }
    }
    return tempReturn;
}
vector<scientist> workingclass::searchByYear(int& yr, char bORd, bool& isFound)
{
    vector<scientist> tempReturn;
    scientist s;
    bool error;
    yr = yearCorrection(yr, error);
    if (error)
    {
        tempReturn.resize(0);
        return tempReturn;
    }
    for(unsigned int i = 0; i < scientistVector.size(); i++)
    {
        if(bORd == 'b')
        {
           if(scientistVector.at(i).getYearOfBirth() == yr)
           {
               s = scientistVector.at(i);
               tempReturn.push_back(s);
               isFound = true;
           }
        }
        else if(scientistVector.at(i).getYearOfDeath() == yr)
        {
            s = scientistVector.at(i);
            tempReturn.push_back(s);
            isFound = true;
        }
    }
    return tempReturn;
}
bool AlphComp(scientist a, scientist b)
{
    return a.getName() < b.getName();

}
bool RevAlphComp(scientist a, scientist b)
{
    return a.getName() > b.getName();

}
bool DB_Comp(scientist a, scientist b)
{
    return a.getYearOfBirth() > b.getYearOfBirth();
}
bool DD_Comp(scientist a, scientist b)
{
    return a.getYearOfDeath() > b.getYearOfDeath();
}
void workingclass::sortAlph(vector<scientist>& v)
{

    sort(v.begin(), v.end(), AlphComp);
}
void workingclass::sortRevAlph(vector<scientist>& v)
{
    sort(v.begin(), v.end(), RevAlphComp);
}
void workingclass::sortYOB(vector<scientist>& v)
{
   sort(v.begin(), v.end(), DB_Comp);
}
void workingclass::sortYOD(vector<scientist>& v)
{
    sort(v.begin(), v.end(), DD_Comp);
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
        display.addEmtyLines(5);
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
        //tempVector = returnVector();
        tempVector = returnVector();
        tempVector.push_back(sO);
        //workingobject.pushToVector(sO);
        pushToVector(sO);
        wO.addLineToFile(sO, 'A');

    };

    //cout<<"\toutput out of vector: "<<endl<<endl;
    //workingobject.printVector();
    //printVector();

    display.mainMenu();

}
string workingclass::addScientistName(string &name)
{
    //workingclass workingobject;
    bool badName = false;

    do
    {
        cout<<"\tEnter name: ";
        getline(cin, name);
        name = nameCorrection(name, badName);
        if (badName == true)
        {
            cout<<"\tIncorrect name format!"<<endl;
        }
    }
    while(badName == true);

    return name;
}
int workingclass::addScientistGender(string &gender)
{
    //workingclass workingobject;
    int selectedGender;
    cout<<"\tEnter gender: ";
    cin>>gender;



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
        cout<<"\tEnter year of birth: ";
        cin>>tempInput;

        stringstream stringToInt (tempInput);
        stringToInt >> temp;

        temp = yearCorrection(temp, errorInYear);

        if (errorInYear == true)
        {
            cout<<"\tIncorrect year format!"<<endl;
        }
    }
    while (errorInYear == true);

    return temp;
}
bool workingclass::addScientistMore(int yob, int &yod, string &descr, string &link)
{
    //workingclass workingobject;
    infoDisplay display;
    display.addEmtyLines(5);
    cout<<"\t1. Add year of Death, 2. Description, "<<endl<<"\t3Website link, any other key skips: ";

    bool addAnother = true;


    char choice;
    //cin>>choice;
    choice = inputNumberToFunction();
    cin.ignore();


    if ((choice < 0)&&(choice > 3))
    {
        cout<<"\tNothing selected. "<<endl;
        addAnother = false;
    }
    else
    {
        switch(choice)
        {
            case '1':
            yod = addScientistYearOfDeath(yob);
            break;

            case '2':
            descr = addScientistDescription(descr);
            break;

            case '3':
            link = addScientistLink(link);
            break;

            default:
            cout<<"\tNothing selected. "<<endl;
            addAnother = false;
            sleep(1);
        }

    }

    if (addAnother == true)
    {
        cout<<"\tAdd more fields? Y/N? ";
        addAnother = display.loopFunction();
    }

    return addAnother;

}
int workingclass::addScientistYearOfDeath(int yob)
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

        temp = yearCorrection(temp, errorInYear);



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
string workingclass::addScientistDescription(string &descr)
{
    cout<<"\tDescription: ";
    getline(cin, descr);
    return descr;
}
string workingclass::addScientistLink(string &link)
{
    cout<<"\tWebsite Link:";
    getline(cin, link);
    return link;
}
bool workingclass::addScientistCheck(string name, int gender, int yob, int yod, string desc, string link)
{
    infoDisplay display;
    display.clearScreen();
    display.addEmtyLines(5);
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

    bool cont = display.loopFunction();

    return cont;
}
void workingclass::addScientistChange(string &name, string gender, int &yob, int &yod, string &desc, string &link, int &selectedGender)
{
    infoDisplay display;
    display.clearScreen();
    int input = 0;
    //bool badSelection = false;
    int yOBirth = yob;

    display.addEmtyLines(5);
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
        //yob = addScientistYearOfBirth(yob);
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
bool workingclass::addScientistContinue()
{
    infoDisplay display;

    //char input;
    display.addEmtyLines(1);
    cout<<"\tWould you like to continue? Y/N: ";

    bool input = display.loopFunction();
    return input;
}

int workingclass::inputNumberToFunction()
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

//    if ((ia >= 0)&&(ia <= 9))
//    {
//        return ia;
//        badSelection = true;
//    }
//    else
//    {
//        return 0;
//    }
}
