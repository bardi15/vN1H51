#include "workingclass.h"
#include <unistd.h>

workingclass::workingclass()
{

}
vector<scientist> workingclass::getSciVector()
{
    return scientistVector;
}
vector<computer> workingclass::getComVector()
{
    return computerVector;
}
vector<computertype> workingclass::getComTypeVector()
{
    return compTypeVector;
}


void workingclass::setVector(vector<scientist>& v)
{
    scientistVector = v;
}

QSqlDatabase workingclass::startDatabase()
{
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = "Group51_verklegt_1.sqlite";
    db.setDatabaseName(dbName);
    db.open();
    return db;
}
void workingclass::closeDatabase()
{
    QSqlDatabase db;
    db.close();
}

void workingclass::readSqlScientists(string sorting)
{
    //QSqlDatabase db;
    //db.open();

    QSqlQuery query;//(db);

    query.prepare("SELECT * FROM scientists "
                  "WHERE deleted = 'FALSE'"
                  "ORDER BY " + QString::fromStdString(sorting));
    query.exec();
//    string s =  query.executedQuery().toStdString();

//    cout << s << endl;
//    sleep(1);


   while(query.next())
    {


        int id = query.value("id").toUInt();
        string nam = query.value("name").toString().toStdString();
        int gen = query.value("gender").toUInt();
        int yob = query.value("yob").toUInt();
        int yod = query.value("yod").toUInt();
        string desc = query.value("description").toString().toStdString();
        string url = query.value("link").toString().toStdString();

        scientist s(id,nam,gen,yob,yod,desc,url);
        scientistVector.push_back(s);
//        cout << nam << " " << s.getName() << endl;
//        usleep(50000);
    }
    //return db;

}
void workingclass::updateSqlComputer(computer& c)
{
    QSqlQuery query;

    query.prepare("UPDATE computers "
                  "SET name = :name, year = :year, type = :type, built = :built, "
                  "description = :desc"
                  "WHERE id = :id");
    query.bindValue(":id", c.getId());
    query.bindValue(":name", QString::fromStdString(c.getComName()));
    query.bindValue(":year", c.getComYear());
    query.bindValue(":type", c.getComType());
    query.bindValue(":built", c.getComBuilt());
    query.bindValue(":desc", QString::fromStdString(c.getComDescription()));
    query.exec();
//    string qstr;
//    qstr = query.lastQuery().toStdString();
//    cout << qstr << endl;
//    sleep(3);
}
void workingclass::updateSqlScientist(scientist& s)
{
    QSqlQuery query;

    query.prepare("UPDATE scientists "
                  "SET name = :name, gender = :gender, yob = :yob, yod = :yod,"
                  "description = :desc, link = :link"
                  "WHERE id = :id");
    query.bindValue(":id", s.getID());
    query.bindValue(":name", QString::fromStdString(s.getName()));
    query.bindValue(":gender", s.getGender());
    query.bindValue(":yob", s.getYearOfBirth());
    query.bindValue(":yod", s.getYearOfDeath());
    query.bindValue(":desc", QString::fromStdString(s.getDescription()));
    query.bindValue(":link", QString::fromStdString(s.getLink()));
    query.exec();
//    string str;
//    str = query.lastQuery().toStdString();
//    cout << str << endl;
//    sleep(3);
}

vector<computer> workingclass::getComputersLinkedToScientists(int sciID)
{
    QSqlQuery query;

    query.prepare("SELECT c.* FROM computers c "
                  "INNER JOIN scientists_and_computers sc "
                  "ON  c.id = sc.computer_id "
                  "WHERE sc.scientist_id = :sid AND "
                  "sc.deleted ='FALSE';");
    query.bindValue(":sid", sciID );
    query.exec();

    vector<computer> tempvector;
    while(query.next())
    {
        computer c;
        c.setComID(query.value("id").toUInt());
        c.setComName(query.value("name").toString().toStdString());
        c.setComYear(query.value("year").toUInt());
        c.setComType(query.value("type").toUInt());
        c.setComBuilt(query.value("built").toUInt());
        c.setComDescription(query.value("description").toString().toStdString());
        tempvector.push_back(c);
    }

    return tempvector;
}
vector<scientist> workingclass::getScientistsLinkedToComputer(int compID)
{
    QSqlQuery query;

    query.prepare("SELECT s.* FROM scientists s "
                  "INNER JOIN scientists_and_computers sc "
                  "ON  s.id = sc.scientist_id "
                  "WHERE sc.computer_id = :cid AND "
                  "sc.deleted = 'FALSE';");
    query.bindValue(":cid", compID );
    query.exec();

    vector<scientist> tempvector;
    while(query.next())
    {
        scientist s;
        s.setID(query.value("id").toUInt());
        s.setName(query.value("name").toString().toStdString());
        s.setGender(query.value("gender").toUInt());
        s.setYearOfBirth(query.value("yob").toUInt());
        s.setYearOfDeath(query.value("yod").toUInt());
        s.setDescription(query.value("description").toString().toStdString());
        s.setLink(query.value("link").toString().toStdString());
        tempvector.push_back(s);
    }

    return tempvector;
}
void workingclass::readSqlComputers(string sorting)
{
    computer c;
    QSqlQuery query;

    query.prepare("SELECT * FROM computers "
                  "WHERE deleted = 'FALSE'"
                  "ORDER BY " + QString::fromStdString(sorting));
    query.exec();
    while(query.next())
    {
        computer c;
        c.setComID(query.value("id").toUInt());
        c.setComName(query.value("name").toString().toStdString());
        c.setComYear(query.value("year").toUInt());
        c.setComType(query.value("type").toUInt());
        c.setComBuilt(query.value("built").toUInt());
        c.setComDescription(query.value("description").toString().toStdString());
        computerVector.push_back(c);
        }
}
void workingclass::readSqlCompTypes()
{
    QSqlQuery query;

    query.prepare("SELECT * FROM computer_types "
                  "WHERE deleted = 'FALSE'"
                  "ORDER BY name ASC");
    query.exec();
    while(query.next())
    {
        computertype ct;
        int tid = query.value("id").toUInt();
        ct.setID(tid);
        ct.setName(query.value("name").toString().toStdString());
        ct.setDesc(query.value("description").toString().toStdString());
        compTypeVector.push_back(ct);
    }
}

bool workingclass::addscientist(scientist& s)
{
    QSqlQuery query;

    query.prepare("INSERT INTO scientists (name, gender, yob, yod, description, link) "
                  "VALUES (:name, :sex, :yob, :yod, :desc, :link);");

    query.bindValue(":name", QString::fromStdString(s.getName()));
    query.bindValue(":sex", s.getGender());
    query.bindValue(":yob", s.getYearOfBirth());
    query.bindValue(":yod", s.getYearOfDeath());
    query.bindValue(":desc", QString::fromStdString(s.getDescription()));
    query.bindValue(":link", QString::fromStdString(s.getLink()));
    query.exec();
    s.setID(query.lastInsertId().toUInt());
    return 1;
}

bool workingclass::addcomputer(computer& c)
{
    QSqlQuery query;
    query.prepare("INSERT INTO computers (name, year, type, built, description )"
                  "VALUES (:name, :year, :type, :built, :desc);");
    query.bindValue(":name", QString::fromStdString(c.getComName()));
    query.bindValue(":year", c.getComYear());
    query.bindValue(":type", c.getComType());
    query.bindValue(":built", c.getComBuilt());
    query.bindValue(":desc", QString::fromStdString(c.getComDescription()));
    query.exec();
    c.setComID(query.lastInsertId().toUInt());
    return 1;
}
bool workingclass::addcomputerType(computertype & ct)
{
    QSqlQuery query;
    query.prepare("INSERT INTO computers_and_scientists (name, description) "
                  "VALUES (:name, :desc);");
    query.bindValue(":name", QString::fromStdString(ct.getName()));
    query.bindValue(":desc", QString::fromStdString(ct.getDesc()));
    query.exec();
    ct.setID(query.lastInsertId().toUInt());

    return 1;
}
void workingclass::deleteScientist(int sciID)
{
    QSqlQuery query;

    query.prepare("UPDATE scientists "
                  "SET deleted = 'TRUE'"
                  "WHERE id = :id");
    query.bindValue(":id", sciID);
    query.exec();
}
void workingclass::deleteComputer(int compID)
{
    QSqlQuery query;

    query.prepare("UPDATE computers "
                  "SET deleted = 'TRUE'"
                  "WHERE id = :id");
    query.bindValue(":id", compID);
    query.exec();
}



void workingclass::pushToVector(const scientist& s)
{
    scientistVector.push_back(s);
}
void workingclass::eraseScientistVector()
{
    scientistVector.clear();
}
void workingclass::eraseComputerVector()
{
    computerVector.clear();
}
void workingclass::eraseCompTypeVector()
{
    compTypeVector.clear();
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
//bool AlphComp(scientist a, scientist b)
//{
//    return a.getName() < b.getName();

//}
//bool RevAlphComp(scientist a, scientist b)
//{
//    return a.getName() > b.getName();

//}
//bool DB_Comp(scientist a, scientist b)
//{
//    return a.getYearOfBirth() > b.getYearOfBirth();
//}
//bool DD_Comp(scientist a, scientist b)
//{
//    return a.getYearOfDeath() > b.getYearOfDeath();
//}
//void workingclass::sortAlph(vector<scientist>& v)
//{

//    sort(v.begin(), v.end(), AlphComp);
//}
//void workingclass::sortRevAlph(vector<scientist>& v)
//{
//    sort(v.begin(), v.end(), RevAlphComp);
//}
//void workingclass::sortYOB(vector<scientist>& v)
//{
//   sort(v.begin(), v.end(), DB_Comp);
//}
//void workingclass::sortYOD(vector<scientist>& v)
//{
//    sort(v.begin(), v.end(), DD_Comp);
//}
//  VectorToFile er ekki notað í SQL verkefninu.
//void workingclass::VectorToFile(vector<scientist>& v, char AppOver) const
//{
//    for(unsigned int i = 0; i < v.size(); i++)
//    {
//        if(toupper(AppOver) == 'A')
//        {
//            addLineToFile(v.at(i), 'A');
//        }
//        else
//        {

//            if(i == 0)
//            {
//                addLineToFile(v.at(i), 'O');
//            }
//            else
//            {
//                addLineToFile(v.at(i), 'A');
//            }
//        }
//    }
//}

//void workingclass::addLineToFile(scientist& s, char AppOver) const
//{


//    string outstring;
//    ofstream file_out;
//    if (toupper(AppOver) == 'A')
//    {
//        file_out.open(WORKFILE.c_str(), ios::app);
//    }
//    else if (toupper(AppOver) == 'O')
//    {
//        file_out.open(WORKFILE.c_str());
//    }
//    if(file_out.fail())
//    {
//        cout << "error opening addToFile file";
//        exit(1);
//    }
//    cout << outstring << endl;
//    file_out  << endl << s.getName() << ";" <<
//                s.getGender() << ";" << s.getYearOfBirth() << ";" <<
//                s.getYearOfDeath() << ";" << s.getDescription() << ";" <<
//                s.getLink();
//    file_out.close();

//}

//void workingclass::readLinesFromFile(ifstream& fileWithLines)
//{
//    while(!fileWithLines.eof())
//    {
//        int loc = 0;
//        string next= "";
//        char nextchar;
//        fileWithLines.get(nextchar);
//        while(!fileWithLines.eof() && nextchar != '\n')
//        {
//            next += nextchar;
//            fileWithLines.get(nextchar);
//        }
//        if( next.size() > 3)
//        {
//            createScientist(next, loc);
//        }

//    }
//}
//void workingclass::removeScientist(scientist& s)
//{
//    readSqlScientists();
//    for(unsigned int j = 0; j < scientistVector.size(); j++)
//    {
//        if(scientistVector[j].getName() == s.getName())
//        {
//            scientistVector.erase(scientistVector.begin() + j);

//              ofstream newFile(WORKFILE.c_str());
//              if(newFile.is_open())
//              {
//                  for(unsigned int i = 0; i < scientistVector.size(); i++)
//                  {
//                      if(i == 0)
//                      {
//                        addLineToFile(scientistVector[i], 'O');
//                      }
//                      else
//                      {
//                          addLineToFile(scientistVector[i], 'A');
//                      }
//                  }
//              }else {
//                  cout << "can't open file";
//              }
//              break;
//        }
//   }

//}



