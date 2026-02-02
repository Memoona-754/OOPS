#include<iostream>
uisng namespace std;

class Employee{
    int id;
    int count;
    public:
    void setData(void){
        cout<<"Entrer the id "<<endl;
        cin>>id;
    }
    void getData(void){
        cout<<"The id of this employee is "<<id;
    }
};

int main(){
    Employee harry;
   /* harry.id=1;
    harry.count = 1;  con't do this bcz id and count are private*/

    harry.setData();
    harry.getData();

    return 0;
}