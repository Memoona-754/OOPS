#include <iostream>
using namespace std;
/*
syntax for initialization list in constructor:
constructor(argument-list) : initilization-section{
        assignment+other code;
}

class Test{
int a;
int b;
public:
Test(int i, int j) : a(i), b(j){constructor-body}
};
*/

class Test
{
   // int a;// for all above 4 follow this order
   // int b;

   //for last one
   int b;
   int a;

public:
  // Test(int i, int j) : a(i), b(j)
   //Test(int i, int j) : a(i), b(i+j)
  // Test(int i, int j) : a(i), b(2*j)
  //Test(int i, int j) : a(i), b(a+j)
   Test(int i, int j) :  b(j),a(i+b)//this will cause problem as  a is decleared first
    { cout << "constructor-body executed"<<endl;
    cout<<"Value of a is "<<a<<endl;
    cout<<"Value of b is "<<b<<endl;
    }
};
int main()
{
    Test t(4, 6);
}