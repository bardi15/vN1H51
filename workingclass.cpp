//#include "scientist.h"
//#include "infodisplay.h"
#include "workingclass.h"
#include <unistd.h>

workingclass::workingclass()
{

}
vector<scientist> workingclass::getVector()
{
    return scientistVector;
}
void workingclass::setVector(vector<scientist>& v)
{
    scientistVector = v;
}

QSqlDatabase workingclass::readFile()
{
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
   // QString dbName = "../vN1H51/Group51_verklegt_1.sqlite";
    QString dbName = "Group51_verklegt_1.sqlite";
        db.setDatabaseName(dbName);
    db.open();

    QSqlQuery query(db);

    query.exec("SELECT * FROM scientists");

    while(query.next())
    {

        int id = query.value("id").toUInt();
        string nam = query.value("name").toString().toStdString();
        nam.substr(0, 30);
        int gen = query.value("gender").toUInt();
        int yob = query.value("yob").toUInt();
        int yod = query.value("yod").toUInt();
        string desc = query.value("description").toString().toStdString();
        string url = query.value("link").toString().toStdString();

        scientist s(nam,gen,yob,yod,desc,url);
        scientistVector.push_back(s);
        }
    return db;
//    ifstream skra_inn;
//    skra_inn.open(WORKFILE.c_str());
//    if(skra_inn.fail())
//    {
//        cout << "error opening readFile file";
//        exit(1);
//    }
//    readLinesFromFile(skra_inn);
//    skra_inn.close();

}
void workingclass::VectorToFile(vector<scientist>& v, char AppOver) const
{
    for(unsigned int i = 0; i < v.size(); i++)
    {
        if(toupper(AppOver) == 'A')
        {
            addLineToFile(v.at(i), 'A');
        }
        else
        {

            if(i == 0)
            {
                addLineToFile(v.at(i), 'O');
            }
            else
            {
                addLineToFile(v.at(i), 'A');
            }
        }
    }
}

void workingclass::addLineToFile(scientist& s, char AppOver) const
{


    string outstring;
    ofstream file_out;
    if (toupper(AppOver) == 'A')
    {
        file_out.open(WORKFILE.c_str(), ios::app);
    }
    else if (toupper(AppOver) == 'O')
    {
        file_out.open(WORKFILE.c_str());
    }
    if(file_out.fail())
    {
        cout << "error opening addToFile file";
        exit(1);
    }
    cout << outstring << endl;
    file_out  << endl << s.getName() << ";" <<
                s.getGender() << ";" << s.getYearOfBirth() << ";" <<
                s.getYearOfDeath() << ";" << s.getDescription() << ";" <<
                s.getLink();
    file_out.close();

}

void workingclass::readLinesFromFile(ifstream& fileWithLines)
{
    while(!fileWithLines.eof())
    {
        int loc = 0;
        string next= "";
        char nextchar;
        fileWithLines.get(nextchar);
        while(!fileWithLines.eof() && nextchar != '\n')
        {
            next += nextchar;
            fileWithLines.get(nextchar);
        }
        if( next.size() > 3)
        {
            createScientist(next, loc);
        }

    }
}
void workingclass::pushToVector(const scientist& s)
{
    scientistVector.push_back(s);
}
void workingclass::eraseVector()
{
    scientistVector.clear();
}

void workingclass::createScientist(string& line, int& oldfind)
{
    string fieldtext;
    int currFind = oldfind;
    scientist s;
    int fieldno = 1;

    do
    {
        currFind = line.find(';',oldfind);
        fieldtext = line.substr(oldfind, (currFind-oldfind));
        fillScientist(fieldtext, s, fieldno);
        fieldno++;
        oldfind = currFind + 1;
    }
    while(fieldno <= 6);

    if(fieldno == MAXFIELDS+1)
    {
        pushToVector(s);
    }
}
void workingclass::removeScientist(scientist& s)
{
    readFile();
    for(unsigned int j = 0; j < scientistVector.size(); j++)
    {
        if(scientistVector[j].getName() == s.getName())
        {
            scientistVector.erase(scientistVector.begin() + j);

              ofstream newFile(WORKFILE.c_str());
              if(newFile.is_open())
              {
                  for(unsigned int i = 0; i < scientistVector.size(); i++)
                  {
                      if(i == 0)
                      {
                        addLineToFile(scientistVector[i], 'O');
                      }
                      else
                      {
                          addLineToFile(scientistVector[i], 'A');
                      }
                  }
              }else {
                  cout << "can't open file";
              }
              break;
        }
   }

}

void workingclass::fillScientist(const string& text, scientist& s, const int& field)
{
    switch (field)
    {
    case 1:
        s.setName(text);
        break;
    case 2:
        s.setGender(atoi(text.c_str()));
        break;
    case 3:
        s.setYearOfBirth(atoi(text.c_str()));
        break;
    case 4:
        s.setYearOfDeath(atoi(text.c_str()));
        break;
    case 5:
        s.setDescription(text);
        break;
    case 6:
        s.setLink(text);
        break;
    default:
        cout << "error" << endl << endl;
        break;
    }
}


vector<scientist> workingclass::searchByName(string subName, bool& isFound)
{
    vector<scientist> returnVector;
    scientist s;

    for(unsigned int i = 0; i < scientistVector.size(); i++)
    {
        string searchstring = scientistVector.at(i).getName();
        for (unsigned int j = 0; j < searchstring.size(); j++)
        {
            searchstring[j] = tolower(searchstring[j]);
        }
        for (unsigned int j = 0; j < subName.size(); j++)
        {
            subName[j] = tolower(subName[j]);
        }

        //  Kemur einhver furðuleg villa þegar reynt er að breyta í lovercase :(
        if( searchstring.find( subName) < 30 )
       {
            s = scientistVector.at(i);
            returnVector.push_back(s);
            isFound = true;
       }
    }
    return returnVector;
}
vector<scientist> workingclass::searchByGender(int sex, bool& isFound)
{
    vector<scientist> tempReturn;
    scientist s;


    for(unsigned int i = 0; i < scientistVector.size(); i++)
    {
        if(scientistVector.at(i).getGender() == sex)
       {
            s = scientistVector.at(i);
            tempReturn.push_back(s);
            isFound = true;
       }
    }
    return tempReturn;
}
vector<scientist> workingclass::searchByYear(int& yr, char bORd, bool& isFound)
{
    vector<scientist> tempReturn;
    scientist s;
    bool error = false;
    if (error)
    {
        tempReturn.resize(0);
        return tempReturn;
    }
    for(unsigned int i = 0; i < scientistVector.size(); i++)
    {
        if(bORd == 'b')
        {
           if(scientistVector.at(i).getYearOfBirth() == yr)
           {
               s = scientistVector.at(i);
               tempReturn.push_back(s);
               isFound = true;
           }
        }
        else if(scientistVector.at(i).getYearOfDeath() == yr)
        {
            s = scientistVector.at(i);
            tempReturn.push_back(s);
            isFound = true;
        }
    }
    return tempReturn;
}
bool AlphComp(scientist a, scientist b)
{
    return a.getName() < b.getName();

}
bool RevAlphComp(scientist a, scientist b)
{
    return a.getName() > b.getName();

}
bool DB_Comp(scientist a, scientist b)
{
    return a.getYearOfBirth() > b.getYearOfBirth();
}
bool DD_Comp(scientist a, scientist b)
{
    return a.getYearOfDeath() > b.getYearOfDeath();
}
void workingclass::sortAlph(vector<scientist>& v)
{

    sort(v.begin(), v.end(), AlphComp);
}
void workingclass::sortRevAlph(vector<scientist>& v)
{
    sort(v.begin(), v.end(), RevAlphComp);
}
void workingclass::sortYOB(vector<scientist>& v)
{
   sort(v.begin(), v.end(), DB_Comp);
}
void workingclass::sortYOD(vector<scientist>& v)
{
    sort(v.begin(), v.end(), DD_Comp);
}



