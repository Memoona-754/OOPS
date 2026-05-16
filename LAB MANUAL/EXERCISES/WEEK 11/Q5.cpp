#include <iostream>
#include <set>
using namespace std;

int main() {

    set<string> guests;
    string name;
    char choice;

    cout << "===== Party Guest Management System =====\n";

    do {
        // Input guest name
        cout << "\nEnter guest name: ";
        cin >> name;

        // Insert into set
        guests.insert(name);

        // Ask user to continue
        cout << "Do you want to add another guest? (y/n): ";
        cin >> choice;

    } while(choice == 'y' || choice == 'Y');

    // Display unique guests
    cout << "\n===== Unique Guest List =====\n";

    for (auto it = guests.begin();
         it != guests.end(); it++) {

        cout << *it << endl;
    }

    // Display total count
    cout << "\nTotal Unique Guests: "
         << guests.size() << endl;

    return 0;
}