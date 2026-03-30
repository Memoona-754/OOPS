#include <iostream>
using namespace std;
class Person
{
public:
    int *age;
    Person(int a)
    {
        age = new int(a);
    }
    ~Person()
    {
        delete age;
    }
};
int main()
{
    Person p1(30);
    Person p2 = p1; // default copy constructor
    return 0;
}