#include <iostream>
using namespace std;

class Employee
{
private:
    // Private attribute
    int salary;

public:
    // Setter
    void setSalary(int s)
    {
        salary = s;
    }
    // Getter
    int getSalary()
    {
        cout<<"The salary is:"<<salary<<endl;
        return salary;
    }
};

int main()
{
    Employee myObj;
    myObj.setSalary(50000);
    myObj.getSalary();
    return 0;
}