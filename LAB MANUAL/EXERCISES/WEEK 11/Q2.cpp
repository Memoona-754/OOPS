#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Stack {
private:
    vector<char> st;

public:
    // Push element into stack
    void push(char ch) {
        st.push_back(ch);
    }

    // Pop element from stack
    void pop() {
        if (!st.empty()) {
            st.pop_back();
        }
    }

    // Peek top element
    char peek() {
        if (!st.empty()) {
            return st.back();
        }
        return '\0';
    }

    // Check if stack is empty
    bool isEmpty() {
        return st.empty();
    }

    // Reverse each word of a sentence
    void reverse(string sentence) {
        cout << "\nReversed Words Sentence:\n";

        for (int i = 0; i <= sentence.length(); i++) {

            // Push characters until space or end
            if (i < sentence.length() && sentence[i] != ' ') {
                push(sentence[i]);
            }
            else {
                // Print characters in reverse order
                while (!isEmpty()) {
                    cout << peek();
                    pop();
                }

                // Print space between words
                if (i != sentence.length()) {
                    cout << " ";
                }
            }
        }
    }
};

int main() {
    Stack s;
    string sentence;

    cout << "Enter a sentence: ";
    getline(cin, sentence);

    s.reverse(sentence);

    return 0;
}



