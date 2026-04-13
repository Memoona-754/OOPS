//CT_25166            //MEMOONA
#include <iostream>
using namespace std;

class Calculator {
private:
    double Num1, Num2, Num3;

public:
    Calculator() {
        cout << "Enter three numbers: ";
        cin >> Num1 >> Num2 >> Num3;
    }

    double add(double a, double b) {
        return a + b;
    }

    double add(double a, double b, double c) {
        return a + b + c;
    }

    double subtract(double a, double b) {
        return a - b;
    }

    double subtract(double a, double b, double c) {
        return a - b - c;
    }

    double multiply(double a, double b) {
        return a * b;
    }

    double multiply(double a, double b, double c) {
        return a * b * c;
    }

    double divide(double a, double b) {
        if (b == 0) {
            cout << "  [Error] Division by zero!\n";
            return 0;
        }
        return a / b;
    }

    double divide(double a, double b, double c) {
        if (b == 0 || c == 0) {
            cout << "  [Error] Division by zero!\n";
            return 0;
        }
        return a / b / c;
    }

    double getNum1() const { return Num1; }
    double getNum2() const { return Num2; }
    double getNum3() const { return Num3; }
};

int main() {
    Calculator calc;   

    double n1 = calc.getNum1();
    double n2 = calc.getNum2();
    double n3 = calc.getNum3();

    cout << "\nNumbers entered  :  "
         << n1 << ",  " << n2 << ",  " << n3 << "\n";
         
    // Addition
    cout << "add("  << n1 << ", " << n2 << ")         = "
         << calc.add(n1, n2)         << "\n";
    cout << "add("  << n1 << ", " << n2 << ", " << n3 << ")   = "
         << calc.add(n1, n2, n3)     << "\n\n";

    // Subtraction
    cout << "subtract(" << n1 << ", " << n2 << ")     = "
         << calc.subtract(n1, n2)    << "\n";
    cout << "subtract(" << n1 << ", " << n2 << ", " << n3 << ") = "
         << calc.subtract(n1, n2, n3)<< "\n\n";

    // Multiplication
    cout << "multiply(" << n1 << ", " << n2 << ")     = "
         << calc.multiply(n1, n2)    << "\n";
    cout << "multiply(" << n1 << ", " << n2 << ", " << n3 << ") = "
         << calc.multiply(n1, n2, n3)<< "\n\n";

    // Division
    cout << "divide(" << n1 << ", " << n2 << ")       = "
         << calc.divide(n1, n2)      << "\n";
    cout << "divide(" << n1 << ", " << n2 << ", " << n3 << ")  = "
         << calc.divide(n1, n2, n3)  << "\n";

    return 0;
}