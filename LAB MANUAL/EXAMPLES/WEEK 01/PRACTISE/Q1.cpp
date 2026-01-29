#include<iostream>
using namespace std;
class Lab{
    public:
        char sec;
        int roll_no;

        Lab(){
            sec = 'A';
            roll_no = 166;
        }

        Lab(char s,int r){
            sec = s;
            roll_no = r;
        }
};
int main(){
    Lab oops1;
    cout<<"The section is: "<<oops1.sec<<endl;
    cout<<"The roll nmbr is: "<<oops1.roll_no<<endl;

    Lab oops2('B',55);
    cout<<"The section is: "<<oops2.sec<<endl;
    cout<<"The roll nmbr is: "<<oops2.roll_no<<endl;

    return 0;
}