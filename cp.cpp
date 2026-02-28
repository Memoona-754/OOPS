#include <iostream>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    map<string, int> m;
    
    while (n--) {
        int type;
        cin >> type;
        
        if (type == 1) {
            string name;
            int marks;
            cin >> name >> marks;
            m[name] += marks;  
        } 
        else if (type == 2) {
            string name;
            cin >> name;
            m.erase(name);    
        } 
        else {
            string name;
            cin >> name;
            cout << m[name] << endl;  
    }
}
    return 0;
}