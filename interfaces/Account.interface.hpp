#ifndef ACCOUNT_INTERFACE_H
#define ACCOUNT_INTERFACE_H

using std::string;

class Account
{
private:
    string AccountNumber;
    double Balance;

public:
    Account()
    {
    }

    void SetAccountNumber(string accountNumber)
    {
        this->AccountNumber = accountNumber;
    }

    void SetAccountBalance(double balance)
    {
        this->Balance = balance;
    }

    string GetAccountNumber() const
    {
        return this->AccountNumber;
    }

    double GetAccountBalance() const
    {
        return this->Balance;
    }
};

class CurrentAccount : public Account
{
    double Limit;

public:
    CurrentAccount()
    {
    }
};

class SavingsAccount : public Account
{
    double InterestRate;

public:
    SavingsAccount()
    {
    }
};

#endif