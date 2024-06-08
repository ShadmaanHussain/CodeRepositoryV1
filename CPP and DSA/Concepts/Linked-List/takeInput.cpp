#include <iostream>
#include "node.cpp"
using namespace std;

Node* takeInput() {
    int data;
    cin >> data;
    Node* head = NULL;
    Node* tail = NULL;
    while(data != -1) {
        Node *newNode = new Node(data);
        if(head == NULL) { // If there's no node in the linked list
            head = newNode;
            tail = newNode;
        } else { // If there are nodes in the linked list then create new node and connect it to the last element of the linked list
            tail->next = newNode;
            tail = newNode;
        }

        cin >> data;
    }
    return head;
}

void print(Node *head) {
    Node *temp = head;
    while(temp != nullptr) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}

int main() {
    Node *head = takeInput();
    print(head);
    return 0;
}