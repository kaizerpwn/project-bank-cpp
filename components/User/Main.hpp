#ifndef MAIN_COMPONENT_H
#define MAIN_COMPONENT_H

#include <iostream>

#include "../../utils/colors.hpp"

void MainForm()
{

    system("clear");
    ShowHeader();

    std::cout << CRVENA << "BANKA >>" << BIJELA << " Dobrodosli, izaberite opciju koju zelite.\n";
    std::cout << CRVENA << "[1]" << BIJELA << " Prijavi se\n";
    std::cout << CRVENA << "[2]" << BIJELA << " Registruj se\n";
    std::cout << CRVENA << "[3]" << BIJELA << " Izlaz\n";

    int option;
    std::cin >> option;

    do
    {
        switch (option)
        {
        case 1:
            LoginForm();
            break;
        case 2:
            option = 1;
            RegisterForm();
            break;
        case 3:
            exit(0);
            break;

        default:
            break;
        }
    } while (option != 3);
}

#endif
