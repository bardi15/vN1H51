#include "compsciclass.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

compsciclass::compsciclass()
{
    name = "";
    gender = 0;
    yearOfBirth=0;
    yearOfDeath=0;
    description = "";
    link = "";
}
compsciclass::compsciclass(string name, bool sex, int yoBirth,int yoDeath, string desc, string link)
{
    name = name;
    gender = sex;
    yearOfBirth = yoBirth;
    yearOfDeath = yoDeath;
    description = desc;
    link = link;
}



string compsciclass::getName() const
{
    return name;
}

bool compsciclass::getgender() const
{
    return gender;
}
int compsciclass::getYearOfBirth() const
{
    return yearOfBirth;
}
int compsciclass::getYearOfDeath() const
{
    return yearOfDeath;
}
string compsciclass::getDescription() const
{
    return description;
}
string compsciclass::getLink() const
{
    return link;
}

void compsciclass::setName(string name)
{
    name = name;
}

void compsciclass::setgender(bool sex)
{
    gender = sex;
}

void compsciclass::setYearOfBirth(int birthYear)
{
    yearOfBirth = birthYear;
}

void compsciclass::setYearOfDeath(int deathYear)
{
    yearOfDeath = deathYear;
}

void compsciclass::setDescription(string desc)
{
    description = desc;
}

void compsciclass::setLink(string url)
{
    link = url;
}
