#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using std::endl;
using std::string;

// >> Functions
#include "utils/colors.hpp"

// >> Classes
#include "interfaces/Account.interface.hpp"
#include "interfaces/Credit.interface.hpp"
#include "interfaces/Transaction.interface.hpp"
#include "interfaces/User.interface.hpp"
#include "interfaces/Worker.interface.hpp"

User currentUser;

// >> Database
#include "database/Database.hpp"

// >> Components
#include "components/Header.hpp"
#include "components/User/Login.hpp"
#include "components/User/Register.hpp"
#include "components/User/Main.hpp"
#include "components/User/Dashboard.hpp"

int main()
{
    srand(time(0));
    MainForm();
    return 0;
}