#pragma once
#include <string>

class Classes {
public:
    static void run();
};

class BankAccount {
private:
    double balance = 0.0;
    std::string account_number;

public:
    BankAccount(const double bal, const std::string& acc_num)
    {
        balance = bal;
        account_number = acc_num;
    }

    void deposit(const double amount)
    {
        balance += amount;
    }

    bool withdraw(const double amount)
    {
        if (balance < amount) {
            return false;
        }

        balance -= amount;
        return true;
    }

    [[nodiscard]] double get_balance() const
    {
        return balance;
    }
};