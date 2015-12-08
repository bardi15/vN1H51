#ifndef WORKINGCLASS_H
#define WORKINGCLASS_H

#include "scientist.h"
#include "computer.h"
#include "computertype.h"
#include <QtSql>
#include<qfile.h>

#include <cstring>
#include <cstdlib>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const string DBASE = "../vN1H51/Group51_verklegt_1.sqlite";
const int MAXFIELDS = 6;
const int MAXNAMELENGTH = 44;
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
    vector<computertype> getCompTypeVector();
    //  Postcondition:  Returns the private vector.
    bool addscientist(scientist& s);
    //  Precondition:   The parameter s is a new scientist.
    //  Postcondition:  The scientist s is now added to the database and
    //      s has been updated with the correct id.
    bool addcomputer(computer& c);
    //  Precondition:   The parameter c is a new computer.
    //  Postcondition:  The computer c is now added the database and
    //      c has been updated with the correct id.
    bool updateSqlComputer(computer& c);
    //  Precondition:   The parameter c is a computer that has changes to it.
    //  Postcondition:  The computer c is now updated with new information.
    void updateSqlScientist(scientist& s);
    //  Precondition:   The parameter s is a scientist that has changes to it.
    //  Postcondition:  The scientist s is now updated with new information.
    bool updateSqlComputerType(computertype& ct);
    //  Precondition:   The parameter ct is a computer type that has changes to it.
    //  Postcondition:  The computer type ct is now updated with new information.
    bool addcomputerType(computertype& ct);
    //  Precondition:   The parameter ct is a new computer type.
    //  Postcondition:  The computer type ct is now added to the database
    //      and ct has been updated with the correct id.
    void deleteScientist(int sciID);
    //  Precondition:   The parameter sciID is the ID of a scientist to be deleted.
    //  Postcondition:  The scientist sciID has been deleted from the database.
    bool deleteComputer(int compID);
    //  Precondition:   The parameter compID is the ID of a computer to be deleted.
    //  Postcondition:  The computer compID has been deleted from the database.
    bool deleteComputerType(int computertypeID);
    //  Precondition:   The parameter computertypeID is the ID of a computer type to be deleted.
    //  Postcondition:  The computer type computertypeID has been deleted from the database.
    void readSqlScientists(string sorting = "name ASC");
    //  Precondition:   The database is open.
    //  Postcondition:  If data available, it is read into the private vector for scientist.
    void readSqlComputers(string sorting = "name ASC");
    //  Precondition:   The database is open.
    //  Postcondition:  If data available, it is read into the private vector for computers.
    void readSqlCompTypes();
    //  Precondition:   The database is open.
    //  Postcondition:  If data available, it is read into the private vector for computertypes.
    vector<computer> getComputersLinkedToScientists(int sciID);
    //  Precondition:   A computer is selected and its ID sent in as compID.
    //  Postcondition:  Returns a vector of scientist related to the computer.
    vector<scientist> getScientistsLinkedToComputer(int compID);
    //  Precondition:   A scientist is selected and its ID sent in as sciID.
    //  Postcondition:  Returns a vector of computers related to the scientist.
    bool createRelationSciComp(int sciID, int compID);
    //  Precondition:   Takes in id's of both an existing scientist and an existing computer.
    //  Postcondition:  Creates a link between the scientist and the computer in the database.  Returns true if the operations goes through, false otherwise.
    void eraseScientistVector();
    //  Precondition:   A new or changed vector is about to be created.
    //  Postcondition:  The privat vector is clear of all scientists.
    void eraseComputerVector();
    //  Precondition:   A new or changed vector is about to be created.
    //  Postcondition:  The privat vector is clear of all computers.
    void eraseCompTypeVector();
    //  Precondition:   A new or changed vector is about to be created.
    //  Postcondition:  The privat vector is clear of all computer types.
    void searchScientistByName(string subName, bool& isFound);
    //  Precondition:   Takes in the parameter subName to be searched for and a boolean
    //      variable to indicate if found.
    //  Postcondition:  Returns a vector of the scientist matching the criteria.
    void searchScientistByGender(int sex, bool& isFound);
    //  Precondition:   Takes in the parameter sex to be searched for and a boolean
    //      variable to indicate if found.
    //  Postcondition:  Returns a vector of the scientist matching the criteria.
    void searchScientistByYear(int& yr, char bORd, bool& isFound);
    //  Precondition:   Takes in the parameter year to be searched for, a char indicating
    //      whether to look for the year of birth or year of death and a boolean
    //      variable to indicate if found.
    //  Postcondition:  Returns a vector of the scientist matching the criteria.
    void searchComputerByName(string subName, bool& isFound);
    //  Precondition:   Takes in the parameter subName to be searched for and a boolean variable to indicate if found.
    //  Postcondition:  Returns a vector of the computers matching the criteria.
    void searchComputerByType(string& type, bool& isFound);
    //  Precondition:   Takes in the parameter type to be searched for and a boolean variable to indicate if found.
    //  Postcondition:  Returns a vector of the computers matching the criteria.
    void searchComputerByYear(int& yr, bool& isFound);
    //  Precondition:   Takes in the parameter year to be searched for and a boolean variable to indicate if found.
    //  Postcondition:  Returns a vector of the computers matching the criteria.
    QSqlDatabase startDatabase();
    //  Precondition:   The database is present in the build directory of the program.
    //  Postconditinon: A link to the database has been established.
    void createEmptyDatabase();
    //  Precondition:   There is no database present directory of choice.
    //  Postconditinon: A new database with empty tables is created.
    bool checkDatabaseExists();
    //  Precondition:   A name for the database has been declered.
    //  Postcondition:  Returns true if database exits, false otherwise.
    void closeDatabase();
    //  Precondition:   The database is open.
    //  Postconditinon: The database has been closed.
    void createScientistsAndComputers();
    void createComputers();
    void createTableScientists();
    void createTableComputerTypes();


private:

    vector<scientist> scientistVector;
    vector<computer> computerVector;
    vector<computertype> compTypeVector;
};

#endif // WORKINGCLASS_H

