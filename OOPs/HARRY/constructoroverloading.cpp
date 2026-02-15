#include<iostream>
using namespace std;
class Complex{
    int a,b;
    public:
    Complex(int x, int y){
        a = x;
        b = y;
    }
    void printNumber(){
        cout<<"Yoyr number is "<<a<<" + "<<b <<" i "<<endl;
    }
};
int main(){
    Complex c1(4,6);
    c1.printNumber();
    return 0;
}