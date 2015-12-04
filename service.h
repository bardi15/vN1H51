#ifndef SERVICE_H
#define SERVICE_H

#include <iostream>
#include <string>
//#include "infodisplay.h"
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
    bool servAddscientist(string nafn, int sex, int yob, int yod, string desc, string link);

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

    void servEraseVector();
    //  Calls the EraseVector function in workingclass.
    void servReadSqlScientists();
    //  Calls the readSqlScientists function in workingclass.
    vector<scientist> servGetVector();
    //  Calls the getVector function in workingclass.
    void servSortScientists(int choice);

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
    void servVectorToFile(vector<scientist>& v, char AppOver) const;
    //  Calls the VectorToFile function in workingclass.
    vector<scientist> servSearchByName(string subName, bool& isFound);
    //  Calls the searchByName function in workingclass.
    vector<scientist> servSearchByGender(int sex, bool& isFound);
    //  Calls the searchByGender function in workingclass.
    vector<scientist> servSearchByYear(int& yr, char bORd, bool& isFound);
    //  Calls the searchByYear function in workingclass.
    void servPushToVector(const scientist& s);
    //  Calls the pushToVector function in workingclass.
    void servRemoveScientist(scientist& s);
    //  Calls the removeScientist function in workingclass.
    void servAddLineToFile(scientist& s, char AppOver) const;
    //  Calls the addLineToFile function in workingclass.
    void servStartDatabase();
    //  Calls the startDatabase function in workingclass.
    void servCloseDatabase();
    //  Calls the CloseDatabase function in workingclass.
    workingclass workingObject;
    // A object of the data layer class.  To be used in good computing :)

};

#endif // SERVICE_H
