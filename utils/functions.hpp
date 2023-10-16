#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>

double calculateInterestRate(double startingAmount, double interestRate, int months)
{
    double rate = startingAmount * (interestRate / 100) * months;
    return rate;
}

std::string generateRandomIBAN()
{
    std::string iban = "BA";

    for (int i = 0; i < 2; ++i)
    {
        int randomDigit = rand() % 10;
        iban += std::to_string(randomDigit);
    }

    for (int i = 0; i < 14; ++i)
    {
        int randomDigit = rand() % 10;
        iban += std::to_string(randomDigit);
    }

    return iban;
}

std::string generateRandomVisaCardNumber()
{
    std::string cardNumber = "4";

    for (int i = 1; i < 16; ++i)
    {
        int randomDigit = rand() % 10;
        cardNumber += std::to_string(randomDigit);
    }

    return cardNumber;
}

std::string generateRandomMastercardNumber()
{
    std::string cardNumber = "5";

    for (int i = 1; i < 16; ++i)
    {
        int randomDigit = rand() % 10;
        cardNumber += std::to_string(randomDigit);
    }

    return cardNumber;
}

#endif