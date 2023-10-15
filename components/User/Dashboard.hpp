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
        ShowHeader();

        std::cout << std::endl;

        printf("" CRVENA "BANKA >>" BIJELA " Dobrodosli %s, izaberite opciju koju zelite.\n", currentUser.GetFullName().c_str());
        printf("" CRVENA "[1]" BIJELA " Stanje računa\n");
        printf("" CRVENA "[2]" BIJELA " Prethodne transakcije\n");
        printf("" CRVENA "[3]" BIJELA " Nova transakcija\n");
        printf("" CRVENA "[4]" BIJELA " Podigni kredit\n");
        printf("" CRVENA "[5]" BIJELA " Promijeni ratu kredita\n");
        printf("" CRVENA "[6]" BIJELA " Promijeni ratu kredita\n");
        printf("" CRVENA "[7]" BIJELA " Odjavite se\n");

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
    std::cout
        << CRVENA "BANKA >>" BIJELA " Stanje vašeg računa iznosi " << ZUTA << currentUser.GetAccountBalance() << " KM" << std::endl;
    std::cout << CRVENA "BANKA >>" BIJELA " Stisnite 'ENTER' za povratak u meni... " << std::endl;
    std::cin.get();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

#endif