#ifndef WORKER_INTERFACE_H
#define WORKER_INTERFACE_H

#include "User.interface.hpp"

class Worker
{
private:
    string Position;
    double Salary;

public:
    Worker()
    {
        this->Position = "Unemployed";
        this->Salary = 0;
    }

    Worker(string position, double salary)
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

    string GetWorkerPosition() const
    {
        return this->Position;
    }

    double GetWorkerSalary() const
    {
        return this->Salary;
    }
};

#endif
