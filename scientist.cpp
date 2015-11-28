#include "scientist.h"

scientist::scientist()
{
    name = "";
    gender = 0;
    yearOfBirth=0;
    yearOfDeath=0;
    description = "";
    link = "";
}
scientist::scientist(string name, bool sex, int yoBirth,int yoDeath, string desc, string link)
{
    name = name;
    gender = sex;
    yearOfBirth = yoBirth;
    yearOfDeath = yoDeath;
    description = desc;
    link = link;
}



string scientist::getName() const
{
    return name;
}

bool scientist::getGender() const
{
    return gender;
}
int scientist::getYearOfBirth() const
{
    return yearOfBirth;
}
int scientist::getYearOfDeath() const
{
    return yearOfDeath;
}
string scientist::getDescription() const
{
    return description;
}
string scientist::getLink() const
{
    return link;
}

void scientist::setName(string name)
{
    name = name;
}

void scientist::setGender(bool sex)
{
    gender = sex;
}

void scientist::setYearOfBirth(int birthYear)
{
    yearOfBirth = birthYear;
}

void scientist::setYearOfDeath(int deathYear)
{
    yearOfDeath = deathYear;
}

void scientist::setDescription(string desc)
{
    description = desc;
}

void scientist::setLink(string url)
{
    link = url;
}
