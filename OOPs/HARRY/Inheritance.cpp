#include<iostream>
using namespace std;
//base class
class Employee{
    public:
    int id;
    public:
    float salary;  
            Employee(int inpId){
                id = inpId;
                salary = 34.0;
            }
            Employee(){}
}; 
//derived class
/*
class {{derived-class-name}} : {{visibility-mode}} {{base-class-name}}
{
class members/functions/methods etc....
}*/
//default visibility mode is private
 class Programmer : Employee{
    public:
    Programmer(int inpId){
        id = inpId;
    }
    int languagecode =9;
     void getData(){
        cout<<id<<endl; 
     }
 };
int main(){
    Employee mm(1),nn(2);
    cout<<mm.salary<<endl;
    cout<<nn.salary<<endl;   
    Programmer skillf(1);
    cout<<skillf.languagecode<<endl;
    cout<<skillf.id<<endl;
    skillf.getData();
    return 0;
}