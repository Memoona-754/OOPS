#include<iostream>
using namespace std;
class Student{
    public:
        string name;
        int roll_no;
        int semester;
        char section;
};
int main(){
    Student s1 = {"Marium",168,2,'D'};
    Student s2 = {"Memoona",166,2,'D'};
    Student s3 = {"Masfa",177,8,'C'};
    Student s4 = {"Maham",122,5,'A'};

    Student studentS[4] = {s1,s2,s3,s4};

    cout<<"Students belonging to sec:A are : \n";
    for(int i=0;i<4;i++){
        if(studentS[i].section == 'A'){
            cout<<"Name: "<<studentS[i].name<<endl;
            cout<<"Roll no.: "<<studentS[i].roll_no<<endl;
            cout<<"Semester: "<<studentS[i].semester<<endl;
            cout<<"Section: "<<studentS[i].section<<endl;
        }
    }
    return 0;
}