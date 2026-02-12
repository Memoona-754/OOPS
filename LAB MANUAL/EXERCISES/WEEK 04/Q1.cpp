#include <iostream>
#include <cstring>
using namespace std;

class Employee {
private:
    char* EmployeeName;
    const int EmployeeId;   // ID cannot change once initialized

public:

    // Parameterized Constructor using Member Initializer List
    Employee(const char* name, int id) : EmployeeId(id) {
        EmployeeName = new char[strlen(name) + 1];
        strcpy(EmployeeName, name);
    }

    // Destructor
    ~Employee() {
        delete[] EmployeeName;
    }

    // Getter for Name
    const char* getEmployeeName() const {
        return EmployeeName;
    }

    // Getter for ID
    int getEmployeeId() const {
        return EmployeeId;
    }

    // Setter for Name (ID has NO setter)
    void setEmployeeName(const char* name) {
        delete[] EmployeeName;   // remove old memory
        EmployeeName = new char[strlen(name) + 1];
        strcpy(EmployeeName, name);
    }
};

int main() {

    // Creating 3 initialized objects
    Employee Employee1("Ali", 101);
    Employee Employee2("Sara", 102);
    Employee Employee3("Ahmed", 103);

    // Changing names (allowed)
    Employee1.setEmployeeName("Usman");
    Employee2.setEmployeeName("Ayesha");

    // Displaying using getters
    cout << "Employee 1: " 
         << Employee1.getEmployeeName()
         << " | ID: " 
         << Employee1.getEmployeeId() << endl;

    cout << "Employee 2: " 
         << Employee2.getEmployeeName()
         << " | ID: " 
         << Employee2.getEmployeeId() << endl;

    cout << "Employee 3: " 
         << Employee3.getEmployeeName()
         << " | ID: " 
         << Employee3.getEmployeeId() << endl;

    return 0;
}