#include<iostream>
using namespace std;
class Student{
    public:
          string name;
          int rollno;
          float gpa;

          Student(string s, int r, float g){
             name = s;
             rollno = r;
             gpa = g;
          }
};
int main(){
    Student s1("Memoona",166,8.2);
    //s1.name = "Memoona";
   // s1.rollno = 166;
   //   s1.gpa = 8.2;

    // Student s2;
    // s2.name = "Marium";
    // s2.rollno = 168;
    // s2.gpa = 8.9;

    cout<<s1.name<<" "<<s1.rollno<<" "<<s1.gpa<<" "<<endl;
   // cout<<s2.name<<" "<<s2.rollno<<" "<<s2.gpa<<" "<<endl;
}