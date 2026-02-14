#include<iostream>
using namespace std;

class Complex{
    int a,b;
    public:
    Complex(void);
    void printNumber(){
        cout<<"Your number is "<<a<<" + "<<b<<" i "<<endl;
    }
};
Complex :: Complex(void){
    a = 0;
    b = 0;
}
int main(){
    Complex a;
    a.printNumber();
    return 0;
}