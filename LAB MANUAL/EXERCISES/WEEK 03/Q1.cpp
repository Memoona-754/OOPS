#include <iostream>
using namespace std;

class Complex
{
private:
    int *real;
    int *imag;

public:
    // Constructor
    Complex(int r, int i)
    {
        real = new int;
        imag = new int;
        *real = r;
        *imag = i;
    }

    // Copy Constructor (Deep Copy)
    Complex(const Complex &obj)
    {
        real = new int;
        imag = new int;
        *real = *(obj.real);
        *imag = *(obj.imag);
    }

    // Display function
    void display()
    {
        cout << "Complex Number: " << *real << " + " << *imag << "i" << endl;
    }

    // Destructor
    ~Complex()
    {
        delete real;
        delete imag;
    }
};

int main()
{
    Complex c1(3, 4); // Original object
    Complex c2 = c1;  // Copy constructor called

    cout << "Object 1: ";
    c1.display();

    cout << "Object 2 (Copied): ";
    c2.display();

    return 0;
}
