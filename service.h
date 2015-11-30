#ifndef SERVICE_H
#define SERVICE_H

#include <iostream>
#include <string>
#include "infodisplay.h"
#include "workingclass.h"

using namespace std;

class service
{
public:
    service();
    vector<scientist> getWCVector();
    void setWCVector(vector<scientist>& v);
    //void screenSelection();
    void selectAction(int sel);
    void searchSelection(int select);
    void chooseSortion(int choice);



};

#endif // SERVICE_H
