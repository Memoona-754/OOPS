#include<iostream>
using namespace std;
class Complex{
    int a,b;
    public:
    void setNumber(int n1, int n2){
        a = n1;
        b = n2;
    }

    friend Complex sumComplex(Complex 01, Complex 02);
    void printNumber(){
        cout<<"Your number is "<<a<<" + "<<b<<"i";
    }
};

Complex sumComplex(Complex 01, Complex 02){
    Complex 03;
    03.setNumber((01.a + 02.a),(01.b + 02.b));
    return 03;
}
int main(){

    Complex c1, c2, sum;
    c1.setNumber(1,4);
    c2.setNumber(5,8);
    c1.primeNumber();
    c2.printNumber();

    sum = sumComplex(c1, c2);
    sum.printNumber(); 
    return 0;
}