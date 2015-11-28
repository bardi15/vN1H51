#include <QCoreApplication>
#include <iostream>
#include "scientist.h"
#include "infodisplay.h"
#include "workingclass.h"
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    vector<scientist> progrVector;

    return a.exec();
}

