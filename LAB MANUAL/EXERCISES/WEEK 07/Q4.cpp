#include <iostream>
using namespace std;

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

    // 🔥 Friend Function Declaration
    friend void updateSalary(Employee &e, double increment);
};

// 🔥 Friend Function Definition
void updateSalary(Employee &e, double increment) {
    e.salary += increment;  // ✅ Access private member
}

int main() {
    Employee emp("Ali", 101, "Manager", 50000);

    cout << "Before Update:\n";
    emp.display();

    // Call friend function
    updateSalary(emp, 8000);

    cout << "\nAfter Update:\n";
    emp.display();

    return 0;
}