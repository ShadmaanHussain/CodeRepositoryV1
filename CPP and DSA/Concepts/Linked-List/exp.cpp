#include <iostream>
#include "node.cpp"
using namespace std;

// Length of Linked List recursively
int recLength(Node *head)
{
    if (head == nullptr)
        return 0;
    return 1 + recLength(head->next);
}

// Insert Node recursively - my approach was just the same I just didn't account for head == nullptr
Node* insertNode(Node *head, int pos, int data)
{
    if (head == nullptr)
        return head;
    if (pos == 0)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        return head;
    }

    Node *newHead = insertNode(head->next, pos - 1, data);
    head->next = newHead;
    return head;
}

Node* deleteNode(Node *head, int pos) {
    if(head == nullptr) return head;
    if(pos == 0) {
        Node* addr = head;
        head = head->next;
        delete addr;
        return head;
    }
    Node* newHead = deleteNode(head->next, pos - 1);
    head->next = newHead;
    return head;
}

void printList(Node* head) {
        Node *temp = head;
        while(temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

Node* mergeLists(Node* head1, Node* head2) {
    Node* head = NULL;
    Node* tail = NULL;
    if(head1 == NULL) return head2;
    if(head2 == NULL) return head1;
    if(head1->data < head2->data) {
        head = head1;
        tail = head1;
        head1 = head1->next;
    } else {
        head = head2;
        tail = head2;
        head2 = head2->next;
    }
    while(head1 && head2) {
        if(head1->data < head2->data) {
            tail->next = head1;
            tail = head1;
            head1 = head1->next;
        } else {
            tail->next = head2;
            tail = head2;
            head2 = head2->next;
        }
    }
    if(head1) tail->next = head1;
    if(head2) tail->next = head2;
    return head;
}

Node* mergeSort(Node* list) {
    //Base Case
    if(list == NULL || list->next == NULL) {
        return list;
    }

    //Dividing the list in two parts
    Node* slow = list;
    Node* fast = slow->next;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* list1 = list;
    Node* list2 = slow->next;
    slow->next = NULL;
    
    //Recursive Call
    list1 = mergeSort(list1);
    list2 = mergeSort(list2);

    //Merging the sorted lists and returning them.
    return mergeLists(list1, list2);
}

int main()
{
    LinkedList l1;
    l1.newNode(2);
    l1.newNode(9);
    l1.newNode(7);
    l1.newNode(4);
    l1.newNode(3);
    l1.newNode(0);
    l1.printList();
    Node* newList = mergeSort(l1.head);
    printList(newList);
    return 0;
}