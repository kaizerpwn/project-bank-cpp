#ifndef ACCOUNT_INTERFACE_H
#define ACCOUNT_INTERFACE_H

class Account
{
private:
    string AccountNumber;
    string CardNumber;
    double Balance;

public:
    Account()
    {
        this->AccountNumber = "N/A";
        this->CardNumber = "N/A";
        this->Balance = 0;
    }

    void SetAccountNumber(string accountNumber)
    {
        this->AccountNumber = accountNumber;
    }

    void SetCardNumber(string cardNumber)
    {
        this->CardNumber = cardNumber;
    }

    void SetAccountBalance(double balance)
    {
        this->Balance = balance;
    }

    string GetAccountNumber() const
    {
        return this->AccountNumber;
    }

    string GetCardNumber() const
    {
        return this->CardNumber;
    }

    double GetCardBalance() const
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
        this->Limit = 10000;
    }

    void SetAccountLimit(double limit)
    {
        this->Limit = limit;
    }

    double GetAccountLimit() const
    {
        return this->Limit;
    }
};

class SavingsAccount : public Account
{
    double InterestRate;

public:
    SavingsAccount()
    {
        this->InterestRate = 10;
    }

    void SetInterestRate(double interestRate)
    {
        this->InterestRate = interestRate;
    }

    double GetInterestRate() const
    {
        return this->InterestRate;
    }
};

#endif