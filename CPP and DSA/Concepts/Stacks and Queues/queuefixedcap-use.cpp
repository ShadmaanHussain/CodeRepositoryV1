#include<iostream>
#include "queuefixedcap.cpp"

using namespace std;

int main() {
    Queue q;
    q.enqueue(2);
    q.enqueue(4);
    q.enqueue(1);
    q.enqueue(6);
    q.enqueue(8);
    q.enqueue(10);
    cout << q.front() << endl;
    q.dequeue();
    q.dequeue();
    q.enqueue(10);
    cout << q.front() << " " << q.returnSize() << endl;
    return 0;
}