//CT_25166            //MEMOONA
#include <iostream>
#include <cmath>
using namespace std;

// ─────────────────────────────────────────
//  Base class
// ─────────────────────────────────────────
class Shape {
protected:
    int    numberOfSides;
    double area;

public:
    Shape(int sides, double area = 0.0)
        : numberOfSides(sides), area(area) {}

    // Accessors
    int    getNumberOfSides() const { return numberOfSides; }
    double getArea()          const { return area; }

    // Mutators
    void setNumberOfSides(int s)  { numberOfSides = s; }
    void setArea(double a)        { area = a; }
};

// ─────────────────────────────────────────
//  Rectangle
// ─────────────────────────────────────────
class Rectangle : public Shape {
protected:
    double length;
    double width;

public:
    Rectangle(double l, double w)
        : Shape(4), length(l), width(w) {}

    // Accessors
    double getLength() const { return length; }
    double getWidth()  const { return width;  }

    // Mutators
    void setLength(double l) { length = l; }
    void setWidth(double w)  { width  = w; }

    void generateArea() {
        area = length * width;
    }
};

// ─────────────────────────────────────────
//  Circle
// ─────────────────────────────────────────
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r)
        : Shape(0), radius(r) {}

    // Accessors / Mutators
    double getRadius() const   { return radius; }
    void   setRadius(double r) { radius = r; }

    void generateArea() {
        area = M_PI * radius * radius;
    }
};

// ─────────────────────────────────────────
//  Triangle
// ─────────────────────────────────────────
class Triangle : public Shape {
private:
    double height;
    double base;

public:
    Triangle(double h, double b)
        : Shape(3), height(h), base(b) {}

    // Accessors / Mutators
    double getHeight() const   { return height; }
    double getBase()   const   { return base;   }
    void   setHeight(double h) { height = h; }
    void   setBase(double b)   { base   = b; }

    void generateArea() {
        area = (height * base) / 2.0;
    }
};

// ─────────────────────────────────────────
//  Square  (inherits Rectangle)
// ─────────────────────────────────────────
class Square : public Rectangle {
public:
    // Passes the same side for both length and width
    Square(double side)
        : Rectangle(side, side) {}

    bool checkSides() const {
        return length == width;     // inherited from Rectangle
    }

    void generateArea() {
        area = length * length;
    }
};

// ─────────────────────────────────────────
//  Driver
// ─────────────────────────────────────────
int main() {
    Rectangle rect(8.0, 5.0);
    rect.generateArea();
    cout << "Rectangle area : " << rect.getArea() << endl;

    Circle circle(7.0);
    circle.generateArea();
    cout << "Circle area    : " << circle.getArea() << endl;

    Triangle tri(10.0, 6.0);
    tri.generateArea();
    cout << "Triangle area  : " << tri.getArea() << endl;

    Square sq(4.0);
    sq.generateArea();
    cout << "Square area    : " << sq.getArea() << endl;
    cout << "Equal sides?   : " << (sq.checkSides() ? "Yes" : "No") << endl;

    return 0;
}