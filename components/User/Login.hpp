#ifndef LOGIN_COMPONENT_H
#define LOGIN_COMPONENT_H

#include <iostream>
#include <string>

bool Login(const string &email, const string &password);

void LoginForm()
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

    string email, password;
    printf("" CYAN "BANKA >>" BIJELA " Molimo Vas unesite Vas email za prijavu.\n");
    std::cin >> email;
    printf("" CYAN "BANKA >>" BIJELA " Sada unesite Vasu lozinku za prijavu.\n");
    std::cin >> password;
    Login(email, password);
}

bool Login(const string &email, const string &password)
{
    printf("[DEBUG]: %s %s\n", email.c_str(), password.c_str());
    std::vector<User> users = GetAllUsers();

    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].GetEmail() == email && users[i].CheckPassword(password))
        {
            cout << "Korisnik je pronadjen na indeksu : " << i << endl;
            currentUser = users[i];
            break;
        }
    }

    return false;
}

#endif
