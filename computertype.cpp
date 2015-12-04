#include "computertype.h"

computertype::computertype()
{

}
computertype::computertype(int ctId, string ctName, string ctDesc)
{
    id = ctId;
    name = ctName;
    desc = ctDesc;
}

computertype::computertype(string ctName, string ctDesc)
{
    name = ctName;
    desc = ctDesc;
}
int computertype::getid()
{
    return id;
}
string computertype::getName()
{
    return name;
}
string computertype::getDesc()
{
    return desc;
}
