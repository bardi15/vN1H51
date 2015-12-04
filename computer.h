#ifndef COMPUTER_H
#define COMPUTER_H


class computer
{
public:
    computer();
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
    int id;
    string name;
    int year;
    int type;
    bool built;
    string description;
};

#endif // COMPUTER_H
