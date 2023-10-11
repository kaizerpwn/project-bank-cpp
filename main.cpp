#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

// >> Functions
#include "utils/colors.hpp"

// >> Classes
#include "interfaces/Account.interface.hpp"
#include "interfaces/Loan.interface.hpp"
#include "interfaces/Transaction.interface.hpp"
#include "interfaces/User.interface.hpp"
#include "interfaces/Worker.interface.hpp"

User currentUser;

// >> Database
#include "database/Database.hpp"

// >> Components
#include "components/User/Login.hpp"
#include "components/User/Register.hpp"
#include "components/User/Main.hpp"

int main()
{
    MainForm();
    return 0;
}