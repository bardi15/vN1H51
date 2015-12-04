#ifndef WORKINGCLASS_H
#define WORKINGCLASS_H

#include "scientist.h"
#include "computer.h"
#include "computertype.h"
#include <QtSql>

#include <fstream>
#include <cstring>
#include <cstdlib>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
//../vN1H51/
//const string WORKFILE = "Scientistinfo.txt";
const string DBASE = "Group51_verklegt_1.sqlite";
const string SCIENTISTTABLE = "scientists";
const string COMPUTERSTTABLE = "computers";
const string COMPTYPESTABLE = "computer_types";
const string LINKTABLE = "scientists_and_computers";
const int MAXFIELDS = 6;
const int MAXNAMELENGTH = 30;
const int CURRENTYEAR = 2015;




class workingclass
{
public:
    workingclass();
    //  Default constructor for class.
    vector<scientist> getSciVector();
    //  Postcondition:  Returns the private vector.
    vector<computer> getComVector();
    //  Postcondition:  Returns the private vector.
    void setVector(vector<scientist>& v);
    //  Precondition:   The vecor v has been filled with scientist.
    //  Postcondition:  The private vector has been set with the new scientist.
    void selectAction(int sel);
    //  Precondition:
    //  Postcondition:
    //QSqlDatabase
    bool addscientist(scientist& s);
    bool addscientist(computer& c);

    void readSqlScientists(string sorting = "name ASC");
    //  Precondition:   The database is open.
    //  Postcondition:  If data available, it is read into the private vector for scientist.
    void readSqlComputers(string sorting = "name ASC");
    //  Precondition:   The database is open.
    //  Postcondition:  If data available, it is read into the private vector for computers.
    void readSqlCompTypes();
    //  Precondition:   The database is open.
    //  Postcondition:  If data available, it is read into the private vector for computertypes.
    void addToFile();
    //  Precondition:
    //  Postcondition:
    void readLinesFromFile(ifstream& fileWithLines);
    //  Precondition:   The file with the scientist has been opened.
    //  Postcondition:  All lines with scientist have been read and scientists created.
    void addLineToFile(scientist& s, char AppOver) const;
    //  Precondition:   The scientist s is legally initialized. If he should be added
    //      to the file, AppOver should be 'A' or 'O' if the file is to overwritten.
    //  Postcondition:  The scientist has been written to file accordingly.
    void VectorToFile(vector<scientist>& v, char AppOver) const;
    //  Precondition:   The vector v is filled with scientist about to be written to
    //      the text file holding the scientist. If they should be added to the file, AppOver should be 'A' or 'O' if the file is to overwritten.
    //  Postcondition:  The vector has been written to file accordingly.
    void pushToVector(const scientist& s);
    //  Precondition:   A scientist is ready to be inserted into the privat vector.
    //  Postcondition:  The scientist has been inserted into the vector.
    void fillScientist(const string& text, scientist& s, const int& field);
    //  Precondition:   The scientist s is about to be created.  Parameters include the
    //      text to inserted into a variable in the scientist, the scientist to be created
    //      and the field to be populated currently.
    //  Postcondition:  The field to be populated has been correcly populated.
    void createScientist(string& line, int& oldfind);
    //  Precondition:   A line from the text file has been read. The old location of
    //      the line splitter ';' is available.
    //  Postcondition:  The line has been splitted into fields and the created
    //      scientist been inserted into the private vector.
    //void sortAlph(vector<scientist>& v);
    //  Precondition:   The vector v that is to be sorted is populated.
    //  Postcondition:  The vector is sorted in alphabetical order.
    //void sortRevAlph(vector<scientist>& v);
    //  Precondition:   The vector v that is to be sorted is populated.
    //  Postcondition:  The vector is sorted in reversed alphabetical order.
    //void sortYOB(vector<scientist>& v);
    //  Precondition:   The vector v that is to be sorted is populated.
    //  Postcondition:  The vector is sorted in chronological order by year of birth.
    //void sortYOD(vector<scientist>& v);
    //  Precondition:   The vector v that is to be sorted is populated.
    //  Postcondition:  The vector is sorted in chronological order by year of birth.
    void removeScientist(scientist& s);
    //  Precondition:   A scientist to be removed has been selected.
    //  Postcondition:  The scientist has been removed from the text file.
    void eraseVector();
    //  Precondition:   A new or changed vector is about to be created.
    //  Postcondition:  The privat vector is clear of all scientists.

    vector<scientist> searchByName(string subName, bool& isFound);
    //  Precondition:   Takes in the parameter subName to be searched for and a boolean
    //      variable to indicate if found.
    //  Postcondition:  Returns a vector of the scientist matching the criteria.
    vector<scientist> searchByGender(int sex, bool& isFound);
    //  Precondition:   Takes in the parameter sex to be searched for and a boolean
    //      variable to indicate if found.
    //  Postcondition:  Returns a vector of the scientist matching the criteria.
    vector<scientist> searchByYear(int& yr, char bORd, bool& isFound);
    //  Precondition:   Takes in the parameter year to be searched for, a char indicating
    //      whether to look for the year of birth or year of death and a boolean
    //      variable to indicate if found.
    //  Postcondition:  Returns a vector of the scientist matching the criteria.
    QSqlDatabase startDatabase();
    //  Precondition:   The database is present in the build directory of the program.
    //  Postconditinon: A link to the database has been established.
    void closeDatabase();
    //  Precondition:   The database is open.
    //  Postconditinon: The database has been closed.

private:

    vector<scientist> scientistVector;
    vector<computer> computerVector;
    vector<computertype> compTypeVector;
};

#endif // WORKINGCLASS_H

