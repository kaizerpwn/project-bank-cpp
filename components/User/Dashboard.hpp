#ifndef USER_DASHBOARD_COMPONENT_H
#define USER_DASHBOARD_COMPONENT_H

#include <iostream>
#include <chrono>
#include <thread>

#include "../../utils/colors.hpp"

void CheckBalance();
void TransferMoney();

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
            TransferMoney();
            break;

        case 7:
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
    std::cout << CRVENA "BANKA >>" BIJELA " Stisnite" << ZUTA << " 'ENTER' " << BIJELA << "za povratak u meni... " << std::endl;
    std::cin.get();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void TransferMoney()
{
    std::cout << CRVENA "BANKA >>" BIJELA " Unesite broj računa na koji želite prebaciti" << ZUTA << " novac" << std::endl;
    std::cout << CRVENA "BANKA >>" BIJELA " Stisnite" << ZUTA << " 'ENTER' " << BIJELA << "za povratak u meni... " << std::endl;
    string accountNumber;
    std::cin >> accountNumber;

    if (!accountNumber.empty())
    {
        std::cout << CRVENA "BANKA >>" BIJELA " Unesite svotu novca koju želite prebaciti na račun " << ZUTA << accountNumber << std::endl;
        std::cout << CRVENA "BANKA >>" BIJELA " Stisnite" << ZUTA << " 'ENTER' " << BIJELA << "za povratak u meni... " << std::endl;
        string amountToTransfer;
        std::cin >> amountToTransfer;

        // >> If user want to send money to his own wallet
        if (accountNumber == currentUser.GetAccountNumber())
        {
            std::cout
                << CRVENA "BANKA >>" BIJELA " Ne možete slati novac na vaš račun. " << std::endl;
            std::cout << CRVENA "BANKA >>" BIJELA " Stisnite" << ZUTA << " 'ENTER' " << BIJELA << "za povratak u meni... " << std::endl;
            std::cin.get();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return;
        }

        // If amount if negative value
        if (std::stod(amountToTransfer) < 0)
        {
            std::cout
                << CRVENA "BANKA >>" BIJELA " Iznos za slanje ne smije biti manji od 0 i od vašeg dozvoljenog limita koji iznosi: " << ZUTA << currentUser.GetAccountLimit() << " KM" << std::endl;
            std::cout << CRVENA "BANKA >>" BIJELA " Stisnite" << ZUTA << " 'ENTER' " << BIJELA << "za povratak u meni... " << std::endl;
            std::cin.get();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return;
        }

        // >> If amount to transfer is bigger than limit on bank account
        if (std::stod(amountToTransfer) > currentUser.GetAccountLimit())
        {
            std::cout
                << CRVENA "BANKA >>" BIJELA " Prekoračili ste vaš dozvoljeni limit za slanje, dozvoljeni limit iznosi: " << ZUTA << currentUser.GetAccountLimit() << " KM" << std::endl;
            std::cout << CRVENA "BANKA >>" BIJELA " Stisnite" << ZUTA << " 'ENTER' " << BIJELA << "za povratak u meni... " << std::endl;
            std::cin.get();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return;
        }

        // >> If user have that amount of money on his bank account
        if (std::stod(amountToTransfer) > currentUser.GetAccountBalance())
        {
            std::cout
                << CRVENA "BANKA >>" BIJELA " Nemate dovoljno novca na vašem računu, trenutni iznos je: " << ZUTA << currentUser.GetAccountBalance() << " KM" << std::endl;
            std::cout << CRVENA "BANKA >>" BIJELA " Stisnite" << ZUTA << " 'ENTER' " << BIJELA << "za povratak u meni... " << std::endl;
            std::cin.get();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return;
        }

        // >> Get all users, loop over that array and find one that have same Account Number as provided in the input field
        std::vector<User> users = User::GetAllUsers();
        int found = -1;

        for (int i = 0; i < users.size(); i++)
        {
            if (users[i].GetAccountNumber() == currentUser.GetAccountNumber())
            {
                users[i].BankAccount.SetAccountBalance(users[i].GetAccountBalance() - std::stod(amountToTransfer));
            }

            if (users[i].GetAccountNumber() == accountNumber)
            {
                found = i;

                try
                {
                    users[i].BankAccount.SetAccountBalance(users[i].GetAccountBalance() + std::stod(amountToTransfer));
                    currentUser.BankAccount.SetAccountBalance(currentUser.GetAccountBalance() - std::stod(amountToTransfer));
                    std::cout
                        << ZELENA "USPJEŠNA TRANSAKCIJA >>" BIJELA " Poslali ste: " << CYAN << amountToTransfer << " KM" << BIJELA << " na račun " << ZUTA << accountNumber << std::endl;
                    std::cout << CRVENA "BANKA >>" BIJELA " Stisnite" << ZUTA << " 'ENTER' " << BIJELA << "za povratak u meni... " << std::endl;
                    User::SaveUsers(users);
                    std::cin.get();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                catch (const std::invalid_argument &e)
                {
                    std::cout
                        << CRVENA "BANKA >>" BIJELA " Došlo je do greške prilikom vaše transakcije, pokušajte ponovo." << std::endl;
                    std::cout << CRVENA "BANKA >>" BIJELA " Stisnite" << ZUTA << " 'ENTER' " << BIJELA << "za povratak u meni... " << std::endl;
                    std::cin.get();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }

                break;
            }
        }

        // >> If account is not found
        if (found == -1)
        {
            std::cout
                << CRVENA "BANKA >>" BIJELA " Bankovni račun " << ZUTA << accountNumber << BIJELA << " ne postoji u našoj databazi, pokušajte ponovo." << BIJELA << std::endl;
            std::cout << CRVENA "BANKA >>" BIJELA " Stisnite" << ZUTA << " 'ENTER' " << BIJELA << "za povratak u meni... " << std::endl;
            std::cin.get();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

#endif