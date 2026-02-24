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
    cout<<b.a;
    return 0;
}