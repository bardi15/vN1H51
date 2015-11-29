#ifndef WORKINGCLASS_H
#define WORKINGCLASS_H

//#include "scientist.h"
#include "infodisplay.h"
#include "workingclass.h"
#include <vector>
#include "scientist.h"
#include <string>

using namespace std;

const string WORKFILE = "Scientistinfo.txt";
const int MAXFIELDS = 6;
const int MAXNAMELENGTH = 30;
const int CURRENTYEAR = 2015;

class workingclass
{
public:
    workingclass();
    void selectAction(int sel);
    void readFile();
    void addToFile();
    void readLinesFromFile(ifstream& fileWithLines);
    void addLineToFile(string& outstring) const;
    string scientistToFile( scientist s) const;
//    vector<scientist> getVector();
    void pushToVector(scientist s);
    void fillScientist(string text, scientist& s, const int field);
    void createScientist(string& line, int& oldfind);
    void printVector() const;
    vector<scientist> returnVector ();
    void modifyVector(vector<scientist> mVector);
    string nameCorrection(string name, bool& badName);
    int genderCorrection(string gender);
    int yearCorrection(int year);
    vector<scientist> searchByName(string subName, bool& isFound);
    vector<scientist> searchByGender(string sex, bool& isFound);
    vector<scientist> searchByYear(int& yr, char bORd, bool& isFound);
    int yearCorrection(int year, bool &errorInYear);

private:
    vector<scientist> scientistVector;
};

#endif // WORKINGCLASS_H

