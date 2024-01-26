#ifndef PERSONTYPE_H
#define PERSONTYPE_H

class PersonType
{
private:
    string firstName;
    string lastName;

public:
    // kişilerin adı ve soyadı setlenip alınır
    string getName()
    {
        return firstName;
    }
    void setName(string ad)
    {
        firstName = ad;
    }
    string getLastName()
    {
        return lastName;
    }
    void setLastName(string soyad)
    {
        lastName = soyad;
    }
};

#endif