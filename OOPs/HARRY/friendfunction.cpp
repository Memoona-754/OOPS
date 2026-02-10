#include<iostream>
using namespace std;
class Complex{
    int a,b;
    public:
    void setNumber(int n1, int n2){
        a = n1;
        b = n2;
    }
    //this line means that sunComplex can access private functions and variables of class
    friend Complex sumComplex(Complex 01, Complex 02);
    void printNumber(){
        cout<<"Your number is "<<a<<" + "<<b<<"i";
    }
};
//its just a friend  function and not a member of complex class functions
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

/*Properties of friend function:
1. Not in the scope of class
2. Since it is not in the scope of class ,it cannot be called from the objects
of that class. c1.sumComplex()== Invalid
3. Can be invoked without the help of any object
4. Usually cantains the objects as arguments 
5. Can be decleared inside public or private section of the class
6. It cannot access the members directly by their names and need object_name.member_name
to access any member. */