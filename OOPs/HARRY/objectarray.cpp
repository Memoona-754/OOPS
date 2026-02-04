#include<iostream>
using namespace std;

class Employee{
    int id;
    int salary;
    public:
         void setId(void){
            salary = 122;
            cout<<"Enter the id of employee ";
            cin>>id;
         }
         void getId(void){
            cout<<"The id of this employee is "<<id<<endl;
         }
};

int main(){
     /*Employee Mubashir, Masfa, Memoona, Noor;
     Mubashir.setId();
     Mubashir.getId();
     Masfa.setId();
     Masfa.getId();
     Memoona.setId();
     Memoona.getId();
     Noor.setId();
     Noor.getId();*/

     //other way

     Employee fb[4];
     for (int i=0;i<4;i++){
        fb[i].setId();
        fb[i].getId();
     }
    return 0;
}