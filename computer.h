#ifndef COMPUTER_H
#define COMPUTER_H
#include <string>

using namespace std;

class computer
{
    public:
        computer();
        computer( int cid, string cname, int cyear, int ctype, bool cbuilt, string cdescription);
        computer(string cName, int cYear, int cType, bool cBuilt, string cDescr);
        int getId() const;
        //  Returns the id of the computer.
        string getComName() const;
        int getComYear() const;
        int getComType() const;
        string getComDescription() const;
        bool getComBuilt() const;
        void setComName(string coName);
        void setComYear(int coYear);
        void setComType(int coType);
        void setComDescription(string coDesc);
        void setComBuilt(bool coBuilt);


    private:
        int comId;
        string comName;
        int comYear;
        int comType;
        bool comBuilt;
        string comDescr;
};

#endif // COMPUTER_H
