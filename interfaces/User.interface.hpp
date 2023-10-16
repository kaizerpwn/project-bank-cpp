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

public:
    CurrentAccount BankAccount;
    SavingsAccount BankSavingsAccount;
    Worker WorkData;
    Credit CreditData;

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

        this->CreditData.SetCreditAmount(0);
        this->CreditData.SetCreditInterestRate(0);
        this->CreditData.SetCreditMonths(0);
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

    double GetAccountLimit()
    {
        return BankAccount.GetAccountLimit();
    }

    static std::vector<User> GetAllUsers()
    {
        std::vector<User> users;

        std::ifstream database("database/data/users.dat", std::ios::binary | std::ios::in);

        if (!database.is_open())
        {
            return users;
        }

        User user;
        while (true)
        {
            user.Deserialize(database);
            if (!database)
            {
                break;
            }
            users.push_back(user);
        }

        database.close();
        return users;
    }

    static void SaveUsers(const std::vector<User> &users)
    {
        std::ofstream database("database/data/users.dat", std::ios::binary | std::ios::out | std::ios::trunc);

        if (!database.is_open())
        {
            return;
        }

        for (const auto &user : users)
        {
            user.Serialize(database);
        }

        database.close();
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
            << WorkData.GetWorkerSalary() << "|"
            << CreditData.GetCreditAmount() << "|"
            << CreditData.GetCreditMonths() << "|"
            << CreditData.GetCreditInterestRate() << "|\n";
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
        savingsAccountCardNumber,
        creditAmount,
        creditMonths,
        creditInterestRate;
    std::getline(inFile, accountNumber, '|');
    std::getline(inFile, accountCardNumber, '|');
    std::getline(inFile, accountBalance, '|');

    std::getline(inFile, savingsAccountNumber, '|');
    std::getline(inFile, savingsAccountCardNumber, '|');
    std::getline(inFile, savingsAccountBalance, '|');

    std::getline(inFile, position, '|');
    std::getline(inFile, salary, '|');

    std::getline(inFile, creditAmount, '|');
    std::getline(inFile, creditMonths, '|');
    std::getline(inFile, creditInterestRate, '|');

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

        CreditData.SetCreditAmount(std::stod(creditAmount));
        CreditData.SetCreditMonths(std::stoi(creditMonths));
        CreditData.SetCreditInterestRate(std::stod(creditInterestRate));
    }
    catch (const std::invalid_argument &e)
    {
    }

    inFile.ignore(10000, '\n');
}

#endif