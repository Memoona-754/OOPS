#include<iostream>
using namespace std;
class Employee{
    public:
    string name;
    virtual void work(){
        cout<<"Employee is working"<<endl;
    }
};
class Developer:public Employee{
    public:
    void work()override{
        cout<<"Developer is writing code"<<endl;
    }
};
class Designer : public Employee{
    public:
    void work()override{
        cout<<"Designer is making UI"<<endl;
    }
};
int main(){
    Employee* a = new Employee();
    Employee* b = new Developer();
    Employee* c= new Designer();

    a->work();
    b->work();
    c->work();

    delete a;
    delete b;
    delete c;

}