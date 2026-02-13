#include <iostream>
using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    Person() {
        name = "";
        age = 0;
    }

    void setPerson(string n, int a) {
        name = n;
        age = a;
    }

    void displayPerson() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Student : public virtual Person {
protected:
    int rollNumber;

public:
    void setStudent(string n, int a, int r) {
        setPerson(n, a);
        rollNumber = r;
    }

    void displayStudent() {
        displayPerson();
        cout << "Roll Number: " << rollNumber << endl;
    }
};

class Employee : public virtual Person {
protected:
    int employeeID;

public:
    void setEmployee(string n, int a, int id) {
        setPerson(n, a);
        employeeID = id;
    }

    void displayEmployee() {
        displayPerson();
        cout << "Employee ID: " << employeeID << endl;
    }
};

class TeachingAssistant : public Student, public Employee {
public:
    void setTA(string n, int a, int r, int id) {
        setPerson(n, a);
        rollNumber = r;
        employeeID = id;
    }

    void displayTA() {
        cout << "----- Teaching Assistant Information -----" << endl;
        displayPerson();
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Employee ID: " << employeeID << endl;
    }
};

int main() {
    TeachingAssistant ta;  

    ta.setTA("Ali Khan", 24, 101, 5001);
    ta.displayTA();

    return 0;
}
