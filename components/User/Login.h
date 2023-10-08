#ifndef LOGIN_COMPONENT_H
#define LOGIN_COMPONENT_H

#include <iostream>
#include <string>

bool Login(string email, string password);

void LoginForm()
{
    string email;
    string password;

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

    printf("" CYAN "BANKA >>" BIJELA " Molimo Vas unesite Vas email za prijavu.\n");
    cin.ignore();
    std::getline(cin, email);

    printf("" CYAN "BANKA >>" BIJELA " Sada unesite Vasu lozinku za prijavu.\n");
    cin.ignore();
    std::getline(cin, password);

    if (password.length() != 0 || email.length() != 0)
    {
        Login(email, password);
    }
}

bool Login(string email, string password)
{
    User *users = GetAllUsers();

    if (users == nullptr)
        return 1;

    bool found = false;
    for (int i = 0; i < MAX_USERS; i++)
    {
        std::cout << users[i].GetEmail();
        if (users[i].GetEmail() == email && users[i].CheckPassword(password))
        {
            currentUser = users[i];
            return true;
        }
    }

    if (!found)
        printf("" CRVENA "[ERROR]: " BIJELA "Ne postoji racun sa takvim podacima u nasoj databazi.\n");

    if (users)
        delete[] users;
    return false;
}

#endif
