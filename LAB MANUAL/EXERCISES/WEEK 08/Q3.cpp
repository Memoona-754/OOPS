#include <iostream>
using namespace std;

class Account {
protected:
    double Balance;

public:
    // Default constructor – takes user input
    Account() {
        cout << "Enter initial balance: ";
        cin >> Balance;
    }

    // Parameterized constructor
    Account(double balance) : Balance(balance) {}

    virtual void deposit(double amount) {
        Balance += amount;
        cout << "Deposited: " << amount << " | New Balance: " << Balance << endl;
    }

    virtual void withdraw(double amount) {
        if (amount > Balance)
            cout << "Insufficient funds!\n";
        else {
            Balance -= amount;
            cout << "Withdrawn: " << amount << " | New Balance: " << Balance << endl;
        }
    }

    void checkBalance() {
        cout << "Current Balance: " << Balance << endl;
    }
};

class InterestAccount : virtual public Account {
protected:
    double Interest;

public:
    // Default constructor – takes user input
    InterestAccount() : Account() {
        cout << "Enter interest rate (default 0.30): ";
        cin >> Interest;
    }

    // Parameterized constructor
    InterestAccount(double balance, double interest = 0.30)
        : Account(balance), Interest(interest) {}

    // Overrides Account::deposit – adds interest on every deposit
    void deposit(double amount) override {
        double withInterest = amount + (amount * Interest);
        Balance += withInterest;
        cout << "Deposited: " << amount
             << " | Interest Added: " << (amount * Interest)
             << " | New Balance: " << Balance << endl;
    }
};

class ChargingAccount : virtual public Account {
protected:
    double fee;

public:
    // Default constructor – takes user input
    ChargingAccount() : Account() {
        cout << "Enter withdrawal fee (default 25): ";
        cin >> fee;
    }

    // Parameterized constructor
    ChargingAccount(double balance, double fee = 25.0)
        : Account(balance), fee(fee) {}

    // Overrides Account::withdraw – deducts fee on every withdrawal
    void withdraw(double amount) override {
        double total = amount + fee;
        if (total > Balance)
            cout << "Insufficient funds (including fee of Rs." << fee << ")!\n";
        else {
            Balance -= total;
            cout << "Withdrawn: " << amount
                 << " | Fee Charged: " << fee
                 << " | New Balance: " << Balance << endl;
        }
    }
};

class ACI : public InterestAccount, public ChargingAccount {
public:
    // Default constructor – takes user input
    ACI() : Account(), InterestAccount(), ChargingAccount() {}

    // Parameterized constructor
    ACI(double balance, double interest = 0.30, double fee = 25.0)
        : Account(balance), InterestAccount(balance, interest),
          ChargingAccount(balance, fee) {}

    // Transfer amount to a plain Account object
    void transfer(double amount, Account& account) {
        if (amount > Balance)
            cout << "Insufficient funds for transfer!\n";
        else {
            Balance -= amount;
            account.deposit(amount);
            cout << "Transferred " << amount << " to Account. Remaining Balance: " << Balance << endl;
        }
    }

    // Transfer amount to an InterestAccount object
    void transfer(double amount, InterestAccount& acc) {
        if (amount > Balance)
            cout << "Insufficient funds for transfer!\n";
        else {
            Balance -= amount;
            acc.deposit(amount);
            cout << "Transferred " << amount << " to InterestAccount. Remaining Balance: " << Balance << endl;
        }
    }
};

int main() {
    cout << "==============================\n";
    cout << "      ACCOUNT SYSTEM DEMO\n";
    cout << "==============================\n\n";

    // --- InterestAccount test ---
    cout << "-- InterestAccount (balance=1000, interest=30%) --\n";
    InterestAccount ia(1000, 0.30);
    ia.checkBalance();
    ia.deposit(500);      // 500 + 30% = 650 added
    ia.withdraw(200);
    ia.checkBalance();

    cout << "\n-- ChargingAccount (balance=2000, fee=Rs.25) --\n";
    ChargingAccount ca(2000, 25);
    ca.checkBalance();
    ca.withdraw(300);     // 300 + 25 = 325 deducted
    ca.deposit(100);
    ca.checkBalance();

    cout << "\n-- ACI Account (balance=5000, interest=30%, fee=Rs.25) --\n";
    ACI aci(5000, 0.30, 25);
    aci.checkBalance();

    cout << "\nTransfer Rs.1000 from ACI to InterestAccount:\n";
    aci.transfer(1000, ia);
    ia.checkBalance();
    aci.checkBalance();

    cout << "\nTransfer Rs.500 from ACI to plain Account:\n";
    Account acc(0);
    aci.transfer(500, acc);
    acc.checkBalance();

    return 0;
}