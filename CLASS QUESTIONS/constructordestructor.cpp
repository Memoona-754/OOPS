#include<iostream>
using namespace std;
class Car {
public:
Car() { cout << "Object created"<<endl; } // constructor
~Car() { cout << "Object destroyed"; } // destructor
};
int main(){
    Car myCar;  //constructor called here
    return 0;   // destructor called here automatically
    
}