#ifndef TRANSACTION_INTERFACE_H
#define TRANSACTION_INTERFACE_H

#include <fstream>
#include <vector>

struct ITransaction
{
    string type;
    double amount;
    string from;
    string to;
    string receiverFullName;
    string senderFullName;
};

class Transaction
{
private:
    string Type;
    string ReceiverFullName;
    string SenderFullName;
    double Amount;
    string From;
    string To;

public:
    Transaction(ITransaction props = {})
    {
        this->Type = props.type;
        this->ReceiverFullName = props.receiverFullName;
        this->SenderFullName = props.senderFullName;
        this->Amount = props.amount;
        this->From = props.from;
        this->To = props.to;
    }

    void Serialize(std::ostream &outFile) const;
    void Deserialize(std::istream &inFile);

    string GetSender()
    {
        return this->From;
    }

    string GetReceiver()
    {
        return this->To;
    }

    string GetReceiverFullName()
    {
        return this->ReceiverFullName;
    }

    string GetTransactionType()
    {
        return this->Type;
    }

    double GetAmount()
    {
        return this->Amount;
    }

    static inline void CreateTransaction(ITransaction *props)
    {
        std::vector<Transaction> transactions;
        std::fstream database("database/data/transactions.dat", std::ios::binary | std::ios::in | std::ios::out);

        // >> If there is no file then create it
        if (!database.is_open())
        {
            std::fstream database("database/data/transactions.dat", std::ios::binary | std::ios::in | std::ios::out | std::ios::trunc);
        }

        // >> Read all transactions from file and push them in vector 'transactions'
        Transaction transaction;
        while (true)
        {
            transaction.Deserialize(database);

            if (!database)
            {
                break;
            }

            transactions.push_back(transaction);
        }

        Transaction newTransaction(*props);
        transactions.push_back(newTransaction);

        // >> Reopen database but this time in write mode
        database.close();
        database.open("database/data/transactions.dat", std::ios::binary | std::ios::out | std::ios::trunc);

        for (const auto &transaction : transactions)
        {
            transaction.Serialize(database);
        }

        database.close();
    }

    static inline std::vector<Transaction> GetUsersTransactions(string accountNumber)
    {
        std::vector<Transaction> transactions;
        std::fstream database("database/data/transactions.dat", std::ios::binary | std::ios::in | std::ios::out);

        // >> If there is no file then create it
        if (!database.is_open())
        {
            std::fstream database("database/data/transactions.dat", std::ios::binary | std::ios::in | std::ios::out | std::ios::trunc);
        }

        // >> Read all transactions from file and push them in vector 'transactions'
        Transaction transaction;
        while (true)
        {
            transaction.Deserialize(database);

            if (!database)
            {
                break;
            }
            if (transaction.From == accountNumber)
            {
                transactions.push_back(transaction);
            }
        }
        database.close();

        return transactions;
    }
};

void Transaction::Serialize(std::ostream &outFile) const
{
    outFile << Type << '|'
            << Amount << '|'
            << From << '|'
            << To << '|'
            << ReceiverFullName << '|'
            << SenderFullName << "|\n";
}

void Transaction::Deserialize(std::istream &inFile)
{
    std::getline(inFile, Type, '|');

    std::string amount;
    std::getline(inFile, amount, '|');
    try
    {
        Amount = std::stod(amount);
    }
    catch (const std::invalid_argument &e)
    {
    }

    std::getline(inFile, From, '|');
    std::getline(inFile, To, '|');
    std::getline(inFile, ReceiverFullName, '|');
    std::getline(inFile, SenderFullName, '|');

    inFile.ignore(10000, '\n');
}

#endif