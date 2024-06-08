#include<iostream>
#include "stackusingLL.cpp"

using namespace std;

int main() {
    LLStack<int> s;
    s.push(10);
    s.push(2);
    s.push(67);
    s.push(11);
    cout << s.top() << endl;
    cout << s.returnSize() << endl;
    s.pop();
    s.pop();
    cout << s.top() << endl << s.returnSize() << endl;
    s.pop();
    s.pop();
    cout << s.top() << endl << s.returnSize() << endl;
    return 0;
}