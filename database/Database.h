#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <fstream>

#include "../utils/colors.h"
#include "../interfaces/User.interface.h"

#define MAX_USERS (100)

std::fstream OpenDatabase(const std::string &db, std::ios_base::openmode mode)
{
    char databaseName[64];
    sprintf(databaseName, "database/data/%s.dat", db.c_str());
    std::fstream database(databaseName, mode);
    return database;
}

// >> Function to save all users in database
void SaveUsers(User *users)
{
    std::fstream database = OpenDatabase("users", std::ios::binary | std::ios::out);

    if (!database.is_open())
    {
        std::ofstream createFile("database/data/users.dat", std::ios::binary);
        createFile.close();
        database = OpenDatabase("users", std::ios::binary | std::ios::out);
    }
    else
    {
        database.close();
        std::ofstream clearFile("database/data/users.dat", std::ios::binary | std::ios::trunc);
        clearFile.close();
        database = OpenDatabase("users", std::ios::binary | std::ios::out);
    }

    if (database.is_open())
    {
        size_t dataSize = sizeof(User) * MAX_USERS;
        database.write(reinterpret_cast<char *>(users), dataSize);

        database.close();
    }
}

// >> Function to get all users from database
User *GetAllUsers()
{
    User *users = new User[MAX_USERS];

    std::fstream database = OpenDatabase("users", std::ios::binary | std::ios::in);
    if (database)
    {
        database.read(reinterpret_cast<char *>(users), sizeof(User) * MAX_USERS);
        database.close();
    }

    return users;
}

struct CreateNewUserResponse
{
    bool Status;
    string Message;
};

// >> Function to create new user
CreateNewUserResponse CreateNewUser(UserConstructorInterface *userData)
{
    User newUser(*userData);
    CreateNewUserResponse response;
    User *users = new User[MAX_USERS];

    std::fstream database = OpenDatabase("users", std::ios::binary | std::ios::in);
    if (database)
    {
        database.read(reinterpret_cast<char *>(users), sizeof(User) * MAX_USERS);
    }

    // >> Check if user exists in database
    bool found = false;
    for (int i = 0; i < MAX_USERS; i++)
    {
        if (users[i].GetEmail() == userData->email)
        {
            found = true;
            database.close();
            response.Status = false;
            response.Message = "" CRVENA "[ERROR]: " BIJELA "Vec postoji registrovani korisnik sa takvim emailom.\n";
            return response;
        }
    }

    // >> If user doesn't exist in database register him
    if (!found)
    {
        // >> Check if limit of users is exceeded
        if (sizeof(users) / sizeof(users[0]) >= MAX_USERS)
        {
            database.close();
            response.Status = false;
            response.Message = "" CRVENA "[ERROR]: " BIJELA "Prekoracen je limit korisnika u databazi.\n";
            return response;
        }

        for (int i = 0; i < MAX_USERS; i++)
        {
            if (users[i].GetName() == "" || users[i].GetName() == "undefined")
            {
                currentUser = newUser;

                SaveUsers(users);
                database.close();

                if (users)
                    delete[] users;
                response.Status = true;
                return response;
            }
        }
    }

    if (users)
        delete[] users;
    return response;
}

#endif