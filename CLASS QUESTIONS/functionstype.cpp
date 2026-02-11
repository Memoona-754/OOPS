#include <iostream>
using namespace std;

// 1. No return, no arguments

void addNoReturnNoArgs() {
    int a=20, b=50;
    int sum = a + b;
    cout << "Sum = " << sum << endl;
}


// 2. Return, no arguments

int addReturnNoArgs() {
    int a=20, b=50;
    return a + b;
}

// 3. No return, with arguments

void addNoReturnWithArgs(int a, int b) {
    int sum = a + b;
    cout << "Sum = " << sum << " (no return, with args)" << endl;
}


// 4. Return, with arguments

int addReturnWithArgs(int a, int b) {
    return a + b;
}


// Main function to call all four

int main() {
    // 1. No return, no arguments
    addNoReturnNoArgs();

    // 2. Return, no arguments
    int result1 = addReturnNoArgs();
    cout << "Sum = " << result1 << " (return, no args)" << endl;

    // 3. No return, with arguments
    int x=50, y=100;
    addNoReturnWithArgs(x, y);

    // 4. Return, with arguments
    int a=40, b=60;
    int result2 = addReturnWithArgs(a, b);
    cout << "Sum = " << result2 << " (return, with args)" << endl;

    return 0;
}