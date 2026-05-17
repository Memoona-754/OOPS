// #include <iostream>
// #include <string>
// using namespace std;

// // Abstract Base Class
// class EncryptionTechnique {
// public:
//     // Pure Virtual Function
//     virtual void encrypt(string message) = 0;

//     // Virtual Destructor
//     virtual ~EncryptionTechnique() {}
// };

// // Derived Class for Technique 1
// class EncryptionTechnique1 : public EncryptionTechnique {
// public:
//     void encrypt(string message) override {

//         string encrypted = "";

//         for (int i = 0; i < message.length(); i++) {
//             encrypted += to_string((int)message[i]);
//         }

//         cout << "\nTechnique 1 Encryption: " << encrypted << endl;
//     }
// };

// // Derived Class for Technique 2
// class EncryptionTechnique2 : public EncryptionTechnique {
// public:
//     void encrypt(string message) override {

//         string encrypted = "";

//         for (int i = 0; i < message.length(); i++) {
//             encrypted += to_string(((int)message[i]) + 2);
//         }

//         cout << "Technique 2 Encryption: " << encrypted << endl;
//     }
// };

// // Main Function
// int main() {

//     string message;

//     cout << "Enter Message: ";
//     cin >> message;

//     // Base Class Pointers
//     EncryptionTechnique* ptr1;
//     EncryptionTechnique* ptr2;

//     // Dynamic Memory Allocation
//     ptr1 = new EncryptionTechnique1();
//     ptr2 = new EncryptionTechnique2();

//     // Calling Encrypt Functions
//     ptr1->encrypt(message);
//     ptr2->encrypt(message);

//     // Free Memory
//     delete ptr1;
//     delete ptr2;

//     return 0;
// }

#include <iostream>
#include <string>
using namespace std;

// Abstract Class
class EncryptionTechnique
{
public:
    // Pure virtual function
    virtual string encrypt(string msg) = 0;
};

// Technique 1
class EncryptionTechnique1 : public EncryptionTechnique
{
public:
    string encrypt(string msg)
    {
        string result = "";

        for (int i = 0; i < msg.length(); i++)
        {
            result += to_string((int)msg[i]);
        }

        return result;
    }
};

// Technique 2
class EncryptionTechnique2 : public EncryptionTechnique
{
public:
    string encrypt(string msg)
    {
        string result = "";

        for (int i = 0; i < msg.length(); i++)
        {
            result += to_string((int)msg[i] + 2);
        }

        return result;
    }
};

int main()
{
    string message;

    cout << "Enter message: ";
    cin >> message;

    EncryptionTechnique1 t1;
    EncryptionTechnique2 t2;

    cout << "\nTechnique 1 Encryption: "
         << t1.encrypt(message) << endl;

    cout << "Technique 2 Encryption: "
         << t2.encrypt(message) << endl;

    return 0;
}