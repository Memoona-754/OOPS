#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main() {
    char str[100];

    // Input string
    cout << "Enter a string: ";
    cin.getline(str, 100);

    // Calculate length of string
    int length = strlen(str);

    cout << "Length of string = " << length << endl;

    // Store string in file
    ofstream outFile("data.txt");

    if (!outFile) {
        cout << "File cannot be opened for writing." << endl;
        return 1;
    }

    outFile << str;

    outFile.close();

    cout << "String stored in file successfully." << endl;

    // Fetch stored characters from file
    ifstream inFile("data.txt");

    if (!inFile) {
        cout << "File cannot be opened for reading." << endl;
        return 1;
    }

    char ch;

    cout << "Characters fetched from file:" << endl;

    while (inFile.get(ch)) {
        cout << ch;
    }

    inFile.close();

    return 0;
}