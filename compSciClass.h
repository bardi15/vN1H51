#ifndef COMPSCICLASS_H
#define COMPSCICLASS_H
#include <iostream>
#include <string>

using namespace std;

class compSciClass
{
    public:
        compSciClass();
        void getName();
        void getgender();
        void getYearOfBirth();
        void getYearOfDeath();
        void getDescription();
        void getLink();

        void setName();
        void setgender();
        void setYearOfBirth();
        void setYearOfDeath();
        void setDescription();
        void setLink();

    private:
        string name;
        string gender;
        int yearOfBirth;
        int yearOfDeath;
        string description;
        string link;
};

#endif // COMPSCICLASS_H
