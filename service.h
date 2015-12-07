#ifndef SERVICE_H
#define SERVICE_H

#include <iostream>
#include <string>
#include <unistd.h>
#include "workingclass.h"


using namespace std;

class service
{
public:
    service();
    //  Default constructor for class.
    int selection();
    //  Precondition:   A need for a selection is present.
    //  Postcondition:  Returns a integer corresponding to the selection made.
    void servAddscientist(scientist& s) ;

    void servAddcomputer(computer& c) ;

    void servAddcomputerType(computertype& ct) ;

    void editScientistService(int i); //(int selection, int scientist);
    //  Precondition:   A scientist is about to be edited.
    //  Postcondition:  The scientist has been edited and file updated.
    int yearCorrection(int year, bool &errorInYear);
    //  Precondition: Takes in an integer for the year correction process.
    //  Postcondition: Returns a corrected year.
    string nameCorrection(string name, bool& badName);
    //  Precondition:   A name has been entered into the parameter name.
    //  Postcondition:  Returns the corrected string and the badName variable is false
    //      if the name is ok, true otherwise.
    int genderCorrection(string gender);
    //  Precondition: Takes in a string for the gender correction process.
    //  Postcondition: Returns 0 if female, 1 if male, 2 otherwise.
    int yearCorrection(int year);
    //  Precondition:   Takes in the year as integer, in two or four digit format.
    //  Postcondition:  Returns the corrected year as integer.

    void servEraseScientistVector();
    //  Calls the eraseScientistVector function in workingclass.
    void servEraseComputerVector();
    //  Calls the eraseComputerVector function in workingclass.
    void servEraseCompTypeVector();
    //  Calls the eraseCompTypeVector function in workingclass.
    void servReadSqlScientists(string sorting="name");
    //  Calls the readSqlScientists function in workingclass.
    void servReadSqlComputers(string sorting="name");
    //  Calls the readSqlComputers function in workingclass.
    void servReadSqlCompTypes();
    //  Calls the readSqlCompTypes function in workingclass.
    vector<scientist> servGetSciVector();
    //  Calls the getVector function in workingclass.
    vector<computer> servGetComVector();
    //  Calls the getVector function in workingclass.
    vector<computertype> servGetComTypeVector();
    //  Calls the getComTypeVector function in workingclass.
    void servSortScientists(int choice);
    //  Precondition: Takes in an interger to select sorting.
    //  Postcondition: Reads scientists from database if selection is legal, returns to main menu otherwise.
    void servSortComputers(int choice);
    //  Precondition: Takes in an interger to select sorting.
    //  Postcondition: Reads computers from database if selection is legal, returns to main menu otherwise.
    void servSortAlph(vector<scientist>& v);
    //  Calls the sortAlph function in workingclass.
    void servSortRevAlph(vector<scientist>& v);
    //  Calls the sortRevAlph function in workingclass.
    void servSortYOB(vector<scientist>& v);
    //  Calls the sortYOB function in workingclass.
    void servSortYOD(vector<scientist>& v);
    //  Calls the sortYOD function in workingclass.
    void servAddScientistChange(string &name, string gender, int &yob, int &yod, string &desc, string &link, int &selectedGender);
    //  Calls the addScientistChange function in workingclass.
    bool servAddScientistCheck(string name, int gender, int yob, int yod, string desc, string link);
    //  Calls the addScientistCheck function in workingclass.
    bool servCreateRelationSciComp(int sciID, int compID);
    //  Calls the createRelationSciComp function in workingclass.
    void servVectorToFile(vector<scientist>& v, char AppOver) const;
    //  Calls the VectorToFile function in workingclass.
    void servSearchScientistByName(string subName, bool& isFound);
    //  Calls the searchByName function in workingclass.
    void servSearchScientistByGender(int sex, bool& isFound);
    //  Calls the searchByGender function in workingclass.
    void servSearchScientistByYear(int& yr, char bORd, bool& isFound);
    //  Calls the searchByYear function in workingclass.
    void servSearchComputerByName(string subName, bool& isFound);
    //  Calls the searchComputerByName function in workingclass.
    void servSearchComputerByType(string& type, bool& isFound);
    //  Calls the searchComputerByName function in workingclass.
    void servSearchComputerByYear(int& yr, bool& isFound);
    //  Calls the searchComputerByYear function in workingclass.
    void servPushToVector(const scientist& s);
    //  Calls the pushToVector function in workingclass.
    void servRemoveScientist(scientist& s);
    //  Calls the removeScientist function in workingclass.
    void servAddLineToFile(scientist& s, char AppOver) const;
    //  Calls the addLineToFile function in workingclass.
    void servStartDatabase();
    //  Calls the startDatabase function in workingclass.
    bool servCheckDatabaseExists();
    //  Calls the checkDatabaseExists function in workingclass.
    void servCreateEmptyDatabase();
    //  Calls the createEmptyDatabase function in workingclass.
    void servCloseDatabase();
    //  Calls the CloseDatabase function in workingclass.
    void servDeleteComputer(int compID);
    //  Calls the deleteComputer function in workingclass.
    void servDeleteScientist(int sciID);
    //  Calls the deleteScientist function in workingclass.
    void servDeleteComputerType(int computertypeID);
    //  Calls the deleteComputerType function in workingclass.
    void servUpdateSqlComputer(computer& c);
    //  Calls the updateScientist function in workingclass.
    void servUpdateSqlScientist(scientist& s);
    //  Calls the updateComputer function in workingclass.
    void servUpdateSqlComputerType(computertype& ct);
    //  Calls the updateComputerType function in workingclass.
    void henda();
    workingclass workingObject;
    // A object of the data layer class.  To be used in good computing :)
    vector<scientist> servGetScientistsLinkedToComputer(int compID);
    vector<computer> servGetComputersLinkedToScientists(int sciID);

};


#endif // SERVICE_H
