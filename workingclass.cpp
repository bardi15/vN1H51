#include "scientist.h"
#include "infodisplay.h"
#include "workingclass.h"
#include "fstream"
#include <cstring>
#include <cstdlib>
#include <stdlib.h>
#include <string>

const string WORKFILE = "Scientistinfo.txt";
const int MAXFIELDS = 6;

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
        cout << "dd: " << scientistVector[i].getYearOfBirth() << endl;
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

string workingclass::nameCorrection(string name)
{
    return name;
}

int workingclass::genderCorrection(string gender)
{
    int gen = (atoi(gender.c_str()));
    return gen;
}

int workingclass::yearCorrection(string year)
{
    int yea = (atoi(year.c_str()));
    return yea;
}
