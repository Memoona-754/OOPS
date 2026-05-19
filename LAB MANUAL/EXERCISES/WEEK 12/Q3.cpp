#include <iostream>
#include <fstream>
using namespace std;

class Person {
private:
    char name[50];
    int age;

public:
    // Parameterized Constructor
    Person(const char n[] = "", int a = 0) {
        int i = 0;

        while (n[i] != '\0') {
            name[i] = n[i];
            i++;
        }

        name[i] = '\0';
        age = a;
    }

    // Function to display data
    void display() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

int main() {

    // Create object
    Person person1("Memoona", 20);

    // Write object to binary file
    ofstream outFile("person.bin", ios::binary);

    if (!outFile) {
        cout << "File cannot be opened for writing." << endl;
        return 1;
    }

    outFile.write((char*)&person1, sizeof(person1));

    outFile.close();

    cout << "Object written to file successfully.\n" << endl;

    // Read object from binary file
    Person person2;

    ifstream inFile("person.bin", ios::binary);

    if (!inFile) {
        cout << "File cannot be opened for reading." << endl;
        return 1;
    }

    inFile.read((char*)&person2, sizeof(person2));

    inFile.close();

    cout << "Object read from file:\n" << endl;

    // Display object data
    person2.display();

    return 0;
}