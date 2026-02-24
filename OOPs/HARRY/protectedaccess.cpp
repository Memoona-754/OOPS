#include <iostream>
using namespace std;
class Base
{
    protected:
    int a;
    private:
    int b;
};
class Derived
{
};
int main()
{
    Base b;
    Derived d;
   // cout<<b.a;  will not work as A is protected in both base and derived class
    return 0;
}