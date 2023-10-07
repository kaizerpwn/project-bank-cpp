#ifndef ACCOUNT_INTERFACE_H
#define ACCOUNT_INTERFACE_H

#include <iostream>
using namespace std;

class Account
{
private:
    string AccountNumber;
    double Balance;

public:
    Account()
    {
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