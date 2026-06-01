#include<iostream>
using namespace std;

template <typename T>
int searchelement(T arr[],int size, T element){
    for (int i=0;i<size;i++){
        if(arr[i]==element)
        return i;
    }
    throw string("Element not found");
}
int main(){
    float a[]={3.3,4.6,5.8,7.8,3.7};
    int asize = 5;

    try{
        int idx = searchelement(a,asize,5.5f);
        cout<<"Element found at index "<<idx<<endl;
    }
    catch(string & e){
        cout<<"Error"<<e<<endl;
    }
    char c[] = {'a', 'b', 'c', 'd', 'e'};
    int cSize = 5;

    try{
        int index = searchElement(c, cSize, 'c');
        cout << "Char element found at index: " << index << endl;
    }
    catch(string & e){
        cout << "Error: " << e << endl;
    }
}