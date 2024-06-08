using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node *next;

    Node(T data)
    {
        this->data = data;
        next = NULL;
    }
};

template <typename T>
class LLStack
{
    Node<T> *head;
    int size;

public:
    LLStack()
    {
        head = NULL;
        size = 0;
    }

    void push(T val)
    {
        Node<T> *newNode = new Node<T>(val);
        if (head != NULL)
        {
            newNode->next = head;
        }
        head = newNode;
        size++;
    }

    T top()
    {   
        if(isEmpty()) return 0;
        return head->data;
    }

    bool isEmpty() {
        if(head == NULL) return true;
        return false;
    }

    void pop() {
        if(isEmpty()) {
            return;
        }
        Node<T> *temp = head->next;
        delete head;
        head = temp;
        size--;
    }

    int returnSize() {
        return size;
    }
};