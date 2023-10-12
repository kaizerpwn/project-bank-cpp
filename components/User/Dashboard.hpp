#ifndef USER_DASHBOARD_COMPONENT_H
#define USER_DASHBOARD_COMPONENT_H

#include <iostream>
#include <chrono>
#include <thread>

#include "../../utils/colors.hpp"
void CheckBalance();

void UserDashboardForm()
{
    int option;

    do
    {
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

        std::cout << std::endl;

        printf("" CYAN "BANKA >>" BIJELA " Dobrodosli %s, izaberite opciju koju zelite.\n", currentUser.GetFullName().c_str());
        printf("" CYAN "[1]" BIJELA " Stanje računa\n");
        printf("" CYAN "[2]" BIJELA " Prethodne transakcije\n");
        printf("" CYAN "[3]" BIJELA " Nova transakcija\n");
        printf("" CYAN "[4]" BIJELA " Podigni kredit\n");
        printf("" CYAN "[5]" BIJELA " Promijeni ratu kredita\n");
        printf("" CYAN "[6]" BIJELA " Promijeni ratu kredita\n");
        printf("" CYAN "[7]" BIJELA " Odjavite se\n");

        std::cin >> option;

        switch (option)
        {
        case 1:
            CheckBalance();
            break;

        case 2:
            break;
        case 3:
            MainForm();
            break;
        default:
            break;
        }

    } while (option != 4);
}

void CheckBalance()
{
    std::cout << CYAN "BANKA >>" BIJELA " Stanje vašeg računa iznosi " << currentUser.GetAccountBalance() << " KM" << std::endl;
    std::cout << CYAN "BANKA >>" BIJELA " Stisnite 'ENTER' za povratak u meni... " << std::endl;
    std::cin.get();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

#endif