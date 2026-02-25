#include<iostream>
using namespace std;
class Student{
    protected:
    int roll_number;
    public:
    void set_roll_number(int);
    void get_roll_number(void);
};
void Student :: set_roll_number(int r){
    roll_number=r;
}
void Student :: get_roll_number(){
    cout<<roll_number<<endl;
}
class Exam :: public Student{
    protected:
    float maths;
    float physics;
    public:
    void set_marks(float,float);
    void get_marks(void);
};void Exam :: set_marks(float m1, float m2){
    maths = m1;
    physics = m2;
}
void Exam :: get_marks(){
    cout<<"The marks in maths are: "<<maths<<endl;
    cout<<"The physics  in maths are: "<<physics<<endl;
}
int main(){

}