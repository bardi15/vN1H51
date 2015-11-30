#ifndef WORKINGCLASS_H
#define WORKINGCLASS_H

#include "infodisplay.h"
#include "workingclass.h"
#include "scientist.h"
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>

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
    void addLineToFile(scientist& s, char AppOver) const;
    void VectorToFile(vector<scientist>& v, char AppOver) const;
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
    string scientistToString(scientist& s) const;
    //  Precondition:   Takes in a scientist s.
    //  Postcondition:  Returns a string ready to be written to file
    vector<scientist> scientistVector;
};

#endif // WORKINGCLASS_H

