#include <QCoreApplication>
#include <iostream>
#include "compsciclass.h"
#include "workingclass.h"
#include "infodisplay.h"
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    vector<compsciclass> progrVector;

    return a.exec();
}

