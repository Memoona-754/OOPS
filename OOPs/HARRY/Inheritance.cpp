#include<iostream>
using namespace std;
//base class
class Employee{
    int id;
    public:
    float salary;  
            Employee(int inpId){
                id = inpId;
                salary = 34.0;
            }
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

 };
int main(){
    Employee mm(1),nn(2);
    cout<<mm.salary<<endl;
    cout<<nn.salary;   
    Programmer skillf(1);
    return 0;
}