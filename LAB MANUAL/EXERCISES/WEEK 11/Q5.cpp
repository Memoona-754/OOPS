#include<iostream>
#include<set>
#include<string>
using namespace std;

int main(){
    set<string> guests;
    string names;
    
    cout << "Enter guest names (type 'stop' to finish):\n";
    
    while(names != "stop"){
        cout << "Guest name: ";
        cin >> names;
        
        if(names != "stop") {
            guests.insert(names);
        }
    }
    
    cout << "\nUnique guests (alphabetically):\n";
    for(string name : guests){     
        cout << "- " << name << "\n"; 
    }
    
    cout << "\nTotal unique guests: " << guests.size() << "\n";
    
    return 0;
}

#include <iostream>
#include <set>
#include <string>
using namespace std;

class PartyGuests {

private:
    set<string> guests;

public:

    // Function to add guests
    void addGuest() {

        string name;
        char choice;

        do {

            cout << "Enter guest name: ";
            getline(cin, name);

            guests.insert(name);

            cout << "Do you want to add another guest? (y/n): ";
            cin >> choice;

            cin.ignore();

        } while (choice == 'y' || choice == 'Y');
    }

    // Function to display guests
    void displayGuests() {

        cout << "\n===== Unique Guest List =====\n";

        for (set<string>::iterator it = guests.begin();
             it != guests.end(); it++) {

            cout << *it << endl;
        }
    }

    // Function to display total guests
    void countGuests() {

        cout << "\nTotal Unique Guests: "
             << guests.size() << endl;
    }
};

int main() {

    PartyGuests party;

    // Add guest names
    party.addGuest();

    // Display unique guests
    party.displayGuests();

    // Display total count
    party.countGuests();

    return 0;
}