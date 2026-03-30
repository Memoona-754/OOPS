#include <iostream>
using namespace std;

class Person
{
public:
    int *age;
    Person(int a)
    {
        age = new int(a);//to allocate space in heep memory and initiliaze
    }
    // Shallow copy constructor
    Person(const Person &p)
    {
        age = p.age;  // just copies the address
    }
    ~Person()
    {
        delete age;
    }
};

int main()
{
    Person p1(30);
    Person p2 = p1; // shallow copy constructor
    cout << *p1.age << endl;
    cout << *p2.age << endl;
    return 0;
}


