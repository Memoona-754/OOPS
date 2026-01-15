#include<iostream>
using namespace std;
void print(int n){
    if(n==0) //base case(just like condition of loops used to break loop)
      return;
    cout<<n<<endl;
    print(n-1);  
}
int main(){
    int n;
    cout<<"Enter n : ";
    cin>>n;
    print(n);
}