#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H

#include <fstream>
#include "Worker.interface.hpp"

struct Contact
{
    string Address;
    string PhoneNumber;
};

struct IUser
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
    string accountNumber;
    string savingsAccountNumber;
    string savingsAccountCardNumber;
    string accountCardNumber;
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
    CurrentAccount BankAccount;
    SavingsAccount BankSavingsAccount;
    Worker WorkData;

public:
    User(IUser props = {})
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

        this->BankAccount.SetAccountNumber(props.accountNumber);
        this->BankAccount.SetCardNumber(props.accountCardNumber);
        this->BankAccount.SetAccountBalance(0.0);

        this->BankSavingsAccount.SetAccountNumber(props.savingsAccountNumber);
        this->BankSavingsAccount.SetCardNumber(props.savingsAccountCardNumber);
        this->BankSavingsAccount.SetAccountBalance(0.0);

        this->WorkData.SetWorkerPosition("Unemployed");
        this->WorkData.SetWorkerSalary(0);
    }

    string GetFullName()
    {
        return this->Name + " " + this->Surname;
    }

    string GetName() const
    {
        return (Name.empty() || Name == "undefined") ? "undefined" : Name;
    }

    string GetEmail() const
    {
        return this->Email;
    }

    bool CheckPassword(string password)
    {
        return password == this->Password ? true : false;
    }

    void Serialize(std::ostream &outFile) const;
    void Deserialize(std::istream &inFile);

    string GetAccountNumber() const
    {
        return BankAccount.GetAccountNumber();
    }

    double GetAccountBalance()
    {
        return BankAccount.GetCardBalance();
    }
};

void User::Serialize(std::ostream &outFile) const
{
    outFile << Name << '|'
            << Surname << '|'
            << JMBG << '|'
            << Email << '|'
            << Password << '|'
            << Gender << '|'
            << BirthDate << '|'
            << ContactInfo.Address << '|'
            << ContactInfo.PhoneNumber << "|"
            << BankAccount.GetAccountNumber() << "|"
            << BankAccount.GetCardNumber() << "|"
            << BankAccount.GetCardBalance() << "|"
            << BankSavingsAccount.GetAccountNumber() << "|"
            << BankSavingsAccount.GetCardNumber() << "|"
            << BankSavingsAccount.GetCardBalance() << "|"
            << WorkData.GetWorkerPosition() << "|"
            << WorkData.GetWorkerSalary() << "|\n";
}

void User::Deserialize(std::istream &inFile)
{
    std::getline(inFile, Name, '|');
    std::getline(inFile, Surname, '|');
    std::getline(inFile, JMBG, '|');
    std::getline(inFile, Email, '|');
    std::getline(inFile, Password, '|');
    std::getline(inFile, Gender, '|');
    std::getline(inFile, BirthDate, '|');
    std::getline(inFile, ContactInfo.Address, '|');
    std::getline(inFile, ContactInfo.PhoneNumber, '|');

    std::string accountNumber,
        accountBalance,
        position,
        salary,
        savingsAccountNumber,
        savingsAccountBalance,
        accountCardNumber,
        savingsAccountCardNumber;
    std::getline(inFile, accountNumber, '|');
    std::getline(inFile, accountCardNumber, '|');
    std::getline(inFile, accountBalance, '|');

    std::getline(inFile, savingsAccountNumber, '|');
    std::getline(inFile, savingsAccountCardNumber, '|');
    std::getline(inFile, savingsAccountBalance, '|');

    std::getline(inFile, position, '|');
    std::getline(inFile, salary, '|');

    try
    {
        BankAccount.SetAccountNumber(accountNumber);
        BankAccount.SetCardNumber(accountCardNumber);
        BankAccount.SetAccountBalance(std::stod(accountBalance));

        BankSavingsAccount.SetAccountNumber(savingsAccountNumber);
        BankSavingsAccount.SetCardNumber(savingsAccountCardNumber);
        BankSavingsAccount.SetAccountBalance(std::stod(savingsAccountBalance));

        WorkData.SetWorkerPosition(position);
        WorkData.SetWorkerSalary(std::stod(salary));
    }
    catch (const std::invalid_argument &e)
    {
    }

    inFile.ignore(10000, '\n');
}

#endif