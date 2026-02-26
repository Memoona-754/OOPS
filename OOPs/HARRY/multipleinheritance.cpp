#include<iostream>
using namespace std;

/*syntax for inheriting in multiple inheritance:
class Derived : cisinility mode base1, visibility mode base2{
      class body of class "DerivedC"
};*/
class Base1{
    protected:
    int base1int;
    public:
    void set_base1int(int a){
        base1int =a;
    }
};
class Base2{
    protected:
    int base2int;
    public:
    void set_base2int(int a){
        base2int =a;
    }
};
class Derived : public  Base1,public Base2{
    public:
    void show(){
        cout<<"The value of base1 is"<<base1int<<endl;
        cout<<"The value of base2 is"<<base2int<<endl;
        cout<<"The sum of values is"<<base1int  + base2int<<endl;

    }
};
int main(){
    return 0;
}