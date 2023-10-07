#include <iostream>
#include <string>
using namespace std;

// >> Functions
#include "utils/colors.h"

// >> Classes
#include "interfaces/User.interface.h"
#include "interfaces/Worker.interface.h"
#include "interfaces/Account.interface.h"
#include "interfaces/Loan.interface.h"
#include "interfaces/Transaction.interface.h"

// >> Components
#include "components/User/Login.h"

int main()
{
    LoginForm();
    return 0;
}