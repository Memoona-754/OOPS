#include <iostream>
using namespace std;
class Number
{
    int a;

public:
    Number()
    {
        a = 0;
    }
    Number(int num)
    {
        a = num;
    }
    // when no copy constructor is found, compiler supplies its own copy constructor thats way this code is working even after commiting below copy constructor
    //  Number(Number &obj){
    //      cout<<"Copy constructor called!!!"<<endl;
    //      a=obj.a;
    //  }

    void display()
    {
        cout << "The number for this object is " << a << endl;
    }
};
int main()
{
    Number x, y, z(45),z2;
    x.display();
    y.display();
    z.display();
    Number z1(z); // copy constructor invoked
    z1.display();
    z2 = z;  
    z2.display();      // copy constructor not called
    Number z3 = z; // copy costructor invoked
    z3.display();
    return 0;
}