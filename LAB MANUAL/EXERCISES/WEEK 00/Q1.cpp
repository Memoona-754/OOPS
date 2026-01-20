// Write a program that take input of your roll number along with the marks obtained
// in five subjects and display the total marks obtained and the percentage.

#include<iostream>
using namespace std;
int main(){
     int rollNo,marks[5],totalMarks=0;
     cout<<"Enter your roll no:";
     cin>>rollNo;
     cout<<"Enter marks (5 subjects):";
     for(int i=0; i<5; i++){
	     cin>>marks[i];
	     totalMarks+=marks[i];
    }
    cout<<"Total marks obtained:"<<totalMarks;
    int percentage = (totalMarks * 100)/500;
    cout<<"\nPercentage:"<<percentage;
}