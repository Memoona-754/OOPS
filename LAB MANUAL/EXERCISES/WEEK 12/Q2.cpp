#include <iostream>
#include <fstream>
using namespace std;

int main() {
    string sourceName, destinationName;
    char ch;

    cout << "Enter source file name: ";
    cin >> sourceName;

    cout << "Enter destination file name: ";
    cin >> destinationName;

    ifstream sourceFile(sourceName);
    ofstream destinationFile(destinationName);

    if (!sourceFile) {
        cout << "Source file cannot be opened." << endl;
        return 1;
    }

    if (!destinationFile) {
        cout << "Destination file cannot be opened." << endl;
        return 1;
    }

    while (sourceFile.get(ch)) {
        destinationFile.put(ch);
    }

    cout << "File copied successfully." << endl;

    sourceFile.close();
    destinationFile.close();

    return 0;
}