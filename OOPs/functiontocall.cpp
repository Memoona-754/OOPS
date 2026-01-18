#include<iostream>
using namespace std;
class Cricketer{
    public:
       int runs;
       string name;
       float avg;

       Cricketer(string name,int runs,float avg){
        this->name = name;  //using this bcz parameter of constructor and class datatypes has same name
        this->runs = runs;
        this->avg = avg;
       }
};

void print(Cricketer c){
    cout<<c.name<<" "<<c.runs<<" "<<c.avg<<endl;
}

int main(){
    Cricketer c1("Babar Azam", 30000,60.9);
    Cricketer c2("Rizwan", 20000,55.8);

  //  cout<<c1.name<<" "<<c1.runs<<endl;
   // cout<<c2.name<<" "<<c2.runs<<endl;

   print(c1);
   print(c2); 
}  