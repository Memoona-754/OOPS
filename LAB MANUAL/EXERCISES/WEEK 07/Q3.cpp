#include <iostream>
using namespace std;

class Payroll; // forward declaration

class Employee {
private:
    string name;
    int id;
    string designation;
    double salary;

public:
    // Constructor
    Employee(string n, int i, string d, double s) {
        name = n;
        id = i;
        designation = d;
        salary = s;
    }

    // Display function
    void display() {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Designation: " << designation << endl;
        cout << "Salary: " << salary << endl;
    }

    //  Friend Class Declaration
    friend class Payroll;
};

class Payroll {
public:
    // Function to update salary
    void updateSalary(Employee &e, double increment) {
        e.salary += increment;  // Direct access to private member
    }
};

int main() {
    Employee emp("Ali", 101, "Manager", 50000);

    cout << "Before Update:\n";
    emp.display();

    Payroll p;
    p.updateSalary(emp, 10000); // increase salary

    cout << "\nAfter Update:\n";
    emp.display();

    return 0;
}