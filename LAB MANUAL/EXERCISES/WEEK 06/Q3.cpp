//CT_25166            //MEMOONA
#include <iostream>
#include <cmath>
using namespace std;

class Vector {
private:
    double x, y;

public:
    // Constructor
    Vector(double x = 0, double y = 0) : x(x), y(y) {}

    // Accessors
    double getX() const { return x; }
    double getY() const { return y; }

    // Vector + Vector
    Vector operator+(const Vector& v) const {
        return Vector(x + v.x, y + v.y);
    }

    // Vector - Vector
    Vector operator-(const Vector& v) const {
        return Vector(x - v.x, y - v.y);
    }

    // Vector * scalar
    Vector operator*(double scalar) const {
        return Vector(x * scalar, y * scalar);
    }

    // Vector / scalar
    Vector operator/(double scalar) const {
        if (scalar == 0) {
            cout << "  [Error] Division by zero!\n";
            return Vector(0, 0);
        }
        return Vector(x / scalar, y / scalar);
    }

    double magnitude() const {
        return sqrt(x * x + y * y);
    }

    void print(const string& label) const {
        cout << label << " = (" << x << ", " << y << ")\n";
    }
};

int main() {
    Vector v1(6.0, 8.0);
    Vector v2(3.0, 4.0);

    v1.print("v1          ");
    v2.print("v2          ");

    // Addition
    Vector sum = v1 + v2;
    sum.print("v1 + v2     ");

    // Subtraction
    Vector diff = v1 - v2;
    diff.print("v1 - v2     ");

    // Multiplication by scalar
    Vector scaled = v1 * 3.0;
    scaled.print("v1 * 3      ");

    // Division by scalar
    Vector divided = v1 / 2.0;
    divided.print("v1 / 2      ");

    // Magnitudes
    cout << "|v1| = sqrt(" << v1.getX() << "^2 + "
         << v1.getY() << "^2) = " << v1.magnitude() << "\n";
    cout << "|v2| = sqrt(" << v2.getX() << "^2 + "
         << v2.getY() << "^2) = " << v2.magnitude() << "\n";

    return 0;
}