#ifndef LOGIN_COMPONENT_H
#define LOGIN_COMPONENT_H

void LoginForm()
{
        string email;
        string password;

        system("clear");

        printf("" CYAN " __                         __                                       \n");
        printf("" CYAN "|  \\                       |  \\                                      \n");
        printf("" CYAN "| ▓▓____   ______  _______ | ▓▓   __       ______   ______   ______  \n");
        printf("" CYAN "| ▓▓    \\ |      \\|       \\| ▓▓  /  \\     |      \\ /      \\ /      \\ \n");
        printf("" CYAN "| ▓▓▓▓▓▓▓\\ \\▓▓▓▓▓▓\\ ▓▓▓▓▓▓▓\\ ▓▓_/  ▓▓      \\▓▓▓▓▓▓\\  ▓▓▓▓▓▓\\  ▓▓▓▓▓▓\\\n");
        printf("" CYAN "| ▓▓  | ▓▓/      ▓▓ ▓▓  | ▓▓ ▓▓   ▓▓      /      ▓▓ ▓▓  | ▓▓ ▓▓  | ▓▓\n");
        printf("" CYAN "| ▓▓__/ ▓▓  ▓▓▓▓▓▓▓ ▓▓  | ▓▓ ▓▓▓▓▓▓\\     |  ▓▓▓▓▓▓▓ ▓▓__/ ▓▓ ▓▓__/ ▓▓\n");
        printf("" CYAN "| ▓▓    ▓▓\\▓▓    ▓▓ ▓▓  | ▓▓ ▓▓  \\▓▓\\     \\▓▓    ▓▓ ▓▓    ▓▓ ▓▓    ▓▓\n");
        printf("" CYAN "\\▓▓▓▓▓▓▓  \\ ▓▓▓▓▓▓▓\\▓▓   \\▓▓\\▓▓   \\▓▓      \\▓▓▓▓▓▓▓ ▓▓▓▓▓▓▓| ▓▓▓▓▓▓▓ \n");
        printf("" CYAN "                                                  | ▓▓     | ▓▓      \n");
        printf("" CYAN "                                                  | ▓▓     | ▓▓      \n");
        printf("" CYAN "                                                   \\▓▓      \\▓▓      \n");

        printf("" CYAN "BANK >>" BIJELA " Molimo Vas unesite Vas email za prijavu.\n");
        std::getline(cin, email);

        printf("" CYAN "BANK >>" BIJELA " Sada unesite Vasu lozinku za prijavu.\n");
        std::getline(cin, email);
}

#endif
