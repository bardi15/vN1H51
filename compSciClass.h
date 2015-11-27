#ifndef COMPSCICLASS_H
#define COMPSCICLASS_H
#include <iostream>
#include <string>

using namespace std;

class compsciclass
{
    public:
        compsciclass();
        // Precondition:    An instance of the class has been created.
        // Postcondition:   Initialises all string variablaes with a space, integer and boolean variables as 0.
        compsciclass(string name, bool sex, int yoBirth,int yoDeath, string desc, string link);
        // Precondition:    All variables have been set with leagal values.
        // Postcondition:   Initialises all variables according to parameters.
        string getName() const;
        // Precondition:    The class has been initialised with a legal name.
        // Postcondition:   Returns a string with the name of the famous scientist.
        bool getgender() const;
        // Precondition:    The class has been initialised with a legal gender.
        // Postcondition:   Returns 0 for female and 1 for male.
        int getYearOfBirth() const;
        // Precondition:    The class has been initialised with a legal year of birth.
        // Postcondition:   Returns a integer with the year of birth.
        int getYearOfDeath() const;
        // Precondition:    The class has been initialised with a legal year of death.
        // Postcondition:   Returns a integer with the year of death.
        string getDescription() const;
        // Precondition:    The class has been initialised with a legal description.
        // Postcondition:   Returns a string with the description.
        string getLink() const;
        // Precondition:    The class has been initialised with a legal link.
        // Postcondition:   Returns a string with a link.

        void setName(string name);
        // Precondition:    The parameter is of a legal type and value.
        // Postcondition:   The name has been set to the parameter name.
        void setgender(bool sex);
        // Precondition:    The parameter is of a legal type and value.
        // Postcondition:   The gender has been set to the parameter sex.
        void setYearOfBirth(int birthYear);
        // Precondition:    The parameter is of a legal type and value.
        // Postcondition:   The YearOfBirth has been set to parameter birthYear.
        void setYearOfDeath(int deathYear);
        // Precondition:    The parameter is of a legal type and value.
        // Postcondition:   The YearOfDeath has been set to parameter deathYear.
        void setDescription(string desc);
        // Precondition:    The parameter is of a legal type and value.
        // Postcondition:   The description has been set to parameter desc.
        void setLink(string url);
        // Precondition:    The parameter is of a legal type and value.
        // Postcondition:   The link has been set to parameter url.

    private:
        string name;
        bool gender;
        int yearOfBirth;
        int yearOfDeath;
        string description;
        string link;
};

#endif // COMPSCICLASS_H
