#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <fstream>
#include <vector>

#include "../utils/colors.hpp"
#include "../interfaces/User.interface.hpp"

#define MAX_USERS (100)

// >> Function to save all users in database
void SaveUsers(const std::vector<User> &users)
{
    std::ofstream database("database/data/users.dat", std::ios::binary | std::ios::out | std::ios::trunc);

    if (!database.is_open())
    {
        std::cerr << "ERROR: Nije moguce uspostaviti konekciju sa databazom." << std::endl;
        return;
    }

    for (const auto &user : users)
    {
        user.Serialize(database);
    }

    database.close();
}

// >> Function to get all users from database
std::vector<User> GetAllUsers()
{
    std::vector<User> users;

    std::ifstream database("database/data/users.dat", std::ios::binary | std::ios::in);

    if (!database.is_open())
    {
        std::cerr << "ERROR: Nije moguce uspostaviti konekciju sa databazom." << std::endl;
        return users;
    }

    User user;
    while (true)
    {
        user.Deserialize(database);
        if (!database)
        {
            break;
        }
        users.push_back(user);
    }

    database.close();
    return users;
}

struct CreateNewUserResponse
{
    bool Status;
    string Message;
};

// >> Function to create new user
CreateNewUserResponse CreateNewUser(IUser *userData)
{
    User newUser(*userData);
    CreateNewUserResponse response;
    std::vector<User> users = GetAllUsers();

    // >> Check if user exists in database
    for (const User &user : users)
    {
        if (user.GetEmail() == userData->email)
        {
            response.Status = false;
            response.Message = "" CRVENA "[ERROR]: " BIJELA "Vec postoji registrovani korisnik sa takvim emailom.\n";
            return response;
        }
    }

    // >> Check if limit of users is exceeded
    if (users.size() >= MAX_USERS)
    {
        response.Status = false;
        response.Message = "" CRVENA "[ERROR]: " BIJELA "Prekoracen je limit korisnika u databazi.\n";
        return response;
    }

    // >> Add the new user
    users.push_back(newUser);
    SaveUsers(users);

    currentUser = newUser;
    response.Status = true;
    return response;
}

#endif