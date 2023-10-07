#ifndef REGISTER_H
#define REGISTER_H

#include <iostream>

#include "../../utils/colors.h"
#include "../../interfaces/User.interface.h"
#include "../../database/Database.h"

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

    printf("" CYAN " __                         __                                       \n");
    printf("" CYAN "|  \\                       |  \\                                      \n");
    printf("" CYAN "| ▓▓____   ______  _______ | ▓▓   __       ______   ______   ______  \n");
    printf("" CYAN "| ▓▓    \\ |      \\|       \\| ▓▓  /  \\     |      \\ /      \\ /      \\ \n");
    printf("" CYAN "| ▓▓▓▓▓▓▓\\ \\▓▓▓▓▓▓\\ ▓▓▓▓▓▓▓\\ ▓▓_/  ▓▓      \\▓▓▓▓▓▓\\  ▓▓▓▓▓▓\\  ▓▓▓▓▓▓\\\n");
    printf("" CYAN "| ▓▓  | ▓▓/      ▓▓ ▓▓  | ▓▓ ▓▓   ▓▓      /      ▓▓ ▓▓  | ▓▓ ▓▓  | ▓▓\n");
    printf("" CYAN "| ▓▓__/ ▓▓  ▓▓▓▓▓▓▓ ▓▓  | ▓▓ ▓▓▓▓▓▓\\     |  ▓▓▓▓▓▓▓ ▓▓__/ ▓▓ ▓▓__/ ▓▓\n");
    printf("" CYAN "| ▓▓    ▓▓\\▓▓    ▓▓ ▓▓  | ▓▓ ▓▓  \\▓▓\\     \\▓▓    ▓▓ ▓▓    ▓▓ ▓▓    ▓▓\n");
    printf("" CYAN "\\▓▓▓▓▓▓▓  \\ ▓▓▓▓▓▓▓\\▓▓   \\▓▓\\▓▓   \\▓▓      \\▓▓▓▓▓▓▓ ▓▓▓▓▓▓▓| ▓▓▓▓▓▓▓ \n");
    printf("" CYAN "                                                  | ▓▓     | ▓▓      \n");
    printf("" CYAN "                                                  | ▓▓     | ▓▓      \n");
    printf("" CYAN "                                                   \\▓▓      \\▓▓      \n");

    printf("" CYAN "BANKA >>" BIJELA " Molimo Vas unesite Vase ime.\n");
    std::cin >> name;
    printf("" CYAN "BANKA >>" BIJELA " Molimo Vas unesite Vase prezime.\n");
    std::cin >> surname;
    printf("" CYAN "BANKA >>" BIJELA " Molimo Vas unesite Vas email koji zelite koristiti.\n");
    std::cin >> email;
    printf("" CYAN "BANKA >>" BIJELA " Sada unesite lozinku koju zelite koristiti.\n");
    std::cin >> password;
    printf("" CYAN "BANKA >>" BIJELA " Kojeg ste spola?.\n");
    printf("" MAGENTA "OPCIJE >>" BIJELA " musko | zensko\n");
    std::cin >> gender;
    printf("" CYAN "BANKA >>" BIJELA " Unesite datum Vaseg rodjenja u formatu DD/MM/YYYY.\n");
    std::cin >> birthDate;
    printf("" CYAN "BANKA >>" BIJELA " Unesite Vas JMBG.\n");
    std::cin >> jmbg;
    printf("" CYAN "BANKA >>" BIJELA " Unesite Vasu trenutnu lokaciju stanovanja.\n");
    std::cin >> address;
    printf("" CYAN "BANKA >>" BIJELA " Unesite Vas trenutni kontakt broj.\n");
    std::cin >> phoneNumber;

    UserConstructorInterface userData;

    userData.name = name;
    userData.surname = surname;
    userData.email = email;
    userData.password = password;
    userData.gender = gender;
    userData.birthDate = birthDate;
    userData.jmbg = jmbg;
    userData.address = address;
    userData.phoneNumber = phoneNumber;

    CreateNewUserResponse response = CreateNewUser(&userData);
    if (response.Status == true)
    {
        LoginForm();
    }
    else
    {
        printf("%s", response.Message);
    }
}

#endif