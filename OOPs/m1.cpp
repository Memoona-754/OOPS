// #include <iostream>

// using namespace std;

// class Athlete {
// private:
//     string name;
//     string sport;
//     int age;
//     float salary;
// public:

//     Athlete(){
//         name = "Ali";
//         sport = "Hokey";
//         age = 16;
//         salary = 10000;
//     }

//     void setname(string m){
//         name = m;
//     }
//     void print() {
//         cout << name << " is " << age << " years old and earns $" << salary << " by playing " << sport << endl;
//     }
// };
// int main(){
//     Athlete A1;
//     A1.print();
//     A1.setname("Ahmed");
//     A1.print();
// }

// #include <iostream>

// using namespace std;

// class Athlete {
// private:
//     string name;
//     string sport;
//     int age;
//     float salary;
// public:
//    // string name;

//       Athlete(){
//         name = "Marium";
//         sport = "Hokey";
//         age = 16;
//         salary = 10000;
//   }

//     Athlete(string n,string s,int a,float y){
//         name = n;
//         sport = s;
//         age = a;
//         salary = y;
//     }

//     void setname(string m){
//         name =  m;
//     }

//     string getname(){

//         return name;
//     }

//     void setsport(string c){
//         sport = c;
//     }

//     string getsport(){
//         return sport;
//     }

//     void print() {
//         cout << name << " is " << age << " years old and earns $" << salary << " by playing " << sport << endl;
//     }
// };
// int main(){
//     Athlete A1("Ali","Hokey",11,1000);
//     A1.print();
//    // A1.name = "Ahmed";
//     A1.setname("Ahmad");
//     A1.print();
//     cout<<A1.getname()<<endl;

//     Athlete A2;
//     A2.print();
//     cout<<A2.getname()<<endl;
//     A2.setsport("Cricket");
//     A2.print();

// }

// #include<iostream>
// using namespace std;
// class Book{
//     string book_title;
//     int nmbr_pages;
//     float price;
//     int quantity;

//     public:
//     Book(string b,int n,float p, int q){
//           book_title = b;
//           nmbr_pages = n;
//           price = p;
//           quantity = q;
//     }
//     void print(){
//         cout<<book_title <<" is "<<nmbr_pages<<" pages long,the price for "<<quantity<<" books is "<<quantity*price<<endl;
//     }
//     ~Book(){         //delets every object individually
//         cout<<"Destructor is called!"<<endl;
//     }
// };

// int main(){
//     Book b1("Programming in C++",300,5000,3);
//     b1.print();

//     Book b2("Fundamentals of Programming",400,4000,1);
//     b2.print();

//     return 0;
// }

// #include<iostream>
// using namespace std;
// class BankAccount{
//     string name;
//     float balance;
//     float debt;
//     public:
//     BankAccount(string n,float b, float d){
//         name = n;
//         balance = b;
//         debt = d;

//         cout<<"Constructor for "<< name << " is called!"<<endl;
//     }
//     void print (){
//         cout<<name <<" has a balance of "<<balance<<" $ "<<debt<<" debt "<<endl;
//     }

//     void setBalance(int newbalance){
//         balance = newbalance;
//     }
//     ~BankAccount(){
//         cout<<"Destructor for "<<name<<" is called !"<<endl;
//     }
// };
// int main(){
//     BankAccount a1("Memoona",33333.000,88.0);
//     a1.print();
//     BankAccount a2("Marium",6666666666,888);
//     a2.setBalance(9999);
//     a2.print();

//     return 0;
// }

// #include<iostream>
// using namespace std;
// class BankAccount{
//     string name;
//     float balance;
//     float debt;
//     public:
//     BankAccount(string name,float balance, float debt){
//        this -> name = name;
//         this -> balance = balance;
//         this -> debt = debt;

//         cout<<"Constructor for "<< name << " is called!"<<endl;
//     }
//     void print (){
//         cout<<name <<" has a balance of "<<balance<<" $ "<<debt<<" debt "<<endl;
//     }

//     void setBalance(int newbalance){
//         balance = newbalance;
//     }
//     ~BankAccount(){
//         cout<<"Destructor for "<<name<<" is called !"<<endl;
//     }
// };
// int main(){
//     BankAccount a1("Memoona",33333.000,88.0);
//     a1.print();
//     BankAccount a2("Marium",6666666666,888);
//     a2.setBalance(9999);
//     a2.print();

//     return 0;
// }

// #include <iostream>
// using namespace std;

// class Student {
// private:
//     string name;
//     float gpa;
//     string major;
// public:
//     Student(string name = "", float gpa = 0, string major = "") {
//         this->name = name;
//         this->gpa = gpa;
//         this->major = major;
//     }

//     // Write copy constructor
//     Student(const Student & s){
//         name = s.name;
//         gpa = s.gpa;
//         major = s.major;
//     }
//     void setter(string n){
//            //this -> name = name;
//           name = n;
//     }
//     void print(){
//         cout<<name <<gpa <<major<<endl;
//     }
// };
// int main(){
//     Student s1("Memoona",3.5,"CSIT");\
//     Student s2 = s1;
//     s1.print();
//     s2.setter("Marium");
//     s2.print();
//     s1.setter("Masfa");
//     s1.print();
//     s2.print();
//     //cout<<s1.name <<s1.gpa <<s1.major;
// }

//shallow copy (copy constructor)
// #include <iostream>
// using namespace std;
// class Person
// {
// public:
//     int *age;
//     Person(int a)
//     {
//         age = new int(a);
//     }
//     ~Person()
//     {
//         delete age;
//     }
//     void print()
//     {
//         cout << *age << endl;
//     }

// };

// int main()
// {
//     Person p1(30);
//     Person p2 = p1; // default copy constructor
//     p1.print();
//     p2.print();
//     *p2.age = 99;
//     p2.print();
//     p1.print();
//     return 0;
// }

#include<iostream>
using namespace std;
class Restaurant{
    string name;
    int capacity;
    float average_price;
    int waiters;

    public:
    Restaurant(string name="",int capacity=0,float average_price=0,int waiters=0){
        this -> name = name;
        this -> capacity = capacity;
        this -> average_price= average_price;
        this -> waiters = waiters;
    }

    Restaurant(const Restaurant & r){
        name = r.name;
        capacity = r.capacity;
        average_price = r.average_price;
        waiters = r.waiters;
    }

    void printinfo(){
        cout<<name<<" has a capacity "<<capacity<<" and "<<waiters<<" waiters "<<endl;
    }

    void updateWaiters(int new_waiters){
        waiters  = new_waiters;
    }
};

int main(){
    Restaurant r1("CG",500,7000,66);
    Restaurant r2 = r1;
    r1.printinfo();
    r2.printinfo();
    r2.updateWaiters(99);
    r2.printinfo();
    r1.printinfo();

    return 0;
}
