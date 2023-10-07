#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H

struct Contact
{
    string Address;
    string PhoneNumber;
};

struct UserConstructorInterface
{
    string name;
    string surname;
    string jmbg;
    string address;
    string phoneNumber;
    string email;
    string gender;
    string birthDate;
    string password;
};

class User
{
private:
    string Name;
    string Surname;
    string JMBG;
    string Email;
    string Password;
    string Gender;
    string BirthDate;
    Contact ContactInfo;

public:
    // >> Default constructor
    User()
    {
        this->Name = "undefined";
    }

    // >> Constructor with parameters
    User(UserConstructorInterface props)
    {
        this->Name = props.name;
        this->Surname = props.surname;
        this->JMBG = props.jmbg;
        this->ContactInfo.Address = props.address;
        this->ContactInfo.PhoneNumber = props.phoneNumber;
        this->Email = props.email;
        this->Password = props.password;
        this->BirthDate = props.birthDate;
        this->Gender = props.gender;
    }

    string GetFullName()
    {
        return this->Name + " " + this->Surname;
    }

    string GetName()
    {
        return this->Name;
    }

    string GetEmail()
    {
        return this->Email;
    }

    bool CheckPassword(string password)
    {
        return password == this->Password ? true : false;
    }
};

#endif