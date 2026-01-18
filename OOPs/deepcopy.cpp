#include<iostream>
using namespace std;
class Student{  //Student is a new data type
    public:
         string name;
         int rno;
         float gpa;

         Student(){    //defult constructor

         }

         Student(string s, int r, float g){   //parameterized constructor
             name = s;
             rno = r;
             gpa = g;
         }
};

int main(){
    Student s1("Memoona",166,3.3); 

    Student s2;      //details  are being printed bcz of defult constructor
    s2.name = "Marium";
    s2.rno = 168;
    s2.gpa = 3.6;

    Student s3 = s1;
    s3.name = "Maham";

    cout<<s1.name<<" "<<s1.gpa<<" "<<s1.rno<<endl;
    cout<<s2.name<<" "<<s2.gpa<<" "<<s2.rno<<endl;
    cout<<s3.name<<" "<<s3.gpa<<" "<<s3.rno<<endl;
}