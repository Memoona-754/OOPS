#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    if(n >= 1){
        cout << n * (n + 1) / 2;
    } else {
        int count = 1 - n + 1;
        cout << (n + 1) * count / 2;
    }
    
    return 0;
}