#include <iostream>
using namespace std;

class Vehicle {                       // abstract class
public:
    virtual void start() = 0;         // pure virtual → no body
    virtual void stop() = 0;          // derived MUST override this
    virtual ~Vehicle() {}
};

class Car : public Vehicle {
public:
    void start() override {
        cout << "Car engine starts\n";
    }
    void stop() override {
        cout << "Car engine stops\n";
    }
};

class Bike : public Vehicle {
public:
    void start() override {
        cout << "Bike engine starts\n";
    }
    void stop() override {
        cout << "Bike engine stops\n";
    }
};

int main() {
    // Vehicle v;                     // ERROR! cannot create abstract object

    Vehicle* v1 = new Car();
    Vehicle* v2 = new Bike();

    v1->start();
    v1->stop();

    v2->start();
    v2->stop();

    delete v1;
    delete v2;
}