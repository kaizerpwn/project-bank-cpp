#ifndef CREDIT_FUNCTIONS_H
#define CREDIT_FUNCTIONS_H

void RaiseCredit()
{
    // >> Check if user have job
    if (currentUser.WorkData.GetWorkerPosition() == "Unemployed")
    {
        std::cout
            << CRVENA "BANKA >>" BIJELA " Vi niste nigdje zaposleni tako da vam banka ne može pružiti opciju podizanja kredita." << std::endl;
        std::cout << CRVENA "BANKA >>" BIJELA " Stisnite" << ZUTA << " 'ENTER' " << BIJELA << "za povratak u meni... " << std::endl;
        std::cin.get();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    // >> Check if user already have credit on it's account
    if (currentUser.CreditData.GetCreditMonths() != 0)
    {
        std::cout
            << CRVENA "BANKA >>" BIJELA " Vi već imate neki podignuti kredit, prvo otplatite njega." << std::endl;
        std::cout << CRVENA "BANKA >>" BIJELA " Stisnite" << ZUTA << " 'ENTER' " << BIJELA << "za povratak u meni... " << std::endl;
        std::cin.get();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    const double credits[] = {10000, 20000, 30000, 40000, 50000, 60000, 80000, 90000};
    const int months[] = {12, 12, 12, 12, 14, 16, 16, 16};
    const int columnWidth = 20;

    std::cout << "+--------------------+--------------------+--------------------------+" << endl;
    std::cout << std::setw(columnWidth - 1) << std::right << "Količina (KM)";
    std::cout << std::setw(columnWidth - 1) << std::right << "Broj mjeseci";
    std::cout << std::setw(columnWidth - 1) << std::right << "Kamatna stopa";
    std::cout << std::endl;
    std::cout << "+--------------------+--------------------+--------------------------+" << endl;

    for (int i = 0; i < sizeof(credits) / sizeof(credits[0]); i++)
    {
        std::cout << std::setw(columnWidth - 1) << std::right << BIJELA << credits[i];
        std::cout << " KM" << std::setw(columnWidth - 1) << std::right << months[i];
        std::cout << std::setw(columnWidth - 1) << std::right << CYAN << "10% (" << calculateInterestRate(credits[i], 10, months[i]) << " KM)";
        std::cout << BIJELA << std::endl;
    }

    std::cout << "+--------------------+--------------------+--------------------------+" << endl;
    std::cout
        << CRVENA "BANKA >>" BIJELA " Unesite količinu kredita koju želite podići npr." << ZUTA << " 10000" << std::endl;
    std::cout << CRVENA "BANKA >>" BIJELA " Upišite" << ZUTA << " '-1' " << BIJELA << "za povratak u meni... " << std::endl;

    double creditAmount;
    std::cin >> creditAmount;

    if (creditAmount == -1)
    {
        return;
    }

    for (int i = 0; i < sizeof(credits) / sizeof(credits[0]); i++)
    {
        if (credits[i] == creditAmount)
        {
            std::vector<User> users = User::GetAllUsers();

            for (int j = 0; j < users.size(); j++)
            {
                if (users[j].GetEmail() == currentUser.GetEmail())
                {
                    users[j].CreditData.SetCreditAmount(creditAmount);
                    users[j].CreditData.SetCreditMonths(months[i]);
                    users[j].CreditData.SetCreditInterestRate(calculateInterestRate(credits[i], 10, months[i]));
                    break;
                }
            }

            currentUser.CreditData.SetCreditAmount(creditAmount);
            currentUser.CreditData.SetCreditMonths(months[i]);
            currentUser.CreditData.SetCreditInterestRate(calculateInterestRate(credits[i], 10, months[i]));

            User::SaveUsers(users);

            std::cout
                << ZELENA "USPJEŠNO >>" BIJELA " Podigli ste kredit u iznosu od: " << ZUTA << credits[i] << " KM" << BIJELA << ", otplaćivati ćete ga narednih " << months[i] << " sa kamatnom stopom od 10%" << std::endl;
            std::cout
                << CRVENA "BANKA >>" BIJELA " Stisnite" << ZUTA << " 'ENTER' " << BIJELA << "za povratak u meni... " << std::endl;

            std::cin.get();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

#endif