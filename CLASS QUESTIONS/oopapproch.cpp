#include <iostream>
using namespace std;
class BankAccount
{
private:
    float balance;

public:
    BankAccount()
    {
        balance = 0;
    }
    void deposit(float amount)
    {
        balance += amount;
    }
    void withdraw(float amount)
    {
        if (amount <= balance)
            balance -= amount;
    }
    void display()
    {
        cout << "Balance: " << balance << endl;
    }
};
int main()
{
    BankAccount acc;
    acc.deposit(1000);
    acc.withdraw(500);
    acc.display();
    return 0;
}