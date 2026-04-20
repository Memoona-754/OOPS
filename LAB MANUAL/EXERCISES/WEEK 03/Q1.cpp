#include <iostream>
using namespace std;

class Complex {
private:
    double* real;
    double* imag;

public:
    // Constructor
  Complex(double r, double i) {
    real = new double(r);    // allocate a double on heap, initialise to r
    imag = new double(i);    // allocate a double on heap, initialise to i
}

    // Copy Constructor (Deep Copy)
    Complex(const Complex& obj) {
        real = new double(*(obj.real));
        imag = new double(*(obj.imag));
    }

    // Copy Assignment Operator (Rule of Three)
    Complex& operator=(const Complex& obj) {
        if (this != &obj) {         // self-assignment guard
            *real = *(obj.real);    // reuse existing memory
            *imag = *(obj.imag);
        }
        return *this;
    }

    void display() const {
        cout << *real << " + " << *imag << "i\n";
    }

    // Destructor
    ~Complex() {
        delete real;  real = nullptr;
        delete imag;  imag = nullptr;
    }
};

int main() {
    Complex c1(3.5, 4.2);
    Complex c2 = c1;          // copy constructor
    Complex c3(0, 0);
    c3 = c1;                  // copy assignment operator

    cout << "c1 (original): "; c1.display();
    cout << "c2 (copied):   "; c2.display();
    cout << "c3 (assigned): "; c3.display();

    return 0;
}
