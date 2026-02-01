#include<iostream>
using namespace std;

class Employee{
    private:
         int a,b,c;
    public:
         int d,e;
        
         //functions can be decleared in and out of class
         void setData(int a1, int b1,int c1);//declearation
         void getData(){  //function decleration and definition
            cout<<"The value of a is "<<a<<endl;
            cout<<"The value of b is "<<b<<endl;
            cout<<"The value of c is "<<c<<endl;
            cout<<"The value of d is "<<d<<endl;
            cout<<"The value of e is "<<e<<endl;
         }  
};

void Employee :: setData(int a1,int b1,int c1){ //function definition out of class 
    a = a1;
    b = b1;
    c  = c1;
}

int main(){
    Employee Harry;
   // Harry.a = 134;  bcz a is private cannot be accessed directly but can be by a function 
    Harry.d = 77;
    Harry.e = 86;
    Harry.setData(1,2,4);
    Harry.getData();

    return 0;
}