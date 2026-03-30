#include <iostream>
using namespace std;
class Student
{
public:
    int age;
    // Constructor with argument
    Student(int a)
    {
        age = a;
    }
    // Copy constructor
    Student(const Student & moon)
    {
        age = moon.age;
        cout << "Copy constructor called!" << endl;
    }
};
int main()
{
    Student s1(20);  // normal constructor
    Student s2 = s1; // copy constructor
    cout<<s1.age<<endl;
    cout << s2.age << endl;
    return 0;
}