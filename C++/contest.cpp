#include<iostream>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int N,X;
        cin>>N>>X;
        int needed_candies = max(0,N-X);
        int packets = (needed_candies +3)/4;
        cout<<packets<<endl;
    }
    return 0;
}