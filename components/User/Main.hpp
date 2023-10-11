#ifndef MAIN_COMPONENT_H
#define MAIN_COMPONENT_H

#include <iostream>

#include "../../utils/colors.hpp"

void MainForm()
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

    printf("" CYAN "BANKA >>" BIJELA " Dobrodosli, izaberite opciju koju zelite.\n");
    printf("" CYAN "[1]" BIJELA " Prijavi se\n");
    printf("" CYAN "[2]" BIJELA " Registruj se\n");
    printf("" CYAN "[3]" BIJELA " Izlaz\n");

    int option;
    std::cin >> option;

    // do
    // {
    switch (option)
    {
    case 1:
        LoginForm();
        break;
    case 2:
        RegisterForm();
        break;
    case 3:
        exit(0);
        break;

    default:
        break;
    }
    // } while (option != 3);
}

#endif
