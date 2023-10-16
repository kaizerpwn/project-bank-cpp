#ifndef USER_DASHBOARD_COMPONENT_H
#define USER_DASHBOARD_COMPONENT_H

#include <iostream>
#include <chrono>
#include <thread>
#include <iomanip>

#include "../../utils/colors.hpp"
#include "Functions/Credit.hpp"
#include "Functions/Transactions.hpp"

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
        printf("" CRVENA "[5]" BIJELA " Odjavite se\n");

        if (currentUser.WorkData.GetWorkerPosition() == "Banker")
        {
            printf("" CRVENA "[6]" BIJELA " Pregled svih transakcija (Samo zaposleni)\n");
        }

        std::cin >> option;

        switch (option)
        {

        case 1:
            CheckBalance();
            break;

        case 2:
            RecentTransactions(currentUser.WorkData.GetWorkerPosition());
            break;

        case 3:
            TransferMoney();
            break;

        case 4:
            RaiseCredit();
            break;

        case 5:
            MainForm();
            break;

        case 6:
            if (currentUser.WorkData.GetWorkerPosition() == "Banker")
            {
                RecentTransactions(currentUser.WorkData.GetWorkerPosition());
            }
            break;

        default:
            break;
        }

    } while (option != 5);
}

void CheckBalance()
{
    std::cout
        << CRVENA "BANKA >>" BIJELA " Stanje vašeg računa iznosi " << ZUTA << currentUser.GetAccountBalance() << " KM" << std::endl;
    std::cout << CRVENA "BANKA >>" BIJELA " Stisnite" << ZUTA << " 'ENTER' " << BIJELA << "za povratak u meni... " << std::endl;
    std::cin.get();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

#endif