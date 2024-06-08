#include <iostream>
#include "node.cpp"
using namespace std;

int main() {
    //Statically
    // Node n1(2);
    // Node *head = &n1;
    // Node n2(3);
    // n1.next = &n2;

    // Node *el = head;
    // do {
    //     cout << el->data << " ";
    //     el = el->next; // incrementing element to the next element
    // } while(el != nullptr); // while element is pointing to some location run the loop

    //Same as above only done dynamically.
    Node *n1 = new Node(2);
    Node *n2 = new Node(3);
    n1->next = n2;
    Node *el = n1;
    while(el != nullptr) {
        cout << el->data << " ";
        el = el->next;
    }
    return 0;
}