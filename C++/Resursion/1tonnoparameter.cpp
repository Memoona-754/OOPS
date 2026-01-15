#include<iostream>
using namespace std;
void print(int n){
    if(n==0) //base case(just like condition of loops used to break loop)
      return;
    print(n-1);  
    cout<<n<<endl;
}
int main(){
    int n;
    cout<<"Enter n : ";
    cin>>n;
    print(n);
}