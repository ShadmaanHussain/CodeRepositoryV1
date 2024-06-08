#include <iostream>
#include <queue>
#include "BinaryTreeNode.h"
#include <utility>
using namespace std;

class Node { 
    public:
    int data;
    Node* next;

    Node(int d) {
        data = d;
    }
};

void print(Node *head) {
    Node *temp = head;
    while(temp != nullptr) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}

pair<Node*,Node*> BSTtoLL(BinaryTreeNode<int>* root) {
    if(root == NULL) {
        pair<Node*,Node*> p(NULL,NULL);
        return p;
    }
    pair<Node*, Node*> ans;
    pair<Node*,Node*> left = BSTtoLL(root->left);
    pair<Node*,Node*> right = BSTtoLL(root->right);
    Node* rootLL = new Node(root->data);
    rootLL->next = right.first;
    if(left.first == NULL && right.first == NULL) {
        ans.first = rootLL;
        ans.second = rootLL;
        return ans;
    }
    if(left.first == NULL) {
        ans.first = rootLL;
        ans.second = right.second;
        return ans;
    }
    left.second->next = rootLL;
    ans.first = left.first;
    ans.second = right.second;
    return ans;
}



void printTreeLevelWise(BinaryTreeNode<int> *root)
{
    // if the tree is empty return
    if (root == NULL)
        return;
    // Queue for nodes to process
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    // While there are nodes to process in the queue -
    // (process the nodes mean printing the node data and all of it's child's data and storing the children in the queue to be processed)
    while (!pendingNodes.empty())
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << front->data << ": ";
        if (front->left != NULL)
        {
            cout << "L" << front->left->data;
            pendingNodes.push(front->left);
        }
        if (front->right != NULL)
        {
            cout << "R" << front->right->data;
            pendingNodes.push(front->right);
        }
        cout << endl;
    }
}

BinaryTreeNode<int> *takeInputLevelWise()
{
    int data;
    cout << "Enter the root of the tree: " << endl;
    cin >> data;
    if (data == -1)
        return NULL;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(data);
    queue<BinaryTreeNode<int> *> toProcess;
    toProcess.push(root);
    while (!toProcess.empty())
    {
        BinaryTreeNode<int> *front = toProcess.front();
        toProcess.pop();
        int left, right;
        cout << "Enter left child of " << front->data << endl;
        cin >> left;
        cout << "Enter right child of " << front->data << endl;
        cin >> right;
        if (left != -1)
        {
            BinaryTreeNode<int> *leftChild = new BinaryTreeNode<int>(left);
            front->left = leftChild;
            toProcess.push(leftChild);
        }
        if (right != -1)
        {
            BinaryTreeNode<int> *rightChild = new BinaryTreeNode<int>(right);
            front->right = rightChild;
            toProcess.push(rightChild);
        }
    }
    return root;
}

// 4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1
int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    printTreeLevelWise(root);
    Node* head = BSTtoLL(root).first;
    print(head);
    delete root;
    return 0;
}