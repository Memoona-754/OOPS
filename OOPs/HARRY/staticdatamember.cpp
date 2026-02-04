#include<iostream>
uisng namespace std;

class Employee{
    int id;
    static int count; //value of static variable is defaultly 0(zero) 
    public:
    void setData(void){
        cout<<"Entr the id "<<endl;
        cin>>id;
        count++;
    }
    void getData(void){
        cout<<"The id of this employee is "<<id<<"and this is employee number "<<count<<endl;
    }
    static void getCount(void){
        cout<<"The value of count is "<<count<<endl;
    }
};

int  Employee :: count;

int main(){
    Employee ali,ahad,ahmad;
   /* harry.id=1;
    harry.count = 1;  con't do this bcz id and count are private*/

    ali.setData();
    ali.getData();
    Employee::getCount();  
    ahad.setData();
    ahad.getData();
    Employee::getCount();
    ahmad.setData();
    ahmad.getData();
    Employee::getCount();
    
    return 0;
}