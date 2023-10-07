#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H

struct Contact
{
    string Address;
    string PhoneNumber;
};

class User
{
private:
    string Name;
    string Surname;
    string JMBG;
    string Gender;
    string BirthDate;
    Contact ContactInfo;

public:
    User(string name, string surname, string jmbg, string address, string phoneNumber)
    {
        this->Name = name;
        this->Surname = surname;
        this->JMBG = jmbg;
        this->ContactInfo.Address = address;
        this->ContactInfo.PhoneNumber = phoneNumber;
    }

    string GetFullName()
    {
        return this->Name + " " + this->Surname;
    }

    string GetName()
    {
        return this->Name;
    }
};

#endif