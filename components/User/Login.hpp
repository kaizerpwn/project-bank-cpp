#ifndef LOGIN_COMPONENT_H
#define LOGIN_COMPONENT_H

#include <iostream>
#include <string>

bool Login(const string &email, const string &password);
void UserDashboardForm();

void LoginForm()
{

    system("clear");
    ShowHeader();

    string email, password;
    std::cout << CRVENA << "BANKA >>" BIJELA " Molimo Vas unesite Vas email za prijavu.\n";
    std::cin >> email;
    std::cout << CRVENA << "BANKA >>" BIJELA " Sada unesite Vasu lozinku za prijavu.\n";
    std::cin >> password;
    Login(email, password);
}

bool Login(const string &email, const string &password)
{
    std::vector<User> users = User::GetAllUsers();

    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].GetEmail() == email && users[i].CheckPassword(password))
        {
            currentUser = users[i];
            UserDashboardForm();
            break;
        }
    }

    return false;
}

#endif
