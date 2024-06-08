using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = nullptr;
    }
};

class LinkedList
{
public:
    Node *head;
    Node *tail;

    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    void printList() {
        Node *temp = head;
        while(temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void newNode(int data)
    {
        Node *node = new Node(data);
        if (head == nullptr)
        {
            head = node;
            tail = node;
            return;
        }
        tail->next = node;
        tail = node;
    }

    void deleteLast()
    {
        Node *temp = head;
        if (temp->next == nullptr)
        {
            delete temp;
            head = nullptr;
            tail = nullptr;
        }
        while (temp->next->next != nullptr)
        {
            temp = temp->next;
        }
        delete temp->next;
        tail = temp;
        temp->next = nullptr;
    }

    int length() {
        int count = 0;
        Node *temp = head;
        while(temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    int dataAt(int i) {
        Node *temp = head;
        int pos = 0;
        while(pos != i) {
            temp = temp->next;
            pos++;
            if(temp == nullptr) {
                break;
            }
        }
        return temp->data;
    }

    void newNodeAt(int data, int pos) {
        Node *newNode = new Node(data);
        if(pos == 0) {
            newNode->next = head;
            head = newNode;
            return;            
        }
        Node *temp = head;
        for(int i = 0; i < pos - 1; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteIthNode(int pos) {
        Node *temp = head;
        if(pos == 0) {
            head = head->next;
            delete temp;            
        }
        for(int i = 0; i < pos - 1; i++) {
            temp = temp->next;
        }
        Node *addr = temp->next->next;
        delete temp->next;
        temp->next = addr;
    }

};