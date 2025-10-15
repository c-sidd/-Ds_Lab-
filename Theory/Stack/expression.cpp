#include <iostream>
using namespace std;

int top = -1;
char stack3[100];

void push(char x) {
    if(top == 99)
        cout << "Overflow" << endl;
    else
        stack3[++top] = x;
}

char pop() {
    if(top == -1) {
        cout << "Underflow" << endl;
        return '\0';
    } else
        return stack3[top--];
}

int priority_check(char ch) {  
    if(ch=='+' || ch=='-') return 1;
    if(ch=='*' || ch=='/') return 2;
    if(ch=='^') return 3;
    return 0;
}

int main() {
    string s;
    cin >> s;
    string result = "";
    char ch;

    for(int i = 0; i < s.length(); i++) {
        ch = s[i];

        if(ch == '(') {
            push(ch);
        } 
        else if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            result += ch;
        } 
        else if(ch == ')') {
            while(top != -1 && stack3[top] != '(')
                result += pop();
            pop(); // remove '('
        } 
        else { // operator
            while(top != -1 && priority_check(stack3[top]) >= priority_check(ch)) {
                if(stack3[top] == '^' && ch == '^') // right-associative
                    break;
                else
                    result += pop();
            }
            push(ch);
        }

        // Optional: print intermediate postfix
        // cout << result << endl;
    }

    // Pop remaining operators
    while(top != -1)
        result += pop();

    cout << "Postfix: " << result << endl;
    return 0;
}
