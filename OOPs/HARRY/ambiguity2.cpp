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
class B{
    public:
    void say(){
        cout<<"Hello world"<<endl;//<<endl;
    }
};
class D:public B{
int a;
//D's new say() method will override base class's say() method
    public:
    void say (){
        cout<<"Hello my beautiful people"<<endl;
    }
};
int main(){

    /*ambiguity 1
    Base1 base1obj;
    Base2 base2obj;
    base1obj.greet();
    base2obj.greet();
    Derived d;
    d.greet();// like this it will cause ambiguity*/

    //ambiguity 2
    B b;
    b.say();

    D d;
    d.say();

    return 0;
}    