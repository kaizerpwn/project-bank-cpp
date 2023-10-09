#include <iostream>
#include <string>

using namespace std;

// >> Functions
#include "utils/colors.h"

// >> Classes
#include "interfaces/Account.interface.h"
#include "interfaces/Loan.interface.h"
#include "interfaces/Transaction.interface.h"
#include "interfaces/User.interface.h"
#include "interfaces/Worker.interface.h"

User currentUser;

// >> Database
#include "database/Database.h"

// >> Components
#include "components/User/Login.h"
#include "components/User/Register.h"
#include "components/User/Main.h"

int main()
{
    MainForm();
    return 0;
}