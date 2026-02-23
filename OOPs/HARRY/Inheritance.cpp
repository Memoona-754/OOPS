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

int main(){
    Employee mm(1),nn(2);
    cout<<mm.salary<<endl;
    cout<<nn.salary;   
    return 0;
}