#ifndef LOAN_INTERFACE_H
#define LOAN_INTERFACE_H

struct ICredit
{
    double amount;
    int months;
    double interestRate;
};

class Credit
{
private:
    double Amount;
    int Months;
    double InterestRate;

public:
    Credit(ICredit props = {})
    {
        this->Amount = props.amount;
        this->Months = props.months;
        this->InterestRate = props.interestRate;
    }

    void SetCreditAmount(double amount)
    {
        this->Amount = amount;
    }

    void SetCreditMonths(int months)
    {
        this->Months = months;
    }

    void SetCreditInterestRate(double interestRate)
    {
        this->InterestRate = interestRate;
    }

    double GetCreditAmount() const
    {
        return this->Amount;
    }

    int GetCreditMonths() const
    {
        return this->Months;
    }

    double GetCreditInterestRate() const
    {
        return this->InterestRate;
    }
};

#endif