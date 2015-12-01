#ifndef OPENGREETING_H
#define OPENGREETING_H
#include "infodisplay.h"
#include <math.h>
#include <iostream>
#include <windows.h>

using namespace std;

class opengreeting
{
public:
    opengreeting();
    void printscreen (char ascii [][80]);
    void fillarray (char ascii [][80], char input);
    void art (char ascii [][80]);
    void greetingPost();

    char input;
    char ascii [20][80];
};

#endif // OPENGREETING_H
