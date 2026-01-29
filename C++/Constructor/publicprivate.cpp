#include<iostream>
using namespace std;

class Employee
{
public:
    string name;
    int salary;

    Employee(string n, int s, int sp)
    {
        this->name = n;
        this->salary = s;
        this->secretPassword = sp;
    }

    void printDetails()
    {
        cout << "The name of our first employee is " << this->name << " and his salary is " << this->salary << " Dollars" << endl;
    }

    void getSecretPassword()
    {
        cout<<"The secret password of employee is "<<this->secretPassword;
    }

private:
    int secretPassword;
};

class Programmer : public Employee{
    public:
    int errors;
};

int main(){
     Employee har("Harry constructor",344,2345);

     har.printDetails();
     har.getSecretPassword(); 
    return 0;
}