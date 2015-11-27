#ifndef COMPSCICLASS_H
#define COMPSCICLASS_H
#include <iostream>
#include <string>

using namespace std;

class compsciclass
{
    public:
        compsciclass();
        string getName();
        bool getgender();
        int getYearOfBirth();
        int getYearOfDeath();
        string getDescription();
        string getLink();

        void setName();
        void setgender();
        void setYearOfBirth();
        void setYearOfDeath();
        void setDescription();
        void setLink();

    private:
        string name;
        bool gender;
        int yearOfBirth;
        int yearOfDeath;
        string description;
        string link;
};

#endif // COMPSCICLASS_H
