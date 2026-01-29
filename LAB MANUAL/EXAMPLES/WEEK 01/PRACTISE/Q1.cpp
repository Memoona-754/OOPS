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

        Lab()
};
int main(){
    Lab oops;
    cout<<"The section is: "<<oops.sec<<endl;
    cout<<"The roll nmbr is: "<<oops.roll_no;

    return 0;
}