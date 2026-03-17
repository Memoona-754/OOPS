#include<iostream>
using namespace std;
class Base{
    int data;
    public:
    Base (int i){
        data=i;
        cout<<"Base class constructor called "<<endl;
    }
    void printData(void){
        cout<<"The value of data is "<<data<<endl;
    }
};
int main(){
     
}