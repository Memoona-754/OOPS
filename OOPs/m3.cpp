// #include<iostream>
// using namespace std;
// class Employee{
//     public:
//     string name;
//     virtual void work(){
//         cout<<"Employee is working"<<endl;
//     }
// };
// class Developer:public Employee{
//     public:
//     void work()override{
//         cout<<"Developer is writing code"<<endl;
//     }
// };
// class Designer : public Employee{
//     public:
//     void work()override{
//         cout<<"Designer is making UI"<<endl;
//     }
// };
// int main(){
//     Employee* a = new Employee();
//     Employee* b = new Developer();
//     Employee* c= new Designer();

//     a->work();
//     b->work();
//     c->work();

//     delete a;
//     delete b;
//     delete c;

// }
#include<iostream>
using namespace std;
class Account{
    public:
    string ownername;
    Account(){
        cout<<"Account created\n";
    }
    virtual void showtype(){
        cout<<"Basic Account\n";
    }
    virtual ~  Account()
    {
        cout<<"Account closed\n";
    }
};
class Savingaccount : public Account{
    public:
    void showtype()override{
        cout<<"Saving account\n";
    }
    ~ Savingaccount(){
        cout<<"Saving accout closed\n";
    }
};
class Currentaccount : public Account{
    public:
    void showtype ( ) override{
        cout<<"Current account\n";
    }
    ~Currentaccount(){
        cout<<"Current account closed\n";
    }
};

int main(){
    Account* arr[3];
    arr[0]= new Account();
    arr[1]=new Savingaccount();
    arr[2]=new Currentaccount();

    for(int i=0;i <3;i++){
        arr[i]->showtype();
    }
    for (int i=0;i<3;i++){
        delete arr[i];
    }

    return 0;
}