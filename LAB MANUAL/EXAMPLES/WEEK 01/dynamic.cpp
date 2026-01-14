#include<iostream>
using namespace std;
    int main(){
    int* intPtr;
    char* charArray;
    int Size;
    intPtr = new int; // allocating memory to single variable
    cout << "Enter an Integer Value: ";
    cin >> *intPtr;
    cout << "Enter the size of the Character Array : ";
    cin >> Size;
    charArray = new char[Size];//allocating memory to array
       for (int i = 0; i < Size; i++)
          cin >> charArray[i];
        for (int i = 0; i < Size; i++)
          cout << charArray[i];
            return 0;
}
   