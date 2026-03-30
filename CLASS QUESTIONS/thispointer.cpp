#include <iostream>
using namespace std;

class Person
{
private:
    int age;
    string name;

public:
    // constructor using this pointer
    Person(int age, string name)
    {
        (*this).age = age;   // this->age = member variable
        this->name = name; // age, name = parameters
    }

    void display()
    {
        cout << "Name: " << this->name << endl;
        cout << "Age: "  << this->age  << endl;
    }
};

int main()
{
    Person p1(20, "Ali");
    Person p2(25, "Sara");

    p1.display();
    p2.display();

    return 0;
}
// ```

// Output:
// ```
// Name: Ali
// Age: 20
// Name: Sara
// Age: 25
// ```

// ---

// **What `this` is doing here:**

// When `p1.display()` runs:
// ```
// this = address of p1 → prints p1's data
// ```
// When `p2.display()` runs:
// ```
// this = address of p2 → prints p2's data