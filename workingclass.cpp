#include "infodisplay.h"
#include "workingclass.h"
#include "scientist.h"
#include "fstream"
#include <cstring>
#include <cstdlib>

const string WORKFILE = "Scientistinfo.csv";
const int MAXFIELDS = 6;

workingclass::workingclass()
{

}
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
        string next;
        getline(cin, next);
        createScientist(next);
    }
    skra_inn.close();

}


void workingclass::pushToVector(scientist s)
{
    scientistVector.push_back(s);
}

void workingclass::createScientist(string& line)
{
    string fieldtext;
    int currFind = 0;
    int oldFind = 0;
    scientist s;
    int fieldno = 1;

    do
    {
        currFind = line.find(';',currFind) - 1;
        fieldtext = line.substr(oldFind, currFind);
        fillScientist(fieldtext, s, fieldno);
        fieldno++;
        oldFind = currFind + 1;
    }
    while(fieldno <= 6);

    if(fieldno == MAXFIELDS)
    {
        pushToVector(s);
    }

}

void workingclass::printVector() const
{
    for(unsigned int i = 0; i < scientistVector.size(); i++)
    {
        scientist s = scientistVector.at(i);
        cout << "Nafn: " << s.getName() << endl;
    }
}

void workingclass::fillScientist(string text, scientist& s, const int field)
{
    switch (field)
    {
    case 1:
        s.setName(text);
        break;
    case 2:
        s.setgender(atoi(text.c_str()));
        break;
    case 3:
        s.setYearOfBirth(atoi(text.c_str()));
        break;
    case 4:
        s.setYearOfDeath(atoi(text.c_str()));
        break;
    case 5:
        s.setDescription(text);
        break;
    case 6:
        s.setLink(text);
        break;
    default:
        cout << "error" << endl;
        break;
    }
}
