#include<iostream>
using namespace std;
// With exception handling
int main() {
    int a = 10, b = 0;
    try {
        if (b == 0)
            throw "Division by zero!";  // 🚨 Throw error
        cout << a / b;
    }
    catch (const char* msg) {
        cout << "Error: " << msg;       // ✅ Handled gracefully
    }
}