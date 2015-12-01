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
    void selectAction();
    int selection();
    void searchSelection(int select);
    void chooseSortion(int choice);
    void editScientistDisplayService();
    void editScientistService(int i); //(int selection, int scientist);
    workingclass workingobject;


};

#endif // SERVICE_H
