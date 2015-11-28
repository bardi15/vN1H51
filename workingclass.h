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
//    vector<scientist> getVector();
    void pushToVector(scientist s);
    void fillScientist(string text, scientist& s, const int field);
    void createScientist(string& line, int& oldfind);
    void printVector() const;

private:
    vector<scientist> scientistVector;
};

#endif // WORKINGCLASS_H

