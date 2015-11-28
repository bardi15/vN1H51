#ifndef WORKINGCLASS_H
#define WORKINGCLASS_H
#include "infodisplay.h"
#include "workingclass.h"
#include "scientist.h"
#include <vector>

class workingclass
{
public:
    workingclass();
    void selectAction(int sel);
    void readFile();
    void addToVectorFromFile(string line);
    void pushToVector(scientist s);
    void fillScientist(string text, scientist& s, const int field);
    void createScientist(string& line);
    void printVector() const;

private:
    vector<scientist> scientistVector;
};

#endif // WORKINGCLASS_H
