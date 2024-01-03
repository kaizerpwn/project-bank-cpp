#ifndef TRANSACTIONS_FUNCTIONS_H
#define TRANSACTIONS_FUNCTIONS_H

void RecentTransactions(string position)
{
    std::vector<Transaction> transactions;

    if (position == "Banker")
    {
        transactions = Transaction::GetAllTransactions();
    }
    else
    {
        transactions = Transaction::GetUsersTransactions(currentUser.GetFullName(), currentUser.GetAccountNumber());
    }

    if (transactions.empty())
    {
        std::cout
            << CRVENA "BANKA >>" BIJELA " Vi niste imali nikakvih transakcija do sada." << std::endl;
        std::cout << CRVENA "BANKA >>" BIJELA " Stisnite" << ZUTA << " 'ENTER' " << BIJELA << "za povratak u meni... " << std::endl;
        std::cin.get();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    else
    {
        std::cout
            << CRVENA "BANKA >>" BIJELA " Vaše nedavne transakcije su bile: " << std::endl;
        const int columnWidth = 20;
        std::cout << "+--------------------+--------------------+--------------------+--------------------+--------------------+---------+" << endl;
        std::cout << std::setw(columnWidth - 1) << std::left << " ID transakcije";
        std::cout << std::setw(columnWidth - 1) << std::right << "Primaoc";
        std::cout << std::setw(columnWidth - 1) << std::right << "Račun";
        std::cout << std::setw(columnWidth - 1) << std::right << "\tNovac (KM)";
        std::cout << std::setw(columnWidth - 1) << std::right << "\t\tVrsta";
        std::cout << std::endl;
        std::cout << "+--------------------+--------------------+--------------------+--------------------+--------------------+---------+" << endl;

        for (int i = 0; i < transactions.size(); i++)
        {
            std::cout << "|" << std::setw(columnWidth - 1) << std::left << CYAN << i + 1;
            std::cout << ")" << std::setw(columnWidth - 1) << std::right << BIJELA << transactions[i].GetReceiverFullName();
            std::cout << std::setw(columnWidth - 1) << std::right << transactions[i].GetReceiver();
            std::cout << std::setw(columnWidth - 1) << std::right << CYAN << transactions[i].GetAmount();
            std::cout << " KM" << std::setw(columnWidth - 1) << std::right << BIJELA << transactions[i].GetTransactionType();
            std::cout << "|" << std::endl;
        }

        std::cout << "+--------------------+--------------------+--------------------+--------------------+--------------------+---------+" << endl;

        std::cout << CRVENA "BANKA >>" BIJELA " Stisnite" << ZUTA << " 'ENTER' " << BIJELA << "za povratak u meni... " << std::endl;
        std::cin.get();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void TransferMoney()
{
    std::cout << CRVENA "BANKA >>" BIJELA " Unesite broj računa na koji želite prebaciti" << ZUTA << " novac" << std::endl;
    std::cout << CRVENA "BANKA >>" BIJELA " Unesite" << ZUTA << " '-1' " << BIJELA << "za povratak u meni... " << std::endl;
    string accountNumber;
    std::cin >> accountNumber;

    if (accountNumber == "-1")
        return;

    if (!accountNumber.empty())
    {
        std::cout << CRVENA "BANKA >>" BIJELA " Unesite svotu novca koju želite prebaciti na račun " << ZUTA << accountNumber << std::endl;
        std::cout << CRVENA "BANKA >>" BIJELA " Unesite" << ZUTA << " '-1' " << BIJELA << "za povratak u meni... " << std::endl;
        string amountToTransfer;
        std::cin >> amountToTransfer;

        if (amountToTransfer == "-1")
            return;

        // >> If user want to send money to his own wallet
        if (accountNumber == currentUser.GetAccountNumber())
        {
            std::cout
                << CRVENA "BANKA >>" BIJELA " Ne možete slati novac na vaš račun. " << std::endl;
            std::cout << CRVENA "BANKA >>" BIJELA " Stisnite" << ZUTA << " 'ENTER' " << BIJELA << "za povratak u meni... " << std::endl;
            std::cin.get();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return;
        }

        // If amount if negative value
        if (std::stod(amountToTransfer) < 0)
        {
            std::cout
                << CRVENA "BANKA >>" BIJELA " Iznos za slanje ne smije biti manji od 0 i od vašeg dozvoljenog limita koji iznosi: " << ZUTA << currentUser.GetAccountLimit() << " KM" << std::endl;
            std::cout << CRVENA "BANKA >>" BIJELA " Stisnite" << ZUTA << " 'ENTER' " << BIJELA << "za povratak u meni... " << std::endl;
            std::cin.get();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return;
        }

        // >> If amount to transfer is bigger than limit on bank account
        if (std::stod(amountToTransfer) > currentUser.GetAccountLimit())
        {
            std::cout
                << CRVENA "BANKA >>" BIJELA " Prekoračili ste vaš dozvoljeni limit za slanje, dozvoljeni limit iznosi: " << ZUTA << currentUser.GetAccountLimit() << " KM" << std::endl;
            std::cout << CRVENA "BANKA >>" BIJELA " Stisnite" << ZUTA << " 'ENTER' " << BIJELA << "za povratak u meni... " << std::endl;
            std::cin.get();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return;
        }

        // >> If user have that amount of money on his bank account
        if (std::stod(amountToTransfer) > currentUser.GetAccountBalance())
        {
            std::cout
                << CRVENA "BANKA >>" BIJELA " Nemate dovoljno novca na vašem računu, trenutni iznos je: " << ZUTA << currentUser.GetAccountBalance() << " KM" << std::endl;
            std::cout << CRVENA "BANKA >>" BIJELA " Stisnite" << ZUTA << " 'ENTER' " << BIJELA << "za povratak u meni... " << std::endl;
            std::cin.get();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return;
        }

        // >> Get all users, loop over that array and find one that have same Account Number as provided in the input field
        std::vector<User> users = User::GetAllUsers();
        int found = -1;

        for (int i = 0; i < users.size(); i++)
        {
            if (users[i].GetAccountNumber() == currentUser.GetAccountNumber())
            {
                users[i].BankAccount.SetAccountBalance(users[i].GetAccountBalance() - std::stod(amountToTransfer));
            }

            if (users[i].GetAccountNumber() == accountNumber)
            {
                found = i;

                try
                {
                    users[i].BankAccount.SetAccountBalance(users[i].GetAccountBalance() + std::stod(amountToTransfer));
                    currentUser.BankAccount.SetAccountBalance(currentUser.GetAccountBalance() - std::stod(amountToTransfer));
                    std::cout
                        << ZELENA "USPJEŠNA TRANSAKCIJA >>" BIJELA " Poslali ste: " << CYAN << amountToTransfer << " KM" << BIJELA << " na račun " << ZUTA << accountNumber << std::endl;
                    std::cout << CRVENA "BANKA >>" BIJELA " Stisnite" << ZUTA << " 'ENTER' " << BIJELA << "za povratak u meni... " << std::endl;
                    User::SaveUsers(users);

                    // >> Log that transaction
                    ITransaction data;

                    data.amount = std::stod(amountToTransfer);
                    data.from = currentUser.GetAccountNumber();
                    data.to = accountNumber;
                    data.type = "Direktna transakcija";
                    data.receiverFullName = users[i].GetFullName();
                    data.senderFullName = currentUser.GetFullName();

                    Transaction::CreateTransaction(&data);

                    std::cin.get();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                catch (const std::invalid_argument &e)
                {
                    std::cout
                        << CRVENA "BANKA >>" BIJELA " Došlo je do greške prilikom vaše transakcije, pokušajte ponovo." << std::endl;
                    std::cout << CRVENA "BANKA >>" BIJELA " Stisnite" << ZUTA << " 'ENTER' " << BIJELA << "za povratak u meni... " << std::endl;
                    std::cin.get();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }

                break;
            }
        }

        // >> If account is not found
        if (found == -1)
        {
            std::cout
                << CRVENA "BANKA >>" BIJELA " Bankovni račun " << ZUTA << accountNumber << BIJELA << " ne postoji u našoj databazi, pokušajte ponovo." << BIJELA << std::endl;
            std::cout << CRVENA "BANKA >>" BIJELA " Stisnite" << ZUTA << " 'ENTER' " << BIJELA << "za povratak u meni... " << std::endl;
            std::cin.get();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

#endif