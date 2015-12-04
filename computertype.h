#ifndef COMPUTERTYPE_H
#define COMPUTERTYPE_H
#include <string>

using namespace  std;


class computertype
{
public:
    computertype();
    computertype(int ctId, string ctName, string ctDesc);
    computertype(string ctName, string ctDesc);
    int getid();
    string getName();
    string getDesc();
private:
    int id;
    string name;
    string desc;

};

#endif // COMPUTERTYPE_H
