#ifndef USER_DASHBOARD_COMPONENT_H
#define USER_DASHBOARD_COMPONENT_H

#include <iostream>
#include <chrono>
#include <thread>
#include <iomanip>

#include "../../utils/colors.hpp"
#include "Functions/Credit.hpp"
#include "Functions/Transactions.hpp"
#include "Functions/Users.hpp"

void CheckBalance();

void UserDashboardForm()
{
    int option;

    do
    {
        system("clear");
        ShowHeader();

        std::cout << std::endl;

        std::cout << CRVENA << "BANKA >>" << BIJELA << " Dobrodosli " << currentUser.GetFullName() << ", izaberite opciju koju zelite.\n";
        std::cout << CRVENA << "[1]" << BIJELA << " Stanje računa\n";
        std::cout << CRVENA << "[2]" << BIJELA << " Prethodne transakcije\n";
        std::cout << CRVENA << "[3]" << BIJELA << " Nova transakcija\n";
        std::cout << CRVENA << "[4]" << BIJELA << " Podigni kredit\n";
        if (currentUser.WorkData.GetWorkerPosition() == "Banker")
        {
            std::cout << CRVENA << "[5]" << BIJELA << " Pregled svih transakcija (Samo zaposleni)\n";
            std::cout << CRVENA << "[6]" << BIJELA << " Pregled svih korisnika (Samo zaposleni)\n";
            std::cout << CRVENA << "[7]" << BIJELA << " Uredi korisnika (Samo zaposleni)\n";
            std::cout << CRVENA << "[8]" << BIJELA << " Obriši korisnika (Samo zaposleni)\n\n";
        }
        std::cout << CRVENA << "[-1]" BIJELA " Odjavite se\n";

        std::cin >> option;

        switch (option)
        {

        case 1:
            CheckBalance();
            break;

        case 2:
            RecentTransactions("N/A");
            break;

        case 3:
            TransferMoney();
            break;

        case 4:
            RaiseCredit();
            break;

        case -1:
            MainForm();
            break;

        case 5:
            if (currentUser.WorkData.GetWorkerPosition() == "Banker")
            {
                RecentTransactions(currentUser.WorkData.GetWorkerPosition());
            }
            break;

        case 6:
            if (currentUser.WorkData.GetWorkerPosition() == "Banker")
            {
                ShowAllUsers();
            }
            break;

        case 7:
            if (currentUser.WorkData.GetWorkerPosition() == "Banker")
            {
                EditUser();
            }
            break;

        case 8:
            if (currentUser.WorkData.GetWorkerPosition() == "Banker")
            {
                DeleteUser();
            }
            break;

        default:
            break;
        }

    } while (option != -1);
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