#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>

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