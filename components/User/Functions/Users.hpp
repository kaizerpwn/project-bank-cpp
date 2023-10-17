#ifndef USERS_FUNCTIONS_H
#define USERS_FUNCTIONS_H

void ViewAllUsers()
{
    // >> Check if user have job
    if (currentUser.WorkData.GetWorkerPosition() != "Banker")
    {
        std::cout
            << CRVENA "BANKA >>" BIJELA " Vi niste zaposleni u banci tako da nemate pristup ovoj opciji." << std::endl;
        std::cout << CRVENA "BANKA >>" BIJELA " Stisnite" << ZUTA << " 'ENTER' " << BIJELA << "za povratak u meni... " << std::endl;
        std::cin.get();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    std::vector<User> users = User::GetAllUsers();

    if (users.empty())
    {
        std::cout
            << CRVENA "BANKA >>" BIJELA " Trenutno ne postoji nijedan registrovani korisnik u databazi." << std::endl;
        std::cout << CRVENA "BANKA >>" BIJELA " Stisnite" << ZUTA << " 'ENTER' " << BIJELA << "za povratak u meni... " << std::endl;
        std::cin.get();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    const int columnWidth = 20;
    std::cout << "+--------------------+--------------------+--------------------+-----------------------------+--------------------+--------------------+--------------------+-----------------------------------------+" << std::endl;
    std::cout << std::setw(columnWidth - 1) << std::left << "ID korisnika";
    std::cout << std::setw(columnWidth - 1) << std::right << "Ime";
    std::cout << std::setw(columnWidth - 1) << std::right << "Prezime";
    std::cout << std::setw(columnWidth - 1) << std::right << "Email";
    std::cout << std::setw(columnWidth - 1) << std::right << "\t\tSpol";
    std::cout << std::setw(columnWidth - 1) << std::right << "\tDatum rođenja";
    std::cout << std::setw(columnWidth - 1) << std::right << "Broj mobitela";
    std::cout << std::setw(columnWidth - 1) << std::right << "Posao";
    std::cout << std::endl;
    std::cout << "+--------------------+--------------------+--------------------+-----------------------------+--------------------+--------------------+--------------------+-----------------------------------------+" << std::endl;

    for (int i = 0; i < users.size(); i++)
    {
        std::cout << "|" << std::setw(columnWidth - 1) << std::left << CYAN << i + 1;
        std::cout << ")" << std::setw(columnWidth - 1) << std::right << BIJELA << users[i].GetName();
        std::cout << std::setw(columnWidth - 1) << std::right << users[i].GetSurname();
        std::cout << std::setw(columnWidth - 1) << std::right << CYAN << users[i].GetEmail();
        std::cout << std::setw(columnWidth - 1) << std::right << CYAN << users[i].GetGender();
        std::cout << std::setw(columnWidth - 1) << std::right << CYAN << users[i].GetBirthDate();
        std::cout << std::setw(columnWidth - 1) << std::right << BIJELA << users[i].GetPhoneNumber();
        std::cout << std::setw(columnWidth - 1) << std::right << BIJELA << users[i].WorkData.GetWorkerPosition();
        std::cout << "|" << std::endl;
    }

    std::cout << "+--------------------+--------------------+--------------------+-----------------------------+-------------------+--------------------+--------------------+-----------------------------------------+" << std::endl;
}

void ShowAllUsers()
{
    ViewAllUsers();
    std::cout << CRVENA "BANKA >>" BIJELA " Stisnite" << ZUTA << " 'ENTER' " << BIJELA << "za povratak u meni... " << std::endl;
    std::cin.get();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

#endif