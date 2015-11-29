#include "scientist.h"
#include "infodisplay.h"
#include "workingclass.h"
#include "fstream"
#include <cstring>
#include <cstdlib>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>

const string WORKFILE = "Scientistinfo.txt";
const int MAXFIELDS = 6;
const int MAXNAMELENGTH = 30;

workingclass::workingclass()
{

}
//vector<scientist> workingclass::getVector()
//{
//    return vector<scientist> scientistVector;
//}

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
void workingclass::addLineToFile(string& outstring) const
{
    ofstream file_out;
    file_out.open(WORKFILE.c_str(), ios::app);
    if(file_out.fail())
    {
        cout << "error opening addToFile file";
        exit(1);
    }
    file_out << outstring;
    file_out.close();

}

string workingclass::scientistToFile( scientist s) const
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



void workingclass::printVector() const
{
    for(unsigned int i = 0; i < scientistVector.size(); i++)
    {
        //scientist s = scientistVector.at(i);
        cout << "Nafn: " << scientistVector[i].getName() << endl;
        cout << "kyn: " << scientistVector[i].getGender() << endl;
        cout << "fd: " << scientistVector[i].getYearOfBirth() << endl;
        cout << "dd: " << scientistVector[i].getYearOfDeath() << endl;
        cout << "descr: " << scientistVector[i].getDescription() << endl;
        cout << "url: " << scientistVector[i].getLink() << endl;
        cout << endl;

        //s.getName() << endl;
    }
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
        return 0;
    }

    else if (isFemale == true)
    {
        return 1;
    }
    else
    {
        return 2;
    }
}

int workingclass::yearCorrection(int year)
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

    return tempYear;
}

vector<scientist> workingclass::searchByName(string subName, bool& isFound)
{
    vector<scientist> v;
    scientist s;
    for(unsigned int i = 0; i < scientistVector.size(); i++)
    {
        if(scientistVector.at(i).getName() == subName)
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
    yr = yearCorrection(yr);
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

