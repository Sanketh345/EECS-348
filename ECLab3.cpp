#include <iostream>
#include <string>

using namespace std;

class Account;  

class Account {
protected:
    string accountNumber;
    string accountHolder;
    double balance;

public:
    Account(string num, string holder, double bal)
        : accountNumber(num), accountHolder(holder), balance(bal) {}

    virtual void displayDetails() const = 0; 

    void deposit(double amount) {
        balance += amount;
    }

    virtual bool withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            return true;
        } else {
            cout << "Insufficient balance!" << endl;
            return false;
        }
    }
};


class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount(string num, string holder, double bal, double rate)
        : Account(num, holder, bal), interestRate(rate) {}

    void displayDetails() const override {
        cout << "Account Details for Savings Account (ID: " << accountNumber << "):\n"
             << "   Holder: " << accountHolder << "\n"
             << "   Balance: $" << balance << "\n"
             << "   Interest Rate: " << interestRate * 100 << "%" << endl;
    }

    bool withdraw(double amount) override {
        if (balance - amount >= 100) { 
            Account::withdraw(amount);
            return true;
        } else {
            cout << "Cannot withdraw! Minimum balance requirement not met." << endl;
            return false;
        }
    }
};


class CurrentAccount : public Account {
private:
    double overdraftLimit;

public:
    CurrentAccount(string num, string holder, double bal, double limit)
        : Account(num, holder, bal), overdraftLimit(limit) {}

    void displayDetails() const override {
        cout << "Account Details for Current Account (ID: " << accountNumber << "):\n"
             << "   Holder: " << accountHolder << "\n"
             << "   Balance: $" << balance << "\n"
             << "   Overdraft Limit: $" << overdraftLimit << endl;
    }

    bool withdraw(double amount) override {
        if (balance + overdraftLimit >= amount) {
            balance -= amount;
            return true;
        } else {
            cout << "Overdraft limit exceeded!" << endl;
            return false;
        }
    }
};


CurrentAccount& operator+(CurrentAccount& current, SavingsAccount& savings) {
    double transferAmount = 300; 
    if (savings.withdraw(transferAmount)) {
        current.deposit(transferAmount);
    } else {
        cout << "Transfer failed due to insufficient funds in Savings Account." << endl;
    }
    return current;
}

int main() {
    SavingsAccount savings("S123", "John Doe", 1000, 0.02);
    CurrentAccount current("C456", "Jane Doe", 2000, 500);

    savings.displayDetails();
    current.displayDetails();

    savings.deposit(500);
    current.withdraw(1000);

    cout << "\nAccount Details after deposit and withdrawal:" << endl;
    savings.displayDetails();
    current.displayDetails();

    current = current + savings;

    cout << "\nAccount Details after transfer:" << endl;
    savings.displayDetails();
    current.displayDetails();

    return 0;
}

