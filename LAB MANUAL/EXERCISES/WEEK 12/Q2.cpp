#include <iostream>
#include <fstream>
using namespace std;

int main() {
    char ch;

    // Open source file
    ifstream sourceFile("source.txt");

    // Open destination file
    ofstream destinationFile("destination.txt");

    // Check if files opened successfully
    if (!sourceFile) {
        cout << "Source file cannot be opened." << endl;
        return 1;
    }

    if (!destinationFile) {
        cout << "Destination file cannot be opened." << endl;
        return 1;
    }

    // Copy contents character by character
    while (sourceFile.get(ch)) {
        destinationFile.put(ch);
    }

    cout << "File copied successfully." << endl;

    // Close files
    sourceFile.close();
    destinationFile.close();

    return 0;
}