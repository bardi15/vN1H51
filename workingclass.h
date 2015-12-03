#ifndef WORKINGCLASS_H
#define WORKINGCLASS_H

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
private:

    vector<scientist> scientistVector;
};

#endif // WORKINGCLASS_H

