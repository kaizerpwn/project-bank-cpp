#ifndef TRANSACTION_INTERFACE_H
#define TRANSACTION_INTERFACE_H

#include <fstream>

class Transaction
{
private:
    string Type;
    double Amount;
    string From;
    string To;

public:
    Transaction(string type, double amount, string from, string to)
    {
        this->Type = type;
        this->Amount = amount;
        this->From = from;
        this->To = to;
    }

    void Serialize(std::ostream &outFile) const;
    void Deserialize(std::istream &inFile);

    void CreateTransaction()
    {
        std::ofstream database("database/data/transactions.dat", std::ios::binary | std::ios::out | std::ios::trunc);

        if (!database.is_open())
        {
            std::cerr << "ERROR: Nije moguce uspostaviti konekciju sa databazom." << std::endl;
            return;
        }

        database.close();
    }
};

void Transaction::Serialize(std::ostream &outFile) const
{
    outFile << Type << '|'
            << Amount << '|'
            << From << '|'
            << To << '|' << "|\n";
}

void Transaction::Deserialize(std::istream &inFile)
{
    std::getline(inFile, Type, '|');

    std::string amount;
    std::getline(inFile, amount, '|');

    std::getline(inFile, From, '|');
    std::getline(inFile, To, '|');

    inFile.ignore(10000, '\n');
}

#endif