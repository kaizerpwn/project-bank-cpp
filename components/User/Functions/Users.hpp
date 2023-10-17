#ifndef USERS_FUNCTIONS_H
#define USERS_FUNCTIONS_H

bool IsBanker()
{
    if (currentUser.WorkData.GetWorkerPosition() != "Banker")
    {
        std::cout
            << CRVENA "BANKA >>" BIJELA " Vi niste zaposleni u banci tako da nemate pristup ovoj opciji." << std::endl;
        std::cout << CRVENA "BANKA >>" BIJELA " Stisnite" << ZUTA << " 'ENTER' " << BIJELA << "za povratak u meni... " << std::endl;
        std::cin.get();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    return true;
}

void ViewAllUsers()
{
    // >> Check if user have job
    if (IsBanker() == false)
        return;

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

void EditUser()
{
    if (IsBanker() == false)
        return;

    ViewAllUsers();
    std::cout << CRVENA "BANKA >>" BIJELA " Unesite" << ZUTA << " 'ID korisnika' " << BIJELA << "kojeg želite izmijeniti... " << std::endl;

    std::vector<User> users = User::GetAllUsers();
    int id;
    bool found = false;

    std::cin >> id;

    for (int i = 0; i < users.size(); i++)
    {
        if (i + 1 == id)
        {
            found = true;
            string option;
            do
            {
                std::cout << CRVENA "BANKA >>" BIJELA " Unesite" << ZUTA << " 'STAVKU' " << BIJELA << "koju želite urediti kod korisnika: " << users[i].GetFullName() << std::endl;
                std::cout << MAGENTA "OPCIJE >>" BIJELA " email | datumrodjenja | lokacija | brojmobitela | posao\n"
                          << std::endl;
                std::cout << CRVENA "BANKA >>" BIJELA " Za povratak nazad u meni unesite" << ZUTA << " '-1' " << std::endl;

                std::cin >> option;

                // >> Editing options & their logic
                if (option == "email")
                {
                    string email;
                    std::cout << CRVENA "BANKA >>" BIJELA " Unesite novi" << ZUTA << " 'EMAIL' " << BIJELA << "koji želite postaviti ovom korisniku: " << std::endl;
                    std::cin >> email;
                    users[i].SetEmail(email);
                    User::SaveUsers(users);

                    std::cout << ZELENA "USPJEŠNO >>" BIJELA " Novi email korisnika " << ZUTA << users[i].GetFullName() << BIJELA << " je: " << email << std::endl;
                    std::cout << CRVENA "BANKA >>" BIJELA " Stisnite" << ZUTA << " 'ENTER' " << BIJELA << "da nastavite dalje sa uređivanjem... " << std::endl;

                    std::cin.get();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }

                else if (option == "datumrodjenja")
                {
                    string birthDate;
                    std::cout << CRVENA "BANKA >>" BIJELA " Unesite novi" << ZUTA << " 'DATUM ROĐENJA' " << BIJELA << "koji želite postaviti ovom korisniku: " << std::endl;
                    std::cin >> birthDate;
                    users[i].SetBirthDate(birthDate);
                    User::SaveUsers(users);

                    std::cout << ZELENA "USPJEŠNO >>" BIJELA " Novi datum rođenja korisnika " << ZUTA << users[i].GetFullName() << BIJELA << " je: " << birthDate << std::endl;
                    std::cout << CRVENA "BANKA >>" BIJELA " Stisnite" << ZUTA << " 'ENTER' " << BIJELA << "da nastavite dalje sa uređivanjem... " << std::endl;

                    std::cin.get();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }

                else if (option == "lokacija")
                {
                    string city;
                    std::cout << CRVENA "BANKA >>" BIJELA " Unesite novu" << ZUTA << " 'LOKACIJU' " << BIJELA << "koji želite postaviti ovom korisniku: " << std::endl;
                    std::cin >> city;
                    users[i].SetLocation(city);
                    User::SaveUsers(users);

                    std::cout << ZELENA "USPJEŠNO >>" BIJELA " Nova lokacija korisnika " << ZUTA << users[i].GetFullName() << BIJELA << " je: " << city << std::endl;
                    std::cout << CRVENA "BANKA >>" BIJELA " Stisnite" << ZUTA << " 'ENTER' " << BIJELA << "da nastavite dalje sa uređivanjem... " << std::endl;

                    std::cin.get();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }

                else if (option == "brojmobitela")
                {
                    string phoneNumber;
                    std::cout << CRVENA "BANKA >>" BIJELA " Unesite novi" << ZUTA << " 'BROJ MOBITELA' " << BIJELA << "koji želite postaviti ovom korisniku: " << std::endl;
                    std::cin >> phoneNumber;
                    users[i].SetPhoneNumber(phoneNumber);
                    User::SaveUsers(users);

                    std::cout << ZELENA "USPJEŠNO >>" BIJELA " Novi broj mobitela korisnika " << ZUTA << users[i].GetFullName() << BIJELA << " je: " << phoneNumber << std::endl;
                    std::cout << CRVENA "BANKA >>" BIJELA " Stisnite" << ZUTA << " 'ENTER' " << BIJELA << "da nastavite dalje sa uređivanjem... " << std::endl;

                    std::cin.get();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }

                else if (option == "posao")
                {
                    string jobTitle;
                    std::cout << CRVENA "BANKA >>" BIJELA " Unesite novi" << ZUTA << " 'POSAO' " << BIJELA << "koji želite postaviti ovom korisniku: " << std::endl;
                    std::cin >> jobTitle;
                    users[i].WorkData.SetWorkerPosition(jobTitle);
                    User::SaveUsers(users);

                    std::cout << ZELENA "USPJEŠNO >>" BIJELA " Novi posao korisnika " << ZUTA << users[i].GetFullName() << BIJELA << " je: " << jobTitle << std::endl;
                    std::cout << CRVENA "BANKA >>" BIJELA " Stisnite" << ZUTA << " 'ENTER' " << BIJELA << "da nastavite dalje sa uređivanjem... " << std::endl;

                    std::cin.get();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                else if (option == "-1")
                {
                    break;
                }
                else
                {
                    std::cout << CRVENA "GREŠKA >>" BIJELA " Opcija za uređivanje '" << ZUTA << option << BIJELA << "' ne postoji, pokušajte ponovo" << std::endl;
                    std::cout << CRVENA "BANKA >>" BIJELA " Stisnite" << ZUTA << " 'ENTER' " << BIJELA << "da nastavite dalje sa uređivanjem... " << std::endl;

                    std::cin.get();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            } while (option != "-1");
            break;
        }
    }

    if (found == false)
    {
        std::cout << CRVENA "BANKA >>" BIJELA " Ne postoji korisnik sa takvim" << ZUTA << " 'ID-om' " << BIJELA << " u nasoj databazi... " << std::endl;
        std::cout << CRVENA "BANKA >>" BIJELA " Stisnite" << ZUTA << " 'ENTER' " << BIJELA << "za povratak u meni... " << std::endl;

        std::cin.get();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void DeleteUser()
{
    if (IsBanker() == false)
        return;

    ViewAllUsers();
    std::cout << CRVENA "BANKA >>" BIJELA " Unesite" << ZUTA << " 'ID korisnika' " << BIJELA << "kojeg želite obrisati iz databaze... " << std::endl;
    std::cout << CRVENA "BANKA >>" BIJELA " Unesite" << ZUTA << " '-1' " << BIJELA << "za povratak u meni... " << std::endl;

    std::vector<User> users = User::GetAllUsers();
    int id;
    bool found = false;
    std::cin >> id;

    if (id == -1)
    {
        return;
    }

    for (int i = 0; i < users.size(); i++)
    {
        if (i + 1 == id)
        {
            std::cout << CRVENA "USPJEŠNO >>" BIJELA " Obrisali ste korisnika '" << ZUTA << users[i].GetFullName() << BIJELA << "' iz databaze... " << std::endl;
            std::cout << CRVENA "BANKA >>" BIJELA " Stisnite" << ZUTA << " 'ENTER' " << BIJELA << "za povratak u meni... " << std::endl;
            users.erase(users.begin() + i);
            User::SaveUsers(users);
            found = true;

            std::cin.get();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
    }

    if (found == false)
    {
        std::cout << CRVENA "BANKA >>" BIJELA " Ne postoji korisnik sa takvim" << ZUTA << " 'ID-om' " << BIJELA << " u nasoj databazi... " << std::endl;
        std::cout << CRVENA "BANKA >>" BIJELA " Stisnite" << ZUTA << " 'ENTER' " << BIJELA << "za povratak u meni... " << std::endl;

        std::cin.get();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

#endif