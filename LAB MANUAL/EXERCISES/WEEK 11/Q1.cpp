#include <iostream>
#include <string>
#include <exception>
using namespace std;

// Custom Exception Class
class InvalidPasswordException : public exception {
public:
    const char* what() const noexcept {
        return "Password must be at least 6 characters long and contain at least one digit.";
    }
};

int main() {
    string username, password;
    bool hasDigit = false;

    try {
        cout << "Enter Username: ";
        cin >> username;

        cout << "Enter Password: ";
        cin >> password;

        // Check password length
        if (password.length() < 6) {
            throw InvalidPasswordException();
        }

        // Check if password contains a digit
        for (int i = 0; i < password.length(); i++) {
            if (isdigit(password[i])) {
                hasDigit = true;
                break;
            }
        }

        if (!hasDigit) {
            throw InvalidPasswordException();
        }

        cout << "\nLogin Successful!" << endl;
    }

    catch (InvalidPasswordException &e) {
        cout << "\nException Caught: " << e.what() << endl;
    }

    return 0;
}