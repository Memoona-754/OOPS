#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isCorrect(string s) {
    stack<char> st;
    
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        
        if (c == '(' || c == '[') {
            st.push(c);
        }
        else if (c == ')') {
            if (st.top() != '(')  
                return false;
            st.pop();
        }
        else if (c == ']') {
            if (st.empty() || st.top() != '(')  
                return false;
            st.pop();
        }
    }

    return true; 
}
int main() {
    int n;
    cin >> n;
    
    while (n--) {
        string s;
        cin >> s;  
        
        if (isCorrect(s))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    
    return 0;
}