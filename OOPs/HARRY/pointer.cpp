#include<iostream>
using namespace std;
int main(){
    //basic example
    int a=4;
    int *ptr = &a;
    cout<<"The value of a is "<<*(ptr)<<endl;

    //new keyword
    int *p= new int(30);
    cout<<"The value at address p is "<<*(p);
    return 0; 
}