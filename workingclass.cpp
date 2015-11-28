#include "scientist.h"
#include "infodisplay.h"
#include "workingclass.h"
#include "fstream"
#include <cstring>
#include <cstdlib>

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
        cout << "error";
        exit(1);
    }
    while(!skra_inn.eof())
    {
        int loc = 0;
        string next= "";
        char nextchar;
        skra_inn.get(nextchar);
        while(!skra_inn.eof() && nextchar != '\n')
        {
            next += nextchar;
            skra_inn.get(nextchar);
        }
        createScientist(next, loc);
    }
    skra_inn.close();

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
