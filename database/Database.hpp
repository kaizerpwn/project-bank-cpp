#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <fstream>
#include <vector>

#include "../utils/colors.hpp"
#include "../interfaces/User.interface.hpp"

#define MAX_USERS (100)
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
    std::vector<User> users = User::GetAllUsers();

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
    User::SaveUsers(users);

    currentUser = newUser;
    response.Status = true;
    return response;
}

#endif