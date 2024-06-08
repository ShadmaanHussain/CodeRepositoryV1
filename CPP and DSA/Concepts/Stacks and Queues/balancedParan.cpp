#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool isValid(string s) {
        stack<char> toClose;
        for(auto ch:s) {
            if(ch != '(' && ch != ')' && ch != '{' && ch != '}' && ch != '[' && ch != ']') continue;
            if(ch == '(') {
                toClose.push(')');
            } else if (ch == '[') {
                toClose.push(']');
            } else if (ch == '{') {
                toClose.push('}');
            } else if(!toClose.empty() && toClose.top() == ch) {
                toClose.pop();         
            } else {
                return false;
            }
        }
        if(toClose.empty()) return true;
        return false;
}

int main() {
    string s = "(b*c/d{5)";
    cout << isValid(s);
    return 0;
}