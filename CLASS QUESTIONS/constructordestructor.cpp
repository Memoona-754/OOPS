#include<iostream>
using namespace std;
class Car {
public:
Car() { cout << "Object created"<<endl; } // constructor
~Car() { cout << "Object destroyed"; } // destructor
};
int main(){
    Car myCar;
    return 0;
    
}