#ifndef REGISTER_H
#define REGISTER_H

#include <iostream>

#include "../../utils/colors.hpp"
#include "../../interfaces/User.interface.hpp"
#include "../../database/Database.hpp"
#include "../../utils/functions.hpp"

void RegisterForm()
{
    std::string email,
        password,
        name,
        surname,
        jmbg,
        birthDate,
        gender,
        address,
        phoneNumber;

    system("clear");
    ShowHeader();

    printf("" CRVENA "BANKA >>" BIJELA " Molimo Vas unesite Vase ime.\n");
    std::cin >> name;
    printf("" CRVENA "BANKA >>" BIJELA " Molimo Vas unesite Vase prezime.\n");
    std::cin >> surname;
    printf("" CRVENA "BANKA >>" BIJELA " Molimo Vas unesite Vas email koji zelite koristiti.\n");
    std::cin >> email;
    printf("" CRVENA "BANKA >>" BIJELA " Sada unesite lozinku koju zelite koristiti.\n");
    std::cin >> password;
    printf("" CRVENA "BANKA >>" BIJELA " Kojeg ste spola?.\n");
    printf("" MAGENTA "OPCIJE >>" BIJELA " musko | zensko\n");
    std::cin >> gender;
    printf("" CRVENA "BANKA >>" BIJELA " Unesite datum Vaseg rodjenja u formatu DD/MM/YYYY.\n");
    std::cin >> birthDate;
    printf("" CRVENA "BANKA >>" BIJELA " Unesite Vas JMBG.\n");
    std::cin >> jmbg;
    printf("" CRVENA "BANKA >>" BIJELA " Unesite Vasu trenutnu lokaciju stanovanja.\n");
    std::cin >> address;
    printf("" CRVENA "BANKA >>" BIJELA " Unesite Vas trenutni kontakt broj.\n");
    std::cin >> phoneNumber;

    IUser userData;

    userData.name = name;
    userData.surname = surname;
    userData.email = email;
    userData.password = password;
    userData.gender = gender;
    userData.birthDate = birthDate;
    userData.jmbg = jmbg;
    userData.address = address;
    userData.phoneNumber = phoneNumber;

    userData.accountNumber = generateRandomIBAN();
    userData.accountCardNumber = generateRandomVisaCardNumber();

    userData.savingsAccountNumber = generateRandomIBAN();
    userData.savingsAccountCardNumber = generateRandomMastercardNumber();

    CreateNewUserResponse response = CreateNewUser(&userData);
    if (response.Status == true)
    {
        LoginForm();
    }
    else
    {
        std::cout << "" CRVENA "[ERROR]: " BIJELA "" << response.Message;
    }
}

#endif