#include <iostream>
#include <fstream>
using namespace std;

class Participant {
private:
    int id;
    char name[50];
    float score;

public:

    // Input function
    void Input() {
        ofstream outFile("participant.dat", ios::binary | ios::app);

        cout << "Enter ID: ";
        cin >> id;

        cin.ignore();

        cout << "Enter Name: ";
        cin.getline(name, 50);

        cout << "Enter Score: ";
        cin >> score;

        outFile.write((char*)this, sizeof(*this));

        outFile.close();

        cout << "Record stored successfully.\n" << endl;
    }

    // Output function
    void Output() {
        int searchID;
        bool found = false;

        ifstream inFile("participant.dat", ios::binary);

        cout << "Enter ID to search: ";
        cin >> searchID;

        while (inFile.read((char*)this, sizeof(*this))) {

            if (id == searchID) {

                cout << "\nParticipant Found\n";
                cout << "ID: " << id << endl;
                cout << "Name: " << name << endl;
                cout << "Score: " << score << endl;

                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Participant not found." << endl;
        }

        inFile.close();
    }

    // Max function
    void Max() {

        ifstream inFile("participant.dat", ios::binary);

        Participant temp;

        float maxScore = -1;

        while (inFile.read((char*)&temp, sizeof(temp))) {

            if (temp.score > maxScore) {
                maxScore = temp.score;

                id = temp.id;

                int i = 0;
                while (temp.name[i] != '\0') {
                    name[i] = temp.name[i];
                    i++;
                }

                name[i] = '\0';

                score = temp.score;
            }
        }

        cout << "\nParticipant with Highest Score\n";
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Score: " << score << endl;

        inFile.close();
    }
};

int main() {

    Participant p;

    int choice;

    do {
        cout << "\n===== MENU =====" << endl;
        cout << "1. Add Participant" << endl;
        cout << "2. Search Participant by ID" << endl;
        cout << "3. Show Highest Score" << endl;
        cout << "4. Exit" << endl;

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            p.Input();
            break;

        case 2:
            p.Output();
            break;

        case 3:
            p.Max();
            break;

        case 4:
            cout << "Program Ended." << endl;
            break;

        default:
            cout << "Invalid choice." << endl;
        }

    } while (choice != 4);

    return 0;
}