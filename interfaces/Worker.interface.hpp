#ifndef WORKER_INTERFACE_H
#define WORKER_INTERFACE_H

#include "User.interface.hpp"

class Worker : public User
{
private:
    string Position;
    double Pay;

public:
    Worker(UserConstructorInterface props, string position, double pay)
        : User(props), Position(position), Pay(pay)
    {
    }
};

#endif
