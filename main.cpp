//#include <QCoreApplication>
#include <iostream>
#include <QtSql>
//#include "scientist.h"
#include "infodisplay.h"
//#include "workingclass.h"

using namespace std;

int main()
{    
//    infoDisplay display;
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = "../vN1H51/Group51_verklegt_1.sqlite";
        db.setDatabaseName(dbName);

    infoDisplay display;
    display.selectAction();
    return 0;
}
