#include <QCoreApplication>
#include <iostream>
#include "compSciClass.h"
#include "workingclass.h"
#include "infodisplay.h"
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    vector<compSciClass> progrVector;

    return a.exec();
}

