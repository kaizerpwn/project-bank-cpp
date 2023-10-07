#ifndef WORKER_INTERFACE_H
#define WORKER_INTERFACE_H

// Include the necessary header file instead of .cpp file
#include "User.interface.h"

class Worker : public User
{
private:
    string Position;
    double Pay;

public:
    Worker(string name, string surname, string jmbg, string address, string phoneNumber) : User(name, surname, jmbg, address, phoneNumber)
    {
    }
};

#endif
