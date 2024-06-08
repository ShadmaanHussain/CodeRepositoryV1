#include <iostream>
#include <queue>
#include "BinaryTreeNode.h"
using namespace std;

// Function to find the given node and return true if it is present false otherwise
bool FindNode(BinaryTreeNode<int> *root, int nodeData)
{
    // if the tree is null then return false
    if (root == NULL)
        return false;

    // if the root->data is same as nodeData return true
    if (root->data == nodeData)
        return true;

    // if the nodeData is present in the left sub-tree or the right sub-tree return true
    return FindNode(root->left, nodeData) || FindNode(root->right, nodeData);
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

// 1 2 3 4 5 6 -1 -1 -1 -1 -1 7 8 -1 -1 -1 -1
int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    printTreeLevelWise(root);
    int findNode;
    cout << "Enter the ndoe to find: " << endl;
    cin >> findNode;
    cout << FindNode(root, findNode);
    delete root;
    return 0;
}