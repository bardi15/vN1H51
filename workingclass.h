#ifndef WORKINGCLASS_H
#define WORKINGCLASS_H

//#include "infodisplay.h"
//#include "workingclass.h"
#include "scientist.h"
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const string WORKFILE = "Scientistinfo.txt";
const int MAXFIELDS = 6;
const int MAXNAMELENGTH = 30;
const int CURRENTYEAR = 2015;

class workingclass
{
public:
    workingclass();
    //  Default constructor for class.
    vector<scientist> getVector();
    //  Postcondition:  Returns the private vector.
    void setVector(vector<scientist>& v);
    //  Precondition:   The vecor v has been filled with scientist.
    //  Postcondition:  The private vector has been set with the new scientist.
    void selectAction(int sel);
    //  Precondition:
    //  Postcondition:
    void readFile();
    //  Precondition:   The file to be read in is located in the build folder of
    //      the program.
    //  Postcondition:  If file is available, it has been read into the private vector.
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
    void AddScientist();
    //  Precondition:   The option to add scientist has been selected on the main mainu.
    //  Postcondition:  One or more scientists have been added to the privat vector.
    string addScientistName(string &name);
    //  Precondition:   A name for a scientist is to be entered.
    //  Postcondition:  The name entered has been corrected or an error message has been
    //      displayed on screen.
    int addScientistGender(string &gender);
    //  Precondition:   The gender for a scientist is to be entered.
    //  Postcondition:  The gender has been corrected or an error message has been
    //      displayed on screen.
    int addScientistYearOfBirth();
    //  Precondition:   The year of birth for a scientist is to be entered.
    //  Postcondition:  The year of birth has been corrected or an error message has been
    //      displayed on screen.
    bool addScientistMore(int yob, int &yod, string &descr, string &link);
    //  Precondition:   The necessary data for a new scientist is to be entered.
    //  Postcondition:  If required the new scientist has the field for year of death,
    //      description and link have been populated.
    int addScientistYearOfDeath(int yob);
    //  Precondition:   The year of death for a scientist is to be entered.
    //  Postcondition:  The year of death has been corrected or an error message has been
    //      displayed on screen.
    string addScientistDescription(string &descr);
    //  Precondition:   The description for a scientist is to be entered.
    //  Postcondition:  The description for a scientist has been entered.
    string addScientistLink(string &link);
    //  Precondition:   The link for a scientist is to be entered.
    //  Postcondition:  The link for a scientist has been entered.
    bool addScientistCheck(string name, int gender, int yob, int yod, string desc, string link);
    //  Precondition:   All data for a new scientist has been entered.
    //  Postcondition:  If approved scientist is added to private vector, else modified.
    bool addScientistContinue();
    //  Precondition:   A new scientist has been entered into the vector and the user is
    //      asked if he wants to add more scientest.
    //  Postcondition:  Returns true if answered 'Y', false otherwise.
    void addScientistChange(string &name, string gender, int &yob, int &yod, string &desc, string &link, int &selectedGender);
    //  Precondition:   Data for a new scientist have been entered. Asks if any of the
    //      inserted data is to be changed.
    //  Postcondition:  Entered data for a new scientist has been corrected.
    void sortAlph(vector<scientist>& v);
    //  Precondition:   The vector v that is to be sorted is populated.
    //  Postcondition:  The vector is sorted in alphabetical order.
    void sortRevAlph(vector<scientist>& v);
    //  Precondition:   The vector v that is to be sorted is populated.
    //  Postcondition:  The vector is sorted in reversed alphabetical order.
    void sortYOB(vector<scientist>& v);
    //  Precondition:   The vector v that is to be sorted is populated.
    //  Postcondition:  The vector is sorted in chronological order by year of birth.
    void sortYOD(vector<scientist>& v);
    //  Precondition:   The vector v that is to be sorted is populated.
    //  Postcondition:  The vector is sorted in chronological order by year of birth.
    void removeScientist(scientist& s);
    //  Precondition:   A scientist to be removed has been selected.
    //  Postcondition:  The scientist has been removed from the text file.
    void eraseVector();
    //  Precondition:   A new or changed vector is about to be created.
    //  Postcondition:  The privat vector is clear of all scientists.
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
    vector<scientist> searchByName(string subName, bool& isFound);
    //  Precondition:   Takes in the parameter subName to be searched for and a boolean
    //      variable to indicate if found.
    //  Postcondition:  Returns a vector of the scientist matching the criteria.
    vector<scientist> searchByGender(string sex, bool& isFound);
    //  Precondition:   Takes in the parameter sex to be searched for and a boolean
    //      variable to indicate if found.
    //  Postcondition:  Returns a vector of the scientist matching the criteria.
    vector<scientist> searchByYear(int& yr, char bORd, bool& isFound);
    //  Precondition:   Takes in the parameter year to be searched for, a char indicating
    //      whether to look for the year of birth or year of death and a boolean
    //      variable to indicate if found.
    //  Postcondition:  Returns a vector of the scientist matching the criteria.
    int yearCorrection(int year, bool &errorInYear);
    //  Precondition: Takes in an integer for the year correction process.
    //  Postcondition: Returns a corrected year.
    int inputNumberToFunction();
    //  Precondition:   A number is about to be entered as an input
    //  Postcondition:  Returns a integer if correctly entered, or reiterate the input.
private:
    string scientistToString(scientist& s) const;
    //  Precondition:   Takes in a scientist s.
    //  Postcondition:  Returns a string ready to be written to file
    vector<scientist> scientistVector;
};

#endif // WORKINGCLASS_H

