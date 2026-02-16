#include <iostream>
using namespace std;

class Account {
private:
    int account_no;
    double account_bal;
    int security_code;

    static int objectCount;   // static variable to count objects

public:
    // Function to initialize data
    void setData(int acc, double bal, int code) {
        account_no = acc;
        account_bal = bal;
        security_code = code;
        objectCount++;
    }

    // Function to display data
    void showData() {
        cout << "Account Number: " << account_no << endl;
        cout << "Account Balance: " << account_bal << endl;
        cout << "Security Code: " << security_code << endl;
    }

    // Static function to display object count
    static void showCount() {
        cout << "Total Objects Created: " << objectCount << endl;
    }
};

// Initialize static variable
int Account::objectCount = 0;

int main() {
    Account a1, a2;

    a1.setData(1001, 5000.75, 1234);
    a2.setData(1002, 8500.50, 5678);

    cout << "\nAccount 1 Details:\n";
    a1.showData();

    cout << "\nAccount 2 Details:\n";
    a2.showData();

    Account::showCount();   // calling static function

    return 0;
}
