#include<iostream>
using namespace std;
class Base1{
    public:
    void greet(){
        cout<<"How are you?"<<endl;
    }
};
class Base2{
    public:
    void greet(){
        cout<<"kasi ho?"<<endl;
    }
};
class Derived : public Base1,public Base2{
    int a;
    public:
    void greet(){
        Base1 :: greet(); // to fix ambiguity
        Base2 :: greet(); //we can also call both like this 
    }
};
int main(){
    Base1 base1obj;
    Base2 base2obj;
    base1obj.greet();
    base2obj.greet();
    Derived d;
    d.greet();// like this it will cause ambiguity
    return 0;
}    