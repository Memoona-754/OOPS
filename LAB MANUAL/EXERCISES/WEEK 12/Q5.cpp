#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void countLines() {

    ifstream file("STORY.TXT");

    if (!file) {
        cout << "File cannot be opened." << endl;
        return;
    }

    string line;

    int count = 0;

    while (getline(file, line)) {

        // Check if line does not start with 'A'
        if (line[0] != 'A') {
            count++;
        }
    }

    file.close();

    cout << "Number of lines not starting with A: "
         << count << endl;
}

int main() {

    countLines();

    return 0;
}