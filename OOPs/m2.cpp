// #include<iostream>
// using namespace  std;
// class Animal{
//     public:
//     void speak(){
//            cout<<"Speak : ";
//     }
// };
// class Dog : public Animal{
//     public:
//     void speak() {
//       cout<<"Woof!";
//     }
// };
// int main(){
//     Animal a;
//     a.speak();
//     Dog d;
//     d.speak();
// }

// #include<iostream>
// using namespace std;
// class Vehicle{
//     public:
//     string brand;

//     Vehicle(string brand){
//         this -> brand = brand;
//     }
//     void show_brand(){
//         cout<<"The brand of car is : "<<brand<<endl;
//     }
// };
// class Car : public Vehicle{
//     public:
//     int doors;
//     Car(string brand , int doors):Vehicle(brand){
//         this -> doors = doors;
//     }
//     void num_doors(){
//         cout<<"The nmbr of doors in car is : "<<doors<<endl;
//     }
// };
// class ElectricCar : public Car{
//     public:
//     float batterylife;
//     ElectricCar(string brand,int doors,float batterylife) : Car(brand,doors){
//         this -> batterylife =batterylife;
//     }
//     void batteryLife(){
//         cout<<"The battery life of car is : "<<batterylife<<endl;
//     }
// };

// int main(){
//     ElectricCar EC1("Tesla",2,18.99);
//     EC1.show_brand();
//     EC1.num_doors();
//     EC1.batteryLife();

//     return 0;
// }

// #include<iostream>
// using namespace std;
// class Fly{
//     public:
//     void canFly(){
//         cout<<"Can Fly!"<<endl;
//     }
// };
// class Swim{
//     public:
//     void canSwim(){
//         cout<<"Can swim!"<<endl;
//     }
// };
// class Duck : public Fly , public Swim{};

// int main(){
//     Duck d1;
//     d1.canFly();
//     d1.canSwim();
// }


// #include<iostream>
// using namespace std;
// class Shape{
//    public:
//     float area(){
//         return 0;
//     }
// };
// class Circle : public Shape{
//     public:
//     int r;
//     Circle(int r){
//         this -> r = r;
//     }
//     float area(){
//         return (3.14*r*r);
//     }
    
// };
// class Rectangle : public Shape{
//     public:
//     int l;
//     int b;
//     Rectangle(int l,int b){
//         this -> l = l;
//         this -> b =b;
//     }
//     float area(){
//         return (l*b);
//     }
// };
// int main(){
//    Circle c1(7);
//    cout<< c1.area()<<endl;
//    Rectangle r1(4,7);
//    cout<< r1.area();
// }


#include<iostream>
using namespace std;
class A{
    public:
    void show(){
        cout<<"I am a parent class";
    }
};
class B: virtual  public A{
    // public :
    // void show(){
    //     cout<<"Child class B";
    // }
};
class C : virtual public A{
    // public:
    // void show(){
    //     cout<<"Child class C";
    // }
};
class D :  public B,public C{
    // public:
    // void show(){
    //   // cout<<"Chid class D";
    // }
};
int main(){
    D d;
    d.show();
    //d.B::show();
}