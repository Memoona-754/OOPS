#include<iostream>
using namespace std;
class Shape{
    private:
    int numberofSides;
    float area;
    //mutator = setter   ,    accessors = getter
    public:
    Shape(int n, float a){
         numberofSides = n;
         area = a;
        }

    void setShape(int num,float ar){
        numberofSides = num;
        area = ar;
    }
    void getShape(){
        return numberofSides , area;
    }
};
class Rectangle : public Shape {
private:
    float length, width;
    float area;

public:
    // Parameterized constructor
    Rectangle(float l, float w) {
        length = l;
        width = w;
        //area = 0;
    }

    // Function to calculate area
    void generateArea() {
        area = length * width;
    }

    void display() {
        cout << "Rectangle Area: " << area << endl;
    }
};

class Circle : public Shape {
private:
    float radius;
    float area;

public:
    // Parameterized constructor
    Circle(float r) {
        radius = r;
        area = 0;
    }

    // Function to calculate area
    void generateArea() {
        area = 3.1416 * radius * radius;
    }

    void display() {
        cout << "Circle Area: " << area << endl;
    }
};

class Triangle : public shape{
       public:
       int  height;
       int base;
       Triangle(int h, int b){
        height h;
        base b;
    }
    float generateArea(){
        area=(height*base)/2;
    } 
     
      void display() {
        cout << "Circle Area: " << area << endl;
    }
}

int main() {
    Rectangle rect(5, 3);
    rect.generateArea();
    rect.display();

    Circle circ(4);
    circ.generateArea();
    circ.display();

    Triangle tri(4,4);
    tri.generateArea();
    tri.display();
    return 0;
}