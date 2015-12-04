#include "service.h"

using namespace std;


service::service()
{

}


int service::selection()
{
    int select;
    cin>>select;
    cin.ignore();
    return select;
}



void service::servEraseVector()
{
    workingObject.eraseVector();
}
void service::servReadSqlScientists(int sorting)
{
    workingObject.readSqlScientists();
}
vector<scientist> service::servGetSciVector()
{
    return workingObject.getSciVector();
}
//<<<<<<< HEAD
void service::servSortScientists(int choice)
{
    string sort;

      switch(choice)
      {
            case 1:
                sort = ("name ASC;");
                //servReadSqlScientists(sort);
                workingObject.readSqlScientists("name ASC;");
                break;
            case 2:
                //sort = ("name DESC;");
                //servReadSqlScientists(sort);
                workingObject.readSqlScientists("name DESC;");
                break;
            case 3:
                //sort = ("yob ASC;");
                //servReadSqlScientists(sort);
                workingObject.readSqlScientists("yob ASC;");
                break;
            case 4:
                //sort = ("yob DESC;");
                workingObject.readSqlScientists("yob DESC;");
                //servReadSqlScientists(sort);
                break;
            default:
                exit(0);
                break;
      }
}
//void service::servSortAlph(vector<scientist>& v)
//{
//    workingObject.sortAlph(v);
//}
//void service::servSortRevAlph(vector<scientist>& v)
//{
//    workingObject.sortRevAlph(v);
//}
//void service::servSortYOB(vector<scientist>& v)
//{
//    workingObject.sortYOB(v);
//}
//void service::servSortYOD(vector<scientist>& v)
//{
//    workingObject.sortYOD(v);
//}
//=======
vector<computer> service::servGetComVector()
{
    return workingObject.getComVector();
}

//void service::servSortAlph(vector<scientist>& v)
//{
//    workingObject.sortAlph(v);
//}
//void service::servSortRevAlph(vector<scientist>& v)
//{
//    workingObject.sortRevAlph(v);
//}
//void service::servSortYOB(vector<scientist>& v)
//{
//    workingObject.sortYOB(v);
//}
//void service::servSortYOD(vector<scientist>& v)
//{
//    workingObject.sortYOD(v);
//}
bool service::servAddscientist(scientist& s) const
{

}
bool service::servAddcomputer(computer& c) const
{

}


//>>>>>>> 5ffdc49055be7ad3de31758e4b97f272d927ff4f
//void service::servAddScientistChange(string &name, string gender, int &yob, int &yod, string &desc, string &link, int &selectedGender)
//{
//    workingObject.addScientistChange(name, gender, yob, yod, desc, link, selectedGender);
//}

// bool service::servAddScientistCheck(string name, int gender, int yob, int yod, string desc, string link)
// {
//     return workingObject.addScientistCheck(name, gender, yob, yod, desc, link);
// }

//void service::servVectorToFile(vector<scientist>& v, char AppOver) const
//{
//    workingObject.VectorToFile(v, AppOver);
//}
vector<scientist> service::servSearchByName(string subName, bool& isFound)
{
    return workingObject.searchByName(subName, isFound);
}
vector<scientist> service::servSearchByGender(int sex, bool& isFound)
{
    return workingObject.searchByGender(sex, isFound);
}
vector<scientist> service::servSearchByYear(int& yr, char bORd, bool& isFound)
{
    yr = yearCorrection(yr,isFound);
    return workingObject.searchByYear(yr, bORd, isFound);
}
void service::servPushToVector(const scientist& s)
{
    workingObject.pushToVector(s);
}
int service::yearCorrection(int year, bool &errorInYear)
{

    int tempYear = year;

    if ((tempYear >= 20) && (tempYear < 100))
    {
        tempYear += 1900;
    }
    else if ((tempYear >= 0) && (tempYear < 20))
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
string service::nameCorrection(string name, bool& badName)
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
int service::genderCorrection(string gender)
{

    for(unsigned int i = 0; i < gender.length(); ++i)
    {
        gender[i] = tolower(gender[i]);
    }

    string male[15] = {"m","karlmadur", "karlkyns", "karl", "kk", "male", "man", "guy", "bro",
                      "kall", "gaur", "dude", "sjomli", "strakur", "piltur"};

    vector<string> maleVector (male, male + sizeof(male) / sizeof(male[0]));

    string female[14] = {"f", "kona", "kvenmadur", "kvenkyns", "kvk", "stelpa", "female", "stulka",
                        "kerling", "kelling", "lady", "woman", "girl", "gal"};

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
//void service::servRemoveScientist(scientist& s)
//{
//    workingObject.removeScientist(s);
//}
// void service::servAddLineToFile(scientist& s, char AppOver) const
// {
//     workingObject.addLineToFile(s, AppOver);
// }
void service::servStartDatabase()
{
    workingObject.startDatabase();
}
void service::servCloseDatabase()
{
    workingObject.closeDatabase();
}

void service::henda()
{
    //workingObject.readSqlComputers();
    workingObject.readSqlScientists();
}
