#include "classes.h"

#include <iostream>

void Classes::run()
{
    auto account = BankAccount(1'000, "ACCT12345");
    account.deposit(500);
    if (account.withdraw(2'000)) {
        std::cout << "witthdrew $2,000 from account: ACCT12345" << std::endl;
        std::cout << "balance: " << account.get_balance() << std::endl;
    }
    else {
        std::cout << "not enough funds to withdraw $2,000 from ACCT12345!" << std::endl;
        std::cout << "balance: " << account.get_balance() << std::endl;
    }
}
