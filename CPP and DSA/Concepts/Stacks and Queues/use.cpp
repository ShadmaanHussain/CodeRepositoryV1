#include <iostream>
#include "stack.cpp"

using namespace std;

int main()
{
    stack s(20);
    cout << s.isEmpty() << endl;
    s.push(10);
    s.push(2);
    s.push(12);
    s.push(4);
    s.push(5);
    cout << s.top() << endl;
    cout << s.pop() << endl;
    s.pop();
    cout << s.top() << endl;
    return 0;
}