#ifndef WORKER_INTERFACE_H
#define WORKER_INTERFACE_H

#include "User.interface.hpp"

class Worker : public User
{
private:
    string Position;
    double Salary;

public:
    Worker(UserConstructorInterface props, string position, double salary)
        : User(props), Position(position), Salary(salary)
    {
        this->Position = position;
        this->Salary = salary;
    }

    void SetWorkerPosition(string position)
    {
        this->Position = position;
    }

    void SetWorkerSalary(double salary)
    {
        this->Salary = salary;
    }

    string GetWorkerPosition()
    {
        return this->Position;
    }

    double GetWorkerSalary()
    {
        return this->Salary;
    }
};

#endif
