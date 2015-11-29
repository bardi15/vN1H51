#ifndef WORKINGCLASS_H
#define WORKINGCLASS_H

//#include "scientist.h"
#include "infodisplay.h"
#include "workingclass.h"
#include <vector>
#include "scientist.h"
#include <string>

using namespace std;


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

private:
    vector<scientist> scientistVector;
};

#endif // WORKINGCLASS_H

